/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/ib/blackjack/blackjack_dealer.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "BlackjackCardCombo.h"

#include "BlackjackDealer.h"

using namespace KabukiCardGames::Blackjack;

BlackjackDealer::BlackjackDealer () :
    Player ("Dealer", startingPoints),
    Dealer (startingPoints, startingAnte, minBet, minNumCardsPerHand, maxNumCardsPerHand, maxNumPlayer)
{
}
