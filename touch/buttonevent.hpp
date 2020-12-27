/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/ButtonEvent.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#ifndef KABUKI_TOOLKIT_TOUCH_EVENTBUTTON
#define KABUKI_TOOLKIT_TOUCH_EVENTBUTTON
#include "Button.hpp"
#include "ControlLayer.hpp"
#include "Event.hpp"
namespace _ {

/* A button that triggers an Event.
A button Event is triggered on the press function. */
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
#endif
#endif
