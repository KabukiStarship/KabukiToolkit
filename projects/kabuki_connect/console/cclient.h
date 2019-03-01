/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_connect/c_client.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#ifndef HEADER_FOR_KABAUKI_STORE_CLIENT
#define HEADER_FOR_KABAUKI_STORE_CLIENT

#include "inventory.h"

namespace _ {

/** Store client with shopping cart.
 */
class Client : public Room {
 public:
  typedef enum States {
    kStateDisconnected = 0,
    kStateAwaitingConnection = 1,
    kStateConnected = 2
  } State;

  enum {
    kMaxPlayers = 64 * 1024,    //< Man number of players.
    kDefaultConsoleWidth = 80,  //< Num rows in a DOS console.
    kMaxMessageLength = 140,    //< Max message length.
    kMaxGameNameLength = 63,    //< Max game name length.
  };

  /** Default constructor. */
  Client();

  /** Virtual destructor. */
  virtual ~Client();

  /** Prints this object to the console. */
  virtual Printer& Print(Printer& printer = Printer());

  /** Abstract Script Operation(s).
      @param index The index of the expression.
      @param expr  The Expression to read and write from.
      @return      Returns null upon success, a Set header upon query, and an
                   error_t ticket upon Read-Write failure. */
  virtual const Op* Star(wchar_t index, Expr* expr);

 protected:
  Authenticator* authenticator_;
  char game_name_[kMaxGameNameLength];  //< Current game name.
  uint32_t xstate_,                     //< Client app state.
      round_number_;                    //< Current round number.
  User user_;                           //< User.
  Cart cart_;                           //< Client shopping cart.

};  //< class Client

}  // namespace _
#endif  //< HEADER_FOR_KABAUKI_STORE_CLIENT
