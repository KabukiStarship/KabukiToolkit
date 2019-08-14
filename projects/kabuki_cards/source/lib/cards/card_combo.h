/** Kabuki Card Games
    @file    ~/source/kabuki/cards/include/card_combo.h
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

#ifndef KABUKI_CARDS_CARDCOMBO_H
#define KABUKI_CARDS_CARDCOMBO_H

#include "CardStack.h"

namespace KabukiCardGames {
    
/** Class that represents a CardStack point combination in a playing card game.
    There are two major things that will effect a combination's rank besides suit rank; the presence of jokers, and if aces are high or low.
*/
class CardCombo : public CardStack { 
public:

    /** Default constructor. */
    CardCombo (CardStack& copyStack, int aces_high, int thisJokerPipValue1 = 0, int thisJokerSuitValue1 = 1, 
        int thisJokerPipValue2 = 0, int thisJokerSuitValue2 = 2);

    /** Function sets values to the new values. */
    void SetValues (int aces_high, int thisJokerPipValue1 = 0, int thisJokerSuitValue1 = 1, 
                    int thisJokerPipValue2 = 0, int thisJokerSuitValue2 = 2);

    /** Function that returns the point value with the wild card and ace values. */
    virtual int GetPointValue () = 0;

    /** Returns the jokerPipValue1. */
    int GetJokerPipValue1 ();
    
    /** Sets the jokerPipValue1 to the value. */
    int SetJokerPipValue1 (int value);

    /** Returns the jokerSuitValue1. */
    int GetJokerSuitValue1 ();
    
    /** Sets the jokerSuitValue1 to the value. */
    int setJokerSuitValue1 (int value);

    /** Returns the jokerPipValue2. */
    int getJokerPipValue2 ();
    
    /** Sets the jokerPipValue2 to the value. */
    int setJokerPipValue2 (int value);

    /** Returns the jokerSuitValue2. */
    int getJokerSuitValue2 ();
    
    /** Sets the jokerSuitValue2 to the value. */
    int setJokerSuitValue2 (int value);

    /** Returns the jokerPipValue1. */
    int getAcesHigh ();
    
    /** Sets the jokerPipValue1 to the value. */
    int SetAcesHigh (int value);
    
private:

    int jokerPipValue1_,    //< The black joker wildcard pip value.
        jokerSuitValue1_,   //< The black joker wildcard suit value.
        jokerPipValue2_,    //< The red joker wildcard pip value.
        jokerSuitValue2_,   //< The red joker wildcard suit value.
        acesHigh_;          //< Flag represents if aces are high (>1) or low (0), or either (<0).
};

}       //< namespace cards
}       //< namespace kabuki

#endif  //< KABUKI_CARDS_CARDCOMBO_H
