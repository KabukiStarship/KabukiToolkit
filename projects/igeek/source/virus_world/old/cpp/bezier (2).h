/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/bezier.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

namespace igeek {
    
class BezierCurve
/*< A fourth order BezierCurve.
*/
{
  public:
    
    static const int DefaultNumPoints = 4;
    
    int numPoints;
               
    double[] xpoints,    /< An array of the 
                    ypoints;
    
    /* Constructor initializes curve with the given points.
    @warning the length of x_points and y_points must equal point_count or curve will not be created correctly.
    */ 
    BezierCurve (double x_points[], double y_points[], int point_count);

    /* Constructor initializes curve with the given points.
    */
    BezierCurve (double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
    {
        numPoints = 4;
        xpoints = new double[4];
        ypoints = new double[4];
        
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
    Point2D getPoint (double t);
    
    static int factoral (int value);
    
    int getNumPoints ();
    
    AString ToString ();
};

}   //< igeek

