/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/library/igeek_cell.cc
@author  Cale McCollough <http://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>

#include "c_bezier.h"

namespace _ {


Cell::Cell (Host cellHost)
{
  super ();

  host = cellHost;
}

Cell::Cell (SI4 x_pos, SI4 y_pos, SI4 width, SI4 height, 
            SI4 point_count, SI4 color, SI4 lifespan, 
            FP8 angle)
    : super (point_count, width, height, color, lifespan, angle) 
{}

void Cell::Highlight (Graphics g, Color circle_color) {
  g.SetColor (circle_color);
  g.DrawOval (Left ()   - circle_buffer, 
              Top ()    - circle_buffer, 
              Width ()  + circle_buffer, 
              Height () + circle_buffer);
}

void Cell::Update () {
  // We only need to do any logic if the cell is infected. 
}

FP8 Cell::X () {
  return x;
}

FP8 Cell::Y () {
  return y;
}

SI4 Cell::Left () {
  return (SI4)x;
}

SI4 Cell::Top () {
  return (SI4)y;
}

SI4 Cell::Right () {
  return (SI4)x + Widget ();
}

SI4 Cell::Bottom () {
  return (SI4)y + Height ();
}

void Cell::InfectCell (Virus thisVirus) {
  virus = thisVirus;
  timeOfInfection = ClockTimeNow ();
}

}   //< namespace _
