/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/seam_tree.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#include <script2/global.h>

/*
#include <kabuki/hal/global.h>
#include <kabuki/drivers/global.h>
#include <kabuki/platform/global.h>
#include <kabuki/features/filecabinet/global.h>
#include <kabuki/features/tls/global.h>
#include <kabuki/osal/global.h>
#include <kabuki/toolkit/data/global.h>
#include <kabuki/toolkit/who/global.h>
#include <kabuki/toolkit/pro/global.h>
#include <kabuki/toolkit/uweb/global.h>
#include <kabuki/toolkit/orm/global.h>
#include <kabuki/toolkit/ai/global.h>
#include <kabuki/features/touch/global.h>
#include <kabuki/features/audio/global.h>
#include <kabuki/toolkit/adsp/global.h>
#include <kabuki/features/midi/global.h>
#include <kabuki/toolkit/music/global.h>
#include <kabuki/toolkit/ai/global.h>
#include <kabuki/features/lights/global.h>
#include <kabuki/features/graphics/global.h>
#include <kabuki/toolkit/drawing/global.h>
#include <kabuki/toolkit/gui/global.h>
#include <kabuki/toolkit/plotting/global.h>
#include <kabuki/features/camera/global.h>
#include <kabuki/features/webcam/global.h>
#include <kabuki/toolkit/video/global.h>
#include <kabuki/toolkit/ai/global.h>

using namespace _;

int main(int arg_count, char** args) {
  enum { kSize = 1024 };
  char _log[kSize];
  return SeamTreeTest<_0_0_0_F2>(arg_count, args, _log, kSize); */

int main(int arg_count, char** args) {
  enum { kSize = 1024 };
  char _log[kSize];
  return ::_::TestTree<TestScript2>(arg_count, args, _log, kSize);
}
/*
0_0_1_HAL,
0_0_2_Drivers,
_0_0_3_Platform,
_0_0_4_0_Crabs,
_0_0_4_1_FileCabinet,
_0_0_4_2_TLS,
_0_0_5_OSAL,
_0_0_6_Data,
_0_0_7_Who,
_0_0_8_Pro,
_0_0_9_uWeb,
_0_0_10_ORM,
_0_0_11_AI_Math,
_0_1_0_HMI,
_0_2_3_Audio,
_0_2_3_ADSP,
_0_2_3_MIDI,
_0_2_3_Music,
_0_2_5_AI_Math,
_0_3_0_Lights,
_0_3_1_Graphics,
_0_3_2_GUI,
_0_3_3_Plotting,
_0_3_5_Camera,
_0_4_0_Webcam,
_0_4_1_Video,
_0_4_2_AI_Math
*/
