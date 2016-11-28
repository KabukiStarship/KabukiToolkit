/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/MIDIButton.hpp
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
#include "AVControl.hpp"

namespace _Dev { namespace Controls {

/** A controller for MIDI signals.
    
 */
class _KabukiSDK MIDIControl : public AVControl
{
    public:

    static const int NumChannels = 16;              //< The number of MIDI channels.

    MIDIControl  (const char* &newLabel = "", int newCC = 0, int newChannel = 0, int initValue = 0, int newMinValue = 0,
        int newMaxValue = 127, int newWordSize = 7, int newAVControlType = AVControl::MIDIControl);
    //< Constructor.
    
    MIDIControl  (const MIDIControl& O);
    //< Copy contructor.
    
    virtual ~MIDIControl () {}
    //< Virtual destructor.

    int cc () const;
    //< Gets th MIDI control change  (CC) parameter.

    void setCC  (int value);
    //< Sets the control change  (CC) parameter.

    void setMinMaxValues  (int newMin, int newMax) override;
    /*< Sets the min and max values. */
    
    void setMinValue  (int value) override;
    //< Sets the min value to the value.
    
    void setMaxValue  (int value) override;
    //< Sets the max value to the value.

    virtual void trigger ();
    //< Triggers the AVControl to fire.

    virtual const char* headerString () const;
    //< Gets th header for toStringRow ().
    
    virtual const char* toStringRow () const;
    //< Gets a column of the values without the labels.
    
    virtual const char* Do  (const char* Query, byte index, Roombot* Bot);
    /*< Inter-process oproutines. */

    private:

    uint16_t cc;    //< The control change  (CC) parameter.
};

#if DEBUG
/** Unit test for the DMXControl class _KabukiSDK */
class _KabukiSDK MIDIControlTests : public UnitTest
{
    public:

    MIDIControlTests () : UnitTest ("Testing Controls::MIDIControl\n" + ConsoleLine ('~')) {}

    void runTest ()
    {
        MIDIControl controlA ("MIDI Control A");
        LogMessage  (controlA.ToString ());

        beginTest ("Testing setCC ()");
        controlA.setCC  (127);
        expect  (controlA.cc () = =  127);
        controlA.setCC  (128);
        expect  (controlA.cc () = =  127);
        controlA.setCC (-1);
        LogMessage ("controlA:\n" + controlA.ToString ());
        expect  (controlA.cc () = =  0);
        LogMessage ("Done testing Controls::MIDIControl class _KabukiSDK. :-)\n");
    }
};
static MIDIControlTests testUnit_MIDIControl;
#endif // DEBUG

}   //< namespace Controls
}   //< namespace _Dev

