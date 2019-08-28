/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/bezier_panel.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "BezierCurvePanel.h"

namespace igeek {
  
BezierCurvePanel::BezierCurvePanel (int thisX, int thisY, BezierCurve thisCurve, 
    Color thisBackgroundColor, Color thisCurveColor, Color thisBorderColor)
{
    x = thisX;
    y = thisY;
    
    width  = defaultSize;
    height = defaultSize;
    
    curve = new BezierCurve (thisCurve);
    
    padding = defaultPadding;
    doublePadding = 2*padding;
    
    numPoints = defaultNumPoints;
    pointRadius = 3;
    twicePointRadius = 2*pointRadius;
    
    resolution = defaultResolution;
    deltaT = defaultDeltaT;
    
    backgroundColor = thisBackgroundColor;
    curveColor = thisCurveColor;
    borderColor = thisBorderColor;
    axesColor = Color.gray;
}

int BezierCurvePanel::getNumPoints ()
{
    return numPoints;
}

void BezierCurvePanel::draw (Graphics g)
{
    int centerY = y + height/2 - padding;
    
    g.setColor (backgroundColor);
    g.fillRect (x-padding, y-padding, width+doublePadding, height+doublePadding);
    
    g.setColor (borderColor);
    g.drawRect (x-padding, y-padding, width+doublePadding, height+doublePadding);
    
    g.setColor (axesColor);
    g.drawLine (x, centerY, x+width, centerY);
    g.drawLine (x, y, x, y + height);
    
    if (curve.numPoints == 4)
        drawCubic (g);
     
    g.setColor (pointColor);
    
    for (int i=0; i < numPoints; i++)
    {
        int currentX = x       + (int)curve.xpoints[i] * width - pointRadius,
            currentY = centerY + (int)curve.ypoints[i] * width - pointRadius;
        
        g.fillOval (currentX, currentY, twicePointRadius, twicePointRadius);
    }
}

void BezierCurvePanel::drawCubic (Graphics g)
{
    g.setColor (curveColor);
    
    double centerY = y + height/2 - padding,
           lastX = 0,
           lastY = 0,
           x0 = curve.xpoints[0],
           y0 = curve.ypoints[0],
           x1 = curve.xpoints[1],
           y1 = curve.ypoints[1],
           x2 = curve.xpoints[2],
           y2 = curve.ypoints[2],
           x3 = curve.xpoints[3],
           y3 = curve.ypoints[3];
           
    //System.out.print (curve.ToString () + "\n deltaT = " + deltaT + "\n\n");
    
    for (double t = deltaT; t < 1.0; t += deltaT)
    {
        double oneMinus_t = 1.0 - t,
               oneMinus_t_Squared = Math.pow (oneMinus_t, 2.0),
               oneMinus_t_Cubed   = Math.pow (oneMinus_t, 3.0),
               tSquared = Math.pow (t, 2.0),
               tCubed   = Math.pow (t, 3.0),
               currentX = x       + width * ((oneMinus_t_Cubed*x0 + 3.0*oneMinus_t_Squared*t*x1+3.0*oneMinus_t*tSquared*x2+tCubed*x3)),
               currentY = centerY + width * ((oneMinus_t_Cubed*y0 + 3.0*oneMinus_t_Squared*t*y1+3.0*oneMinus_t*tSquared*y2+tCubed*y3));
        
        lastX = currentX;
        lastY = currentY;
        
        //System.out.print ("currentX = " + currentX + ", currentY " + currentY + "\n");
        
        g.drawLine ((int)lastX, (int)lastY, (int)currentX, (int)currentY);
    }
}

}   //< namespace igeek {
