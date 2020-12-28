/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Pro/Mission.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_PRO_CORE
#ifndef KABUKI_PRO_PROJECT
#define KABUKI_PRO_PROJECT
#include "Schedule.hpp"
#include "Task.hpp"
namespace _ {

/* . */
class Mission : public Issue {
 public:
  
  /* Constructs a Mission from the given parameters. */
  Mission(CHA* key, CHA* readme)
    : key_ (key), readme_ (readme), task_ (nullptr) {}

  /* Destructor. */
  ~Issue() {}
  
  /* Gets the Issue Id number. */
  ISW Id () { return id_; }
  
  /* Prints the Shopping list to the console.*/
  template<typename Printer>
  Printer& Print(Printer& o) {
    return o << "\nIssue #" << id_;
  }

  /* Script2 operations. */
  virtual const Op* Star (wchar_t index, Expr* expr) {
    return nullptr;
  }

 private:
  ISW id_;   //< The unique identification number.
};

}  // namespace _
#endif
#endif
