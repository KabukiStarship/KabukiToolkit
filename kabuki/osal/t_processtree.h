/* Kabuki Toolkit
@file    $kabuki-toolkit/kabuki_toolkit/app/process_tree.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

#include "app.h"

namespace _ {

/* Class that stores a group of app.Window objects. */
class KTH_APP_API ProcessTree
{
    public:
    
    static const SI4 DefaultMaxWindows = 1024;

    /* Default constructor. **/
    ProcessTree ();

    /* Constructor initializes with a single window. */
    ProcessTree (Window& this_window);

    /* Constructor initializes with an array of windows. */
    ProcessTree (TArray<Window> init_windows);

    /* Returns the UID of this Group. */
    uint32_t GetUID ();

    /* Gets and sets the maximum number of windows in this group */
    SI4 GetMaxWindows ();
    
    /* Gets and sets the maximum number of windows in this group */
    void SetMaxWindows (SI4 value);

    /* . */
    SI4 Select (SI4 window_number);

    /* Returns the number of windows in this group. */
    SI4 GetNumWindows ();

    /* Adds a newWindow to the group. */
    void AddWindow (Window newWindow);

    /* Prints this object to the stdout. */
    void Print ();

    private:

    uint32_t uid_;                  //< The UID of this Group.
    SI4 num_windows_,           //< The number of windows in this group.
        max_windows_;           //< The maximum number of windows allowed in a group.
    TArray<Window> windows_;    //< The Window (s) in this group. 
};

}       //< namespace _
#endif  //< KABUKI_TOOLKIT_APP_PROCESSTREE
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

