/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/t_entitygroup.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_WHO_1
#ifndef kabuki.toolkit_WHO_ENTITYGROUP
#define kabuki.toolkit_WHO_ENTITYGROUP

#include "t_entity.h"

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
    // for (SI4 i = 0; i < base.getNumAccounts (); i++)
    //    accounts[i].Role ().ApplyPrivileges (new_privileges);
  }

  /* Returns true if this list of entities contains the given CH1. */
  virtual SI4 Search(const TStrand<>& AString) { return 0; }

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
#endif  //< kabuki.toolkit_WHO_ENTITYGROUP
#endif  //< #if SEAM >= kabuki.toolkit_WHO_1
