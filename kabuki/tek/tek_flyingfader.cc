/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /firmware/tek_flyingfader.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2014-19 (C) Cale Jamison McCollough <<http://calemccollough.github.io>>. 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain 
one at https://mozilla.org/MPL/2.0/. */

#include "c_flyingfader.h"

namespace _ {

FlyingFader::FlyingFader() {}

void FlyingFader::Print() {
  cout << "\n| FlyingFader:0x";
  PrintPointer(this);
}
const Operation* FlyingFader::Star(char_t index, Expr* expr) {
  static const Operation This = {"FlyingFader", NumOperations(0),
                                 FirstOperation('a'), "tek", 0};
  switch (index) {
    case '?':
      return &This;
  }
  return nullptr;
}

FlyingFaderOp::FlyingFaderOp(FlyingFader* ff) : ff_(ff) {}

const Operation* FlyingFaderOp::Star(char_t index, Expr* expr) {
  return ff_->Star(index, expr);
}

}  // namespace _
