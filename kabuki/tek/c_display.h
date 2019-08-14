/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /firmware/c_display.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2014-19 (C) Cale Jamison McCollough <<http://calemccollough.github.io>>. 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain 
one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_DISPLAY
#define INCLUDED_KABUKI_FEATURE_TEK_DISPLAY 1

namespace _ {

class Controller;

/* An abstract Display. */
class Display : public _::Operation {
 public:
  /* Constructs an abstract display. */
  Display();

  /* Virtual destructor. */
  virtual ~Display() = 0;

  /* Virtual function updates the display. */
  virtual void Update() = 0;

  /*< Script operations. */
  const Operation* Star(char_t index, _::Expr* expr);

 private:
};
}  // namespace _

#endif  //< INCLUDED_KABUKI_FEATURE_TEK_DISPLAY
