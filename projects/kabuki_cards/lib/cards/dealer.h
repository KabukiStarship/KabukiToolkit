/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_cards/source/lib/dealer.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#ifndef KABUKI_CARDS_DEALER_H
#define KABUKI_CARDS_DEALER_H

#include "hand.h"
#include "player.h"

namespace kabuki_cards {

/* A class that represnts a dealer in a card game.
    A dealer has the Deck of cards, but is not neccissaraly a player. A dealer
   needs to keep track of all of the Players.
*/
class Dealer {
  SIN num_decks_,           //< The number of decks in this game.
      deck_size_,           //< The size of the deck for this game.
      pot_total_,           //< The number of points in the pot.
      starting_ante_,       //< The starting ante_ for the game.
      ante_,                //< The current ante_ for the game.
      min_bet_,             //< The minimum bet for this round.
      min_cards_per_hand_,  //< The minimum number of Cards per Hand.
      max_cards_per_hand_,  //< The maximum number of Cards per Hand.
      max_num_players_,     //< The maximum number of players in this game.
      current_player_num_;  //< The player number of the current player who is
                            // playing in this round.
  /* The main pack of Card objects; the Deck owns the Card objects.
  A pack of Cards is the entire deck of cards. Note: can be a
  DoubleDeck (which you should make). */
  Deck pack_;
  /*< The stock of playing Card pointers.
  The stock is the main pile of cards in a playing game. */
  CardStack stock_;
  AStack<Player> players_;  //< The ownwed array of Player objects.

 public:
  /* Constructor. */
  Dealer(SIN deck_size, SIN ante_, SIN min_bet, SIN min_cards_per_hand,
         SIN max_cards_per_hand, SIN max_num_player);

  /* Destructor. */
  virtual ~Dealer();

  void SetValues(SIN ante_, SIN min_bet, SIN min_cards_per_hand,
                 SIN max_cards_per_hand, SIN max_num_player);

  /* Returns the number of Players. */
  SIN PlayerCount();

  /* Returns the min_cards_per_hand_. */
  SIN GetMinNumCardsPerHand();

  /* Returns the max_cards_per_hand_. */
  SIN GetMaxNumCardsPerHand();

  /* Sets the min_cards_per_hand_ to the card_count. */
  SIN SetMinNumCardsPerHand(SIN card_count);

  /* Sets the max_cards_per_hand_ to the card_count. */
  SIN SetMaxNumCardsPerHand(SIN card_count);

  /* Adds the newPlayer to the game. */
  void AddPlayer(Player* newPlayer);

  /* Removes a Player with the specified playerName from the game.
  @returns the index number of the player if the player is found. */
  SIN RemovePlayer(const CHR* playerName);

  /* Removes a Player with the specified index from the game.
  @return Returns 0 upon success.
  @return Returns -1 if playerNumber is < 0.
  @return Returns 1 if the playerNumber is > getNumPlayers ().*/
  SIN RemovePlayer(SIN playerNumber);

  /* Retruns a pointer to the player with the specified playerNumber.
  @return Returns nullptr if the playerNumber < 0 or > getNumPlayers (). */
  Player* GetPlayer(SIN playerNumber);

  /* Returns the address of the dealer's pack. */
  Deck& GetPack();

  /* Returns the address of the dealer's stock. */
  CardStack& GetStock();

  /* Returns the total number of points in the pot. */
  SIN GetPotTotal();

  /* Sets the pot_total_. */
  void SetPotTotal(SIN new_total);

  /* Adds the pointsToAdd to the pot_total_.
      @pre    pointsToAdd > 0 */
  void AddToPot(SIN points);

  /* Returns the num_decks_. */
  SIN GetNumDecks();

  /* Sets the deck_count_ to the new_num_decks. */
  void SetNumDecks(SIN new_num_decks);

  /* Returns the deck_size_. */
  SIN GetDeckSize();

  /* Sets the deck_size_. */
  void SetDeckSize(SIN newMaxPlayers);

  /* Returns the total number of points in the pot */
  SIN GetStartingAnte();

  /* Sets the pot_total_. */
  void SetStartingAnte(SIN ante_);

  /* Returns the total number of points in the pot. */
  SIN GetAnte();

  /* Sets the pot_total_. */
  void SetAnte(SIN ante_);

  /* Returns the current min bet. */
  SIN GetMinBet();

  /* Sets the min_bet_ to the value. */
  void SetMinBet(SIN value);

  /* Returns the current min bet. */
  SIN GetMaxPlayers();

  /* Sets the min_bet_ to the value. */
  void SetMaxPlayers(SIN newMaxPlayers);

  /* Virtual function that shuffles the cards and gets ready to starts a new
  game. */
  virtual void StartNewGame();

  /* Virtual function that shuffles the cards and gets ready for a new round. */
  virtual void Redeal();

  template <typename Printer>
  Printer& PrintTo(Printer& o) {
    return o << "\nDealer:\nPot Total: " << pot_total_;
  }
};

}  // namespace kabuki_cards

#endif  //< KABUKI_CARDS_DEALER_H
