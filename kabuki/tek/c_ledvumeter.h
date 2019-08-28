/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /c_ledvumeter.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_LED_VU_METER
#define INCLUDED_KABUKI_FEATURE_TEK_LED_VU_METER 1

namespace _ {

/* An LED VU Meter
    i.e. volume bar. */
template <UI1 kNumSegments>
class LedVuMeter {
 public:
  /* Default constructor initializes LEDs in off state. */
  LedVuMeter();

  /* Prints this object to the console. */
  void Print();

 private:
  UI1 value;  //< The value of the VU meter.
};
}  // namespace _
#endif
