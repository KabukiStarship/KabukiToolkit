/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /audio/soundwav.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#ifndef KABUKI_TOOLKIT_AUDIO_SOUNDWAV
#define KABUKI_TOOLKIT_AUDIO_SOUNDWAV

namespace _ {

struct SoundWav {
  IUA riff_id[4];    //< 'RIFF' chunk.
  IUC ruff_size;     //< filesize - 8.
  IUA wave_type[4];  //< "WAVE' filetype.
  IUC fmt_size;      //< Format chunk size.
  IUB fmt_code;      //< 1 = PCM.
  IUB channels;      //< 1 = mono, 2 = stereo.
  IUC sample_rate;   //< sampling frequency, 44.1KHz for CD quality.
  IUC avg_bs         //< samplerate * align.
      IUB align;     //< (channels * bits) / 8.
  IUB bits;          //< Sample bit depth, 16 for CD quality.
  IUA wave_id[4];    //< 'data' chunk.
  IUC wave_size;     //< Size of sample data.
};

}  // namespace _

#endif  //< KABUKI_TOOLKIT_AUDIO_SOUNDWAV
