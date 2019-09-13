/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/t_buttondummy.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_AV_1
#ifndef kabuki.toolkit_AV_DUMMYBUTTON
#define kabuki.toolkit_AV_DUMMYBUTTON

#include "t_button.h"
#include "t_buttonevent.h"

namespace _ {

/* Cummy Button does nothing. */
class LIB_MEMBER ButtonDummy : public Button {
 public:
  /* Creates a ButtonDummy with the given label. */
  ButtonDummy(const CH1* label = "") :
    Button (label) {}

  /* Action that gets performed when this button gets pressed. */
  virtual void Press(ButtonEvent button_event) {}

  /* Action that gets performed when this button gets depressed. */
  virtual void Depress(ButtonEvent button_event) {}

  /* Action that gets performed when this button gets FP8 pressed. */
  virtual void DoublePress (ButtonEvent button_event) {}

  /* Script2 Operations. */
  virtual const Op* Op (CHW index, Expr* expr) {
    static const Op kThis = { "ButtonDummy", 
      OpFirst ('@'), OpLast ('@'),
      "kabuki.toolkit.av" };

    switch (index) {
    case '?':
      return kThis;
    }

    return nullptr;
  }
};
}  // namespace _
#endif
#endif
