/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/who/t_organization.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_ORGANIZATION
#define KABUKI_TOOLKIT_WHO_ORGANIZATION

#include "t_entity.h"

namespace _ {

/* An entity that is not a person such as a business or non-profit
   organization. Roster - list or plan showing turns of duty or leave for
   individuals or groups in an organization.
*/
class Organization : public Entity {
 public:
  /* Default constructor. */
  Organization();

  /* Prints this object to a expression. */
   Printer& Print (Printer& o) {

 private:
};

}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_ORGANIZATION
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
