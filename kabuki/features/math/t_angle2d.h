/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/math/t_angle2d.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_FEATURES_MATH_1
#ifndef KABUKI_FEATURES_MATH_ANGLE_T
#define KABUKI_FEATURES_MATH_ANGLE_T 1

namespace _ {

/* An angle between two lines stored in radians. */
template<typename T>
class TAngle2D
{
    public:

    T rads;        //< The angle stored in radians.

    /* Constructor. */
    Angle2D (T value = 0) {
        
    }

    /* Converts the angle to degrees. */
    T GetDegs () {
        return (rads * 180.0) / pi;
    }

    /* Sets the angle to the new value in degrees. */
    void SetDegs (T angle) {
        rads = angle * Pi<T> ();
    }

    /* Prints this object to the terminal. */
    inline void Print (Expression& io) {
    }
};

#if WORD_SIZE == 32
using Angle = Angle<FP4>;
#elif WORD_SIZE == 64
using Angle = Angle<double>;
#endif

}       //< namespace _
#endif
#endif
