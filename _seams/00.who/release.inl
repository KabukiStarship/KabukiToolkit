/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /_seams/who/tests/all.inl
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights 
reserved (R). This Source Code Form is subject to the terms of the Mozilla 
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "../../../script2/test.hpp"
using namespace _;
#include "00.core.inl"

namespace kabuki {
namespace toolkit {
namespace who {
SIN TestKabukiToolkitWho(const CHA* args) {
  return _::TTestTree<Foo, Bar>(args);
}
}  // namespace who
}  // namespace toolkit
}  // namespace kabuki
