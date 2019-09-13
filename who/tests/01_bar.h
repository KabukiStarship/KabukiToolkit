/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/tests/01_bar.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>

#if SEAM == kabuki.toolkit_WHO_0
#include "test_debug.inl"
#else
#include "test_release.inl"
#endif



namespace kabuki { namespace toolkit { namespace who {
inline const TStrand<>& _1_Bar (TStrand<>& seam_log, TStrand<>& seam_end, const TStrand<>& args) {
#if SEAM >= kabuki.toolkit_WHO_0
  TEST_BEGIN;

  PRINT_HEADING ("Testing Foo Fun.");

#endif
  return 0;
}
} //< namespace who
} //< namespace toolkit
} //< namespace kabuki
