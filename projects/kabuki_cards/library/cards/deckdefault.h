/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/deck_default.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#ifndef KABUKI_CARDS_DECKDEFAULT_H
#define KABUKI_CARDS_DECKDEFAULT_H

#include <pch.h>

#include "deck.h"

namespace kabuki {
namespace cards {

class DeckDefault : public Deck {
  CardSuit suit_;        //< The suit of this Card.
  SIN value_;            //< The value of this Card.
  CardCulture culture_;  //< The Culture of this Card.
  Image& suit_icon_;     //< The icon of the suit.

 public:
  /* An enumberated list of the different suites on playing cards in various
  countries. */
  typedef enum Suites {
    kClub = 1,
    kAcorn = 1,
    kCoin = 1,
    kDiamond = 2,
    kRose = 2,
    kCup = 2,
    kHeart = 3,
    kBell = 3,
    kSpade = 4,
    kLief = 4,
    kShield = 4,
    kSword = 4
  } CardSuit;

  /* An enumerated list of different European-style playing card suites.
      Piacentine, Napoletane, Spagnole, Bergamasche suits are also known as
     Latin suites, because they are from countries that speak Romantic
     languages. */
  typedef enum CardCulture {
    kFrench = 1,
    kGerman = 2,
    kSwissGerman = 3,
    latin = 4,
    Piacentine = 4,
    Napoletane = 4,
    Spagnole = 4,
    Bergamasche = 4
  };

  /* An enumberated list of the different French playing cards suites. */
  typedef enum FrenchSuits { kClub = 1, kDiamond, kHeart, kSpade } FrenchSuit;

  /* An enumberated list of the different German playing cards suites. */
  typedef enum GermanSuits { kAcorn = 1, kBell, kHeart, kLief } GermanSuit;

  /* An enumberated list of the different German playing cards suites. */
  typedef enum SwissGermanSuits {
    kAcorn = 1,
    kBell,
    kRose,
    kShield
  } SwissGermanSuit;

  /* An enumberated list of the different Latin playing cards suites. */
  typedef enum LatinSuits { kClub = 1, kCoin, kCup, kSword } LatinSuit;

  /* Constructor. */
  Card(SIN value, CardSuit suit, Culture culture = kFrench);

  /* Virtual destructor so users can make a Card sub-class! */
  virtual ~Card() {}

  /* Compares this Card to the other Card and returns 0 if they are identical.
   */
  SIN Compare(const Card& other);

  /* Compares this Card to the other Card and returns true if the two are
  identical. */
  BOL Equals(const Card& other);

  /* Returns the face value of this Card. */
  SIN GetValue();

  /* Returns the CardSuit of this card. */
  CardSuit GetSuit();

  /* Returns the Culture of this Card. */
  CardCulture Culture();

  /* Function sets the culture to the newCulture. */
  void SetCulture(CardCulture newCulture);

  /* Returns a AString representation of the suit. */
  const CH1* SuitString();

  /* Prints this object to the Printer. */
  template <typename Printer>
  Printer& PrintTo(Printer& o) {
    if (face_value == 1)
      o << "Ace of " << suit_string << ", ";
    else if (face_value == 11)
      o << "Jack of " << suit_string << ", ";
    else if (face_value == 12)
      o << "Queen of " << suit_string << ", ";
    else if (face_value == 13)
      o << "King of " << suit_string << ", ";
    else if (face_value == 0)
      o << "Empty"
        << ", ";
    else
      o << face_value << " of " << suit_string << ", ";
    return o;
  }
};

}  // namespace cards
}  // namespace kabuki

#endif
