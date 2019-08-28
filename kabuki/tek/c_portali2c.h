/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /c_portali2c.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_I2C_PORTAL_H
#define INCLUDED_KABUKI_FEATURE_TEK_I2C_PORTAL_H

namespace _ {

/* A Portal for a half-duplex I2C data link. */
class I2cPortal : public _::Portal {
  /* Constructor creates a loop back port. */
  I2cPortal(_::Expr* expr, PinName sda_pin, PinName scl_pin);

  /* Feeds tx messages through the a without scanning them. */
  virtual void Feed();

  /* Pulls rx messages through the a and runs them through the scanner. */
  virtual void Pull();

 private:
  _::Expr* expr_;  //< Expr for this Portal.
  I2C i2c_;        //< mbed Serial port.
};                 //< class I2CPortal
}  // namespace _
#endif
