/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/tests/01_bar.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights 
reserved (R). This Source Code Form is subject to the terms of the Mozilla 
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#if SEAM == KABUKI_TOOLKIT_WHO_BAR
#include "_debug.inl"
#else
#include "_release.inl"
#endif

namespace kabuki {
namespace toolkit {
namespace who {
inline const CHA* Bar(const CHA* args) {
#if SEAM >= KABUKI_TOOLKIT_WHO_BAR
  A_TEST_BEGIN;

#endif
  return 0;
}
}  // namespace who
}  // namespace toolkit
}  // namespace kabuki
