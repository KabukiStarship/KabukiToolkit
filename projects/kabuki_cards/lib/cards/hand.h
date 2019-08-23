/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki::cards/source/lib/cards/hand.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#ifndef KABUKI_CARDS_HAND_HEADER
#define KABUKI_CARDS_HAND_HEADER

#include "cardcombo.h"
#include "cardstack.h"

namespace kabuki {
namespace cards {

/* A hand in a playing card game.
In most cases, the player will have a visible set of cards, and a hidden
set of cards. */
class Hand : public CardStack {
  SIN card_count_min_,       //< The minimum number of cards in a Hand.
      card_count_max_;       //< The maximum number of cards in a Hand.
  CardStack visible_cards_,  //< Cards others can see.
      hidden_cards_;         //< Cards only the player should be able to see.
 public:
  /* Default constructor. */
  Hand();

  /* Constructs an new hand with the min_cards.
  In order to create a Hand, first create a CardStack with a card_count_max_,
  and add the minimumNumCards to it.
  @pre stock.CardCount() must be > min_cards. */
  Hand(CardStack& stock, SIN min_cards = 1,
       SIN card_count_max_ = Deck::kCardCountWithJokers);

  /* Virtual destructor. */
  virtual ~Hand() {}

  /* Operator= overloader deep copiers the state of the other object. */
  Hand& operator=(const Hand& other);

  /* Returns the card_count_min_ in a Hand. */
  SIN CardCountMin();

  /* Sets the card_count_min_ to the card_count. */
  SIN SetMinCards(SIN card_count);

  /* Returns the card_count_max_ in a Hand. */
  SIN CardCountMax();

  /* Sets the card_count_min_ to the card_count. */
  SIN SetMaxCards(SIN card_count);

  /* Retruns the number of Cards in this Hand. */
  SIN CardCount();

  /* Adds the new_card to this Hand. */
  virtual SIN AddCard(Card* new_card);

  /* Adds the new_card to this Hand. */
  SIN DrawCard(CardStack& stack);

  /* Returns a combination of the visible and nonvisible cards. */
  CardStack Cards();

  /* Returns the visible_cards. */
  CardStack& VisibleCards();

  /* Returns the hidden_cards. */
  CardStack& HiddenCards();

  /* Returns a list different hand point combinations for this game.
  @return AStack<CardCombo>. */
  virtual _::Autoject Combos();

  /* Compares this hand to the other hand.
  @return Returns 0 if they are equal, 1 if this hand is greater than
  the other Hand, and -1 if the other Hand is greater than this Hand. */
  virtual SIN Compare(const Hand& other);

  /* Virtual function that organizes the player's hand. */
  virtual void Organize() {}

  /* PPrints this object to the Printer. */
  template <typename Printer>
  Printer& PrintTo(Printer& o) {
    o << _::Linef("\nCards:\n");
    o << visible_cards_.PrintTo<Printer>(o);

    if (nonvisible_pile_.CardCount() > 0) {
      o << "\n\nHidden Cards:\n";
      o << hidden_cards_.PrintTo<Printer>(o);
    }
    return o;
  }
};

}  // namespace cards
}  // namespace kabuki

#endif
