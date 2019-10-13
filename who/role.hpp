/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/role.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_ROLE
#define KABUKI_TOOLKIT_WHO_ROLE


namespace _ {

/* A role that an entity plays in an organization.
    Examples of a role are:
    1. Owner
    2. Executive
    3. Manager
    4. Employee
    5. Volunteer
*/
struct LIB_MEMBER TRole {
  IUD GetRole() = 0;
};
}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_ROLE
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
