/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/lib/blackjack/blackjack_card_combo.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "blackjack_hand.h"
//
#include "blackjack_cardcombo.h"

using namespace kabuki_cards;

BlackjackHand::BlackjackHand(CardStack& startingCards)
    : Hand(startingCards, 2, Deck::defaultNumCards) {}

AStack<CardCombo> BlackjackHand::getHandCombos() {
    auto low_score = BlackjackCardCombo (,
        high_score;

    scores.low = 0;     //< scores.low is the total of the cards with aces as 1
    scores.high = 0;    //< scores.high is the number of aces to add on an opt 10.

    for (SIN s=0; s < CardCount (); ++s)
    {
    SIN currentValue = GetCard(s)->getPipValue();

    if (currentValue == 1)  // First check if its an ace
    {
      ++scores.low;       //< Aces low means add 1 to the low total.
      scores.high += 10;  //< Aces high means add a 10 to the high total.
    } else if (currentValue >= 10)  // Next check to see if its a Jack, Queen,
                                    // or King because they are all 10 points.
    {
      scores.low += 10;
      scores.high += 10;
    } else  // then its just number card so add it to both the low and high
            // totals.
    {
      scores.low += currentValue;
      scores.high += currentValue;
    }
    }
      
    return scores;
}

SIN BlackjackHand::AddCard(Card* new_card) {
  if (CardCount() + 1 > card_count_max_) return 1;
  hidden_cards.AddCard(new_card);
}

String BlackjackHand::toString() {
  HighLowScore highLowScore = GetHighLowScore();

  return "BlackjackHand:\nHigh score: " + String(highLowScore.high) +
         " Low Score: " + String(highLowScore.low) + "\n" +
         CardStack::toString();
}

#if DEBUG_MODE

#include "../Deck.h"

class BlackjackHandUnitTest : public UnitTest {
  BlackjackHandUnitTest()
      : UnitTest("Testing Blackjack::BlackjackHand class...") {}

  void runTest() {
    D_COUT("Creating deck...");

    Deck stackedDeck(Deck::Culture Deck::kFrench, Deck::acesHighOrLow,
                     Deck::doesNotContainJokers);

    CardStack deck(stackedDeck);

    deck.Shuffle();

    D_COUT("Creating playerBlackjackHand");

    BlackjackHand playerBlackjackHand(deck.TakeNextCard(), deck.TakeNextCard()),
        dealersBlackjackHand(deck.TakeNextCard(), deck.TakeNextCard());

    D_COUT("Testing String Hard::toString ()...");
    D_COUT(playerBlackjackHand.toString);
    D_COUT(dealersBlackjackHand.toString);

    D_COUT(
        "Creating BlackjackHands Player{Ace of Hearts, Ace of Clubs) Dealer{ "
        "King of Hearts, Nine of Diamonds } ...");
    playersBlackjackHand.SetCards();
  }
};
static CardStackUnitTest cardPileUnitTest;
#endif  // DEBUG_MODE
