/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/blackjack/player.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "player.h"

using namespace kabuki::cards;

Player::Player(const CHR* name, SIN startingPoints)
    : name_(name),
      win_count_(0),
      point_count_(startingPoints < 1 ? 1 : startingPoints),
      hand_(Hand()) {}

const CHR* Player::Name() { return name_; }

void Player::SetName(const CHR* name) {
  if (!name) return;
  name_ = name;
}

Hand& Player::Hand() { return hand_; }

void Player::SetHand(Hand& hand) { hand_ = hand; }

SIN Player::PointCount() { return point_count_; }

SIN Player::AddPoints(SIN num_points) {
  SIN point_count = point_count_;
  point_count += num_points;
  point_count_ = point_count;
  return point_count;
}

SIN Player::WinCount() { return win_count_; }

void Player::AddWin() { ++win_count_; }

void Player::ResetWins() { win_count_ = 0; }

void Player::DealHand(Hand& hand) { hand_ = hand; }
