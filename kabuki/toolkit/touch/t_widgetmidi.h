/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /toolkit/touch/t_widgetmidi.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_MIDIWIDGET
#define KABUKI_TOOLKIT_AV_MIDIWIDGET

#include "t_widget.h"

namespace _ {

class WidgetMidi : public TWidget {
 public:
  enum {
    kChannelCommon = 0,         //< Channel for outputting to all channels.
    kPressDoubleTicksMin = 1,   //< ASCII TSS ticks offset min.
    kPressDoubleTicksMax = 1000 //<  ASCII TSS ticks offset min.
  };

  WidgetMidi(UI1 common_channel, UI1 keyboard_channel, UI1 drums_channel)
    : common_channel_ (common_channel_),
      channel_keyboard_ (channel_keyboard_),
      drums_channel_ (drums_channel_),
      double_press_ticks_ (500) {}

  WidgetMidi(const WidgetMidi& o)
    : common_channel_ (o.common_channel_),
      channel_keyboard_ (o.channel_keyboard_),
      drums_channel_ (o.drums_channel_) {}

  virtual ~WidgetMidi () {}

  UI1 GetKeyboardChannel() { return channel_keyboard_; }

  void SetKeyboardChannel(UI1 channel) {
    if (channel == 0)
      channel_keyboard_ = 1;
    else if (channel >= 16)
      channel_keyboard_ = 16;
    else
      channel_keyboard_ = channel;
  }

  SI1 GetDrumsChannel() {
    if (channel == 0)
      drums_channel_ = 1;
    else if (channel >= 16)
      drums_channel_ = 16;
    else
      drums_channel_ = channel;
  }

  void SetDrumsChannel(UI1 channel);

  UI4 GetDoublePressTime() { return double_press_ticks_; }

  SI4 SetDoublePressTime(UI4 new_time) {
    if (newTime < minDoubleClickTime) return -1;

    if (newTime > maxDoubleClickTime) return 1;

    double_press_ticks_ = newTime;
    return 0;
  }

  template<typename Printer>
  Printer& Print(Printer& o) {
    o << "\nWidgetMidi:";
  }

private:
  SI1 common_channel_,  //< Channel 
    channel_keyboard_,
    drums_channel_;
  UI4 double_press_ticks_;
};
}  // namespace _

#endif  //< KABUKI_TOOLKIT_AV_MIDIWIDGET
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
