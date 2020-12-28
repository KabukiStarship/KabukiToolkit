/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Who/Person.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_WHO_PERSON
#define KABUKI_TOOLKIT_WHO_PERSON
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
#include "Entity.hpp"
namespace _ {

/* Class that represents a person/human.
@todo Load a person from social media account using Facebook and OAuth APIs. */
class TPerson : public TEntity {
 public:
  /*Creates a person with no name. */
  TPerson();

  /* Prints this object to a expression. */
  Printer& Print (Printer& o) { o << "Person: "; }

 private:
  TString<>& lastName;  //< The last name of the entity.
};
}       // namespace _
#endif
#endif
