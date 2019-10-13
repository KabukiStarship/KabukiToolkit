/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/relationahip.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_RELATIONSHIP
#define KABUKI_TOOLKIT_WHO_RELATIONSHIP

#include "entity.hpp"

namespace _ {

/* A relationship node between . */
class TRelationship {
 public:
  /* Default constructor. */
  TRelationship();

  /* Prints this object to a expression. */
   Printer& Print (Printer& o) {

 private:
  const TStrand<>& type_;
  Entity *a, *b;
};
}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_RELATIONSHIP
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
