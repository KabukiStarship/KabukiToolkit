/* Kabuki Toolkit
@file    /osal/comparable.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

#ifndef KABUKI_TEK_UTILS_COMPARABLE_H
#define KABUKI_TEK_UTILS_COMPARABLE_H

#include "config.h"

namespace _ {

/* Interface for a numerically comparable object. */
class Comparable
{
    public:

    /* Numerically compares this object to the other. */
    virtual SI4 compare (Comparable* o) = 0;
};

}       //< namespace _
#endif  //< KABUKI_TOOLKIT_APP_COMPARABLE
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
