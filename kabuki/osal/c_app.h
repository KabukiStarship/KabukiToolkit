/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki_toolkit/osal/c_app.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_OSAL_1

#ifndef KABUKI_TOOLKIT_APP
#define KABUKI_TOOLKIT_APP

#include "config.h"

namespace _ {

/* Interface for an Kabuki Starship app.
 */
struct App {
  /*
  const SI4 MaxWindows = 256;
      
  uint32_t UID;
  numWindows;
      
  Window windows[];
  Window activeWindow;
  */

  /* Initializer. */
  virtual void Initialize() = 0;

  /* Returns the process ID of this App. */
  virtual uint32_t GetUID() = 0;

  /* Sets the activeWindow to the new index. */
  virtual SI4 ActivateWindow(SI4 i) = 0;

  /* Sets the activeWindow to the new window. */
  virtual SI4 ActivateWindow(Window w) = 0;

  /*  */
  virtual ProcessTree GetWindows() = 0;

  /*  */
  virtual SI4 Show() = 0;

  /*  */
  virtual SI4 Hide() = 0;

  /*  */
  virtual SI4 Close() = 0;

  /* Returns a link to this application's osal context. */
  virtual _g::Cell& GetDrawCell() = 0;

  /*  */
  virtual void Draw(_g::Cell& c) = 0;

  /*  */
  virtual void Redraw() = 0;

  /* Prints this object to a Expression.  */
  virtual void Print() = 0;
};  //< struct App

}  // namespace _
#endif
#endif
