/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /pro/workspace.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_PRO_WORKSPACE
#ifndef KABUKI_TOOLKIT_PRO_WORKSPACE
#define KABUKI_TOOLKIT_PRO_WORKSPACE

#include "project.hpp"

namespace _ {

/* A workspace folder and settings. */
class LIB_MEMBER Workspace {
 public:
  /* Constructor. */
  Workspace() {}

  /* Clones the other object. */
  Project(const Project& p);

  /* Destructor. */
  virtual ~Workspace();

  /* Adds the given controller to the workspace. */
  void Add(const Project& p);

  /* Gets the number of widgets in the project. */
  ISC GetNumWidgets();

  template <typename Printer>
  Printer& Print(Printer& o) {
    o << "\nWorkspace:";
  }

 private:
  _::TArray<TProject> projects_;  //< Workspace Projects.
};

}  // namespace _
#endif
#endif
