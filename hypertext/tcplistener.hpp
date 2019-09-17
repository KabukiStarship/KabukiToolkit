/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /hypertext/pch.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

namespace kabuki {
namespace toolkit {
namespace hypertext {

class TCPListener {
  public:

  private:
  const CH1* ip_address_; //< The server's IP address.
  SIN port_,              //< The server's port number.
    socket_;              //< The socket number.
};
}
}
}
