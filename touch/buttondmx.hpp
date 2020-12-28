/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/ButtonDMX.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_CORE
#ifndef KABUKI_TOOLKIT_AV_DMXBUTTON
#define KABUKI_TOOLKIT_AV_DMXBUTTON
#include "Button.hpp"
#include "ControlDMX.hpp"
namespace _ {

class LIB_MEMBER DMXButton : public Parameter<ISC>, public Button {
 public:
  /* Default constructor. */
   DMXButton (const CHA* label = "", ISC channel = 0, ISC init_value = 0,
     ISC min_value = 0, ISC max_value = 255, ISC word_size = 8,
     ISC action = Button::Action::Momentary, ISC step_size = 0,
     ISC double_press_ticks = Button::kDefaultDoublePressTicks)
     : Button (action, step_size, double_press_ticks),
     ControlDMX (label, channel, init_value, min_value, max_value, word_size,
       Parameter<ISC>::DmxButton) {}

  /* Virtual destructor. */
  virtual ~DMXButton () override {}

  /* Prints this object to the stdout. */
  template<typename Printer>
  Printer& Print (Printer& o) const override {
    return o << "ButtonDMX: " << GetButtonActionString (actions_);
  }

 private:
};
}  // namespace _
#endif
#endif
