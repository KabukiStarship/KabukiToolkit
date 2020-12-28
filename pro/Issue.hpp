/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Pro/Issue.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_PRO_1
#ifndef KABUKI_PRO_ISSUE
#define KABUKI_PRO_ISSUE
#include "Schedule.hpp"
#include "Task.hpp"
namespace _ {

/* And 'issue ticket'. */
class Issue : public Operand {
 public:
  
  /* Default constructor initializes list with the given or left key. */
  Issue(const CHA* key = "Unnamed", const CHA* readme = "")
    : key_ (key == nullptr ? StringClone ("") : key),
    readme_ (readme == nullptr ? StringClone ("") : readme),
    task_ (nullptr) {}

  /* Constructor initializes with stolen key and readme. */
  Issue(CHA* key, CHA* readme)
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
