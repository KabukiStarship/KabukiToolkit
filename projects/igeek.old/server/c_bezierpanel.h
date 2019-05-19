/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/console/c_bezierpanel.h
@author  Cale McCollough <calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

namespace _ {


class BezierCurvePanel
  /* This class draws a BezierCurve drawn on a JPanel.

  */
{
  static const SI4 defaultNumPoints = 4, //< The default number of points.
    defaultResolution = 1000, //< The default resolution.
    defaultPadding = 20, //< The default padding.
    defaultSize = 200; //< The default size of the

    static const double defaultDeltaT = 1 / (double)defaultResolution; //< The default increment in the path to iterate when drawing.


    static const Color defaultCurveColor = Color.red, //< The default of of the curve.
    defaultBorderColor = Color.white; //< The border color.


    BezierCurvePanel (SI4 thisX, SI4 thisY, BezierCurve thisCurve, Color thisBackgroundColor, Color thisCurveColor,
      Color thisBorderColor);

  SI4 getNumPoints ();

  void draw (Graphics g);

  void drawCubic (Graphics g);

private:

  SI4 numPoints, //< The number of bezier points.
    resolution, //< The path resolution.
    padding, //< The panel padding.
    doublePadding, //< Double to padding for calculation acceleration.
    x, //< The x position of this panel on the screen.
    y, //< The y position of this panel on the screen.
    width, //< The width of this panel.
    height, //< The height of this panel.
    pointRadius, //< The radius of the point to draw.
    twicePointRadius; //< Twice the pointRaidus.

    double deltaT, //< The increment in the path to iterate when drawing.
    curveScale, //< The scale of the Bezier path.
    /*< The Bezier Curve path is a scalar path bounced from 0<x<1 and -1<y<1. This determines how far 1 is. */
    x1, //< The second x point.
    y1, //< The second y point.
    x2, //< The third x point.
    y2; //< The third y point.

    BezierCurve curve; //< The bezier curve.

    Color backgroundColor, //< The background color.
    curveColor, //< The color of the curve.
    borderColor, //< The color of the border.
    axesColor, //< The color to draw the axes.
    pointColor; //< The color of the points to draw.

    double[] points; //< The bazier points.
};

} //< namespace igeek
} //< namespace kabuki
