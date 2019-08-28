/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/genetic_polygon_panel.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <Kabuki_Theater/Cell_IGA/GeneticPolygonPanel.h>

namespace igeek {
    
GeneticPolygonPanel::GeneticPolygonPanel (GeneticPolygon thisShape, String thisShapeLabel, int width, int height)
{
    setPreferredSize (new Dimension (width, height));
    setBorder(BorderFactory.createLineBorder(Color.BLACK));
    setLayout(new BorderLayout());
    
    JLabel thisLabel = new JLabel (thisShapeLabel);
    add(thisLabel, BorderLayout.NORTH);
    
    gPoly = thisShape;
}

void GeneticPolygonPanel::paintComponent (Graphics g)
{
    super.paintComponent(g);
    
    int offsetX, offsetY;
    
    // We want to center the GeneticPolygon
    
    Dimension panelDimensions = getPreferredSize ();
    
    if (gPoly != null)
    {
        offsetX = (panelDimensions.width  - gPoly.getWidth  ()) /2;
        offsetY = (panelDimensions.height - gPoly.getHeight ()) /2;
        
        g.drawImage(gPoly.getBitmap (), offsetX, offsetY, null);
    }
}

GeneticPolygonPanel::GeneticPolygon getGeneticPolygon ()
{
    return gPoly;
}

void GeneticPolygonPanel::respawn (int numPoints, int width, int height, int color, int lifespan, double angle)
{
    gPoly = new GeneticPolygon (numPoints, width, height, color, lifespan, angle);
}

void GeneticPolygonPanel::setGeneticPolygon (GeneticPolygon newPoly)
{
    gPoly = newPoly;
}

}   //< namespace igeek {
