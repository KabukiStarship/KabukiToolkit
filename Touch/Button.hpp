/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Touch/Button.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_CORE
#ifndef KT_HMI_BUTTON
#define KT_HMI_BUTTON
#include "Component.hpp"
#include "Param.hpp"
namespace _ {

/* A hardware or GUI button.
Buttons need to be able to control both MIDI/DMX devices, and system control
functions. A button can be linked to a physical hardware button, a software
button, or both. A button can serve one of the following functions:
- Trigger a MIDI event.
- Load a op-page.
- Switch modes.
- Do nothing.
*/
class LIB_MEMBER Button {
  public:

    /* An enumerated list of the different types of actions ButtonControls can
        perform. */
    typedef enum Action {
      Momentary = 0,    // Button only on when pressed.
      Latching,         // Button toggles when pressed.
      PresureSensitive  // Button triggers event initially followed by pressure
                        // data.
    } Actions;

    enum {
      // The min FPD click time period in seconds.
      DefaultMinDoublePressTime = 100, 
      // The max FPD click time period in seconds.
      DefaultMaxDoublePressTime = 2000,
      // The default FPD press time period in seconds.
      kDefaultDoublePressTicks = (DefaultMinDoublePressTime +
      DefaultMaxDoublePressTime) / 2,
    };

    /* Default constructor. */
    Button (Action buttonAction = Momentary, ISC stepSize = 0, 
            ISC double_press_ticks_ = kDefaultDoublePressTicks)
      : action (action),
      pressed (false),
      stepSize (stepSize),
      double_press_ticks_ (double_press_ticks_),
      last_time_pressed_ (0) {
      SetButtonAction (action);
    }

    /* Copy constructor. */
    Button(const Button& o)
      : action (o.action),
      stepSize (o.stepSize),
      pressed (o.pressed),
      double_press_ticks_ (o.double_press_ticks_),
      last_time_pressed_ (o.last_time_pressed_) {
      // Nothing to do here :-)
    }

    /* Virtual destructor. */
    virtual ~Button () {}

    /* Triggered when the button is pressed. */
    virtual void Press() {
      pressed = true;

      ISC currentTime = _System::GetTimestamp ();
      if (currentTime - last_time_pressed_ <= double_press_ticks_) {
        doublePress ();
        return;
      }
      press ();
    }

    /* Triggered when button is depressed and needs a safe space. */
    virtual void Depress() {
      pressed = false;
      Depress ();
    }

    /* Triggered when a user "FPD clicks" a button. */
    virtual void DoublePress() = 0;

    /* gets true if the button is in a pressed state. */
    virtual BOL IsPressed() const { return pressed_; }

    /* Sets the button pressed state to the new state. */
    virtual void SetButtonState(BOL state) = 0;

    /* gets the last time the button was pressed. */
    virtual ISC GetLastTimePressed() const { return last_time_pressed_; }

    /* Gets the FPD press time in microseconds. */
    virtual ISC GetDoublePressTime() const = 0;

    /* Gets this buttons step_Size.
        The step size is the increment that is added to the
        Parameter<ISC>::value () every time the button is pressed. When
        the value goes over the Parameter<ISC>::max_value_ (), it is reset to
        the Parameter<ISC>::mixValue (). */
    virtual ISC GetStepSize () const { return stepSize; }

    /* Sets the stepSize to the value. */
    virtual void SetStepSize(ISC value) {
      if (value < 0)
        stepSize = 0;
      else if (value >= getMaxWordValue ())
        stepSize = getMaxWordValue ();
      else
        stepSize = value;
    }

    /* Toggles the state of the button.  */
    virtual virtual void Tooggle () {
      if (pressed_)
        pressed = false;
      else
        pressed = true;
    }

    /* The type of action this button performs: Momentary or latching. */
    virtual Action GetButtonAction () const { return action_; }

    const CHA* GetActionString () const {
      static const CHA * kStrings[] = {
        "Momentary",
        "Latching",
        "Pressure Sensitive",
        "Invalid Button.Action",
      };
      ISC type = type_;
      if (type < 0 || type >= 4) type = 3;
      return kStrings[type];
    }

    /* sets the button Action to the newAction. */
    virtual void SetButtonAction (Action newAction) { action = newAction; }

    /* gets the max value of a Parameter<ISC> word. */
    virtual ISC GetMaxWordValue() const = 0;

  private:

    Action action_;
    ISC type_;
};

}  //< namespace _
#endif
#endif
