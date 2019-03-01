/* Kabuki Toolkit
@file    /osal/app.h
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
    
App::App (SI4 initWidth, SI4 initHeight)
{
    if (initWidth < MinWidthOrHeight)   initWidth = MinWidthOrHeight;
    else if (initWidth > MaxWidth)      initWidth = MaxWidth;

    if (initHeight < MinWidthOrHeight)  initHeight = MinWidthOrHeight;
    else if (initHeight > MaxWidth)     initHeight = MaxWidth;
}

uint32_t App::getUID { return uid; }

SI4 App::activateWindow (SI4 newWindowIndex)
{
    return windows.select (newWindowIndex);
}

SI4 App::activateWindow (Window& newWindow)
{
    if (newWindow == nullptr)
        return -1;

    activeWindow = newWindow;

    return 0;
}

ProcessTree& getWindows { return windows; }

SI4 App::show  ()
{
    return 0;
}

SI4 App::hide  ()
{
    return 0;
}

SI4 App::close ()
{
    return 0;
}

_G.::Cell& App::getCell ()
{
    return nullptr;
}

void App::draw (_G::Cell& c)
{

}

void App::redraw ()
{

}

void App::print ()
{
    printf ("");
}

}       //< namespace _
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
