/* Cell Evolutionary Interface
@version   0.x
@file      /.../CellEvolutionaryInterface/BezierCurve.h
@author  Cale McCollough <http://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

namespace CellEvolutionaryInterface {
    
/* A fourth order BezierCurve.
*/
class BezierCurve
{
  public:
    
    static const SI4 DefaultNumPoints = 4;
    
    SI4 numPoints;
               
    FP8* xpoints,    //< An array of the 
          * ypoints;
    
    /* Constructor initializes curve with the given points.
    @warning the length of xPoints and yPoints must equal nPoints or curve will not be created correctly.
    */ 
    BezierCurve (FP8 xPoints[], FP8 yPoints[], SI4 nPoints);

    /* Constructor initializes curve with the given points.
    */
    BezierCurve (FP8 x0, FP8 y0, FP8 x1, FP8 y1, FP8 x2, FP8 y2, FP8 x3, FP8 y3)
    {
        numPoints = 4;
        xpoints = new FP8[4];
        ypoints = new FP8[4];
        
        xpoints[0] = x0;
        ypoints[0] = y0;
        xpoints[1] = x1;
        ypoints[1] = y1;
        xpoints[2] = x2;
        ypoints[2] = y2;
        xpoints[3] = x3;
        ypoints[3] = y3;
    }

    /* Copy constructor initializes curve with the given points.
    */
    BezierCurve (BezierCurve initState);
    
    / Returns a Point2D along the path of the of curve at time t.
    Point2D getPoint (FP8 t);
    
    static SI4 factoral (SI4 value);
    
    SI4 getNumPoints ();
    
    String toString ();
};

}   //< CellEvolutionaryInterface

