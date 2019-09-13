/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/t_controldmx.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_AV_1
#ifndef kabuki.toolkit_AV_DMXCONTROL
#define kabuki.toolkit_AV_DMXCONTROL

#include "t_param.h"

namespace _ {

/* A DMX Control.
 */
class LIB_MEMBER ControlDMX : public Parameter<SI4> {
 public:
  enum {
    NumChannels = 512  //< The number of DMX512 channels.
  };

  /* Default constructor. */
  ControlDMX(const CH1* label = "", SI4 channel = 0, SI4 value = 0,
             SI4 min_value = 0, SI4 max_value = 255, SI4 word_size = 8,
             SI4 control_type = Parameter<SI4>::ControlDMX)
    : Parameter<SI4> (control_type, label, channel, init_value, min_value,
      max_value, word_size) {

  /* Copy contructor. */
  ControlDMX(const ControlDMX& o)
    : Parameter<SI4> (other) {}

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
