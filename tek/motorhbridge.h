/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /hbridgemotor.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#ifndef KABUKI_FEATURE_TEK_H_BRIDGE_MOTOR
#define KABUKI_FEATURE_TEK_H_BRIDGE_MOTOR 1

namespace _ {

class HBridgeMotor {
 public:
  /* Simple constructor. */
  HBridgeMotor(PinName pwm_pin, PinName forward_pin, PinName reverse_pin);

  /* Virtual destructor. */
  virtual ~HBridgeMotor();

  /* Stops the motor. */
  void Stop();

  /* Moves the motor forward(+) or backwards(-). */
  void Move(FP4 value);

  /* Script operations. */
  const _::Operation* Star(char_t index, _::Expr* expr);

 private:
  FP4 pulse_width_;     //< The velocity.
  PwmOut pulse_;        //< PWM output pin
  DigitalOut forward_,  //< The forward motor pin.
      reverse_;         //< The reverse motor pin.
};

class HBridgeMotorOp {
 public:
  HBridgeMotorOp(HBridgeMotor* motor);

  /* Script operations. */
  const _::Operation* Star(char_t index, _::Expr* expr);

 private:
  HBridgeMotor* motor_;  //< Pointer to the motor.
};
}  // namespace _
#endif
