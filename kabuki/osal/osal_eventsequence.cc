/* Kabuki Toolkit
@file    /osal/osal_eventsequence.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

#include "event_sequence.h"

namespace _ {

EventNode::EventNode(IEvent* nodeEvent)
:   iEvent(nodeEvent)
{
     
}

EventNode* EventNode::getNext()
{
    return next;
}

IEvent* EventNode::getEvent()
{
    return iEvent;
}

void EventNode::setEvent(IEvent* newEvent)
{
    iEvent = newEvent;
}

void EventNode::trigger(EventSequence* source)
{
    iEvent->trigger();
}

void EventNode::query(Expression& io)
{
    if(iEvent == nullptr)
    {
        if(next == nullptr) return;
        next->query(io);
    }
    iEvent->query(io);
    if(next == nullptr) return;
    next->query(io);
}

EventSequence::EventSequence()
{

}

void EventSequence::trigger()
{
    if(head == nullptr) return;

    head->trigger(this);
}

void EventSequence::query(Expression& io)
{
    if(head == nullptr) return;
    
    io << eventTime;

    head->query(io);
    EventNode* next = head->getNext();
    if(next != nullptr) next->query(io);
}

}       //< namespace _
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
