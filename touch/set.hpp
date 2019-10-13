/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/set.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>

#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_SET
#define KABUKI_TOOLKIT_AV_SET

#include "../pro/project.hpp"

namespace _ {

/* A collection of shared objects, . */
class LIB_MEMBER Set {
 public:
  /* Constructor. */
  Set(const CHA* name, IUD uid) : name_(name), uid_(uid) {}

  /* Copy constructor copies the other object. */
  Set(const Set& s) {}

  /* Destructor. */
  virtual ~Set() {}

  /* Adds a new Project to the set. */
  void Add(const Project& workspace) { workspaces_.Add(workspace); }

  /* Gets the number of projects in the set. */
  ISC WorkspaceCount() { return workspaces_.GetCount(); }

  /* Prints this object to the terminal. */
  template <typename Printer>
  Printer& Print(Printer& o) {
    o << "\nSet:" << name << " IUD:" << uid_;
  }

 private:
  TStrand<> name_;                //< Set name.
  IUD uid_;                       //< IUD of this set.
  AArray<Workspace> workspaces_;  //< Array of Project(s).
};
}  // namespace _
#endif
#endif
