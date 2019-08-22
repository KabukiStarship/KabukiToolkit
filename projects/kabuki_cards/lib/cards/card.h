/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/lib/card.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#ifndef KABUKI_CARDS_CARD_HEADER
#define KABUKI_CARDS_CARD_HEADER

#include <pch.h>

namespace kabuki_cards {

/* Class that represents a card in a card game.
Cards as we know them originated in Europe. We traditionally think of cards as
only being clubs, hearts, diamonds, and spades, but there are also some other
variations from other European countries. For more information on them, please
Wiki "Playing Card Suits". The nifty thing about these extra card decks, is
that we can make a double deck of cards, and use the suit culture to tell the
decks apart. */
class Card {
 public:
  /* An enumerated list of different European-style playing card suites.
  Piacentine, Napoletane, Spagnole, Bergamasche suits are also known as Latin
  suites, because they are from countries that speak Romantic languages. */
  enum class SuitCulture {
    kFrench = 1,
    kGerman,
    kSwissGerman,
    kPiacentine,
    kNapoletane,
    kSpagnole,
    kBergamasche
  };

  /* An enumberated list of the different suites on playing cards in various
  countries. */
  enum class Suit {
    kClub = 1,
    kAcorn = 1,
    kCoin = 1,
    kBlack = 1,
    kDiamond = 2,
    kRose = 2,
    kCup = 2,
    kRed = 2,
    kHeart = 3,
    kBell = 3,
    kSpade = 4,
    kLief = 4,
    kShield = 4,
    kSword = 4
  };

 private:
  SIN pip_value_,    //< The value of this Card from 0-13.
      face_value_,   //< The face value of this Card from 1-14.
      point_value_,  //< The number of points this Card is worth from 0-10.
      suit_value_;   //< The value of this suit.
  Suit suit_;        //< The suit of this Card.
  SuitCulture suit_culture_;  //< The culture of this Card.
  const CH1* suit_String_;    //< A AString that stores the suit.
  // Image card_image_;        //< The Image of this Card.

 public:
  /* An enumberated list of the different French playing cards suites. */
  enum class FrenchSuits { kClub = 1, kDiamond, kHeart, kSpade } FrenchSuit;

  /* An enumberated list of the different German playing cards suites. */
  enum class GermanSuits { kAcorn = 1, kBell, kHeart, kLief } GermanSuit;

  /* An enumberated list of the different German playing cards suites. */
  enum class SwissGermanSuits {
    kAcorn = 1,
    kBell,
    kRose,
    kShield
  } SwissGermanSuit;

  /* An enumberated list of the different Latin playing cards suites. */
  enum class LatinSuits { kClub = 1, kCoin, kCup, kSword } LatinSuit;

  /* A list of the Strings "Clubs", "Diamonds", "Hearts", "Spades" */
  const CH1** FrenchSuitss();

  /* A list of the Strings "Acorns", "Bells", "Hearts", "Lieves" */
  const CH1** GermanSuits();

  /* A list of the Strings "Acorns", "Bells", "Roses", "Shields" */
  const CH1** SwissGermanSuits();

  /* A list of the Strings "Clubs", "Coins", "Cups", "Swords" */
  const CH1** LatinSuits();

  /* An array of Strings that represnet the 7 different directories for the suit
  icon file */
  const CH1** SuitCultureStrings();

  /* Creates a simple card with no image. The face_value will equal the
  point_value. */
  Card(SIN pip_value = 0, Suit suit = Suit::kBlack);

  /* Verbose constructor. */
  Card(SIN pip_value, Suit suit, SIN face_value, SIN point_value,
       SIN suit_value, SuitCulture culture, const CHR* image_directory);

  /* Copy constructor. */
  Card(const Card& other);

  /* Virtual destructor just incase we want to make a sub-class later.
  virtual ~Card () {}

  /* Operator= overlaoder deeps copies the other Card. */
  Card& operator=(const Card& other);

  /* Compares this Card to the other Card.
  @return Returns 0 if they are identical.
  @return Returns 1 if this Card is greater than the other Card. */
  virtual SIN Compare(const Card& other);

  /* Compares this Card to the other Card and returns true if the two are
   * identical. */
  BOL Equals(const Card& other);

  /* Returns the pip value of this Card.
  The pip value is a number between 0-13 that represents which card it is:
  J=0, A=1, 2-10, J=11, Q=12, K=13. */
  SIN PipValue();

  /* Returns the face value of this Card
       The face value represents the rank of the card. */
  SIN FaceValue();

  /* Returns the point value of this Card
  The face value represetns how many points this card is worth. */
  SIN PointValue();

  /* Sets the point value to the value. */
  void SetPointValue(SIN value);

  /* Returns the face value of this Card
  The face value represetns how many points this card is worth. */
  SIN SuitValue();

  /* Returns the Suit of this card. */
  Suit GetSuit();

  /* Returns the Card::Culture of this Deck.
  Function sets the suit_culture to the newCardCulture. */
  SuitCulture SuitCulture();

  void SetSuitCulture(SuitCulture culture);

  /* Returns the suitString. */
  const CH1* SuitString();

  /* Loads and sets the card_image to the on in the given directory.
  @return Returns 0 upon succes;
  returns -1 if the directory was actually a file;
  returns 1 if the directory doesn't exist;
  returns 2 if the file doesn't; or
  retruns 3 if the image didn't load right. */
  SIN SetCardImage(const CHR* directory);

  /* Returns the address of this Card's image.
  Image& GetImage(); */

  /* Prints this object to the Printer. */
  template <typename Printer>
  Printer& PrintTo(Printer& o) {}

 private:
  /* Sets the values of the cards. */
  void SetVCard(SIN pip_value, SIN face_value, SIN point_value, SIN suit_value,
                SuitCulture suit_culture, const CHR* image_directory);

  /* Loads the card_image from the specified directory.
  Image LoadCardImage(const CHR* directory); */
};

}  // namespace kabuki_cards

#endif
