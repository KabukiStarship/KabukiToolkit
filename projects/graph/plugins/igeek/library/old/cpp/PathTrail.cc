/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/path_trail.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "path_trail.h"

namespace igeek {
    
PathTrail::PathTrail ()
{
    trailColor   = DefaultTrailColor;
    maxNumPoints = DefaultMaxNumPoints;
    
    initialize ();
}

PathTrail::PathTrail (Color thisTrailColor)
{
    if (thisTrailColor == null)
        trailColor = DefaultTrailColor;
    else
        trailColor = thisTrailColor;
        
    maxNumPoints = DefaultMaxNumPoints;
        
    initialize ();
}

PathTrail::PathTrail (Color thisTrailColor, int thisMaxNumPoints)
{
    if (thisTrailColor == null)
        trailColor = DefaultTrailColor;
    else
        trailColor = thisTrailColor;
        
    if (thisMaxNumPoints < 0)
        maxNumPoints = DefaultMaxNumPoints;
    else
        maxNumPoints = thisMaxNumPoints;
    
    initialize ();
}

void PathTrail::initialize ()
{
    startPoint = stopPoint = numPoints = 0;
    
    xpoints = new int[maxNumPoints];
    ypoints = new int[maxNumPoints];
}

void PathTrail::setTrailColor (Color newColor)
{
    if (newColor != null)
        trailColor = newColor;
}

Color PathTrail::getTrailColor ()
{
    return trailColor;
}

void PathTrail::draw (Graphics g)
{
    //System.out.print (toString ());
    g.setColor (trailColor);
    
    for (int i = startPoint; i < stopPoint-1; ++i)
    {
        if (i >= maxNumPoints)
             i = 0;
        
        g.drawLine (xpoints[i], ypoints[i], xpoints[i+1], ypoints [i+1]);
    }
    for (int i = 0; i <= stopPoint-2; ++i)
    {
        g.drawLine (xpoints[i], ypoints[i], xpoints[i+1], ypoints [i+1]);
    }
}

void PathTrail::addPoint (int x, int y)
{
    //System.out.print ("\nAdding point { x = " + x + ", y = " + y + " }\n");
    
    if (numPoints < maxNumPoints)
        ++numPoints;
    
    // This is a circular que. This means that when we add at first, the stopIndex is going to increment
    // until we hit the maxNumPoints, then the startIndex and stopIndex will increment and loop around such
    // that startIndex = stopIndex + 1.
    
    xpoints[stopPoint] = x;
    ypoints[stopPoint] = y;
    
    if (++stopPoint >= maxNumPoints)
        stopPoint = 0;
    
    if (stopPoint == startPoint)
        startPoint++;
        
    if (startPoint >= maxNumPoints)
        startPoint = 0;
    
    //System.out.print (toString ());
}

String PathTrail::toString ()
{
    String returnString = "PathTrail: numPoints = " + numPoints + ", startPoint = " + startPoint + ", stopPoint = " + stopPoint + "\n";
    
    for (int i = 0; i < numPoints; i++)
        returnString +=  i + ".) x = " + xpoints[i] + ", y = " + ypoints[i] + "\n";
    
    return returnString;
}

}   //< namespace igeek {
