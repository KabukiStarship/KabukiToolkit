/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki::cards/source/lib/cards/blackjack_cardcombo.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough
<<calemccollough.github.io>>; All right reserved (R). This Source Code
Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of
the MPL was not distributed with this file, You can obtain one at
<https://mozilla.org/MPL/2.0/>. */

#pragma once

#ifndef KABUKI_BLACKJACK_CARDCOMBO_HEADER
#define KABUKI_BLACKJACK_CARDCOMBO_HEADER

#if SEAM >= KABUKI_BLACKJACK_CONSOLE

#include <pch.h>

namespace kabuki { namespace cards {
/* Class that represents a CardCombo in a game.
    There are two major things that will effect a combination's rank besides
   suit rank; the presence of jokers, and if aces are high or low.
*/
class BlackjackCardCombo : public CardCombo {
 public:
  /* Default constructor.
   */
  BlackjackCardCombo(CardStack& copyStack, SIN acesHighLowORNA);

  SIN PointValue();  //< Function that returns the point value based on the
                     // ace value.
};
} }  //< namespace kabuki
}  //< namespace kabuki
#endif
