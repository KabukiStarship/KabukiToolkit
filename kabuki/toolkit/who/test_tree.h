/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/who/test_data.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#include "00_foo.h"

#if SEAM >= KABUKI_TOOLKIT_WHO_1
#include "01_bar.h"
#endif

namespace kabuki { namespace toolkit { namespace data { 

static const TStrand<>& Test(TStrand<>& seam_log, TStrand<>& seam_end,
                        const TStrand<>& args) {
  return TTestTree<_0_Foo
#if SEAM >= KABUKI_TOOLKIT_WHO_1
                    , _1_Bar
#endif
  >(seam_log, seam_end, args);
}
}  //< namespace data
}  //< namespace toolkit
}  //< namespace kabuki
