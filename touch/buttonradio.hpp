/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/buttonradio.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <module_config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_RADIOBUTTON
#define KABUKI_TOOLKIT_AV_RADIOBUTTON

#include "component.hpp"

namespace _ {

/* */
class ButtonRadio : public HmiComponent {
 public:

  /* Constructs a radio button with starting index 0. */
  ButtonRadio()
    : index_ (0),
      button_count_ (0)
  {}

  /* Virtually destructs the sub-objects. */
  virtual ~ButtonRadio () {}

  /* Gets the currently selected choice. */
  SI4 Index() { return index_; }

  /* Attempts to set the value to the new one and returns false upon success. 
  */
  BOL SetValue(SI4 value) {
    if (value < 0) return false;
    index_ = value;
  }

  /* Increments the index or resets it to zero if out bounds. */
  void Press() {
    ++index_;
    if (index > button_count_) index = 0;
  }

  /* Prints this object to a AString. */
  template<typename Printer>
  Printer& Print (Printer& o) const {
    return o << "\nButtonRadio:" << index << buttons_.Print (o);
  }

 private:
  SI4 index_;         //< Current index of the radio button.
  ParamSet buttons_;  //< The radio buttons ParamSet.
};
}  // namespace _
#endif  //< KABUKI_TOOLKIT_AV_BUTTONRADIO
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
