/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/lib/blackjack/card_stack.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "cardstack.h"
//
#include <script2/t_stack.h>

using namespace kabuki_cards;

CardStack::CardStack()
    : card_count_min_(0),
      card_count_max_(Deck::defaultNumCardsWithJokers),
      is_visible_(true),
      cards_(AStack<Card*>()) {}

CardStack::CardStack(CardStack& card_stack, SIN cards_min, SIN cards_max,
                     BOL is_visible)
    : card_count_min_(cards_min < 0 ? 0 : cards_min),
      card_count_max_(cards_max < 1 ? 1 : cards_max),
      is_visible_(is_visible) {}

CardStack::CardStack(Deck& theDeck)
    : card_count_max_(theDeck.CardCount()), is_visible_(false) {
  for (SIN i = 0; i < theDeck.CardCount(); ++i) AddCard(theDeck.GetCard(i));
}

CardStack::CardStack(const CardStack& other)
    : card_count_max_(other.card_count_max_),
      cards_(other.cards_),
      is_visible_(other.is_visible_) {}

CardStack& CardStack::operator=(const CardStack& other) {
  card_count_min_ = other.card_count_min_;
  card_count_max_ = other.card_count_max_;

  is_visible_ = other.is_visible_;

  cards_ = other.cards_;
}

SIN CardStack::Compare(CardStack& other) {
  SIN point_value = PointValue(), other_point_value = other.PointValue();

  if (point_value > other_point_value) return 1;
  if (point_value < other_point_value) return -1;
  return 0;
}

SIN CardStack::PointValue() {
  SIN total = 0;
  for (auto currentCard : cards_) total += currentCard->PointValue();
  return total;
}

void CardStack::Shuffle() {
  // Create an identical copy of this CardStack.
  CardStack unshuffled_pile = CardStack(*this);

  cards_.Clear();  //< Delete all of the cards_ in this CardStack

  // Then for each Card in the CardStack,
  for (SIN i = 0; i < cards_.Size(); ++i)
    cards_.add(unshuffled_pile.TakeRandomCard());
}

SIN CardStack::CardCount() { return cards_.Size(); }

SIN CardStack::CardCountMin() { return card_count_min_; }

SIN CardStack::CardCountMax() { return card_count_max_; }

SIN CardStack::AddCard(Card* new_card) {
  if (CardCount() + 1 > card_count_max_) return 2;

  if (card_count_max_ > cards_.Size() + 1) return 1;

  cards_.Add(new_card);
}

SIN CardStack::InsertCard(Card* new_card, SIN index) {
  if (index < 0 || index >= CardCount()) return 1;

  if (CardCount() + 1 > card_count_max_) return 2;

  cards_.Insert(index, new_card);
}

SIN CardStack::AddCards(CardStack& cards_) {
  if (CardCount() + cards_.CardCount() > card_count_max_) return 1;

  cards_.AddArray(cards_.cards_);
}

SIN CardStack::DrawCards(CardStack& card_source, SIN cards_to_take) {
  if (cards_to_take < 0)  //< Remember the @pre thing???
    return -1;  //< And the @return thing??? Then help you write code better and
                // faster!

  if (cards_to_take > card_source.CardCount()) return 1;

  if (CardCount() + cards_to_take > card_count_max_) return 2;

  for (SIN i = 0; i < cards_to_take; ++i) AddCard(card_source.TakeNextCard());

  return 0;
}

BOL CardStack::RemoveCard(Card* thisCard) {
  if (!cards_.Contains(thisCard)) return false;
  cards_.RemoveFirstMatchingValue(thisCard);
  return true;
}

SIN CardStack::SetCards(CardStack& stack, SIN card_count) {
  if (card_count < 0) return -1;
  if (card_count > stack.CardCount()) return 1;
  if (card_count < card_count_min_) return 2;
  if (card_count > card_count_max_) return 3;

  cards_.Clear();

  for (SIN i = 0; i < card_count; ++i) cards_.Add(stack.PeekCard(i));
}

SIN CardStack::TakeCards(CardStack& stack, SIN card_count) {
  if (card_count < 0) return -1;
  if (card_count > stack.CardCount()) return 1;
  if (card_count < card_count_min_) return 2;
  if (card_count > card_count_max_) return 3;

  cards_.Clear();

  for (SIN i = 0; i < card_count; ++i) cards_.Add(stack.TakeNextCard());
}

Card* CardStack::PeekCard(SIN index) {
  SIN card_count = cards_.Size();
  if (card_count == 0 || index > card_count) return nullptr;

  return cards_[index];
}

Card* CardStack::TakeCard(SIN index) {
  SIN card_count = cards_.Size();
  if (card_count <= 0 || index >= card_count) return nullptr;

  Card* result = cards_[index];
  cards_.Remove(index);
  return result;
}

Card* CardStack::TakeNextCard() {
  if (cards_.Size() == 0) return nullptr;

  SIN last_index = cards_.Size() - 1;
  Card* next_card = cards_[last_index];
  cards_.Remove(last_index);
  return next_card;
}

Card* CardStack::TakeRandomCard() {
  if (cards_.Size() == 0) return nullptr;
  SIN random_index = RandomSIN(cards_.Size());
  Card* result = cards_[random_index];
  cards_.Remove(random_index);
  return result;
}

BOL CardStack::IsEmpty() { return cards_.Size() == 0; }

BOL CardStack::IsVisible() { return is_visible_; }

void CardStack::SetVisiblity(BOL visiblity) { is_visible_ = visiblity; }
