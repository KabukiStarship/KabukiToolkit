/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /toolkit/touch/t_mixer_channel.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_MIXERCHANNEL
#define KABUKI_TOOLKIT_AV_MIXERCHANNEL

#include "t_config.h"

namespace _ {

/* A mixer channel Operation. */
class LIB_MEMBER MixerChannel : public Op {
  NONCOPYABLE(MixerChannel)
 public:
  enum {
    DefaultNumAuxSends = 3,  //< Default number of aux sends.
  };

  /* Constructs a mixer channel with the given name. */
  MixerChannel(const CH1* initName = nullptr);

  /* Destructor. */
  ~MixerChannel();

  /* Gets th level of this channel. */
  SI4 GetVolume();

  /* Gets th pan of of the channel. */
  SI4 GetPan();

  /* Gets if this channel is muted. */
  SI4 IsMuted();

  /* Gets if this channel is soloed. */
  SI4 IsSoloed();

  /* Sets the channel level to the value. */
  void setVolume(SI4 value);

  /* Sets the channel pan to the value. */
  void SetPan(SI4 value);

  /* Either mutes or unmutes this channel. */
  void SetMute(BOL isMuted);

  /* Either solos or unsolos this channel. */
  void SetSolo(BOL isSoloed);

  /* Toggles the mute variable. */
  void ToggleMute();

  /* Toggles the solo variable. */
  void ToggleSolo();

  /* Gets thisAux level. */
  SI4 GetAux(SI4 thisAux);

  /* Sets thisAuxSend level. */
  void SetAux(SI4 thisAuxSend, SI4 level);

  /* Deletes the aux send channel at thisIndex.
    @warning This function does not trim the auxSend array size for speed
    considerations Inserts an aux send at thisIndex. */
  void DeleteAux(SI4 thisIndex);

  /* Script Operations. */
  const Op Star(uint index, Expr expr);

 private:
  const CH1* label_text_;  //< Name of this channel.
  SI4 vol_value_,           //< Volume value for this channel.
      pan_value_,           //< Pan value for this channel.
      mute_value_,          //< Mute value for this channel.
      solo_value_,          //< Solo value for this channel.
      num_aux_sends_;       //< Number of aux sends.
  SI4* aux_send_;           //< Array of aux send levels.

};  //< class MixerChannel
}  // namespace _
#endif  //< KABUKI_TOOLKIT_AV_MIXERCHANNEL
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
