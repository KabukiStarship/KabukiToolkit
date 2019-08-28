/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /projects/kabuki_cards/include/player.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#ifndef KABUKI_CARDS_PLAYER_H
#define KABUKI_CARDS_PLAYER_H

#include <script2/t_strand.h>

#include "cardstack.h"
#include "hand.h"

namespace kabuki {
namespace cards {

class Player {
  AStrand<> name_;   //< Player's name.
  SIN win_count_,    //< Number of wins.
      point_count_;  //< Number of points.
  Hand hand_;        //< The cards in the player's hand.

 public:
  /* Default Constructor. */
  Player(const CHR* name = "You", SIN points_init = 10, BOL is_player = false);

  /* Does nothing. */
  virtual ~Player() {}

  /* Virtual function that determines if this Player plays, or passes. */
  virtual BOL PlayOrPass(Hand& other) = 0;

  /* Virtual function that performs a Player's turn. */
  virtual void PlayHand() = 0;

  /* Virtual function that performs the discard action.
  @return AStack<Card*>. */
  virtual Autoject Discard();

  /* Gets the name_. */
  const CHR* Name();

  /* Sets the name_ to the new name. */
  void SetName(const CHR* name);

  /* Returns the player's hand. */
  Hand& Hand();

  /* Sets the hand to the hand. */
  void SetHand(Hand& hand);

  /* Returns the point total. */
  SIN PointCount();

  /* Adds a specified point_count to the players point total.
  @return Returns 0 upon success, and -1 if point_count is less than 1. */
  SIN AddPoints(SIN num_points);

  /* Resets the win_count to 0. */
  void ResetWins();

  /* Returns the number of wins. */
  SIN WinCount();

  /* Adds a win to the players win_count. */
  void AddWin();

  /* Resets the number of wins to 0. */
  void DealHand(Hand& hand);

  /* Prints this object to the Printer. */
  template <typename Printer>
  Printer& PrintTo(Printer& o) {
    o << "Player: " << name << "\npoint_count: " << point_count
      << "\nnumWindows: " << win_count << "\n"
      << Linef("\n---");

    return o << hand.PrintTo<COut>(cout);
  }
};

}  // namespace cards
}  // namespace kabuki

#endif
