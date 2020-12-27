/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/MixerPage.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_TOUCH_MIXERPAGE
#define KABUKI_TOOLKIT_TOUCH_MIXERPAGE
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
namespace _ {

class LIB_MEMBER Mixer;
class LIB_MEMBER MixerChannel;

/* Class that represents a page of mixer channels on the Symmetry Live!
A MixerPage stores 8 TemplatePages in an array. The user can switch through
banks of pages on the mixer. The mixer can either be sorted in ascending
track index order or the page banks can be customized to make buses. */
class LIB_MEMBER MixerPage {
  public:
    /* Constructor. */
    MixerPage(Mixer* mixer = nullptr, ISC index_start = 0)
      : mixer_ (mixer) {
      DASSERT (mixer);
      if (index_start < 0) {
        index_start = 0;
      }
      else {
        index_start = index_start_;
      }

      for (ISC i = 0; i < 8; ++i) channels_[i] = 0;
    }

    /* Destructor. */
    ~MixerPage() {}

    /* Gets the name_. */
    TString<>& Name () { return name_; }

    /* Gets the startingIndex of this MixerPage. */
    ISC GetStartIndex () { return index_start_; }

    /* Sets the startingIndex to the newIndex. */
    void SetStartIndex(ISC newIndex) {
      if (index < 0) return;
      if (mixer != 0)
        if (index > mixer->channel_count_ ()) return;

      startingIndex = index;  //< The channel index starts at 1.
    }

    /* Replaces channel with theNewOne. */
    void SetChannel (ISC channel, MixerChannel* new_channel) {
      DASSERT (new_channel);
      return channels_.Set (channel, new_channel);
    }

    /* Gets a pointer to the channel[atThisIndex]. */
    MixerChannel* GetChannel (ISC index) {
      return channels_[index];
    }

    /* Prints this object to a terminal. */
    template<typename Printer>
    Printer& Print (Printer& o) {
      return o << "\nMixerPage:" << 
    }

  private:
    TString<> name_;  //< MixerPage name.
    ISC index_start_;  //< Starting index of this page this MixerPage.
    Mixer* mixer_;     //< Pointer to the global AVMixer.
    TArray<MixerChannel*> channels_;  //< The Mixer channels.

};
}  // namespace _
#endif
#endif
