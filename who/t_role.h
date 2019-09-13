/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/t_role.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_WHO_1
#ifndef kabuki.toolkit_WHO_ROLE
#define kabuki.toolkit_WHO_ROLE


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
  UID GetRole() = 0;
};
}       // namespace _
#endif  //< kabuki.toolkit_WHO_ROLE
#endif  //< #if SEAM >= kabuki.toolkit_WHO_1
