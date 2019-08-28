/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/blackjack/dealer.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "dealer.h"

namespace kabuki { namespace cards {

Dealer::Dealer(SIN starting_ante, SIN min_bit, SIN min_cards_per_hand,
               SIN max_cards_per_hand, SIN max_player_count)
    : pack(Deck()), stock(pack), players(OwnedArray<Player>()) {
  SetValues(starting_ante, min_bit, min_cards_per_hand, max_cards_per_hand,
            max_player_count);
}

Dealer::~Dealer() {}

void Dealer::SetValues(SIN starting_ante, SIN min_bet, SIN min_cards_per_hand,
                       SIN max_cards_per_hand, SIN max_player_count) {
  if (starting_ante < 0) starting_ante = 0;
  if (min_bet < 1) min_bet = 1;
  if (max_cards_per_hand < 1) max_cards_per_hand = 1;
  if (max_cards_per_hand < 1) max_cards_per_hand = 1;
  if (max_player_count < 1) max_player_count = 1;

  pot_total_ = 0;
  starting_ante_ = starting_ante;
  ante_ = ante_ = starting_ante;
  min_bet_ = min_bet;
  min_cards_per_hand_ = min_cards_per_hand;
  max_cards_per_hand_ = max_cards_per_hand;
  max_player_count_ = max_player_count;
}

SIN Dealer::PlayerCount() { return players_.Size(); }

SIN Dealer::GetMinNumCardsPerHand() { return min_cards_per_hand_; }

SIN Dealer::GetDeckSize() { return deck_size_; }

SIN Dealer::SetDeckSize(SIN card_count) {
  if (card_count < 1) return -1;
  deck_size_ = card_count;
}

SIN Dealer::DeckCount() { return deck_count_; }

SIN Dealer::SetNumDecks(SIN deck_count) {
  if (deck_count < 1) return -1;
  deck_count_ = deck_count;

  pack = Deck();
}

SIN Dealer::GetMaxNumCardsPerHand() { return max_cards_per_hand_; }

SIN Dealer::SetMinNumCardsPerHand(SIN card_count) {
  if (card_count < 1) return -1;
  min_cards_per_hand_ = card_count;
}

SIN Dealer::GetMaxNumCardsPerHand() { return max_cards_per_hand_; }

SIN Dealer::SetMinNumCardsPerHand(SIN card_count) {
  if (card_count < 1) return -1;
  min_cards_per_hand_ = card_count;
}

SIN Dealer::SetMaxNumCardsPerHand(SIN card_count) {
  if (card_count < min_cards_per_hand_) return -1;
  max_cards_per_hand_ = card_count;
}

void Dealer::AddPlayer(Player* newPlayer) { players.Add(newPlayer); }

SIN Dealer::RemovePlayer(const CHR* playerName) {
  for (SIN i = 0; i < players.Size(); ++i) {
    if (players[i]->Name() == playerName) {
      players.Remove(i);
      return i;
    }
  }
  return 0;
}

SIN Dealer::RemovePlayer(SIN playerNumber) {
  // Note: Arrays in C++ always start at element 0 (ie.e players[0])
  if (playerNumber < 0) return -1;

  if (playerNumber >= players.Size()) return 1;

  players.Remove(playerNumber);
  return true;
}

Player* Dealer::GetPlayer(SIN playerNumber) {
  if (playerNumber < 0 || playerNumber > players.Size()) return nullptr;

  return players[playerNumber];
}

Deck& Dealer::GetPack() { return pack_; }

CardStack& Dealer::GetStock() { return stock_; }

SIN Dealer::GetPotTotal() { return pot_total_; }

void Dealer::SetPotTotal(SIN pot_total) {
  if (pot_total < 0) return;
  pot_total_ = pot_total;
}
void Dealer::AddToPot(SIN points) {
  if (points < 0) return;
  pot_total_ += points;
}

SIN Dealer::GetStartingAnte() { return starting_ante_; }

void Dealer::SetStartingAnte(SIN newAnte) {
  if (newAnte < 0) return;
  starting_ante_ = newAnte;
}

SIN Dealer::GetAnte() { return ante_; }

void Dealer::SetAnte(SIN newAnte) {
  if (newAnte < 0) return;
  ante_ = newAnte;
}

SIN Dealer::GetMinBet() { return min_bet_; }

void Dealer::SetMinBet(SIN value) {
  if (value < 0) return;
  min_bet_ = value;
}
SIN Dealer::GetMaxPlayers() { return max_players_; }

void Dealer::SetMaxPlayers(SIN max_players) {
  if (max_players < 0) return;
  max_players_ = max_players;
}

void Dealer::StartNewGame() {
  stock = CardStack(pack);
  stock.Shuffle();
  Redeal();
}

void Dealer::Redeal() {
  for (Player* currentPlayer : players)
    currentPlayer->dealHand(Hand(stock, 2, Deck::defaultNumCardsWithJokers));
}

} }  //< namespace kabuki
