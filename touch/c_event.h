/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/t_event.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_AV_1
#ifndef kabuki.toolkit_AV_EVENT
#define kabuki.toolkit_AV_EVENT

#include "t_config.h"

namespace kabuki {
namespace toolkit {
namespace touch {

/* A event with an ASCII TSS (Time Subsecond) timestamp. */
class Event {
 public:
  /* Default constructor. */
  Event();

  /* Virtual destructor. */
  virtual ~Event();

  /* gets the timestamp of the Event. */
  TSS GetTimestamp();

  /* Triggers the event. */
  virtual void Trigger() = 0;

  /* Prints this object to a AString. */
  template <typename Printer>
  virtual Printer& Print(Printer& o) const = 0;

 private:
  timestamp_t timestamp;  //< Event timestamp in microseconds.
};

}  // namespace touch
#endif  //< kabuki.toolkit_AV_EVENT
#endif  //< #if SEAM >= kabuki.toolkit_AV_1
