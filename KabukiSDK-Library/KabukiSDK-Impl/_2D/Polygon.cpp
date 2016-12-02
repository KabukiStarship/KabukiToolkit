/** Kabuki Software Development Kit
    @file    /.../Kabuki-Library/_2D/Polygon.cpp
    @author  
*/

#pragma once

#include <_2D/Polygon.hpp>

#include <_Math/Calc.hpp>

using namespace _Math;

namespace _G {

Polygon_f::Polygon_f()
{
    xPoints = new int[MinLength];
    yPoints = new int[MinLength];
}

Polygon_f::Polygon_f (int xPoints[], int yPoints[], int numPoints) 
{
    if (numPoints < 0)
    {
        xPoints = new int[MinLength];
        yPoints = new int[MinLength];
    }

    numPoints = numPoints;
    xPoints = Arrays.copyOf (xPoints, numPoints);
    yPoints = Arrays.copyOf (yPoints, numPoints);
}

void Polygon_f::reset()
{
    numPoints = 0;
    bounds = nullptr;
}

void Polygon_f::invalidate ()
{
    bounds = nullptr;
}

void Polygon_f::translate (int deltaX, int deltaY)
{
    for (int i = 0; i < numPoints; i++)
    {
        xPoints[i] += deltaX;
        yPoints[i] += deltaY;
    }

    bounds.translate (deltaX, deltaY);
}

void Polygon_f::calculateBounds (int* xPoints, int* yPoints, int numPoints)
{
    int boundsMinX = ~(0);
    int boundsMinY = ~(0);
    int boundsMaxX = (~(0)) & (1 << (sizeof (int) * 8- 1));
    int boundsMaxY = (~(0)) & (1 << (sizeof (int) * 8 - 1));

    for (int i = 0; i < numPoints; ++i)
    {
        int x = xPoints[i];
        boundsMinX = min (boundsMinX, x);
        boundsMaxX = max (boundsMaxX, x);
        int y = yPoints[i];
        boundsMinY = min (boundsMinY, y);
        boundsMaxY = max (boundsMaxY, y);
    }
    return Rect_f (boundsMinX, boundsMinY, boundsMaxX - boundsMinX, boundsMaxY - boundsMinY);
}

void Polygon_f::updateBounds (int x, int y)
{
    if (x < bounds.x)
    {
        bounds.width = bounds.width + (bounds.x - x);
        bounds.x = x;
    }
    else
    {
        bounds.width = max (bounds.width, x - bounds.x);
        // bounds.x = bounds.x;
    }

    if (y < bounds.y)
    {
        bounds.height = bounds.height + (bounds.y - y);
        bounds.y = y;
    }
    else
    {
        bounds.height = max (bounds.height, y - bounds.y);
        // bounds.y = bounds.y;
    }
}

void Polygon_f::addPoint (int x, int y)
{
    if (numPoints >= xPoints.length || numPoints >= yPoints.length)
    {
        int newLength = numPoints * 2;
        // Make sure that newLength will be greater than MinLength and
        // aligned to the power of 2
        if (newLength < MinLength) {
            newLength = MinLength;
        } else if ((newLength & (newLength - 1)) != 0) {
            newLength = Integer.highestOneBit (newLength);
        }

        xPoints = Arrays.copyOf (xPoints, newLength);
        yPoints = Arrays.copyOf (yPoints, newLength);
    }
    xPoints[numPoints] = x;
    yPoints[numPoints] = y;
    numPoints++;
    if (bounds != nullptr)
    {
        updateBounds (x, y);
    }
}

Rect_f Polygon_f::getBounds()
{
    return getBoundingBox();
}


bool Polygon_f::contains (Point_f p)
{
    return contains (p.x, p.y);
}

bool contains (int x, int y)
{
    return contains((float) x, (float) y);
}

_2D::Rect_f Polygon_f::getBounds2D()
{
    return getBounds();
}

bool Polygon_f::contains (float x, float y)
{
    if (numPoints <= 2 || !getBoundingBox().contains (x, y)) {
        return false;
    }
    int hits = 0;

    int lastx = xPoints[numPoints - 1];
    int lasty = yPoints[numPoints - 1];
    int curx, cury;

    // Walk the edges of the polygon
    for (int i = 0; i < numPoints; lastx = curx, lasty = cury, i++) {
        curx = xPoints[i];
        cury = yPoints[i];

        if (cury == lasty) 
            continue;

        int leftx;
        if (curx < lastx) 
        {
            if (x >= lastx) continue;
            
            leftx = curx;
        } else 
        {
            if (x >= curx) 
            {
                continue;
            }
            leftx = lastx;
        }

        float test1, test2;
        if (cury < lasty) 
        {
            if (y < cury || y >= lasty) 
            {
                continue;
            }
            if (x < leftx) {
                hits++;
                continue;
            }
            test1 = x - curx;
            test2 = y - cury;
        } else {
            if (y < lasty || y >= cury) {
                continue;
            }
            if (x < leftx) {
                hits++;
                continue;
            }
            test1 = x - lastx;
            test2 = y - lasty;
        }

        if (test1 < (test2 / (lasty - cury) * (lastx - curx))) {
            hits++;
        }
    }

    return ((hits & 1) != 0);
}

bool Polygon_f::contains (Point_f p)
{
    return contains (p.getX(), p.getY());
}

bool Polygon_f::intersects (float x, float y, float w, float h)
{
    if (numPoints <= 0 || !getBoundingBox().intersects (x, y, w, h)) {
        return false;
    }

    Crossings cross = getCrossings (x, y, x+w, y+h);
    return (cross == nullptr || !cross.isEmpty());
}

bool Polygon_f::intersects (_2D::Rect_f r)
{
    return intersects (r.getX(), r.getY(), r.getWidth(), r.getHeight());
}

bool Polygon_f::contains (float x, float y, float w, float h)
{
    if (numPoints <= 0 || !getBoundingBox().intersects (x, y, w, h)) {
        return false;
    }

    Crossings cross = getCrossings (x, y, x+w, y+h);
    return (cross != nullptr && cross.covers (y, y+h));
}

bool Polygon_f::contains (_2D::Rect_f r)
{
    return contains (r.getX(), r.getY(), r.getWidth(), r.getHeight());
}

PathIterator Polygon_f::getPathIterator (AffineTransform at)
{
    return new PolygonPathIterator (this, at);
}

PathIterator Polygon_f::getPathIterator (AffineTransform at, float flatness)
{
    return getPathIterator (at);
}

Crossings Polygon_f::getCrossings (float xlo, float ylo, float xhi, float yhi)
{
    Crossings cross = new Crossings.EvenOdd (xlo, ylo, xhi, yhi);
    int lastx = xPoints[numPoints - 1];
    int lasty = yPoints[numPoints - 1];
    int curx, cury;

    // Walk the edges of the polygon
    for (int i = 0; i < numPoints; i++) {
        curx = xPoints[i];
        cury = yPoints[i];
        if (cross.accumulateLine (lastx, lasty, curx, cury)) {
            return nullptr;
        }
        lastx = curx;
        lasty = cury;
    }

    return cross;
}

//-----------------------------------------------------------------------------

PolygonPathIterator_f::Polygon32PathIterat (Polygon pg, AffineTransform at)
{
    poly = pg;
    transform = at;
    if (pg.numPoints == 0) {
        // Prevent a spurious SEG_CLOSE segment
        index = 1;
    }
}

int PolygonPathIterator_f::getWindingRule()
{
    return WIND_EVEN_ODD;
}

bool PolygonPathIterator_f::isDone()
{
    return index > poly.numPoints;
}

void PolygonPathIterator_f::getNext()
{
    index++;
}

int PolygonPathIterator_f::currentSegment (float* coords)
{
    if (index >= poly.numPoints) {
        return SEG_CLOSE;
    }
    coords[0] = poly.xPoints[index];
    coords[1] = poly.yPoints[index];
    if (transform != nullptr) {
        transform.transform (coords, 0, coords, 0, 1);
    }
    return (index == 0 ? SEG_MOVETO : SEG_LINETO);
}

int PolygonPathIterator_f::currentSegment (float* coords)
{
    if (index >= poly.numPoints) {
        return SEG_CLOSE;
    }
    coords[0] = poly.xPoints[index];
    coords[1] = poly.yPoints[index];
    if (transform != nullptr) {
        transform.transform (coords, 0, coords, 0, 1);
    }
    return (index == 0 ? SEG_MOVETO : SEG_LINETO);
}

}   //< namespace _2D