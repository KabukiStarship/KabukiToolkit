/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/Set.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_TOUCH_SET
#define KABUKI_TOOLKIT_TOUCH_SET
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#include "../Pro/project.hpp"
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
  TString<> name_;                //< Set name.
  IUD uid_;                       //< IUD of this set.
  AArray<Workspace> workspaces_;  //< Array of Project(s).
};
}  // namespace _
#endif
#endif
