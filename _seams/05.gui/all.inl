/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /gui/tests/all.inl
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights 
reserved (R). This Source Code Form is subject to the terms of the Mozilla 
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "00_foo.inl"
#include "01_bar.inl"

namespace gui {
static const CHA* Test(CHA* seam_log, CHA* seam_end, const CHA* args) {
#if SEAM >= KABUKI_GUI
  A_TEST_BEGIN;
  return TTestTree<Foo, Bar>(seam_log, seam_end, args);
#endif
  return 0;
}
}  // namespace gui
