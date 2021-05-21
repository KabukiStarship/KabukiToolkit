/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Who/Relationahip.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_WHO_RELATIONSHIP
#define KABUKI_TOOLKIT_WHO_RELATIONSHIP
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
#include "Entity.hpp"
namespace _ {

/* A relationship node between . */
class TRelationship {
 public:
  /* Default constructor. */
  TRelationship();

  /* Prints this object to a expression. */
   Printer& Print (Printer& o) {

 private:
  const TString<>& type_;
  Entity *a, *b;
};
}       // namespace _
#endif
#endif
