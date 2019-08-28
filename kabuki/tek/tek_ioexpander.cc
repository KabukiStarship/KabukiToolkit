/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /tek/tek_ioexpander.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "c_ioexpander.h"

namespace _ {

IoExpander::IoExpander(UI1* buffer, UI1 num_in_bytes, UI1 num_out_bytes,
                       PinName mosi_pin, PinName miso_pin, PinName clock_pin,
                       PinName strobe_pin, UI4 frequency)
    : spi_(mosi_pin, miso_pin, clock_pin, strobe_pin),
      num_in_bytes_(num_in_bytes),
      num_out_bytes_(num_out_bytes),
      in_bytes_(reinterpret_cast<UI1*>(buffer)),
      out_bytes_(in_bytes_ + num_in_bytes) {
  spi_.frequency(frequency);
}

UI1 IoExpander::GetNumInBytes() { return num_in_bytes_; }

UI1 IoExpander::GetNumOutBytes() { return num_out_bytes_; }

// void IoExpander::Attach (Controller* controller) {
//	if (controller == 0)
//		return;
//}

// void IoExpander::SetDevice (UI1 device_number) {
//}

/* Gets the digital input UI1 at the given index. */
inline void IoExpander::Update(UI1 index) {
  if ((index < num_in_bytes_) && (index < num_out_bytes_))
    in_bytes_[index] = spi_.write(out_bytes_[index]);
  else if (index < num_in_bytes_)
    in_bytes_[index] = spi_.write(0);
  else
    spi_.write(out_bytes_[index]);
}

}  // namespace _
