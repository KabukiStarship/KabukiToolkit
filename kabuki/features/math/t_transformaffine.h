/* Kabuki Toolkit @version 0.x_
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/math/t_transformaffine.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_FEATURES_MATH_1
#ifndef KABUKI_FEATURES_MATH_TRANSFORMAFFINE_T
#define KABUKI_FEATURES_MATH_TRANSFORMAFFINE_T 1

namespace _ {

/* A 2D affine transformation. */
template<typename T>
class TransformAffine {
public:

  /* Constructs an unintialized object. */
  TransformAffine () {

  }

  /* Prints this object to the terminal. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    return o << "\nTransformAffine:";
  }
};

}       //< namespace _
#endif
#endif

