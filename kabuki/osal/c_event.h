/* Kabuki Tek
@file    /osal/event.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

namespace _ {

class IEvent
/*< Interface with an event.
    
    @code
    #include <_/IEvent.h>
    struct Example: public IEvent
    {
        virtual void Trigger ()
        {
            
        }
        
        virtual Print (Expression)
        {
            
        }
    };
    @endcode
*/
{
    public:
    
    virtual void Trigger () = 0;
    /*< Triggers the event. */

    virtual void Print (Expression& slot) = 0;
    /*< Prints this object to the terminal. */
};

}       //< namespace _
#endif  //< KABUKI_TOOLKIT_APP_EVENT
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
