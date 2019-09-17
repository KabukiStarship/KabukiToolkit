/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/tests/00_foo.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#if SEAM == KABUKI_TOOLKIT_WHO_0
#include "module_debug.inl"
#else
#include "module_release.inl"
#endif

using namespace _;

namespace kabuki {
namespace toolkit {
namespace who {

inline const TStrand<>& _0_Foo(TStrand<>& seam_log, TStrand<>& seam_end,
                               const TStrand<>& args) {
#if SEAM >= KABUKI_TOOLKIT_WHO_0
  A_TEST_BEGIN;

  PRINT_HEADING("Testing user.");

#endif
  return 0;
}
}  // namespace who
}  // namespace toolkit
}  // namespace kabuki
