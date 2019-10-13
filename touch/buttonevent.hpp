/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/buttonevent.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_EVENTBUTTON
#define KABUKI_TOOLKIT_AV_EVENTBUTTON

#include "button.hpp"
#include "control_layer.hpp"
#include "event.hpp"

namespace _ {

/* A button that triggers an Event.
    A button Event is triggered on the press function.
*/
class EventButton : public Button {
 public:
  /* Default constructor. */
  EventButton(const CHA *initLabel = "", ISC initAction = Button::Momentary)
    : AButton (initLabel, Control::AButton, initAction) {}

  /* Copy constructor. */
  EventButton (const EventButton &o) {}

  /* Destructor. */
  virtual ~EventButton () {}

  /* The action that gets performed when this button gets pressed. */
  virtual void Press (const ControlLayer &cl) {
    Trigger ();
  }

  /* Action that gets performed when this button gets FPD pressed. */
  virtual void Depress (const ControlLayer &cl) {}

  /* Action that gets performed when this button FPD pressed. */
  virtual void DoublePressed (const ControlLayer &cl) {}

  /* Event interface implementation. */
  virtual void Trigger () {}

};
}  // namespace _
#endif  //< KABUKI_TOOLKIT_AV_EVENTBUTTON
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
