/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/math/t_exceptioninvalidpath.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_FEATURES_MATH_1
#ifndef KABUKI_FEATURES_MATH_EXCEPTIONPATHINVALID_T
#define KABUKI_FEATURES_MATH_EXCEPTIONPATHINVALID_T 1

namespace _ { 

template<typename T>
class InvalidPathException: public runtime_error  {
 public:
  InvalidPathException (T x, T y)
  : runtime_error( "Invalid path") {}
};

}       //< namespace _
#endif
#endif
