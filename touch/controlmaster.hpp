/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/master_controls.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <module_config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_MASTERCONTROLS
#define KABUKI_TOOLKIT_AV_MASTERCONTROLS

#include "param.hpp"

namespace _ {

/* Master control for an isymmetric control surface.
 */
class ControlMaster {
 public:
  /* Constructs a blank set of master controls. */
  ControlMaster();

  /* Prints this object to a terminal. */
  inline template<typename Printer> Printer& Print(Printer& o) const;

 private:
  Parameter<SI4>*a, *b, *c, *d;
};

}  // namespace _
#endif
#endif
