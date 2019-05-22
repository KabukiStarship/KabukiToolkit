/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/console/c_geneticpolygonpanel.h
@author  Cale McCollough <calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

namespace _ {


class GeneticPolygonPanel : public JPanel
{
  static const SI4 defaultMargin = 30;

  GeneticPolygonPanel (GeneticPolygon thisShape, String thisShapeLabel, SI4 width, SI4 height);

  void paintComponent (Graphics g);

  GeneticPolygon getGeneticPolygon ();

  void respawn (SI4 numPoints, SI4 width, SI4 height, SI4 color, SI4 lifespan, double angle);

  void setGeneticPolygon (GeneticPolygon newPoly);

private:

  GeneticPolygon gPoly;
};

}
}
