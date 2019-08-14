/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /project/0_0_2.hello_machina_spectulatrix/test_tree.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#include "00_foo.h"

#if SEAM >= KABUKI_AUTOPILOT_1
#include "01_bar.h"
#endif

namespace kabuki { namespace hello_machina_spectulatrix { 

static const CH1* Test(CH1* seam_log, CH1* seam_end,
                        const CH1* args) {
  return TTestTree<_0_Foo
#if SEAM >= KABUKI_AUTOPILOT_1
                    , _1_Bar
#endif
  >(seam_log, seam_end, args);
}
}  //< namespace hello_machina_spectulatrix
}  //< namespace kabuki
