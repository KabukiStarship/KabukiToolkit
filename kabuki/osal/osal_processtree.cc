/* Kabuki Toolkit
@file    /osal/osal_processtree.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1


#include "process_tree.h"

namespace _ {
    
ProcessTree::ProcessTree ()
{
    maxWindows = DefaultMaxWindows;
    numWindows = 0;
}

ProcessTree::ProcessTree (Window thisWindow)
{
    maxWindows = DefaultMaxWindows;
    numWindows = 1;
    windows.push_back (thisWindow);
}

ProcessTree::ProcessTree (TArray<Window> initWindows)
{
    windows = initWindows;
}

uint32_t ProcessTree::GetUID () { return uID; }

/* Gets and sets the maximum number of windows in this group */
SI4 ProcessTree::GetMaxWindows () { return maxWindows; }

void ProcessTree::SetMaxWindows (SI4 Value)
{
    if (value < 0) return;
    maxWindows = value;
}

/*  */
SI4 ProcessTree::Select (SI4 windowNumber)
{
    if (windowNumber < 0) return -1;
    if (windowNumber >= numWindows) return 0;
    return windowNumber;
}

/* Returns the number of windows in this group. */
SI4 ProcessTree::GetNumWindows { return numWindows; }

/* Adds a newWindow to the group. */
void ProcessTree::AddWindow (Window newWindow) {
}

/* Returns a string representation of this object. */
_::UTF& ProcessTree::Print (_::UTF& print) {
    return "";
}

}       //< namespace _
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
