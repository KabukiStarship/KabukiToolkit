/* Kabuki Toolkit @version 0.x_
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/math/t_point2d.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_FEATURES_MATH_1
#ifndef KABUKI_FEATURES_MATH_SOFTMAX_T
#define KABUKI_FEATURES_MATH_SOFTMAX_T 1

namespace _ {

template<typename F, typename U>
void TSoftmax (F* x, U count, F* y) {
    DASSERT (x);
    DASSERT (x_count > 0);
    DASSERT (y);
    F sum_of_e_j_to_the_x = 0.0;
    SIW delta_yx = y - x;
    for (F* x_cursor = x; x_cursor <= x + count; ++x_cursor) {
        F e_j_to_the_x = exp (*x_cursor);
        sum_of_e_j_to_the_x += e_j_to_the_x;
        *(x_cursor + delta_yx) = e_j_to_the_x;
    }
    for (F* y_cursor = y; y_cursor <= y + cursor; ++y_cursor) {
        *y_cursor = *y_cursor / sum_of_e_j_to_the_x;
    }
}

}       //< namespace _
#endif
#endif
