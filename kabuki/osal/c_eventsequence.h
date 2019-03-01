/* Kabuki Tek
@file    /osal/c_eventsequence.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "Event.h"

namespace _ {

class EventSequence;

/*U An Event node in a linear linked list. */
class EventNode
{
    public:
    
    /* Constructs an event node with the given Event. */
    EventNode (Event* nodeEvent);

    /* Gets the next Event */
    EventNode* Next ();
    
    /* Gets the event this node triggers. */
    Event* GetEvent ();

    /* Sets the event this node triggers. */
    void SetEvent (Event* newEvent);

    /* Triggers the event. */
    void Trigger (EventSequence* source);

    /* Prints this object to the terminal. */
    inline void Print (Expr& slot);
    
    private:
    
    Event* iEvent;      //< The event this node triggers.

    EventNode* next;    //< The next node in the LLL.
};

/* A sequence of events stored as a linear linked list. */
class EventSequence : public _::Event
{
    public:
    
    /* Constructs an empty event sequence. */
    EventSequence ();

    /* Triggers the event. */
    void Trigger ();

    /* Prints this object to the terminal. */
    inline void Print (Expr& slot);

    private:

    EventNode* head;            //< Head of the linear linked list of EventNode(s).
    timestamp_t eventTime;      //< The time in microseconds the event occurred.
};

}   //<  _
