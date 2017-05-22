/** Kabuki Theater
    @file    /.../Source/KabukiTheater-Impl/_HMI/TESTS/Module.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <https://calemccollough.github.io>

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
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

namespace _HMI {

#if _DebugKabukiTheater
class _KabukiTheater_ MacroButtonTests : public UnitTest
{
    public:

    MacroButtonTests () : UnitTest ("Testing Controls::MacroButton class _KabukiTheater_:\n" + ConsoleLine ('~')) {}

    void runTest ()
    {
        auto macroA = MacroButton ("Macro Button A");

        beginTest ("Testing const char* print (I2P::Terminal& slot)...");
        logMessage  (macroA.print (I2P::Terminal& slot));
        beginTest ("Testing add  (AVControl*)");
        macroA.add  (new DMXControl  ("Macro 1"));
        macroA.add  (new MIDIControl ("Macro 2"));
        macroA.add  (new DMXButton   ("Macro 3"));
        macroA.add  (new MIDIButton  ("Macro 4"));
        logMessage ("Added " + const char*  (macroA.numControls ()) + " test controls.\n" + macroA.print (I2P::Terminal& slot));
        beginTest ("Testing void trigger ()");
        macroA.trigger ();
        beginTest ("Testing AVControl* remove  (index);");
    }
};
static MacroButtonTests testUnit_MacroButton;
#endif  //< _DebugKabukiTheater
    
}   //< namespace _HMI