/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Touch/ButtonDummy.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#ifndef KABUKI_TOOLKIT_TOUCH_DUMMYBUTTON
#define KABUKI_TOOLKIT_TOUCH_DUMMYBUTTON
#include "Button.hpp"
#include "ButtonEvent.hpp"
namespace _ {

/* Dummy Button does nothing. */
class LIB_MEMBER ButtonDummy : public Button {
 public:
  /* Creates a ButtonDummy with the given label. */
  ButtonDummy(const CHA* label = "") :
    Button (label) {}

  /* Action that gets performed when this button gets pressed. */
  virtual void Press(ButtonEvent button_event) {}

  /* Action that gets performed when this button gets depressed. */
  virtual void Depress(ButtonEvent button_event) {}

  /* Action that gets performed when this button gets FPD pressed. */
  virtual void DoublePress (ButtonEvent button_event) {}

  /* Script2 Operations. */
  virtual const Op* Op (CHW index, Expr* expr) {
    static const Op cThis = { "ButtonDummy", 
      OpFirst ('@'), OpLast ('@'),
      "KT.av" };

    switch (index) {
    case '?':
      return cThis;
    }

    return nullptr;
  }
};
}  // namespace _
#endif
#endif
