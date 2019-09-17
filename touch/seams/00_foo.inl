/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/tests/00_foo.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#if SEAM == KABUKI_TOOLKIT_AV_0
#include "module_debug.inl"
#else
#include "module_release.inl"
#endif

using namespace _;

namespace kabuki {
namespace toolkit {
namespace touch {

inline const CH1* _0_Foo(CH1* seam_log, CH1* seam_end, const CH1* args) {
#if SEAM >= KABUKI_TOOLKIT_AV_0
  A_TEST_BEGIN;

#endif
  return 0;
}
}  // namespace touch
}  // namespace toolkit
}  // namespace kabuki
