/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/geneticpolygonpanel.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace igeek {

class GeneticPolygonPanel: public JPanel
{
    static const int defaultMargin = 30;
    
    GeneticPolygonPanel (GeneticPolygon thisShape, AString thisShapeLabel, int width, int height);
    
    void paintComponent (Graphics g);
    
    GeneticPolygon getGeneticPolygon ();
    
    void respawn (int numPoints, int width, int height, int color, int lifespan, double angle);
    
    void setGeneticPolygon (GeneticPolygon newPoly);
    
  private:
    
    GeneticPolygon gPoly;
};

}   /< namespace igeek {
