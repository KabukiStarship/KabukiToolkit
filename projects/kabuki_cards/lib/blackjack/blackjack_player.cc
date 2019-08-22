/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/lib/blackjack/blackjack_player.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <pch.h>

#include "blackjack_player.h"

#include <cards/card_stack.h>
#include <cards/hand.h>

#include "blackjack_dealer.h"
#include "blackjack_hand.h"

#include <script2/c_rng.h>

using namespace kabuki_cards;

BlackjackPlayer::BlackjackPlayer(const CHR* name, SIN startingPoints,
                                 BOL is_player)
    : player_(name, startingPoints, is_player) {}

BlackjackPlayer::~BlackjackPlayer() {
  // Nothing to do here.
}

BOL BlackjackPlayer::PlayOrPass(Dealer& dealer) {
  BlackjackHand::HighLowScore hand_totals = GetHighLowScore(),
                              other_hand_totals = dealer.GetHighLowScore();

  SIN high_score = hand_totals.high, low_score = hand_totals.low,
      other_high_score = other_hand_totals.high,
      otherLowScore = other_hand_totals.low;

  if (low_score > 21)  //< Then we definitly lost.
    return false;

  if (low_score == 21 || high_score == 21)
    return false;  //< Then we might have won so don't play again or we'll
                   // loose!

  if (high_score <= 21 - 10)
    return true;  //< The highest card value is 10, so if our highest score is
                  // less than 11, then we can take any card and not go over 21.

  if (high_score < other_high_score)  // Than we have to play or we loose.
    return true;

  /* From here on out, we dont actually have to take another card because we
  might go over and loose, so we're playing a numbers game. At this point in
  time, we are less than 10 points away from going bust, and each number of
  points away from 21 we are has an x percent chance loosing. In this case,
  we should figure out what the percent chance is,
  and only take another card if the chances are high enough. */
  float chance_of_winning;

  if (high_score < 21) {
    SIN points_left = 21 - high_score;
    const float chance_of_winning[] = {0.1, 0.2, 0.3, 0.4, 0.5,
                                       0.6, 0.7, 0.8, 0.9};
    chance_of_winning = chance_of_winning[points_left];
  } else {
    SIN points_left = 21 - low_score;
    const float chance_of_winning[] = {0.6, 0.6, 0.5, 0.5, 0.4,
                                       0.4, 0.2, 0.2, 0.2};
    chance_of_winning = chance_of_winning[points_left];
  }

  if (chance_of_winning >= 0.5) return true;

  /* To do this, we're going to use a random number between 0 and 1, and
  multiply it by a number between 1-10 to get a percent. For example, a 50 %
  chance of winning would get the number 5, then if you multiplied that by a
  random number between 0 and 1, then we have a 50 % chance of getting a
  number greater than 0.5. */

  float random_number_between_0_and_1 = RandomFP4();

  return chance_of_winning * random_number_between_0_and_1 >= 0.5;
}

void BlackjackPlayer::PlayHand() {}
