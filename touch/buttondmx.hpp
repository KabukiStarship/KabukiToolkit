/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/dmx_button.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <module_config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_DMXBUTTON
#define KABUKI_TOOLKIT_AV_DMXBUTTON

#include "button.hpp"
#include "control_dmx.hpp"

namespace _ {

class LIB_MEMBER DMXButton : public Parameter<SI4>, public Button {
 public:
  /* Default constructor. */
   DMXButton (const CH1* label = "", SI4 channel = 0, SI4 init_value = 0,
     SI4 min_value = 0, SI4 max_value = 255, SI4 word_size = 8,
     SI4 action = Button::Action::Momentary, SI4 step_size = 0,
     SI4 double_press_ticks = Button::kDefaultDoublePressTicks)
     : Button (action, step_size, double_press_ticks),
     ControlDMX (label, channel, init_value, min_value, max_value, word_size,
       Parameter<SI4>::DmxButton) {}

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
#endif  //< KABUKI_TOOLKIT_AV_DMXBUTTON
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
