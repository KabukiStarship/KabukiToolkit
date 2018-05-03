/** Kabuki Toolkit
    @file    ~/source/hmi/event.h
    @author  Cale McCollough <calemccollough.github.io>
    @license Copyright (C) 2014-2017 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once
#include <stdafx.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

#ifndef HEADER_FOR_KABUKI_TOOLKIT_HMI_EVENT
#define HEADER_FOR_KABUKI_TOOLKIT_HMI_EVENT

#include "config.h"

namespace kt { namespace hmi {

/** A event with a timestamp.
    An example of an Event is typically like a Control or menu function.
 */
class Event {
    public:

    /** Default constructor. */
    Event ();
    
    /** Virtual destructor. */
    virtual ~Event ();

    /** gets the timestamp of the Event. */
    timestamp_t GetTimestamp ();

    /** Triggers the event. */
    virtual void Trigger () = 0;
    
    /** Prints this object to a string. */
    virtual _::Printer& Print (_::Printer& print) const = 0;

    private:

    timestamp_t timestamp;    //< Event timestamp in microseconds.
};

}       //< namespace hmi
}       //< namespace toolkit
}       //< namespace kabuki
#endif  //< HEADER_FOR_KABUKI_TOOLKIT_HMI_EVENT
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1