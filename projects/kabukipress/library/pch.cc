/* SCRIPT Script @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /pch.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough
<<calemccollough.github.io>>; All right reserved (R). This Source Code
Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
the MPL was not distributed with this file, You can obtain one at
<https://mozilla.org/MPL/2.0/>. */

#include <pch.h>

#if SCRIPT2_RUN_TESTS == YES_0

#include "00_foo.h"

#if SEAM == KABUKIPRESS_FOO
#include "module_debug.inl"
#else
#include "module_release.inl"
#endif

using namespace _;

namespace kabukipress {
static const CH1* TestNode(const CH1* args) { return TTestTree<Foo>(args); }
}  // namespace kabukipress

SIN main(SIN arg_count, CH1** args) {
  return _::TTestTree<kabukipress::TestNode>(arg_count, args);
}
#endif
