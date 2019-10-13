/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/privilage.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_PRIVILAGE
#define KABUKI_TOOLKIT_WHO_PRIVILAGE 1

namespace _ {

/* An account privilege level. */
class TPrivilege {
 public:

   enum {
     kPrivilageLevelCheck = 420,  //< Check yo privilage people.
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
  ISC privilage_count_, //< The number of privileges.
      privileges_level_;      //< The privilege level.
};
}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_PRIVILAGE
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
