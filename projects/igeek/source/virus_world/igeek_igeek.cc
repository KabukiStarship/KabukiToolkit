/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/library/igeek_igeek.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>

#include "c_igeek.h"

namespace _ {


Cell_IGA::Cell_IGA ()
{
  add (new LeukocyteWar ());
}

static void Cell_IGA::main (String[] args)
{
  JFrame window = new JFrame ("Kabuki.Cell_IGA");
  window.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);

  JScrollPane scrollableArea = new JScrollPane (new LeukocyteWar ());

  window.setContentPane (scrollableArea);

  window.pack ();
  window.setVisible (true);
}

}
}
