/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /portali2c.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#ifndef KABUKI_FEATURE_TEK_PORTALSERIAL
#define KABUKI_FEATURE_TEK_PORTALSERIAL 1

#include "Serial.h"

namespace _ {

/* A portal that connects two Chinese Rooms through a UART connection.
 */
class SerialPortal : public _::Portal {
  /* Constructor creates a loop back port. */
  SerialPortal(_::Expr* expr, PinName tx_pin, PinName rx_pin);

  /* Sets the Portal up for a batch of bytes transfer.
  Implementation of this function is not required to do anything, but
  regardless it will be called by the Set. */
  // virtual void Prime ();

  /* Gets the length of current portal.
  @warning Length might not be the actual length, but rather the length
  of the data that is read to be pulled. */
  // virtual uint_t Length ();

  /* Feeds tx messages through the a without scanning them. */
  virtual void Feed();

  /* Pulls rx messages through the a and runs them through the scanner. */
  virtual void Pull();

 private:
  _::Expr* expr_;  //< Expr for this Portal.
  Serial serial_;  //< mbed Serial port.
};
}  // namespace _
#endif
