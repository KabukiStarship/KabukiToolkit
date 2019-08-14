/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/console/c_geneticpolygonchildpanel.h
@author  Cale McCollough <calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

namespace _ {


class GeneticPolygonChildPanel : public Panel {
public:

  GeneticPolygonChildPanel (GeneticPolygon fitShape, GeneticPolygon initChild, String thisShapeLabel, SI4 width, SI4 height);

  void paintComponent (Graphics g);

  GeneticPolygon getChild ();

  void setChild (GeneticPolygon newChild);

private:

  GeneticPolygon child,
    cell;

  Label infoLabel;

  boolean timerOn;
};
}
}
