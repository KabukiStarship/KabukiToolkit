/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/blackjack/card.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "card.h"
#include "deck.h"

using namespace _;
using namespace kabuki::cards;

const CH1** SuitCultures() {
  static const CH1* strings[] = {"French",     "German",     "Swiss-German",
                                 "Piacentine", "Napoletane", "Spagnole",
                                 "Bergamasche"};
  return strings;
}

const CH1** Card::FrenchSuits() {
  static const CH1* strings[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  return strings;
}

const CH1** Card::GermanSuits() {
  static const CH1* strings[4] = {"Acorns", "Bells", "Hearts", "Lieves"};
  return strings;
}
const CH1** Card::SwissGermanSuits() {
  static const CH1* strings[4] = {"Acorns", "Bells", "Roses", "Shields"};
  return strings;
}

const CH1** Card::LatinSuits() {
  static const CH1* strings[4] = {"Clubs", "Coins", "Cups", "Swords"};
  return strings;
}

Card::Card(SIN pip_value, CardSuit suit) { Set(pip_value, suit); }

Card::Card(SIN pip_value, CardSuit suit_, SIN face_value, SIN point_value,
           SIN suit_value, SuitCulture suit_culture, const CHR* image_directory)
    : suit_(suit_) {
  Set(pip_value, face_value, point_value, suit_value, suit_culture);
}

Card::Card(const Card& other)
    : pip_value_(other.pip_value_),
      face_value_(other.face_value_),
      point_value_(other.point_value_),
      suit_value_(other.suit_value_),
      suit_(other.suit_),
      suit_culture_(other.suit_culture_),
      suit_string_(other.suit_string_),
      card_image_(other.card_image_) {}

Card& Card::operator=(const Card& other) {
  pip_value_ = other.pip_value_;
  face_value_ = other.face_value_;
  point_value_ = other.point_value_;
  suit_value_ = other.suit_value_;
  suit_ = other.suit_;
  suit_culture_ = other.suit_culture_;
  suit_string_ = other.suit_string_;
  card_image_ = other.card_image_;
}

SIN Card::Compare(const Card& other) {
  SIN pip_value = pip_value_, other_value = other.pip_value_;
  if (pip_value > other_value) return 1;
  if (pip_value < other_value) return -1;

  SIN suit_value = suit_value_, other_suite_value = other.suit_value_;
  if (suit_value > other_suite_value) return 1;
  if (suit_value < other_suite_value) return -1;
  return 0;
}

BOL Card::Equals(const Card& other) { return Compare(other) == 0; }

SIN Card::PipValue() { return pip_value_; }

SIN Card::FaceValue() { return face_value_; }

SIN Card::PointValue() { return point_value_; }

void Card::SetPointValue(SIN value) { point_value_ = value; }

void Card::Set(SIN pip_value, SIN face_value, SIN point_value, SIN suit_value,
               SuitCulture suit_culture, const CH1* image_directory) {
  if (pip_value < 0)
    pip_value = pip_value;
  else if (pip_value > 13)
    pip_value = 13;
  pip_value_ = pip_value;

  if (face_value < 0)
    face_value = 0;
  else if (face_value > 14)
    face_value = 14;
  face_value_ = face_value;

  if (face_value < 0)
    face_value = 0;
  else if (face_value > 10)
    face_value = 10;
  face_value_ = face_value;

  if (suit_value < 1)
    suit_value = 1;
  else if (suit_value > 4)
    suit_value = 4;
  suit_value_ = suit_value;

  suit_culture_ = suit_culture_;

  switch (suit_culture) {
    case 1: {
      suit_string_ = FrenchSuits()[suit_];
      break;
    }
    case 2: {
      suit_string_ = GermanSuits()[suit_];
      break;
    }
    case 3: {
      suit_string_ = SwissGermanSuits()[suit_];
      break;
    }
    default: {
      suit_string_ = LatinSuits()[suit_];
      break;
    }
  }
  LoadCardImage(image_directory);
}

SIN Card::FaceValue() { return face_value_; }

SIN Card::SuitValue() { return suit_value_; }

CardSuit Card::CardSuit() { return suit_; }

SuitCulture Culture() { return suit_culture_; }

void Card::SetCulture(SuitCulture suit_culture) {
  if (suit_culture < 1 || suit_culture >= kSuitCultureCount) return;
  suit_culture_ = suit_culture;
}

const CHR* Card::SuitString() { return suit_string_; }

SIN Card::LoadCardImage(const CHR* directory) {
  // First, check to see if the directory is valid.
  File file_path(directory);
  // Next check to see if it isn't a normal file.
  if (file_path.IsOnFile()) return -1;
  if (!file_path.isDirectory()) return -1;
  // The directory is good, now check to see if the the directory contains an
  // image with the correct naming convention.
  AString<> image_filename = pip_value << '-' << suit_ << ".svg";
  File filename = directory << image_filename;
  if (!filename.IsOnFile()) return 2;
  Image image = ImageCache::GetFromFile(filename);
  if (temp_image.IsNull()) return 3;
  card_image = image;
  return 0;
}

/* Image& Card::GetImage() { return card_image; */

template <typename Printer>
Printer& CardPrint(Printer& o, const Card& card) {
  switch (pip_value) {
    case 0:
      break;
    case 1: {
      o << "Ace of ";
      break;
    }
    case 11: {
      o << "Jack of ";
      break;
    }
    case 12: {
      o << "Queen of ";
      break;
    }
    case 13: {
      o << "King of ";
      break;
    }
    default: {
      o << pip_value << " of ";
      break;
    }
  }
  return o << suit_string;
}
