/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /test_tree.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>

#include "00_foo.h"

#if SEAM >= UNICONTROLLER_FIRMWARE_1
#include "01_bar.h"
#endif

namespace project { namespace unicontroller_firmware { 

static const CH1* Test(CH1* seam_log, CH1* seam_end,
                        const CH1* args) {
  return TTestTree<_0_Foo
#if SEAM >= UNICONTROLLER_FIRMWARE_1
                    , _1_Bar
#endif
  >(seam_log, seam_end, args);
}
}  //< namespace unicontroller_firmware
}  //< namespace project
