/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki_toolkit/who/t_name.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_NAME
#define KABUKI_TOOLKIT_WHO_NAME

namespace _ {

/* A name of an entity. */
class TName {
 public:
  /* Default constructor. */
  TName() {}

  /* Writes this object to the given text. */
  Printer& Print (Printer& o) {
    o << "\nName:";
  };

private:
  THandle name_;
};

}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_NAME
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
