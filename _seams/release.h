/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /_seams/01.release.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights 
reserved (R). This Source Code Form is subject to the terms of the Mozilla 
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#if SEAM == KABUKI_TOOLKIT_RELEASE
#include "_debug.inl"
#else
#include "_release.inl"
#endif

using namespace _;

namespace kabuki {
namespace toolkit {
inline const CHA* Release(CHA* seam_log, CHA* seam_end, const CHA* args) {
#if SEAM >= KABUKI_TOOLKIT_RELEASE
  TEST_BEGIN;

  PRINT_HEADING("Testing Foo fun.");

#endif
  return 0;
}
}  // namespace toolkit
}  // namespace kabuki
