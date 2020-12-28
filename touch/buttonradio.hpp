/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/buttonradio.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#ifndef KABUKI_TOOLKIT_TOUCH_RADIOBUTTON
#define KABUKI_TOOLKIT_TOUCH_RADIOBUTTON
#include "Component.hpp"
namespace _ {

/* An abstract radio button. */
class ButtonRadio : public HMIComponent {
 public:

  /* Constructs a radio button with starting index 0. */
  ButtonRadio()
    : index_ (0),
      button_count_ (0)
  {}

  /* Virtually destructs the sub-objects. */
  virtual ~ButtonRadio () {}

  /* Gets the currently selected choice. */
  ISC Index() { return index_; }

  /* Attempts to set the value to the new one and returns false upon success. 
  */
  BOL SetValue(ISC value) {
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
  ISC index_;         //< Current index of the radio button.
  ParamSet buttons_;  //< The radio buttons ParamSet.
};
}  // namespace _
#endif
#endif
