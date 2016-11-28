/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Library/KabukiSDK-Impl/_/EventSequence.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

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


#include <_/EventSequence.hpp>

namespace _ {

EventSequence::EventSequence ()
{

}

timestamp_t EventSequence::getEventTime ()
{
    return 0;
}

void EventSequence::Trigger (I2P::IObject* Source)
{
    if (head == nullptr) return;
    head->Trigger (Source);
}

void EventSequence::Print (I2P::Terminal& Slot)
{
    if (head == nullptr) return;
    
    head->Print (Slot);
    EventNode* next = head->GetNext ();
    if (next != nullptr) next->Print (Slot);
}

}   //< namespace _
