/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_/EventSequence.hpp
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

#include "IEvent.hpp"

namespace _ {

class EventNode
/*< An IEvent node in a linear linked list. */
{
    public:
    
    EventNode (IEvent* nodeEvent);
    /*< Constructs an event node with the given IEvent. */

    EventNode* getNext () = 0;
    /*< Gets the next IEvent */

    timestamp_t getEventTime () = 0;
    /*< Gets the timestamp of when the event occurred. */
    
    IEvent* getEvent ();
    /*< Gets the event this this node triggers. */

    void trigger ();
    /*< Triggers the event. */

    inline void print (I2P::Terminal& slot) = 0;
    /*< Prints this object to the terminal. */
    
    private:
    
    IEvent* event;   //< The event this node triggers.
};

class EventSequence : public _::IEvent
/** A sequence of events stored as a linear linked list. */
{
    public:
    
    EventSequence ();
    /*< Constructs an empty event sequence. */

    virtual timestamp_t getEventTime () override;
    /*< Gets the timestamp of when the event occurred. */

    virtual void trigger (I2P::IObject* source) override;
    /*< Triggers the event. */

    inline void print (I2P::Terminal& slot);
    /*< Prints this object to the terminal. */

    private:

    EventNode* head;            //< Head of the linear linked list of IEventNode(s).
    timestamp_t eventTime;      //< The time in microseconds the event occurred.
};

}   //< namespace _
