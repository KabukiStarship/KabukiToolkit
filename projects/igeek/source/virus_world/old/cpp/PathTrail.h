/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/pathtrail.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace igeek {
 
/* A class that represents a trail of lines.
    This class is represented by a circular cue of 2 dimensionsal points.
 */
class PathTrail {
  public:
  
    /* The default PathTrail color. */
    static const Color DefaultTrailColor = Color.red;
    
    /* In order to make a line, we need two points. */
    static const int DefaultMaxNumPoints = 300;
    
    PathTrail ();
    
    PathTrail (Color thisTrailColor);
    
    PathTrail (Color thisTrailColor, int thisMaxNumPoints);
    
    void initialize ();
    
    void setTrailColor (Color newColor);
    
    Color getTrailColor ();
    
    void draw (Graphics g);
    
    void addPoint (int x, int y);
    
    AString ToString ();
    
  private:
    
    Color trailColor;           /< The Color of this PathTrail.
    
    int numPoints,              /< The number of points.
        startPoint,             /< The current startPoint in the circular queue.
        stopPoint,              /< The current stopPoint in the circular queue.
        maxNumPoints;           /< The maximum number of points.
                
    int xpoints[],              /< The x values for the points.
        ypoints[];              /< The y values for the points.
 };
 
}   //< igeek
