/** Kabuki Software Development Kit
    @file    /.../Kabuki-Library/_G/ErrorList.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#pragma once

#include "Rect.hpp"

namespace _2D {
    
class _KabukiSDK Polygon_f
/** A 2D polygon that uses 32-bit floating point values. */
{
    public:

    enum {
        MinLength = 4       //< The minimum length of a Polygon
    };
    
    Polygon_f ();

    Polygon_f (int* xPoints, int* yPoints, int numPoints);

    void reset();

    void invalidate();

    void translate (int deltaX, int deltaY);

    void calculateBounds (int* xPoints, int* yPoints, int numPoints);

    void updateBounds (int x, int y);

    void addPoint (float x, float y);

    Rect_f getBounds();

    bool contains (Point_f p);

    bool contains (int x, int y);

    bool contains (float x, float y);

    bool contains (Point_f p);

    bool intersects (float x, float y, float w, float h);

    bool intersects (Rect_f r);

    PolygonPathIterator_f getPathIterator (AffineTransform_f at);

    PathIterator_f getPathIterator (AffineTransform_f at, float flatness);

    protected:

    Rect_f bounds;
    
    private:
	
	_G::Color_i color;  //< The color of the polygon.

    int numPoints;

    int* xPoints;

    int* yPoints;

    Crossings getCrossings (float xlo, float ylo, float xhi, float yhi);
};



class PolygonPathIterator_f: public PathIterator 
{
    public:

    PolygonPathIterator_f (Polygon pg, AffineTransform at);

    int getWindingRule();

    bool isDone();

    void next();

    int currentSegment (float* coords);

    int currentSegment (float* coords);

    private:

    Polygon poly;

    AffineTransform transform;

    int index;
};

}   //< _2D