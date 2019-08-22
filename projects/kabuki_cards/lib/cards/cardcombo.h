/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/lib/cards/card_combo.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#ifndef KABUKI_CARDS_CARDCOMBO_H
#define KABUKI_CARDS_CARDCOMBO_H

#include "cardstack.h"

namespace kabuki_cards {

/* Class that represents a CardStack point combination in a playing card game.
There are two major things that will effect a combination's rank besides suit
rank; the presence of jokers, and if aces are high or low. */
class CardCombo : public CardStack {
  SIN joker_pip_value_1_,   //< The kBlack joker wildcard pip value.
      joker_suit_value_1_,  //< The kBlack joker wildcard suit value.
      joker_pip_value_2_,   //< The kRed joker wildcard pip value.
      joker_suit_value_2_,  //< The kRed joker wildcard suit value.
      aces_high_;  //< Flag represents if aces are high (>1) or low (0), or
                   // either (<0).

 public:
  /* Default constructor. */
  CardCombo(CardStack& copyStack, SIN aces_high, SIN thisJokerPipValue1 = 0,
            SIN thisJokerSuitValue1 = 1, SIN thisJokerPipValue2 = 0,
            SIN thisJokerSuitValue2 = 2);

  /* Function sets values to the new values. */
  void SetValues(SIN aces_high, SIN joker_pip_value_1 = 0,
                 SIN joker_suit_value_1 = 1, SIN joker_pip_value_2 = 0,
                 SIN joker_suit_value_2 = 2);

  /* Function that returns the point value with the wild card and ace values. */
  virtual SIN PointValue() = 0;

  /* Returns the joker_pip_value_1. */
  SIN JokerPipValue1();

  /* Sets the joker_pip_value_1 to the value. */
  SIN SetJokerPipValue1(SIN value);

  /* Returns the joker_suit_value_1. */
  SIN JokerSuitValue1();

  /* Sets the joker_suit_value_1 to the value. */
  SIN SetJokerSuitValue1(SIN value);

  /* Returns the joker_pip_value_2. */
  SIN JokerPipValue2();

  /* Sets the joker_pip_value_2 to the value. */
  SIN SetJokerPipValue2(SIN value);

  /* Returns the joker_suit_value_2. */
  SIN JokerSuitValue2();

  /* Sets the joker_suit_value_2 to the value. */
  SIN SetJokerSuitValue2(SIN value);

  /* Returns the joker_pip_value_1. */
  SIN AcesHigh();

  /* Sets the joker_pip_value_1 to the value. */
  SIN SetAcesHigh(SIN value);
};

}  // namespace kabuki_cards

#endif
