/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/toolkit/pch.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h"

#include <script2/global.h"

/*
#include <kabuki/hal/global.h"
#include <kabuki/drivers/global.h"
#include <kabuki/platform/global.h"
#include <kabuki/features/filecabinet/global.h"
#include <kabuki/features/tls/global.h"
#include <kabuki/osal/global.h"
#include <kabuki/toolkit/data/global.h"
#include <kabuki/toolkit/who/global.h"
#include <kabuki/toolkit/pro/global.h"
#include <kabuki/toolkit/uweb/global.h"
#include <kabuki/toolkit/orm/global.h"
#include <kabuki/toolkit/ai/global.h"
#include <kabuki/features/touch/global.h"
#include <kabuki/features/audio/global.h"
#include <kabuki/toolkit/adsp/global.h"
#include <kabuki/features/midi/global.h"
#include <kabuki/toolkit/music/global.h"
#include <kabuki/toolkit/ai/global.h"
#include <kabuki/features/lights/global.h"
#include <kabuki/features/graphics/global.h"
#include <kabuki/toolkit/drawing/global.h"
#include <kabuki/toolkit/gui/global.h"
#include <kabuki/toolkit/plotting/global.h"
#include <kabuki/features/camera/global.h"
#include <kabuki/features/webcam/global.h"
#include <kabuki/toolkit/video/global.h"
#include <kabuki/toolkit/ai/global.h"

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
