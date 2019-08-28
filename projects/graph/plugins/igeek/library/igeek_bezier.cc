/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/library/igeek_bezier.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <pch.h"

#include "c_bezier.h"

namespace _ {


BezierCurve::BezierCurve (FP8 x_points[], FP8 y_points[], SI4 point_count)
{
  DASSERT (y_points != null) : "Error creating BezierCurve. xPoings is null.";
  DASSERT (y_points != null) : "Error creating BezierCurve. y_points is null.";

  SI4 tempX = x_points.length;

  DASSERT (tempX != point_count) : "Error creating BezierCurve. point_count doesn't match the length of the point arrays.";


  if (y_points == null || x_points == null || tempX != y_points.length || tempX != point_count)
  {
    numPoints = 4;

    xpoints = new FP8[4];
    ypoints = new FP8[4];

    xpoints[0] = 0;
    ypoints[0] = 0;
    xpoints[1] = 0;
    ypoints[1] = 1;
    xpoints[2] = 1;
    ypoints[2] = -1;
    xpoints[3] = 1;
    ypoints[3] = 0;
  }
  else
  {
    numPoints = point_count;
    xpoints = new FP8[point_count];
    ypoints = new FP8[point_count];

    for (SI4 i = 0; i < point_count; i++)
    {
      xpoints[i] = x_points[i];
      ypoints[i] = y_points[i];
    }
  }
}

BezierCurve::BezierCurve (FP8 x0, FP8 y0, FP8 x1, FP8 y1, FP8 x2, FP8 y2, FP8 x3, FP8 y3)
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

BezierCurve::BezierCurve (BezierCurve initState)
{
  DASSERT (initState != null) : "Error creating BezierCurve using copy constructor. Input was null.";

  if (initState != null)
  {
    numPoints = 4;

    xpoints = new FP8[4];
    ypoints = new FP8[4];

    xpoints[0] = 0;
    ypoints[0] = 0;
    xpoints[1] = 0;
    ypoints[1] = 1;
    xpoints[2] = 1;
    ypoints[2] = -1;
    xpoints[3] = 1;
    ypoints[3] = 0;
  }
  else
  {
    numPoints = initState.numPoints;

    xpoints = new FP8[numPoints];
    ypoints = new FP8[numPoints];

    for (SI4 i = 0; i < numPoints; i++)
    {
      xpoints[i] = initState.xpoints[i];
      ypoints[i] = initState.ypoints[i];
    }
  }
}

Point2D BezierCurve::getPoint (FP8 t)
{
  FP8 x = 0,                           //< The x position to return.
    y = 0,                           //< The y position to return.
    factn = factoral (numPoints);    //< Local copy of n!.

  SI4 n = numPoints;                      //< Local copy of numPoints as a FP8.

  for (SI4 i = 0; i <= n; i++)
  {
    FP8 b = factn / (factoral (i) * factoral (n - i)), //< Calculate binomial coefficient
      k = Math.pow (1 - t, n - i) * Math.pow (t, i);   //< Calculate powers

// Add weighted points to totals
    x += b * k*xpoints[i];
    y += b * k*ypoints[i];
  }

  return new Point2D.Double (x, y);
}

static SI4 BezierCurve::factoral (SI4 value)
{
  // return special case
  if (value == 0)
    return 1;

  if (value < 0)
    value *= -1;

  // Calculate factoral of value

  SI4 total = value;
  while (--value > 1)
    total *= value;

  return total;
}

SI4 BezierCurve::getNumPoints ()
{
  return numPoints;
}

AString BezierCurve::ToString ()
{
  AString returnString = new AString ("numPoints = " + numPoints + "\n");

  for (SI4 i = 0; i < numPoints; i++)
  {
    returnString += ("x[" + i + "] = " + xpoints[i] + ", y[" + i + "] = " + ypoints[i] + "\n");
  }
  returnString += ("\n");

  return returnString;
}
}   //< namespace igeek
}   //< namespace kabuki
