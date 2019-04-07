/* Kabuki Theater - Cell Interactive Genetic Algorihm
@version   0.x
@file    /projects/igeek/c_geneticpolygonTestApp.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "c_geneticpolygontestapp.h"

namespace _ {

GeneticPolygonTestApp::GeneticPolygonTestApp () {
  add (new GeneticPolygonTestPanel ());
}

static void GeneticPolygonTestApp::main (Loom<> args) {
  JFrame window = new JFrame ("GeneticPolygon Test App");
  window.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

  window.setContentPane (new GeneticPolygonTestPanel ());

  window.pack ();
  window.setVisible (true);
}

}
