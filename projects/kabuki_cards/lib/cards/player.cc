/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/lib/blackjack/player.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "player.h"

using namespace kabuki_cards;

Player::Player(const CHR* name, SIN startingPoints)
    : name(name),
      win_count(0),
      point_count(startingPoints < 1 ? 1 : startingPoints),
      hand(Hand()) {}

const CHR* Player::Name() { return name; }

void Player::Name(const CHR* name) { name = name; }

Hand& Player::Hand() { return hand; }

void Player::SetHand(Hand& hand) { hand = hand; }

SIN Player::PointCount() { return point_count; }

SIN Player::AddPoints(SIN num_points) {
  point_count += num_points;

  return point_count;
}

SIN Player::WinCount() { return win_count; }

void Player::AddWin() { ++win_count; }

void Player::ResetWins() { win_count = 0; }

void Player::DealHand(Hand& hand) { hand = hand; }
