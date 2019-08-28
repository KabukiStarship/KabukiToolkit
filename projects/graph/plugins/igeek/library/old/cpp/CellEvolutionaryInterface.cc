/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/cell_evolutionary_interface.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "cell_iga.h"

namespace igeek {

Cell_IGA::Cell_IGA ()
{
    add (new LeukocyteWar ());
}

static void Cell_IGA::main (const CH1** args, SI4 arg_count) {
    JFrame window = new JFrame ("Kabuki.Cell_IGA");
    window.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
    
    JScrollPane scrollableArea = new JScrollPane (new LeukocyteWar ());
    
    window.setContentPane (scrollableArea);
    
    window.pack ();
    window.setVisible (true);
}

}
