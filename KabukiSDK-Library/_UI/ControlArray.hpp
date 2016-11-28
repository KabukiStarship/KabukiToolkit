/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/ControlArray.hpp
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

#include <FreeI2P.hpp>
#include <KabukiSDK-Config.hpp>
#include "AVControl.hpp"
#include "MIDIControl.hpp"
#include "DMXControl.hpp"
#include "MIDIButton.hpp"
#include "DMXButton.hpp"
#include "MacroButton.hpp"

namespace _Dev { namespace Controls {

/** A row of AVControl  (s). */
class _KabukiSDK ControlArray
{
    public:

    static const int MinNumElements = 2,                 //< The minimum number of columns.
        MaxNumElements = 256;                           //< The minimum number of columns.

    /** Default constructor. */
    ControlArray  (int newNumControls = MinNumElements);

    /** Constructor creates a row with pointers to the newControls. */
    ControlArray  (const std::vector<AVControl*>& newControls);

    ControlArray  (const ControlArray& other);
    //< Copy constrcutor.
    
    ~ControlArray ();
    //< Destructor.

    void AddControl  (AVControl* newControl);
    //< Adds a new control to the array.
    
    int SetControl  (int index , AVControl* newControl);
    //< Adds a new control to the array.
    
    AVControl* RemoveControl  (int index);
    //< Deletes the AVControl at the given index.
    
    AVControl* GetControl  (int index);
    /*< Gets th control at the given index.
        @return Gets nullptr if the index if out of bounds. */
    int GetNumControls () const;
    //< Gets th number of AVControl  (s) in the row.
    
    void Print (I2P::Terminal& Slot);
    /*< Prints this object to a terminal. */

    private:

    int numControls;                                   //< The number of controls in this row.

    AVControl** controls;                                //< And array of AVControl pointers.
};

#if DEBUG
class _KabukiSDK ControlArrayTests : public UnitTest
{
    public:

    ControlArrayTests () : UnitTest ("Controls::ControlArray class _KabukiSDK\n" + ConsoleLine ('-') + "\n") {}

    void runTest ()
    {
        auto buttonA = ControlArray ();

        beginTest ("Testing const char* ToString ()...");
        LogMessage  (buttonA.ToString ());

        auto testControl1 = DMXControl ("Control 1", 50, 33);
        auto testControl2 = MIDIControl ("Control 2", 11, 102);

        beginTest ("testing void setControl  (Control*)");

        buttonA.setControl  (0, &testControl1);
        buttonA.setControl  (1, &testControl2);

        LogMessage ("Added 2 controls to buttonA:\n" + buttonA.ToString ());

        auto testControl3 = DMXControl ("Control 3", 27, 66);
        auto testControl4 = MIDIControl ("Control 4", 62, 24);

        buttonA.addControl (&testControl3);
        buttonA.addControl (&testControl4);

        LogMessage ("Attempted to add 2 more controls buttonA:\n" + buttonA.ToString ());

        auto testControl5 = DMXButton ("Control 5", 27, 66);
        auto testControl6 = MIDIButton ("Control 6", 62, 24);
        auto testControl7 = MacroButton ("Control 7");
        testControl7.add (&testControl1);
        testControl7.add (&testControl2);
        testControl7.add (&testControl3);
        testControl7.add (&testControl4);
        testControl7.add (&testControl5);
        testControl7.add (&testControl6);

        buttonA.addControl (&testControl5);
        buttonA.addControl (&testControl6);
        buttonA.addControl (&testControl7);

        LogMessage ("Attempted to add some buttons:\n" + buttonA.ToString ());

        LogMessage ("Controls::ControlArray tests completed successfully. :-)");
    }
};
static ControlArrayTests testUnit_ControlArray;
#endif // DEBUG
}   //< namespace Controls
}   //< namespace _Dev

