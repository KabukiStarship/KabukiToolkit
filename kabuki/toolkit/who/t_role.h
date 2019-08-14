/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/who/t_role.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
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
struct SDK TRole {
  UID GetRole() = 0;
};
}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_ROLE
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
