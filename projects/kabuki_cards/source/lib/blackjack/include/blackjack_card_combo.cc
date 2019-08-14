/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/kabuki_cards/source/ib/blackjack/blackjack_card_combo.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */
#include "BlackjackCardCombo.h"

using namespace kabuki_cards;

BlackjackCardCombo::BlackjackCardCombo (CardStack& copyStack, int acesHighLowORNA) :
    CardCombo (copyStack, acesHighLowORNA)
{
    setValues (0, 1, 0, 1, acesHighLowORNA);
}

int BlackjackCardCombo::getPointValue ()
{
    int total = 0;
    Card* currentCard;
    for (int i = 0; i < GetNumCards (); ++i)
    {
        int currentPipValue = currentCard->getPipValue ();

        if (currentPipValue == 1) // If its an ace.
        {
            if (getAcesHigh ())
                total += 10;
            else
                total += 1;
        }
        else
            total += currentCard->getPointValue (); //< Then just add the point to to the score like normal.
    }
    return total;
}
