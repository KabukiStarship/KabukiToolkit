/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /audio/soundwav.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <_config.h>

#ifndef KABUKI_TOOLKIT_AUDIO_SOUNDWAV_TEMPLATES
#define KABUKI_TOOLKIT_AUDIO_SOUNDWAV_TEMPLATES

#include "soundwav.h"

namespace _ {

template <typename ISZ>
void TAudioStore(const CHR* filename, const ISZ* sample_buffer,
                 ISN sample_count, ISN channels, ISN sample_rate) {
  ISN byte_count = (sample_count * channels) * sizeof(ISZ);

  SoundWav wav;
  wav.riff_id[0] = 'R';
  wav.riff_id[1] = 'I';
  wav.riff_id[2] = 'F';
  wav.riff_id[3] = 'F';
  wav.ruff_size = byte_count + sizeof(SoundWav) - 8;
  wav.wave_type[0] = 'W';
  wav.wave_type[1] = 'A';
  wav.wave_type[2] = 'V';
  wav.wave_type[3] = 'E';
  wav.fmt_id[0] = 'f';
  wav.fmt_id[1] = 'm';
  wav.fmt_id[2] = 't';
  wav.fmt_id[3] = ' ';
  wav.fmt_size = 16;
  wav.fmt_code = 1;
  wav.channels = (IUB)channels;
  wav.sample_rate = (IUC)sample_rate;
  wav.bits = sizeof(ISZ) * 8;
  wav_align = (wav.channels * wav.bits) >> 3;  // >> 3 means /8
  wav.align = wav_align;
  wav.avg_bps = sample_rate * wav_align;
  wav.wav_id[0] = 'd';
  wav.wav_id[1] = 'a';
  wav.wav_id[2] = 't';
  wav.wav_id[3] = 'a';
  wav.wave_size = byte_count;

  FILE* f = fopen(filename, "wb");
  fwrite(&wav, 1, sizeof(wav), f);
  fwrite(sample_buffer, 2 * channels, sample_total, f);
  fclose(f);
}

}  // namespace _

#endif  //< KABUKI_TOOLKIT_AUDIO_SOUNDWAV_TEMPLATES
