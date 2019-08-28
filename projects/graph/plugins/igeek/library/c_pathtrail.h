/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/c_pathtrail.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace igeek {
 
class PathTrail
/* A class that represents a trail of lines.
    This class is represented by a circular cue of 2 dimensionsal points.
 */
 {
  public:
  
    static const Color DefaultTrailColor = Color.red;        
    /< The default PathTrail color.
    
    static const SI4 DefaultMaxNumPoints = 300;
    /< In order to make a line, we need two points.
    
    PathTrail ();
    
    PathTrail (Color thisTrailColor);
    
    PathTrail (Color thisTrailColor, SI4 thisMaxNumPoints);
    
    void initialize ();
    
    void setTrailColor (Color newColor);
    
    Color getTrailColor ();
    
    void draw (Graphics g);
    
    void addPoint (SI4 x, SI4 y);
    
    AString ToString ();
    
  private:
    
    Color trailColor;           /< The Color of this PathTrail.
    
    SI4 numPoints,              /< The number of points.
        startPoint,             /< The current startPoint in the circular queue.
        stopPoint,              /< The current stopPoint in the circular queue.
        maxNumPoints;           /< The maximum number of points.
                
    SI4 xpoints[],              /< The x values for the points.
        ypoints[];              /< The y values for the points.
 };
 
}   //< igeek
