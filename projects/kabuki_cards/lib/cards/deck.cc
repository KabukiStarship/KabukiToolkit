/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/lib/blackjack/deck_.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "cardstack.h"
#include "deck_.h"

#include <script2/t_strand.h>

using namespace _;
using namespace kabuki_cards;

const SIN* SuitValuesDefault() {
  static const SIN kDefaultSuitValues[4] = {1, 2, 3, 4};
  return kDefaultSuitValues;
}

const CH1* Deck::DefaultDeckArtDirectory() {
  return "../../../images/front_deck_art/vectorized_playing_cards/";
}

const CH1* Deck::DefaultRearDeckImage() {
  return "../../../images/rear_deck_art/default_deck_rear_image.svg";
}

const Deck Deck::Standard = Deck();
const Deck Deck::StandardWithJokers = Deck(false);

Deck::Deck(BOL deck_contains_jokers, SIN aces_are_high,
           Card::SuitCulture suit_culture, const CHR* read_deck_image_filename,
           const CHR* deck_art_folder)
    : has_jokers_(deck_contains_jokers),
      aces_high_(aces_are_high),
      suit_culture_(suit_culture),
      card_count_(deck_contains_jokers ? defaultNumCardsWithJokers
                                       : defaultNumCards),
      lowest_card_value_(aces_are_high == 0 ? 1 : 2),
      highest_card_value_(aces_are_high == 0 ? 13 : 14) {
  Initialise(read_deck_image_filename, deck_art_folder);
}

void Deck::Initialise(const CHR* rear_deck_image_filename,
                      const CHR* deck_art_folder) {
  if (deck_.Size() == 0) deck_.clear();
  // Depending on if aces are high, the value of an Ace will be either 1
  // followed by the 2 card, or 14.
  SIN startValue = aces_high_ ? 1 : 2;
  const CHR* suitCulturestringAddress = Card::SuitCultureStrings[suit_culture_];

  // First we want to start by creating the Aces because their pip_value is 1,
  // but might have a face_value of 14.
  SIN ace_value = aces_high ? 14 : 1;

  for (SIN suit = 1; suit <= 4; ++suit) {
    deck_.Add (new Card (1, 1, ace_value, suit_values_[suit], (Card::Suit) suit, 
       Card::SuitCultureStrings()[suit], deck_art_folder);
  }
  // This is a nested for loop. It makes it so that our deck_ will be sorted by
  // suit and value.
  for (SIN suit = 1; suit <= 4; ++suit) {
    // If we had switched the order of the for loops, it would sort it by
    // value then suit.
    for (SIN cardValue = 2; cardValue <= 13; ++cardValue) {
      // There are 13 different face values { 2,3,4,5,6,7,8,9,10,J,Q,K,A }
      // The (Card::Suit) "casts" the suit_value to a Card::Suit.
      deck_.add(new Card(cardValue, (Card::Suit)suit, this));
    }
  }
  // rear_image_ = ImageCache::GetFromFile (rear_deck_image_filename);

  // if (rear_image_.isNull ())
  //    ImageCache::GetFromFile (DefaultRearDeckImage ());
}

Deck& Deck::operator=(const Deck& other) {}

SIN Deck::SetSuitValues(SIN value_1, SIN value_2, SIN value_3, SIN value_4) {
  if (value_1 < 1) return -1;
  if (value_1 > 4) return 1;

  if (value_2 < 1) return -2;
  if (value_2 > 4) return 2;

  if (value_3 < 1) return -3;
  if (value_3 > 4) return 3;

  if (value_4 < 1) return -4;
  if (value_4 > 4) return 4;

  suit_values_[1] = value_1;
  suit_values_[2] = value_2;
  suit_values_[3] = value_3;
  suit_values_[4] = value_4;
}

SIN Deck::SuitValue(SIN suit) {
  if (suit < 1 || suit > 4) return -1;
  return suit_values_[suit];
}

BOL Deck::DeckHasJokers() { return has_jokers_; }

SIN Deck::CardCount() { return card_count_; }

SIN Deck::AcesHigh() { return aces_high_; }

Card* Deck::GetCard(SIN index) {
  if (index < 0 || index >= deck_.Size()) return nullptr;
  return deck_[index];
}

SIN Deck::SetRearImage(const File& file) {
  Image tempImage = ImageCache::GetFromFile(file);
  if (tempImage.isNull) return 0;
  rear_image_ = tempImage;
  return 1;
}

SIN Deck::CheckDeckArtFolder(const CHR* deck_art_folder) {
  // Make a file fromt he deck_art_folder string.
  File art_folder = File(deck_art_folder);

  // Before we go trying to change all of the images, lets first check to see if
  // the deck_art_folder is a valid folder.
  if (!art_folder.isDirectory()) return 1;

  // Next, we need to check to see if the folder contains 54 .svg images.
  AStack<File> card_image_files;
  if (art_folder.FindChildFiles(card_image_files,
                                File::TypesOfFileToFind::FindFiles, false,
                                ".svg") != 54) {
    return 54;
  }
  // Note: I'm assuming that the deck_art_folder is sorted by name.
  // Then check to see if all of the images were nammed correctly.
  for (SIN suit = 1; suit <= 4; ++suit) {
    for (SIN pip_value = 1; pip_value <= 13; ++pip_value) {
      SIN index = suit * pip_value;

      AStrand<CH1> expected_filename;
      // Examples "1-2.svg" = Ace of Diamons
      // "13-4" = King of Spades
      expected_filename << pip_value << '-' << suit << ".svg";

      if (card_image_files[index].GetFilename() != expected_filename)
        return -1 * index;
    }
  }
  if (card_image_files[52].GetFilename() != "0-1.svg") return -53;
  if (card_image_files[53].GetFilename() != "0-2.svg") return -54;
}

SIN Deck::SetDeckArt(const CHR* deck_art_folder) {
  SIN returnValue = Deck::CheckDeckArtFolder();

  // Now we know that all of the files are in the directory and are nammed
  // correctly. Now lets actually change the images.
  for (SIN suit = 1; suit <= 4; ++suit) {
    for (SIN pip_value = 1; pip_value <= 13; ++pip_value) {
      SIN index = suit * pip_value;
      AStrand<> filename;
      filename << pip_value << '-' << suit << ".svg";

      SIN result =
          deck_[index]->SetCardImage(ImageCache::GetFromFile(filename));

      if (result != 0) return result;
    }
  }
  return 0;
}

const CH1* Deck::SuitString(Card::Suit suit) {
  switch (suit_culture_) {
    case Card::kFrench: {
      switch (suit) {
        case 1:
          return "Clubs";
        case 2:
          return "Diamonds";
        case 3:
          return "Hearts";
        case 4:
          return "Spades";
      }
      break;
    }
    case Card::kGerman: {
      switch (suit) {
        case 1:
          return "Acorns";
        case 2:
          return "Bells";
        case 3:
          return "Hearts";
        case 4:
          return "Lieves";
      }
      break;
    }
    case Card::kSwissGerman: {
      switch (suit) {
        case 1:
          return "Acrons";
        case 2:
          return "Bells";
        case 3:
          return "Roses";
        case 4:
          return "Shields";
      }
      break;
    }
    default: {  // Then its a Latin suit.
      switch (suit) {
        case 1:
          return "Clubs";
        case 2:
          return "Coins";
        case 3:
          return "Cups";
        case 4:
          return "Swords";
      }
    }
  }
  return "Invalid";
}
