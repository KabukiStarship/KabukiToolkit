/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /firmware/tek_micelectrolytic.cc
@author  Cale McCollough <https://calemccollough.github.io>
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain 
one at https://mozilla.org/MPL/2.0/. */

#include "c_micelectrolytic.h"

namespace _ {

ElectrolyticMic::ElectrolyticMic(PinName pin)
    : min_(0), max_(~0), input_(pin) {}

UI2 ElectrolyticMic::GetMin() { return min_; }

void ElectrolyticMic::SetMin(UI2 value) {
  if (value > max_) return;
  min_ = value;
}

UI2 ElectrolyticMic::GetMax() { return max_; }

void ElectrolyticMic::SetMax(UI2 value) {
  if (value < min_) return;
  max_ = value;
}

void ElectrolyticMic::BoundMinMax() {
  UI2 sample = input_.read_u16();

  if (sample < min_)
    min_ = sample;
  else if (sample > max_)
    max_ = sample;
}

UI2 ElectrolyticMic::Read() { return input_.read_u16(); }

}  // namespace _
