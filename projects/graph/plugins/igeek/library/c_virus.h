/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/c_virus.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "GeneticPolygon.h"
#include "PathTrail.h"

namespace igeek {
 
class Virus: public GeneticPolygon
/* This class represents a GeneticPolygon Virus.
@desc  A virus is a Genetic Polygon

Movement:

Drift Speed: This is a constant speed that is added onto a Virus's movement TArray. This allows Viruses.

Movement of Viruses is define by Bezier curves. There are two distinct patterns of movement:

1.) Linear Movement - This is defined where the movement occurs primarily 

2.) Circular movement - This is where a a Virus moves back and forth through the curve waveform.    
*/
{
  public:
    
    static const SI4 defaultWidth   = 50,                   /< The default width.
        DefaultHeight               = 50,                   /< The default height.
        defaultSpeed                = 20,                   /< The default speed.
        CircleMargin                = 20,                   /< The margin around the 
        CircleMarginX2              = CircleMargin * 2,     /< Twice the margin used to drawOval (...);
        numTrailSegments            = 2;                    /< The number of segments in the trail.
                            
    static const long DefaultReproductionTime   = 10000;    /< The default time to reproduce.
    
    static const FP8 minSpeed                = 10.0,     /< The minimum speed in pixels/frame.
        maxSpeed             = 20.0,                        /< This is the maximum speed in pixels/frame.
        defaultPathLength    = 500,                         /< The default length the movement path in seconds
        defaultDeltaT        = 0.01,                        /< The default deltaT???
        trailDeltaT_accuracy = 1000,                        /*< This number represents the number of digits of accuracy.
                                                                Note: Must be an even power of 10 */
        defaultTrailDeltaT   = 1/(2 * numTrailSegments);    /< 
    
    Virus (FP8 initX, FP8 initY);
    
    Virus (SI4 point_count, SI4 width, SI4 height, SI4 color, 
                  SI4 lifespan, FP8 angle);
    
    void initialize ();
    
    FP8 velocityX ();
    /*< Returns the instantaneous velocity in the x axis of this object in relation to the prior frame. */
    
    FP8 velocityY ();
    /*< Returns the instantaneous velocity in the y axis of this object in relation to the prior frame. */
    
    FP8 centerX ();
    
    FP8 centerY ();
    
    void collideWith (Virus thatVirus);
    
    void updatePosition (SI4 hostWidth, SI4 hostHeight);
    
    void updateTrail ();
    
    BOL checkHostBoundsCollision (SI4 hostWidth, SI4 hostHeight);
    
    void select ();
    
    void deselect ();

    BOL containsPoint (SI4 thisX, SI4 thisY);
    
    BOL containsPoint (FP8 thisX, FP8 thisY);
    
    BOL contains (Rectangle thisRectangle);
    
    BOL intersects (Virus thatVirus);
    
    FP8 getX ();
    
    FP8 getY ();
    
    SI4 Left ();
    
    SI4 Top ();
    
    SI4 rightEdge ();
    
    SI4 bottomEdge ();
        
    BezierCurve getBezierCurve ();
    
    void fillCircle (Graphics g);
    
    void drawCircle (Graphics g);
    
    void drawCircle (Graphics g, Color thisColor);
    
    void draw (Graphics g);
    
    void setTrailColor (Color newColor);
    
    void setDrawTrail (BOL newState);
    
    BOL getDrawTrail ();
    
    void setCircleColor (Color newColor);
    
    void setDrawCircle (BOL newState);
    
    void setCircleFillColor (Color newColor);
    
    void setFillCircle (BOL newState);
    
  private:

    
    SI4 velocityDirection,          /< Variable that indicates which direction the.
        numTailSegments,
        currentIndex;
    
    FP8 x,                       /< The current x position.
        y,                       /< The current y position.
        lastX,                   /< The last x position.
                                    /*< Used to calculate collision angles. */
        lastY,                   /< The last y position.
                                    /*< Used to calculate collision angles. */
        lastPathX,               /< The last path in the Bezier Curve.
        lastPathY,               /< 
        pathLength,              /< The scale of the Bezier path.
                                    /*< The Bezier Curve path is a scalar path bounced from 0<x<1 and -1<y<1. This determines how far 1 is. */
        trailDelta,              /< The period during the transition from 0-1 on a Bezier Curve,
                                    /*< The trail that is drawn behind a Polygon is a series of dots that are connected */
        velocity,                /< The velocity of this Virus in pixels per second.
        pathAngle,               /< The degree at which this Virus is moving.
        t,                       /< The current time t in the Bezier curve path.
        deltaT,                  /< The change in time per frame
        x1,                      /< The second x point in the Bezier Curve.
        y1,                      /< The second y point in the Bezier Curve.
        x2,                      /< The third x point in the Bezier Curve.
        y2,                      /< The third y point in the Bezier Curve.
        trailDeltaT,             /< The distance in the time t from 0-1 between the first marker point,
        trailMarkerT;            /< The next value of t to add a point to the trail.
    
    Color trailColor,               /< The Color of the trail to draw.
        outlineColor,             /< The outline color.
        selectedColor;            /< The color of the fill circle.
                  
    BOL drawTrail,              /< Determines whether to draw the trail or not.
        ciricleVirus,           /< Draws a circle a round this Virus.
        selected;               /< Oh shit! I need to stop programming in class!!!!
    
    PathTrail trail;                /< The PathTrail
};

}   //< igeek

