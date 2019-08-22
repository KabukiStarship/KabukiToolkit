/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/lib/blackjack/01_blackjack.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

#include "../hand.h"
#include "../cardstack.h"

namespace kabuki_cards {
    
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
    int Compare (const Hand& other);
            
    /* Returns the HighLowScore.
    @return AStack<CardCombo> */
    Autoject GetHandCombos ();

    /* Adds the new Card to this Hand. */
    int AddCard (Card* new_card);

    // Resturns a AString representation of this object.
    AString ToString ();
};

class BlackjackCardCombo : public CardCombo
{ 
public:

    /** Default constructor. */
    BlackjackCardCombo (CardStack& copyStack, int acesHighLowORNA);

	// Function that returns the point value based on the ace value.
    int GetPointValue ();
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
    BlackjackPlayer (AString playerName = "You", int startPoints = 10, bool playerOrDealer);
    
    // Destructor.
    ~BlackjackPlayer ();
    
    /* AI function that determines if a player (usually the dealer) hits or holds. */
    bool PlayOrPass (Dealer& dealer);
    
    // Function that performs the logic of playing a hand.
    void PlayHand ();
};

} //< kaubki_cards
