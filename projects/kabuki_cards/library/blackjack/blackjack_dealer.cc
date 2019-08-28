/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/blackjack/blackjack_dealer.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "blackjackcardcombo.h"
#include "blackjackdealer.h"

using namespace kabuki::cards;

BlackjackDealer::BlackjackDealer(const CHR* name)
    : Player((!name) ? "Dealer" : name, startingPoints),
      Dealer(startingPoints, starting_ante_, min_bet_, min_cards_per_hand_,
             max_cards_per_hand_, maxNumPlayer) {}
