/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/blackjack/player.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "pch.h"

#ifndef SCRIPT2_RUN_TESTS

#include "t_test.h"

#if SEAM >= KABUKI_CARDS_CARD
#include "00_card.h"
#endif

using namespace _;

namespace script2 {
static const CH1* TestNode(const CH1* args) {
  return TTestTree<Uniprinter>(args);
}
}  //< namespace script2

SIN main(SIN arg_count, CH1** args) {
  return _::TTestTree<script2::TestNode>(arg_count, args);
}
#endif
