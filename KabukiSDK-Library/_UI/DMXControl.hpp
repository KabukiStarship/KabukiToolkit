/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/DMXControl.hpp
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

namespace _UI { namespace Controls {

/** A DMX Control.
 */
class _KabukiSDK DMXControl : public AVControl
{
    public:

    static const int NumChannels = 512;             //< The number of DMX512 channels.

    /** Default constructor. */
    DMXControl  (const char* &newLabel = "", int newChannel = 0, int initValue = 0, int newMinValue = 0,
        int newMaxValue = 255, int newWordSize = 8, int newAVControlType = AVControl::DMXControl);
    DMXControl  (const DMXControl& other);           //< Copy contructor.
    ~DMXControl () {}                               //< Virtual destructor.

    virtual void trigger () override {}             //< Triggers this DMX event to send out the target device.
    
    void Print (I2P::Terminal& Slot);
    /*< Prints this object to a terminal. */
};

#if DEBUG
/** Unit test for the DMXControl class _KabukiSDK. */
class _KabukiSDK DMXControlTests : public UnitTest
{
    public:
    
    DMXControlTests () : UnitTest ("Controls::DMXControl") {}

    void runTest () 
    {
        LogMessage  (ConsoleLine ('-'));
        DMXControl controlA ("DMX Control A");

        LogMessage ("Printing controlA.ToString ()\n" + controlA.ToString ());

        LogMessage ("Testing copy constructor\n");
        DMXControl controlB  (controlA);
        LogMessage ("Printing controlB.ToString ()\n" + controlB.ToString ());
        LogMessage ("Testing int Compare  (const Control&)");

        expect  (controlA.Compare  (controlB) == 0);
        int CompareValue = controlA.Compare  (controlB);
        LogMessage ("Testing int Compare  (const Control&): " + CompareValue);
        expect  (CompareValue == 0);

        beginTest ("Testing valid inputs...");

        controlA = DMXControl ("", 1, 1, 0, 255, 8);

        LogMessage ("Printing controlA.ToString ()...\n" + controlA.ToString ());

        controlA.setLabel ("DMX Control B");
        expect  (controlA.label () == "DMX Control B");
        controlA.setInitValue  (35);
        LogMessage  (controlA.ToString ());
        expect  (controlA.initValue () == 35);
        controlA.setLSBValue  (66);
        expect  (controlA.lSBValue () == 66);
        controlA.setMaxValue  (245);
        expect  (controlA.maxValue () == 245);
        controlA.setMinValue  (70);
        expect  (controlA.minValue () == 70);

        beginTest ("Retesting copy constructor");

        controlB = DMXControl  (controlA);
        CompareValue = controlA.Compare  (controlB);
        expect (!CompareValue);

        beginTest ("Testing invalid input...");

        controlA.setWordSize  (5);
        LogMessage ("controlA.wordSize (): " + const char*  (controlA.wordSize ()));
        expect  (controlA.wordSize () == 7);
        controlA.setChannel  (555);
        expect  (controlA.channel () == DMXControl::NumChannels);
        controlA.setChannel (-5);
        expect  (controlA.channel () == 0);
        controlA.setChannel  (1);
        expect  (controlA.channel () == 1);

        LogMessage ("Done testing DMXControl class _KabukiSDK");
    }
};
static DMXControlTests testUnit_DMXControl;
#endif // DEBUG
}   //< namespace Controls
}   //< namespace _Dev

