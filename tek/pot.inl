/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /tek/poc.inl
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#include "c_pot.h"

namespace _ {

Pot::Pot(ch_t channel, PinName adc_pin) : channel_(channel), ain_(adc_pin) {
  // Nothing to do here :-)
}

void Pot::Poll(UI2 new_value, Expr* expr, UI2 value, UI2 min_value,
               UI2 max_channel) {}

void Pot::Print(Log& log) { o << "Pot"; }

const _::Operation* Pot::Star(char_t index, _::Expr* expr) {
  static const Operation This = {"Pot", NumOperations(0), FirstOperation('A'),
                                 "A potentiometer.", 0};
  void* args[1];
  switch (index) {
    case '?':
      return &This;
    case 'A': {
      static const Operation OpA = {"Read", _::Params<0>(), _::Params<1, UI2>(),
                                    "Reads the pot's value", 0};
      if (!expr) return &OpA;
      UI2 value = ain_.read_u16();
      return Result(expr, _::Params<1, UI2>(), _::Args(args, &value));
    }
  }
  return nullptr;
}

PotOp::PotOp(Pot* object) : object_(object) {
  // Nothing to do here!
}

const Operation* PotOp::Star(char_t index, Expr* expr) {
  return object_->Star(index, expr);
}

}  // namespace _
