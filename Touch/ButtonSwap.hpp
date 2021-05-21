/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Touch/ButtonSwap.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#ifndef KABUKI_TOOLKIT_TOUCH_BUTTONSWAP
#define KABUKI_TOOLKIT_TOUCH_BUTTONSWAP
#include "Button.hpp"
namespace {

/* A Button that cycles a Control's functionality through various different
modes.
@details The primary purpose of this type of control is for instance that
you have a Knob that has a Button that you can press that changes the
functionality of the knob through a cycle of different parameters.
*/
class LIB_MEMBER ButtonSwap : public Button {
 public:
  /* Constructor. */
  ButtonSwap(const CHA* init_name = StringEmpty ()) 
    : Button (init_name) {}

  /* Copy constructor. */
  ButtonSwap(const ButtonSwap& page) () {}

  /* Destructor. */
  ~ButtonSwap () {}

  /* Prints this object to the stdout. */
  template<typename Printer>
  Printer& Print (Printer& o) const {
    o << "\nSwap Button: Mode:" << mode << "\nButtons:\n";
    for (ISC i = 0; i < control_modes_.Count (); ++i)
      o << control_modes_[i];
    return o;
  }

  const Op* Star (CHW index, Expr * expr) {
    static const Op This = { "ButtonSwap", NumOperations (0), FirstOperation (1),
                            "Buttons that swaps the Isymmetric control layers.",
                            0 };
    switch (index) {
    case '?':
      return &cThis;
    }

    return nullptr;
  }

 private:
  IUC mode;                     //< Index of the current Button.
  TArray<Button*> control_modes_;  //< Array of control mode buttons.
};

}  // namespace Touch
#endif
#endif
