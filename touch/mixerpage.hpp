/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/mixerpage.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_MIXERPAGE
#define KABUKI_TOOLKIT_AV_MIXERPAGE

namespace _ {

class LIB_MEMBER Mixer;
class LIB_MEMBER MixerChannel;

/* Class that represents a page of mixer channels on the Symmetry Live!
A MixerPage stores 8 TemplatePages in an array. The user can switch through
banks of pages on the mixer. The mixer can either be sorted in ascending
track index order or the page banks can be customized to make buses.
*/
class LIB_MEMBER MixerPage {
  public:
    /* Constructor. */
    MixerPage(Mixer* mixer = nullptr, SI4 index_start = 0)
      : mixer_ (mixer) {
      DASSERT (mixer);
      if (index_start < 0) {
        index_start = 0;
      }
      else {
        index_start = index_start_;
      }

      for (SI4 i = 0; i < 8; ++i) channels_[i] = 0;
    }

    /* Destructor. */
    ~MixerPage() {}

    /* Gets the name_. */
    TStrand<>& Name () { return name_; }

    /* Gets the startingIndex of this MixerPage. */
    SI4 GetStartIndex () { return index_start_; }

    /* Sets the startingIndex to the newIndex. */
    void SetStartIndex(SI4 newIndex) {
      if (index < 0) return;
      if (mixer != 0)
        if (index > mixer->channel_count_ ()) return;

      startingIndex = index;  //< The channel index starts at 1.
    }

    /* Replaces channel with theNewOne. */
    void SetChannel (SI4 channel, MixerChannel* new_channel) {
      DASSERT (new_channel);
      return channels_.Set (channel, new_channel);
    }

    /* Gets a pointer to the channel[atThisIndex]. */
    MixerChannel* GetChannel (SI4 index) {
      return channels_[index];
    }

    /* Prints this object to a terminal. */
    template<typename Printer>
    Printer& Print (Printer& o) {
      return o << "\nMixerPage:" << 
    }

  private:
    TStrand<> name_;  //< MixerPage name.
    SI4 index_start_;  //< Starting index of this page this MixerPage.
    Mixer* mixer_;     //< Pointer to the global AVMixer.
    TArray<MixerChannel*> channels_;  //< The Mixer channels.

};
}  // namespace _
#endif  //< KABUKI_TOOLKIT_AV_MIXERPAGE
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
