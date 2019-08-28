/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/blackjack_player.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

#ifndef KABUKI_BLACKJACK_HAND_HEADER
#define KABUKI_BLACKJACK_HAND_HEADER

#include <pch.h>

#include <cards/cardstack.h>
#include <cards/hand.h>

namespace kabuki {
namespace blackjack {

/* Class that represents a Hand in Blackjack.
A blackjack hand has a minmum of 2 cards. */
class BlackjackHand : Hand {
 public:
  /* Constructor.
  The game of blackjack starts with each player having two cards. */
  BlackjackHand(CardStack& stock);

  /* Compares this hand to the other hand.
  @return Returns 0 if they are equal, 1 if this hand is greater than    the
  other Hand, and -1 if the other Hand is greater than this Hand. */
  SIN Compare(const Hand& other);

  /* Returns the HighLowScore. */
  _::AStack<CardCombo> Combos();

  /* Adds the new Card to this Hand. */
  SIN AddCard(Card* new_card);

  /* Prints this object to the Printer. */
  template <typename Printer>
  Printer& PrintTo(Printer& o) {}
};
}  //< namespace blackjack
}  //< namespace kabuki
#endif
