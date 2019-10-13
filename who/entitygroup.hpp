/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/entitygroup.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_ENTITYGROUP
#define KABUKI_TOOLKIT_WHO_ENTITYGROUP

#include "entity.hpp"

namespace _ {

/* A group of entities. */
class TEntityGroup {
 public:
  /* A group of entities such as people or businesses. */
  TEntityGroup(const TStrand<>& name)
    : name_ (StrandClone (name == nullptr ? "" : name)) {}

  /* Gets the name of the entity group. */
  const TStrand<>& GetName() { return name_; }

  /* Sets the name of the entity group. */
  void SetName(const TStrand<>& AString) {
    name_ = StrandClone (AString);
  }

  /* Applies privileges to the entity group. */
  void ApplyPrivilege(const TStrand<>& privileges) {
    // for (ISC i = 0; i < base.getNumAccounts (); i++)
    //    accounts[i].Role ().ApplyPrivileges (new_privileges);
  }

  /* Returns true if this list of entities contains the given CHA. */
  virtual ISC Search(const TStrand<>& AString) { return 0; }

  template<typename Printer>
  Printer& Print (Printer& o) { 
    out << "Group: " << name_ << " ";
    return out;
  }

 private:
  TStrand<> name_,             //< The name of the entity group.
       privileges_;            //< A AString of privileges the group has.
  TArray<TEntity*>* entities_;  //< A TArray if Entity pointers.
};

}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_ENTITYGROUP
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
