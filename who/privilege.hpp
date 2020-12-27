/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Who/Privilage.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_WHO_PRIVILAGE
#define KABUKI_TOOLKIT_WHO_PRIVILAGE
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE

namespace _ {

/* An account privilege level. */
class TPrivilege {
 public:

   enum {
     cPrivilageLevelCheck = 420,  //< Check yo privilage people.
   };

  /* Default constructor. */
   TPrivilege (ISC num_privileges = 1)
     : privilage_count_ (kPrivilageLevelCheck) {

  }

  /* Gets the privilege level. */
  Privileges PrivilegeLevel() {
    return privileges_level_;
  }

  /* Attempts to set the privilege level to the new level. */
  Privileges SetPrivilegeLevel(ISC privileges) {
    ISC level = privileges_level_;
    if (level < 0) return false;
    if (level >= privilage_count_) return false;
    privileges_level_ = privilages;
    return true;
  }

  /* Prints this object to a expression. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    o << "\nPrivilage:";
  }

 private:
  ISC privilage_count_,   //< The number of privileges.
      privileges_level_;  //< The privilege level.
};
}       // namespace _
#endif
#endif
