/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/00_card.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>

#include "t_string.h"

#if SEAM == KABUKI_CARDS_DECK
#include "module_debug.inl"
#else
#include "module_release.inl"
#endif

using namespace _;

namespace kabuki { namespace cards {

inline const CH1* Uniprinter(const CH1* args) {
#if SEAM >= SCRIPT2_UNIPRINTER
  A_TEST_BEGIN;

  Deck deck();

  D_COUT(deck.PrintTo<COut>());

  for (SIN i = 0; i < 7; ++i) {
    D_COUT("Creating " + Deck::CardSuitCultureStrings[i] + " Deck...");
    Deck testDeck((Deck::Culture)i, Deck::kAcesLow,
                  Deck::kDoesNotContainJokers);
    D_COUT(testDeck.PrintTo<COut>(cout));
  }
  // D_COUT (testDeck.tostring ());
#endif
  return 0;
}
} }  //< namespace kabuki
