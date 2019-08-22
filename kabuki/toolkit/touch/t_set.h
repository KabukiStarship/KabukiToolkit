/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /toolkit/touch/t_set.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_SET
#define KABUKI_TOOLKIT_AV_SET

#include "../pro/t_project.h"

namespace _ {

/* A collection of shared objects, . */
class SDK Set {
 public:
  /* Constructor. */
   Set (const CH1* name, UID uid) 
   : name_ (name),
     uid_ (uid) {}

  /* Copy constructor copies the other object. */
  Set(const Set& s) {}

  /* Destructor. */
  virtual ~Set() {}

  /* Adds a new Project to the set. */
  void Add(const Project& workspace) {
    workspaces_.Add (workspace);
  }

  /* Gets the number of projects in the set. */
  SI4 WorkspaceCount() { return workspaces_.GetCount (); }

  /* Prints this object to the terminal. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    o << "\nSet:" << name << " UID:" << uid_;
  }

 private:
   TStrand<> name_;           //< Set name.
   UID uid_;                  //< UID of this set. 
   TArray<Workspace> workspaces_; //< Array of Project(s).
};                            //< class Set
}  // namespace _
#endif  //< KABUKI_TOOLKIT_AV_SET
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
