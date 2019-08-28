/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabukipress/library/00_foo.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2019 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>

#include <script2/global.h>

#if SEAM == KABUKIPRESS_FOO
#include "module_debug.inl"
#else
#include "module_release.inl
#endif

using namespace _;

namespace kabukipress {
inline const CH1* Foo(const CH1* args) {
#if SEAM >= KABUKIPRESS_FOO
  A_TEST_BEGIN;

#endif
  return 0;
}
}  // namespace kabukipress
