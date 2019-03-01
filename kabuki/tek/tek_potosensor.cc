/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /firmware/tek_photosensor.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2014-19 (C) Cale Jamison McCollough <<cale@astartup.net>>. 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain 
one at https://mozilla.org/MPL/2.0/. */

#include "photosensor.h"

namespace _ {

Photosensor::Photosensor(PinName pin) : input_(pin) {
  /// Nothing to do here!
}

FP4 Photosensor::Read() { return input_.read(); }

const Operation* Photosensor::Star(char_t index, Expr* expr) {
  static const Operation This = {
      "Photosensor", NumOperations(0), FirstOperation('A'),
      "A standard photosensor hooked up to an ADC pin of a microcontroller.",
      0};

  void* args[1];

  switch (index) {
    case '?':
      return &This;
    case 'A': {
      static const Operation OpA = {"Read", Params<0>(), Params<1, UI2>(),
                                    "Reads the light sensor.", 0};
      if (!expr) return &OpA;

      UI2 value = input_.read_u16();

      return Result(expr, Params<1, UI2>(), Args(args, &value));
    }
  }
  return nullptr;
}

PhotosensorOp::PhotosensorOp(Photosensor* photosensor)
    : photosensor_(photosensor) {
  // Nothing to do here :-)
}

const Operation* PhotosensorOp::Star(char_t index, Expr* expr) {
  return photosensor_->Star(index, expr);
}

}  // namespace _
