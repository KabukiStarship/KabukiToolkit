/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Who/EntityGroup.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
#ifndef KABUKI_TOOLKIT_WHO_ENTITYGROUP
#define KABUKI_TOOLKIT_WHO_ENTITYGROUP
#include "Entity.hpp"
namespace _ {

/* A group of entities. */
class TEntityGroup {
 public:
  /* A group of entities such as people or businesses. */
  TEntityGroup(const TString<>& name)
    : name_ (StringClone (name == nullptr ? "" : name)) {}

  /* Gets the name of the entity group. */
  const TString<>& GetName() { return name_; }

  /* Sets the name of the entity group. */
  void SetName(const TString<>& AString) {
    name_ = StringClone (AString);
  }

  /* Applies privileges to the entity group. */
  void ApplyPrivilege(const TString<>& privileges) {
    // for (ISC i = 0; i < base.getNumAccounts (); i++)
    //    accounts[i].Role ().ApplyPrivileges (new_privileges);
  }

  /* Returns true if this list of entities contains the given CHA. */
  virtual ISC Search(const TString<>& AString) { return 0; }

  template<typename Printer>
  Printer& Print (Printer& o) { 
    out << "Group: " << name_ << " ";
    return out;
  }

 private:
  TString<> name_,             //< The name of the entity group.
       privileges_;            //< A AString of privileges the group has.
  TArray<TEntity*>* entities_; //< A TArray if Entity pointers.
};

}  // namespace _
#endif
#endif
