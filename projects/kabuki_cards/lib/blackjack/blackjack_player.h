/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/lib/blackjack_player.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

#ifndef KABUKI_BLACKJACK_PLAYER_H
#define KABUKI_BLACKJACK_PLAYER_H

#include <pch.h>

#include "../cards/dealer.h"

namespace kabuki_cards {

class BlackjackPlayer {
 public:
  /* Default Constructor. */
  BlackjackPlayer(const CHR* playerName = nullptr, SIN points_init = 10,
                  BOL is_player);

  /* Destructor. */
  ~BlackjackPlayer();

  /* AI function that determines if a player (usually the dealer) hits or holds.
   */
  BOL PlayOrPass(Dealer& dealer);

  /* Function that performs the logic of playing a hand. */
  void PlayHand();
};
}  // namespace kabuki_cards
#endif
