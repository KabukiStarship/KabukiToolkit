/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Who/Organization.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
#ifndef KABUKI_TOOLKIT_WHO_ORGANIZATION
#define KABUKI_TOOLKIT_WHO_ORGANIZATION
#include "Entity.hpp"
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
#endif
#endif
