/* Kabuki Toolkit
@file    /osal/window_group.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

namespace _ {
    
class ProcessTree {
    public:

    ProcessTree ();
    ProcessTree (Window thisWindow);
    ProcessTree (TArray<Window> initWindows);
    uint32_t GetUID () { return uID; }

/* Gets and sets the maximum number of windows in this group */
    SI4 ProcessTree::GetMaxWindows () { return maxWindows; }

    void ProcessTree::SetMaxWindows (uint32_t value)
    {
        if (value < 0) return;
        maxWindows = value;
    }

    /*  */
    SI4 Select (SI4 windowNumber);

    SI4 GetNumWindows{ return numWindows; }

    /* Adds a newWindow to the group. */
    void AddWindow (Window newWindow);
    /* Returns a string representation of this object. */
    _::Printer& Print (_::Printer& print);

    private:

    uint32_t maxWindows;

};

}       //< namespace _
#endif  //< KABUKI_TOOLKIT_APP_GROUP
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
    