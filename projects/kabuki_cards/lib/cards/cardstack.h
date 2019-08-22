/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/lib/cards/card_stack.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

#include <script2/t_stack.h>

#include "card.h"
#include "deck.h"

namespace kabuki_cards {

/* Class that represents a stack of playing cards.
A CardStack stores pointers to the Card objects in the Deck. When a card is
removed from the stack, the pointer is deleted, and not the actual Card
object in the Deck. You can extend the CardStack class to program the
various elements of a card game use as a Hand and discard stack. */
class CardStack {
  SIN min_num_cards_,  //< The minimum number of cards in a CardStack.
      max_num_cards_;  //< The number of cards in the cardstack.
  BOL is_visible_;     //< Flags if the CardStack is visible.
  _::Autoject cards_;  //< An AStack<Card*> of Card pointers.

 public:
  static const CardStack empty;

  /* Constructs an empty card stack with a max of 54 cards. */
  CardStack();

  /* Verbose constructor. */
  CardStack(CardStack& cards, SIN min_num_cards = 0,
            SIN card_count_max_ = Deck::kCardCountWithJokers,
            BOL is_visible = false);

  /* Creates a CardStack from the deck. */
  CardStack(Deck& deck);

  /* Copy constructor deep copies the state of the other object.
  The copy constructor is use Shuffle the CardStack. */
  CardStack(const CardStack& other);

  /* Destructor. */
  virtual ~CardStack() {}

  /* Operator= overloader makes this object = other object. */
  CardStack& operator=(const CardStack& other);

  /* Compares this CardStack to the other CardStack.
      @return Returns 0 if the two have equal values, 1 if this stack is
     greater, and -1 if the other stack is greater. */
  virtual SIN Compare(CardStack& other);

  /* Returns the point value total of this stack of cards. */
  virtual SIN PointValue();

  /* Shuffles this CardStack. */
  void Shuffle();

  /* Returns the number of Card(s) in this stack. */
  SIN CardCount();

  /* Returns the card_count_min_. */
  SIN CardCountMin();

  /* Returns the card_count_max_. */
  SIN CardCountMax();

  /* Adds the new_card to top of the stack. */
  SIN AddCard(Card* new_card);

  /* Inserts the new_card into the stack at the specified index.
  @return Returns 0 upon success
  @return Returns 1 if the index is out of bounds.
  @return Returns 2 if adding a card about exceed the manNumCards. */
  SIN InsertCard(Card* new_card, SIN index);

  /* Adds the cards to the stack.
  Functions takes the cards_to_take from the cardsToTakeFrom and adds them
  to this Stack.
  @pre cardsToTakeFrom.getNuMCards () must be > cards_to_take.
  @pre cards_to_take must be less than the maximum number of cards allowed.
  @return Returns 0 upon success.
  @return Returns -1 if the cards_to_take is < 0.
  @return Returns 1 if the cards_to_take is greater than the
  cardsToTakeFrom.CardCount ()
  @return Returns 2 if the cards_to_take would put the user over the
  card_count_max_. */
  SIN AddCardStack(CardStack& cards);

  /* Attempts to draw the given number of cards from the deck if there is
  enough.
  @return Returns the number of cards drawn. */
  SIN DrawCards(CardStack& cardsToTakeFrom, SIN cards_to_take);

  /* Removes card from the stack.
  @return Returns true upon success and false if this stack doesn't contain
  card. */
  BOL RemoveCard(Card* card);

  /* Copies the card_count from the stack
  @pre card_count must be greater than the number of cards in the stock. */
  SIN SetCards(CardStack& stack, SIN card_count);

  /* Draws the specified card_count and adds them to this stack
  @pre card_count must be greater than the number of cards in the stock.
  @return Returns -1 if num*/
  SIN TakeCards(CardStack& stock, SIN card_count);

  /* Returns a poinnter to the Card at the specified index.
  @return Returns nullptr if the index is greater than the number of Cards
  in this Hand. */
  Card* PeekCard(SIN index);

  /* Returns and removes the Card at the specified index. */
  Card* TakeCard(SIN index);

  /* Returns and removes the next Card off of the top of the Deck. */
  Card* TakeNextCard();

  /* Returns and removes a random Card from the stack. */
  Card* TakeRandomCard();

  /* Returns true if there are no more cards in the deck. */
  BOL IsEmpty();

  /* Returns if the card is_visible_. */
  BOL IsVisible();

  /* Sets is_visible_ to the new visiblityState. */
  void SetVisiblity(BOL visiblity);

  /* Prints this object to the Printer. */
  template <typename Printer>
  Printer& PrintTo(Printer& o) {
    o << '\n';
    for (SIN i = 0; i < cards.Size(); ++i) o << i << ".) ";
    o << cards[i]->PrintTo<Printer>(o);
  }
};

}  // namespace kabuki_cards
