/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /tek/tek_portal.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "i2c_portal.h"

namespace _ {

I2cPortal::I2cPortal(Expr* expr, PinName sda_pin, PinName scl_pin)
    : expr_(expr), i2c_(sda_pin, scl_pin) {
  /// Nothing to do here!
}

void I2cPortal::Feed() {
  // while (serial_.readable ()) slot.StreamTxByte ();
}

void I2cPortal::Pull() {
  /*
      //const SI4 addr7bit = 0x48;      // 7-bit I2C address.
      const SI4 addr8bit = 0x48 << 1; // 8-bit I2C address: 0x90.

      UI1 cmd[80]; //< @todo what size do  I need?
      cmd[0] = 0x01;
      cmd[1] = 0x00;
      i2c_.write (addr8bit, cmd, 2);

      wait (0.5);

      cmd[0] = 0x00;
      i2c_.write (addr8bit, cmd, 1);
      i2c_.read (addr8bit, cmd, 2);

      FP4 tmp = (FP4 ((cmd[0] << 8) | cmd[1]) / 256.0);
      printf ("\n| Temp = %.2f\n", tmp);
      */
}

}  // namespace _
