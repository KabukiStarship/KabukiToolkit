/* Kabuki Toolkit @version 0.x_
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/math/t_polar2d.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_FEATURES_MATH_1
#ifndef KABUKI_FEATURES_MATH_POLAR2D_T
#define KABUKI_FEATURES_MATH_POLAR2D_T 1

namespace _ {

/* A point in a polar coordinate system. */
template<typename Float>
class TPolar2D
{
    public:

    Float angle,  //< The angle in radians.
          radius; //< The radius in abstract units.

    /* Constructor initializes with given values
        @param  thisAngle   The angle of the coordinate.
        @param  thisNumber  The Magnitude of the coordinate.
    */
    TPolar2D (FP4 angle, FP4 radius) :
        angle (angle),
        radius (radius) {
    }

    /* Calculates the Magnitude of the . */
    T Magnitude () {
        T angle = angle,
            radius = radius;
        return Sqrt (angle * angle + radius * radius);
    }

    /* Prints this object to the terminal. */
    Printer& Print (Printer& printer) {

    }
};

}       //< namespace _
#endif
#endif

