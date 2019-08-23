/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki::cards/source/lib/deck.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#ifndef KABUKI_CARDS_DECK_H
#define KABUKI_CARDS_DECK_H

#include "card.h"

namespace kabuki {
namespace cards {

/* Class that reprents a Deck of Cards.
A Deck of cards usually has 52 cards, but can also have 2 jokers, a kBlack
one, and a kRed one. Not all card games have this many cards, so this class is
setup for you to create decks of cards for just about any card game you can
think of. */
class Deck {
  BOL has_jokers_;         //< Variable represents if this deck has Jokers.
  Card::Culture culture_;  //< The culture of the suits.
  /* Variable represeents if this deck is aces high, low, or neighter.
  Aces high (aces_high > 0) means that an ace is worth   14 points. Aces low
  (aces_high == 0) means that it is  worth 1.   In some games, like blackjack,
  aces can be either  high or low (aces_high < 0), meaning that they can be
  worth  either a 1, or a 14. */
  SIN aces_high_,
      card_count_,          //< The number of cards in the deck.
      lowest_card_value_,   //< The lowest allowed card value.
      highest_card_value_,  //< The highest allowed card value.
      /* An array of 4 numbers that represent the values of each suit. Used for
      changing the order of the suits */
      suit_values_[4];
  // Image rear_image_;   //< The rear Image of the Deck.
  AStack<Card> deck_;  //< The deck of Card objects.

 public:
  enum {
    // The default number of playing cards in a deck excluding Jokers.
    kDefaultCardCount = 52,
    // The default number of playing cards in a deck including Jokers.
    kCardCountWithJokers = 54,
    // Flag represents if Aces are high (i.e. has a face value of 14).
    kAcesHigh = 14,
    // Flag represents if Aces are low (i.e. has a face value of 1).
    kAcesLow = 0,
    /* Flag represents if Aces can be either high or low
      (i.e. has a point value of 1 or 14). */
    kAcesHighOrLow = 1,
    // Flag for if this deck contains Jokers.
    kHasJokers = 1,
    // Flag for if this deck doesn't contains Jokers.
    kHasNoJokers = 0,
  };

  /* The default suit value order, Clubs = 1, Diamonds=2, Hearts=3, and
  Spades=4. */
  const SIN* SuitValuesDefault();

  static const Deck
      kStandard,            //< A standard deck of playing cards without Jokers.
      kStandardWithJokers;  //< A standard deck of playing cards with Jokers.

  /* The default deck art directory. */
  static const char kDefaultDeckArtDirectory[] = "./";

  /* The default rear deck image. */
  static const char DefaultRearDeckImage[] = "card.png";

  /* Constructor.
  @param  deck_contains_jokers True if the deck continas jokers, and false
  otherwise.
  @param  aces_are_high 0 means that aces are low;
  a positive number means that aces are high; and
  a negative number means that aces are low.
  @param  card_suit_culture This paramter is used to determine what suites
  we are using. */
  Deck(BOL deck_contains_jokers = kHasNoJokers, SIN aces_are_high = kAcesHigh,
       Card::Culture card_suit_culture = Card::kFrench,
       const CH1* rear_deck_image_filename = kDefaultRearDeckImage),
       const CH1* deck_art_folder = kDefaultDeckArtDirectory);

  /* Destructor. */
  virtual ~Deck() {}

  /* Operator= overlaoder deep copies the state of the other object. */
  Deck& operator=(const Deck& other);

  /* Function sets the suit values to the new values.
  @pre    valueN must be between 1-4.
  @return Returns 0 upon success, and a number 1-4 if the valueN is not
  between 1-4. The number will be negative if the inputed number was, and
  vice-versa. */
  SIN SetSuitValues(SIN value_1, SIN value_2, SIN value_3, SIN value_4);

  /* Gets the suit value of the given suit.
  @pre    suit must be between 1-4.
  @return Returns a number between 1-4 upon sucess, and -1 if the index was
  out of bounds. */
  SIN SuitValue(SIN suit);

  /* Returns true if this deck has Jokers. */
  BOL DeckHasJokers();

  /* Returns the number of cards in the deck. */
  SIN CardCount();

  /* Returns the if aces are high or low. */
  SIN AcesHigh();

  /* Returns a pointer to the Card at the spcified index.
  @return Returns nullptr if the index is out of bounds. */
  Card* GetCard(SIN index);

  /* Sets the frontImage to a new Image from file.
  @pre    file must be a valid existing Image file.
  @return returns -1 if file is not a valid Image. */
  // SIN SetRearImage(const File& file);

  /* Loads the art from the deck_art_folder.
  @pre    deck_art_folder must contain all 54 card Images in
  [1-13]-[1-4].svg/J-1.svg/J-2.svg format format.
  @return Returns 0 upon success, 54 if the directory doesn't contain 54
  .svg files, and -x if images are not named correctly, where x is the first
  failed filename. */
  SIN SetDeckArt(const CHR* deck_art_folder);

  /* Returns a AString representation of the suit. */
  const CH1* SuitString(Card::Suit suit);

  /* Prints this object to the Printer. */
  template <typename Printer>
  Printer& PrintTo(Printer& o) {
    o << "Deck: card_count: " << deck.Size() << ", "
      << (aces_high ? "Aces high, " : "Aces low, ")
      << (aces_high ? "Has Jokers\n" : "No Jokers\n");

    for (SIN i = 0; i < deck.Size(); ++i) {
      o << '\n';
      o << deck[i]->PrintTo<COut>(cout);
    }
    return o;
  }

 private:
  /* Function initializes the deck with a traditional set of playing cards. */
  void Initialize(const CHR* rear_deck_image_filename,
                  const CHR* deck_art_folder);

  /* Function that checks the artFolder to see if the it has 54 Images in
   * [1-13]-[1-4].svg/J-1.svg/J-2.svg format. */
  SIN CheckDeckArtFolder(const CHR* deck_art_folder);
};

}  // namespace cards
}  // namespace kabuki

#endif
