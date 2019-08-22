/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/library/igeek_geneticpolygonpanel.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <pch.h"

#include "c_geneticpolygonpanel.h"

namespace _ {

GeneticPolygonPanel::GeneticPolygonPanel (GeneticPolygon thisShape, AString thisShapeLabel, SI4 width, SI4 height)
{
  setPreferredSize (new Dimension (width, height));
  setBorder (BorderFactory.createLineBorder (Color.BLACK));
  setLayout (new BorderLayout ());

  JLabel thisLabel = new JLabel (thisShapeLabel);
  add (thisLabel, BorderLayout.NORTH);

  gPoly = thisShape;
}

void GeneticPolygonPanel::paintComponent (Graphics g)
{
  super.paintComponent (g);

  SI4 offsetX, offsetY;

  // We want to center the GeneticPolygon

  Dimension panelDimensions = getPreferredSize ();

  if (gPoly != null)
  {
    offsetX = (panelDimensions.width - gPoly.Width ()) / 2;
    offsetY = (panelDimensions.height - gPoly.Height ()) / 2;

    g.drawImage (gPoly.getBitmap (), offsetX, offsetY, null);
  }
}

GeneticPolygonPanel::GeneticPolygon getGeneticPolygon ()
{
  return gPoly;
}

void GeneticPolygonPanel::respawn (SI4 numPoints, SI4 width, SI4 height, SI4 color, SI4 lifespan, FP8 angle)
{
  gPoly = new GeneticPolygon (numPoints, width, height, color, lifespan, angle);
}

void GeneticPolygonPanel::setGeneticPolygon (GeneticPolygon newPoly)
{
  gPoly = newPoly;
}

}
