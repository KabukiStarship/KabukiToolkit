/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/genetic_polygon_test_app.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <Kabuki_Theater/Cell_IGA/GeneticPolygonTestApp.h>

namespace igeek {

GeneticPolygonTestApp::GeneticPolygonTestApp ()
{
    add (new GeneticPolygonTestPanel ());
}

static void GeneticPolygonTestApp::main (String[] args)
{
    JFrame window = new JFrame ("GeneticPolygon Test App");
    window.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

    window.setContentPane (new GeneticPolygonTestPanel ());
    
    window.pack ();
    window.setVisible (true);
}

}   //< namespace igeek {
