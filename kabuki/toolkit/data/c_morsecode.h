/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki_toolkit/data/c_codemore.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#if SEAM >= KABUKI_TOOLKIT_DATA_1
#if SEAM == KABUKI_TOOLKIT_DATA_1
#ifndef INCLUDED_KABUKI_TEK_UTILS_MORSECODE
#define INCLUDED_KABUKI_TEK_UTILS_MORSECODE 1

namespace _ {

/* Gets the Morse code for the given CH1. */
const CH1* ToMorseCode (CH1 value);

}       //< _utils
#endif
#endif
