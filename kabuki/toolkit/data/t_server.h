/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/data/t_server.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_DATA_1
#if SEAM == KABUKI_TOOLKIT_DATA_1
#include "test_debug.inl"
#else
#include "test_release.inl"
#endif

#ifndef INCLUDED_KABUKI_TOOLKIT_DATA_SERVER
#define INCLUDED_KABUKI_TOOLKIT_DATA_SERVER

namespace _ {

class Server: public _::Room {
  public:

  typedef enum States {
    kStateShuttingDown = 0, //< Server State 0: Shutting down.
    kStateBooting      = 1, //< Server state 1: Booting.
    kStateServing      = 2, //< Server state 2: Serving.
  } State;

  /* Constructs the default server. */
  Server ();

  /* Abstract Script Op(s).
  @param index The index of the expression.
  @param expr  The Expr to read and write from.
  @return      Returns nil upon success, a Set header upon query, and an
  error_t ticket upon Read-Write failure. */
  virtual const _::Op* Star (wchar_t index, _::Expr* expr);

  private:

};
} //< namespace _
#endif
#endif
