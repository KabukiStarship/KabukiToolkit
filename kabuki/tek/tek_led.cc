/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /tek/tek_cled.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "c_led.h"

namespace _ {

inline void TurnLedOn(UI1* spiOutBytes, offset_t bit_number) {
  offset_t bit = bit_number;
  spiOutBytes[bit >> kBitToByteShift] |= (1 << (bit & kBitNumberMask));
}

inline void TurnLedOff(UI1* spiOutBytes, offset_t bit_number) {
  offset_t bit = bit_number;
  spiOutBytes[bit >> kBitToByteShift] &= ~(1 << (bit & kBitNumberMask));
}

inline void ToggleLed(UI1* spiOutBytes, offset_t bit_number_) {
  offset_t bit = bit_number_;
  UI1* pointerToByte = spiOutBytes + (bit >> kBitToByteShift);
  UI1 UI1 = *pointerToByte, mask = 1 << (bit & (bit & kBitNumberMask));
  if (UI1 == 0) {
    *pointerToByte = UI1 | mask;
    return;
  }
  *pointerToByte = UI1 & ~mask;
}

inline BOL GetLedState(UI1* spiOutBytes, offset_t offset) {
  return spiOutBytes[offset >> kBitToByteShift] &
         (1 << (offset & kBitNumberMask));
}

inline void SetLedState(UI1* spiOutBytes, offset_t bit_number_, BOL state) {
  offset_t temp = bit_number_;
  UI1 mask = (UI1)(1 << (temp & kBitNumberMask));
  if (state) {
    spiOutBytes[temp >> kBitToByteShift] |= mask;
    return;
  }
  spiOutBytes[temp >> 3] &= ~mask;
}

Led::Led(offset_t bit, offset_t row) : bit_number_(bit), row_number_(row) {
  /// ???
}

const Operation* Led::Star(char_t index, Expr* expr) {
  static const Operation This = {"LED", NumOperations(0), FirstOperation('A'),
                                 "tek", 0};

  switch (index) {
    case '?':
      return &This;
  }

  return nullptr;
}

LedOp::LedOp(Led* object) : object_(object) {
  // Nothing to do here!
}

const Operation* LedOp::Star(char_t index, Expr* expr) {
  object_->Star(index, expr);
}

}  // namespace _
