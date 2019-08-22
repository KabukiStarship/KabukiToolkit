/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/lib/blackjack/hand.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "Hand.h"

using namespace _;
using namespace kabuki_cards;

Hand::Hand(CardStack& stack, SIN min_cards, SIN card_count_max_)
    : card_count_min_(min_cards),
      card_count_max_(card_count_max_),
      visible_cards_(CardStack()),
      hidden_cards_(CardStack()) {}

Hand& Hand::operator=(const Hand& other) {
  card_count_min_ = other.card_count_min_;
  card_count_max_ = other.card_count_max_;

  visible_cards_ = other.visible_cards_;
  hidden_cards_ = other.hidden_cards_;
}

SIN Hand::CardCountMin() { return card_count_min_; }

SIN Hand::SetMinCards(SIN card_count) {
  if (card_count < 0) return card_count;
  card_count_min_ = card_count;
  return 0;
}

SIN Hand::CardCountMax() { return card_count_max_; }

SIN Hand::CardCount() { return visible_cards_.Size() + hidden_cards_.Size(); }

SIN Hand::SetMaxCards(SIN card_count) {
  if (card_count < 0) return 1;
  card_count_min_ = card_count;
  return 0;
}

SIN Hand::DrawCard(CardStack& stack) { return AddCard(stack.TakeCard()); }

Autoject Hand::Cards() { return {0, 0}; }

CardStack& Hand::VisibleCards() { return visible_cards_; }

CardStack& Hand::HiddenCards() { return hidden_cards_; }
