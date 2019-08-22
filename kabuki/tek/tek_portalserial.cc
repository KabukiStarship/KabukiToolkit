/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /tek/tek_portserial.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "c_portalserial.h"

namespace _ {

SerialPortal::SerialPortal(Expr* expr, PinName tx_pin, PinName rx_pin)
    : expr_(expr), serial_(tx_pin, rx_pin) {
  /// Nothing to do here!
}

void SerialPortal::Feed() {
  // while (serial_.readable ()) expr_.StreamTxByte ();
}

void SerialPortal::Pull() {
  // while (serial_.readable ()) expr_.StreamRxByte (serial_.getc ());
}

}  // namespace _
