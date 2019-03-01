/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /firmware/c_ledvumeterarray.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2014-19 (C) Cale Jamison McCollough <<cale@astartup.net>>. 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain 
one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_LEDS_LEDVUMETERARAY
#define INCLUDED_KABUKI_FEATURE_TEK_LEDS_LEDVUMETERARAY 1

namespace _ {

/* An array of LEDs used for a VU Meter like on a stereo. */
template <SI4 kNumSegments>
class LedVuMeterArray {
 public:
  /* Simple default constructor. */
  LedVuMeterArray() {}

  /* Gets the number of segments. */
  static SI4 GetNumSegments() { return kNumSegments; }

  /* Prints this object to a console. */
  void Print() {}
};
}  // namespace _
#endif  //< INCLUDED_KABUKI_FEATURE_TEK_LEDS_LEDVUMETERARAY
