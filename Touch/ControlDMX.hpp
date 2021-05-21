/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Touch/ControlDMX.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#ifndef KABUKI_TOOLKIT_TOUCH_DMXCONTROL
#define KABUKI_TOOLKIT_TOUCH_DMXCONTROL
#include "Param.hpp"
namespace _ {

/* A DMX Control.
 */
class LIB_MEMBER ControlDMX : public Parameter<ISC> {
 public:
  enum {
    NumChannels = 512  //< The number of DMX512 channels.
  };

  /* Default constructor. */
  ControlDMX(const CHA* label = "", ISC channel = 0, ISC value = 0,
             ISC min_value = 0, ISC max_value = 255, ISC word_size = 8,
             ISC control_type = Parameter<ISC>::ControlDMX)
    : Parameter<ISC> (control_type, label, channel, init_value, min_value,
      max_value, word_size) {

  /* Copy contructor. */
  ControlDMX(const ControlDMX& o)
    : Parameter<ISC> (other) {}

  /* Virtual destructor. */
  ~ControlDMX() {}

  /* Triggers this DMX event to send out the target device. */
  virtual void Trigger() {}

  /* Prints this object to a AString. */
  template<typename Printer>
  Printer& Print(Printer& o) const;

};  //< class ControlDMX
}  // namespace _
#endif
#endif
