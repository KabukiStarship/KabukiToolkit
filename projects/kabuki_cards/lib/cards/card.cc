/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/lib/blackjack/card.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "card.h"
#include "deck.h"

using namespace kabuki_cards;

const CH1* Card::SuitCultures() {
  static const CH1* strings[] = {"French",     "German",     "Swiss-German",
                                 "Piacentine", "Napoletane", "Spagnole",
                                 "Bergamasche"};
  return strings;
}

const CH1** Card::FrenchSuit() {
  static const CH1* strings[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  return strings;
}

const CH1** Card::GermanSuit() {
  static const CH1* strings[4] = {"Acorns", "Bells", "Hearts", "Lieves"};
  return strings;
}
const CH1** Card::SwissGermanSuit() {
  static const CH1* strings[4] = {"Acorns", "Bells", "Roses", "Shields"};
  return strings;
}

const CH1** Card::LatinSuit() {
  static const CH1* strings[4] = {"Clubs", "Coins", "Cups", "Swords"};
  return strings;
}

Card::Card(SIN pip_value, Suit suit_) {
  SetVCard(pip_value, face_value, point_value, suit_value);
}

Card::Card(SIN pip_value, Suit suit_, SIN face_value, SIN point_value,
           SIN suit_value, SuitCulture suit_culture, const CHR* image_directory)
    : suit_(suit_) {
  SetVCard(pip_value, face_value, point_value, suit_value, suit_culture);
}

Card::Card(const Card& other)
    : pip_value(other.pip_value),
      face_value(other.face_value),
      point_value(other.point_value),
      suit_value(other.suit_value),
      suit_(other.suit_),
      suit_culture(other.suit_culture),
      suit_string(other.suit_string),
      card_image(other.card_image) {}

Card& Card::operator=(const Card& other) {
  pip_value = other.pip_value;
  face_value = other.face_value;
  point_value = other.point_value;
  suit_value = other.suit_value;
  suit_ = other.suit_;
  suit_culture = other.suit_culture;
  suit_string = other.suit_string;
  card_image = other.card_image;
}

SIN Card::Compare(const Card& other) {
  SIN other_value = other.pip_value, other_suite_value = other.suit_value;

  if (pip_value > other_value) return 1;
  if (pip_value < other_value) return -1;

  if (suit_value > other_suite_value) return 1;
  if (suit_value < other_suite_value) return -1;
  return 0;
}

BOL Card::Equals(const Card& other) { return Compare(other) == 0; }

SIN Card::PipValue() { return pip_value; }

void Card::SetPointValue(SIN value) {
  // The user might want to use a negative point value in a game.
  point_value = value;
}

void Card::SetVCard(SIN pip_value, SIN face_value, SIN point_value,
                    SIN suit_value, SuitCulture suit_culture,
                    const CH1* image_directory) {
  if (pip_value < 0)
    pip_value = pip_value;
  else if (pip_value > 13)
    pip_value = 13;
  pip_value = pip_value;

  if (face_value < 0)
    face_value = 0;
  else if (face_value > 14)
    face_value = 14;
  face_value = face_value;

  if (face_value < 0)
    face_value = 0;
  else if (face_value > 10)
    face_value = 10;
  face_value = face_value;

  if (suit_value < 1)
    suit_value = 1;
  else if (suit_value > 4)
    suit_value = 4;
  suit_value = suit_value;

  suit_culture_ = suit_culture_;

  switch (suit_culture) {
    case 1: {
      suit_string = frenchSuit[suit_];
      break;
    }
    case 2: {
      suit_string = germanSuit[suit_];
      break;
    }
    case 3: {
      suit_string = swissGermanSuit[suit_];
      break;
    }
    default: {
      suit_string = latinSuit[suit_];
      break;
    }
  }
  loadCardImage(image_directory);
}

SIN Card::FaceValue() { return face_value; }

SIN Card::SuitValue() { return suit_value; }

Card::Suit Card::GetSuit() { return suit_; }

Card::SuitCulture Card::SuitCulture() { return suit_culture_; }

void Card::SetSuitCulture(Card::SuitCulture suit_culture) {
  suit_culture_ = suit_culture_;
}

const CHR* Card::SuitString() { return suit_string; }

SIN Card::LoadCardImage(const CHR* directory) {
  // First, check to see if the directory is valid.
  File filePath = File(directory);

  // Next check to see if it isn't a normal file.
  if (filePath.existsAsFile()) return -1;

  if (!filePath.isDirectory()) return -1;
  // The directory is good, now check to see if the the directory contains an
  // image with the correct naming convention.

  string cardImageFilename = string(pip_value) + "-" + string(suit_) + ".svg";

  File filename = directory + cardImageFilename;

  if (!filename.existsAsFile()) return 2;

  Image tempImage = ImageCache::GetFromFile(filename);

  if (tempImage.isNull()) return 3;

  card_image = tempImage;

  return 0;
}

/* Image& Card::GetImage() { return card_image; */

template <typename Printer>
Printer& CardPrint(Printer& o, const Card& card) {
  string cardstring;

  switch (pip_value) {
    case 0: {
      return suit_string;
    }
    case 1: {
      cardstring = "Ace of ";
      break;
    }
    case 11: {
      cardstring = "Jack of ";
      break;
    }
    case 12: {
      cardstring = "Queen of ";
      break;
    }
    case 13: {
      cardstring = "King of ";
      break;
    }
    default: {
      cardstring = string(pip_value) + " of ";
      break;
    }
  }
  cardstring += suit_string;

  return cardstring;
}
