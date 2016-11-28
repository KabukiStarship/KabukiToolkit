/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/ButtonScroller.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright  (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved  (R).

        Licensed under the Apache License, Version 2.0  (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/
 
#pragma once

#include <KabukiSDK-Config.hpp>
#include <FreeI2P.hpp>
#include "Label.hpp"
#include "ButtonControl.hpp"

namespace _Dev { namespace Controls {

/** A scrollable array Button  (s). */
class _KabukiSDK ButtonScroller, public Label
{
    public:

    static const int DefaultNumVisibleButtons = 5;  //< The default number of visible numbers.

    ButtonScroller  (const char* newLabel = "", int newArraySize = DefaultNumVisibleButtons);
    //< Default constructor.
    
    ButtonScroller  (const ButtonScroller& other);
    //< Copy constructor.

    std::vector<ButtonControl*>& buttons ();
    //< Gets the array of buttons.

    int GetNumButtons () const;
    //< Gets the number of buttons in the array.

    int GetNumVisibleButtons () const;
    //< Gets the number of visible buttons.
    
    int GetCurrentIndex () const;
    //< Gets the index of the first visible button.

    void SetNumVisibleButtons  (int value);
    //< Sets the number of visible buttons to the new value.

    void RemoveButton  (int thisIndex);
    //< Removes the button at the given index from the array.

    void ScrollUp ();
    //< Scrolls up the list.
    
    void ScrollDown ();
    //< Scrolls down the list.

    void ScrollUp  (int numNodes);
    //< Scrolls up the list.
    
    void ScrollDown  (int numNodes);
    //< Scrolls down the list.

    void ScrollPageUp ();
    //< Scrolls up one page
    
    void ScrollPageDown ();
    //< Scrolls down one page

    int Press  (int index);
    //< Presses the Button at the specified index.
    
    void Print (I2P::Terminal& Slot);
    /*< Prints this object to a terminal. */

    private:

    int currentIndex,                   //< The index of the first visible button.
        numVisibleButtons;              //< The number of physical buttons.

    std::vector<ButtonControl*> buttons;      //< The array of buttons.
};
}   //< namespace Controls
}   //< namespace _Dev

