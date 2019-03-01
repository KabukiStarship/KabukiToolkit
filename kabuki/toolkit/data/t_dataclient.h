/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/data/t_dataclient.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_DATA_1
#if SEAM == KABUKI_TOOLKIT_DATA_1
#ifndef KABAUKI_DATA_CLIENT
#define KABAUKI_DATA_CLIENT 1

namespace _ {

/* Data Client.
 */
class TDataClient : public _::Room {
 public:
  typedef enum States {
    kStateDisconnected = 0,
    kStateAwaitingConnection = 1,
    kStateConnected = 2
  } State;

  /* Default constructor. */
  TDataClient () {}

  /* Virtual destructor. */
  virtual ~TDataClient() {}

  /* Prints this object to the console. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    return o << "\nTDataClient";
  }

  /* Abstract Script Op(s).
  @param index The index of the expression.
  @param expr  The Expr to read and write from.
  @return      Returns nil upon success, a Set header upon query, and an
  error_t ticket upon Read-Write failure. */
  virtual const _::Op* Star (wchar_t index, _::Expr* expr) {
    return nullptr;
  }

 private:
  SI4 state_;  // TDataClient state.

};
}       //< namespace _
#endif
#endif
