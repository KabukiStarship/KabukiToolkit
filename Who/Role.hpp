/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Who/role.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_WHO_ROLE
#define KABUKI_TOOLKIT_WHO_ROLE
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
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
#endif
#endif
