/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /tek/knobrotary.inl
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#include "rotaryknob.h"

namespace _ {

RotaryKnob::RotaryKnob(ch_t channel, offset_t a, offset_t b)
    : channel_(channel), in_a_(a), in_b_(b) {
  // Assert  (32 <  (inputB -  (inputA & kBitNumberMask)),
  //    "\n| Error: RotaryEncoder::RotaryEncoder (offset_t, offset_t):
  //     Encoders are not word aligned!");
}

SI2 RotaryKnob::GetAccelerationMultiplier(SI4 time) {
  /*
  static const UI1 curves[3][_TekHMIHMI_NumAccellorationCurves] = {
  {

  SI4 timeDelta = currentTime - lastMoveTime,
  lastMoveTime = currentTime;
  */
  return 0;
}

void RotaryKnob::Poll(Controller* controller, offset_t channel,
                      UI1* debounced_xor, SI4 microseconds) {
  offset_t input_a = in_a_, input_b = in_b_;

  UI1 mask_a = debounced_xor[input_a >> kBitToByteShift] &
               (1 << (input_a & kBitNumberMask)),
      mask_b = debounced_xor[input_b >> kBitToByteShift] &
               (1 << (input_b & kBitNumberMask));

  if ((mask_a & mask_b) == 0) return;  //< No change in state.

  // SI2 value =  (maskA ? -1 : 1) *
  //                 GetAccelerationMultiplier (microseconds);
}

const Operation* RotaryKnob::Star(char_t index, Expr* expr) {
  static const Operation This = {"RotaryEncoder", NumOperations(0),
                                 FirstOperation('a'), "tek::sensors", 0};

  switch (index) {
    case '?':
      return &This;
  }

  return nullptr;
}

RotaryEncoderOp::RotaryEncoderOp(RotaryKnob* object) : object_(object) {
  // Nothing to do here!
}

const Operation* RotaryEncoderOp::Star(char_t index, Expr* expr) {
  return object_->Star(index, expr);
}

}  // namespace _
