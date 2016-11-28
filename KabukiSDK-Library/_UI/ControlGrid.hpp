/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/ControlGrid.hpp
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
#include "ControlArray.hpp"

namespace _UI { namespace Controls {

/** A grid of Controls.
    Each AVControl Layer on the Symmetry Live can either have 8 pots or encoders, or can have 4 pots and 4 encoders.
    This class _KabukiSDK helps us swap the values out quickly and efficiently.

    A ControlGrid must have the option of being bifurcated.
*/
class _KabukiSDK ControlGrid
{
    public:

    static const int MinNumRows = 1,                    //< The min number of rows.
        MinNumColumns = 2,                              //< The min number of columns.
        MaxNumRows    = ControlArray::MaxNumElements,   //< The max number of rows.
        MaxNumColumns = ControlArray::MaxNumElements;   //< The max number of columns.

    ControlGrid  (int newNumColumns = 8, int newNumRows = 6);
    /*< Default constructor. */
    
    ControlGrid  (const ControlGrid& other);
    //< Copy constructor.
    
    virtual ~ControlGrid ();
    //< Virtual Destructor.

    int GetNumRows () const;
    //< Gets th number of rows.
    
    int GetNumColumns () const;
    //< Gets th number of columns.

    void SetControl  (int Column, int Row, AVControl* NewKnob);
    /*< Sets the pointer to knobs[index] pointer to the newKnob. */
    
    ControlArray* GetRow  (int Row);
    /*< Gets th row at the given index.
        @return Gets nullptr if the index is invalid. */
    
    void Print (I2P::Terminal& Slot);
    /*< Prints this object to a terminal. */
    
    private:

    int numRows,            //< The number of rows.
        numColumns;         //< The number of columns.

    ControlArray* rows;     //< The rows of control array columns.
};

#if DEBUG
class _KabukiSDK ControlGridTests : public UnitTest
{
    public:
    ControlGridTests () : UnitTest ("Testing Controls::ControlGrid class _KabukiSDK.") {}

    void runTest ()
    {
        auto controlGrid = ControlGrid  (5, 2);

        beginTest ("Testing const char* ToString ():\n");
        LogMessage  (controlGrid.ToString ());

        beginTest ("Testing setControl ()");

        auto testControl0_0 = DMXControl  ("DMX Control 1");
        auto testControl1_0 = MIDIControl ("MIDI Control 1");
        auto testControl2_0 = DMXButton   ("DMX Button 1");
        auto testControl3_0 = MIDIButton  ("MIDI Button 1");
        auto testControl4_0 = MacroButton ("Macro Button 1");

        auto testControl0_1 = DMXControl  ("DMX Control 2");
        auto testControl1_1 = MIDIControl ("MIDI Control 2");
        auto testControl2_1 = DMXButton   ("DMX Button 2");
        auto testControl3_1 = MIDIButton  ("MIDI Button 2");
        auto testControl4_1 = MacroButton ("Macro Button 2");

        controlGrid.setControl  (0, 0, &testControl0_0);
        controlGrid.setControl  (1, 0, &testControl1_0);
        controlGrid.setControl  (2, 0, &testControl2_0);
        controlGrid.setControl  (3, 0, &testControl3_0);
        controlGrid.setControl  (4, 0, &testControl4_0);

        controlGrid.setControl  (0, 1, &testControl0_1);
        controlGrid.setControl  (1, 1, &testControl1_1);
        controlGrid.setControl  (2, 1, &testControl2_1);
        controlGrid.setControl  (3, 1, &testControl3_1);
        controlGrid.setControl  (4, 1, &testControl4_1);

        LogMessage  (controlGrid.ToString ());


        LogMessage ("Done testing Controls::ControlGrid class _KabukiSDK! :-)");
    }
};
static ControlGridTests testUnit_ControlGrid;
#endif // DEBUG
}   //< namespace Controls
}   //< namespace _UI

