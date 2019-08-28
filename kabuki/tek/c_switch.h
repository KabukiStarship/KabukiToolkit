/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /c_switch.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_BOUNCYSWITCH
#define INCLUDED_KABUKI_FEATURE_TEK_BOUNCYSWITCH 1

#include <mbed.h"

namespace _ {

/* A software debounced switch. */
class Switch : public _::Operation {
 public:
  /* A software debcounced switch. */
  Switch(PinName din_pin);

  /* Script operations. */
  const _::Operation* Star(char_t index, _::Expr* expr);

 private:
  DigitalIn input_;  //< The DIN pin.
};

class SwitchOp : public _::Operation {
 public:
  SwitchOp(Switch* sw);

  virtual const _::Operation* Star(char_t index, _::Expr* expr);

 private:
  Switch* object_;  //< The Switch.
};                  //< SwitchOp
}  // namespace _
#endif
