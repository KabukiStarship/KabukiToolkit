/** Kabuki Card Games
    @file    ~/source/kabuki/cards/include/dealer.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
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

#ifndef KABUKI_CARDS_DEALER_H
#define KABUKI_CARDS_DEALER_H

#include "hand.h"
#include "player.h"

namespace kabuki { namespace cards {

/** A class that represnts a dealer in a card game. 
    A dealer has the Deck of cards, but is not neccissaraly a player. A dealer needs to keep track of all of the Players.
*/
class Dealer {
    public:
    
    /** Constructor. */
    Dealer (int deck_size, int ante, int min_bet, int min_cards_per_hand, 
            int max_cards_per_hand, int max_num_player);
    
    /** Destructor. */
    virtual ~Dealer ();

    void setValues (int ante, int min_bet, int min_cards_per_hand, 
            int max_cards_per_hand, int max_num_player);

    /** Returns the number of Players. */
    int GetNumPlayers ();

    /** Returns the minNumCardsPerHand. */
    int GetMinNumCardsPerHand ();
    
    /** Returns the maxNumCardsPerHand. */
    int GetMaxNumCardsPerHand ();

    /** Sets the minNumCardsPerHand to the numCards. */
    int SetMinNumCardsPerHand (int numCards);
    
    /** Sets the maxNumCardsPerHand to the numCards. */
    int SetMaxNumCardsPerHand (int numCards);

    void AddPlayer (Player* newPlayer);
    /** Adds the newPlayer to the game.
    
    /** Removes a Player with the specified playerName from the game.
        @returns the index number of the player if the player is found. */
    int RemovePlayer (string& playerName);
                                                    
    /** Removes a Player with the specified index from the game.
        @return Returns 0 upon success.
        @return Returns -1 if playerNumber is < 0.
        @return Returns 1 if the playerNumber is > getNumPlayers ().*/
    int RemovePlayer (int playerNumber);
                                                    
    /** Retruns a pointer to the player with the specified playerNumber.
        @return Returns nullptr if the playerNumber < 0 or > getNumPlayers (). */
    Player* GetPlayer (int playerNumber);

    /** Returns the address of the dealer's pack. */
    Deck& GetPack ();
    
    /** Returns the address of the dealer's stock. */
    CardStack& GetStock ();

    /** Returns the total number of points in the pot. */
    int GetPotTotal ();
    
    /** Sets the potTotal. */
    void SetPotTotal (int new_total);
    
    /** Adds the pointsToAdd to the potTotal.
        @pre    pointsToAdd > 0 */
    void AddToPot (int points);

    /** Returns the num_decks_. */
    int GetNumDecks ();
    
    /** Sets the numDecks to the new_num_decks. */
    void SetNumDecks (int new_num_decks);

    /** Returns the deckSize. */
    int GetDeckSize ();
    
    /** Sets the deckSize. */
    void SetDeckSize (int newMaxPlayers);

    /** Returns the total number of points in the pot */
    int GetStartingAnte ();
    
    /** Sets the potTotal. */
    void SetStartingAnte (int ante);

    /** Returns the total number of points in the pot. */
    int GetAnte ();
    
    /** Sets the potTotal. */
    void SetAnte (int ante);

    /** Returns the current min bet. */
    int GetMinBet ();
    
    /** Sets the minBet to the value. */
    void SetMinBet (int value);

    /** Returns the current min bet. */
    int GetMaxPlayers ();
    
    /** Sets the minBet to the value. */
    void SetMaxPlayers (int newMaxPlayers);

    /** Virtual function that shuffles the cards and gets ready to starts a new game. */
    virtual void StartNewGame ();
    
    /** Virtual function that shuffles the cards and gets ready for a new round. */
    virtual void Redeal ();

    /** Prints this object to the log. */
    virtual void Print (_::Log& log);

private:
    
    int           num_decks_,           //< The number of decks in this game.
                  deck_size_,           //< The size of the deck for this game.
                  pot_total_,           //< The number of points in the pot.
                  starting_ante_,       //< The starting ante for the game.
                  ante_,                //< The current ante for the game.
                  min_bet_,             //< The minimum bet for this round.
                  min_cards_per_hand_,  //< The minimum number of Cards per Hand.
                  max_cards_per_hand_,  //< The maximum number of Cards per Hand.
                  max_num_players_,     //< The maximum number of players in this game.
                  current_player_num_;  //< The player number of the current player who is playing in this round.
    Deck          pack_;                /*< The main pack of Card objects; the Deck owns the Card objects.
                                            A pack of Cards is the entire deck of cards. Note: can be a DoubleDeck (which you should make). */
    CardStack     stock_;               /*< The stock of playing Card pointers.
                                            The stock is the main pile of cards in a playing game. */
    Array<Player> players_;             //< The ownwed array of Player objects.
};

}       //< namespace cards
}       //< namespace kabuki
#endif  //< KABUKI_CARDS_DEALER_H
