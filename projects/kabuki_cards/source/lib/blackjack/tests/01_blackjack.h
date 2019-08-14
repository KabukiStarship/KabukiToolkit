/** Kabuki Card Games
    @file    /.../KabukiTheater-Examples/KabukiCardGames/KabukiCardGames/Blackjack/BlackjackHand.h
    @author  Cale McCollough <http://calemccollough.github.io>
    @license Copyright (C) 2017 Cale McCollough <calemccollough.github.io>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once

#include "../Hand.h"
#include "../CardStack.h"

namespace KabukiCardGames { namespace Blackjack {
    
/* Class that represents a Hand in Blackjack.
A blackjack hand has a minmum of 2 cards.
*/
class BlackjackHand : public Hand { 
public:

    /* Constructor.
	The game of blackjack starts with each player having two cards. */
    BlackjackHand (CardStack& stock);
        
    /* Compares this hand to the other hand.
	@return Returns 0 if they are equal, 1 if this hand is greater than 
	the other Hand, and -1 if the other Hand is greater than this Hand. */
    int compare (const Hand& other);
            
    // Returns the HighLowScore.
    AStack<CardCombo> GetHandCombos ();

    // Adds the new Card to this Hand.
    int addCard (Card* new_card);

    // Resturns a string representation of this object.
    string tostring ();
};

class BlackjackCardCombo : public CardCombo
{ 
public:

    /** Default constructor. */
    BlackjackCardCombo (CardStack& copyStack, int acesHighLowORNA);

	// Function that returns the point value based on the ace value.
    int getPointValue ();
};
    
/** A class that represnts a dealer in a card game. 
    A dealer has the Deck of cards, but is not neccissaraly a player. A dealer needs to keep track of all of the Players.
    A BlackjackDealer is both a Player and a Dealer at the same time.
*/
class BlackjackDealer: public Player, public Dealer
{
public:
    
    enum {
        numDecks = 1,                               //< The number of decks for this game.
        deckSize = 52,                              //< The number of cards in the Deck.
        startingPoints = 999999,                    //< The dealers starting points.
        startingAnte = 5,                           //< The starting ante.
        minBet = 1,                                 //< The minimum bet.
        minNumCardsPerHand = 2,                     //< The minimum number of cards in a hand.
        maxNumCardsPerHand = Deck::defaultNumCards, //< The maximum number of cards in a hnd.
        maxNumPlayer = 2                            //< The maximum number of players.
    };

    /** Constructor. 
	This is why we like polymorphism. Notice all we have is a single constructor here, because all of our code we are recycling from the Dealer class.*/
    BlackjackDealer ();
};

/* A player in the game Blackjack. */
class BlackjackPlayer {
public:
    
    /** Default Constructor. */
    BlackjackPlayer (string playerName = "You", int startPoints = 10, bool playerOrDealer);
    
    // Destructor.
    ~BlackjackPlayer ();
    
    /* AI function that determines if a player (usually the dealer) hits or holds. */
    bool playOrPass (Dealer& dealer);
    
    // Function that performs the logic of playing a hand.
    void playHand ();
};

}   // Blackjack
}   // KabukiCardGames
