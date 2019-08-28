/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/genetic_polygon_child_panel.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <Kabuki_Theater/Cell_IGA/GeneticPolygonChildPanel.h>

namespace igeek {

GeneticPolygonChildPanel::GeneticPolygonChildPanel (GeneticPolygon fitShape, GeneticPolygon initChild, String thisShapeLabel, int width, int height)
{
    setPreferredSize (new Dimension (width, height));
    setBorder(BorderFactory.createLineBorder(Color.BLACK));
    setLayout(new BorderLayout());
    
    JLabel thisLabel = new JLabel (thisShapeLabel);
    infoLabel = new JLabel ("");
    
    add(thisLabel, BorderLayout.NORTH);
    add(infoLabel, BorderLayout.SOUTH);
    
    cell = fitShape;
    setChild (initChild);
}

void GeneticPolygonChildPanel::paintComponent (Graphics g)
{
    super.paintComponent(g);
    
    int offsetX, offsetY;
    
    // We want to center the GeneticPolygon
    
    Dimension panelDimensions = getPreferredSize ();

    // Draw the cell
    
    if (cell != null)
    {
        offsetX = (panelDimensions.width  - cell.getWidth  ()) / 2;
        offsetY = (panelDimensions.height - cell.getHeight ()) / 2;
        
        g.drawImage(cell.getBitmap (), offsetX, offsetY, null);
    }
    // Draw the child
    
    if (child != null)
    {
        offsetX = (panelDimensions.width  - child.getWidth  ()) / 2;
        offsetY = (panelDimensions.height - child.getHeight ()) / 2;
        
        g.drawImage(child.getBitmap (), offsetX, offsetY, null);
    }
}

GeneticPolygon GeneticPolygonChildPanel::getChild ()
{
    return child;
}

void GeneticPolygonChildPanel::setChild (GeneticPolygon newChild)
{
    if (newChild == null)
        return;
    child = newChild;
    
    // Update childLabel
    
    String infoString;
    
    if (cell.containsGeneticPolygon (newChild))
    {
        infoString = "Cell contains child\n"
                   + "Cell mass = " + cell.getNumPixels () + "\n"
                   + "Child mass = " + newChild.getNumPixels () + "\n";
                   //+ "Child is " + cell.getNumPixels ()/child.getNumPixels () + "% of the mass of the cell.\n";
    }
    else
    {
        infoString = "Cell does not contain child.";
    }
    
    infoLabel.setText (infoString);
}

}   //< namespace igeek {
