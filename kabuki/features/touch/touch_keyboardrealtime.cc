/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/touch/t_t_real-time_keyboard.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>
#if SEAM >= KABUKI_TEK_1
#if SEAM == KABUKI_TEK_1
#define PRINTF(format, ...) Printf(format, __VA_ARGS__)
#define PRINT_PAUSE(message)   \
  Printf("\n\n%s\n", message); \
  system("PAUSE");
#else
#define PRINTF(x, ...)
#define PRINT_PAUSE(message)
#endif

namespace _ {

CKeyboard::CKeyboard(SI4 a = DefaultBufferSize) {
  if (a < MinBufferSize)
    bufferSize = MinBufferSize;
  else if (a > MaxBufferSize)
    bufferSize = MaxBufferSize;
  else
    bufferSize = a;

  start = stop = begin;
}

void CKeyboard::Clear() { start = stop = begin; }

void CKeyboard::Insert(Event a) {
  if (stop + 1 > end) {
    Debug.Assert(start != begin, "Insert  (byte): Buffer overflow.");
    stop = begin;
    buffer[stop] = a;
  }
  Debug.Assert(stop + 1 == start, "Insert  (byte): Buffer overflow.");

  buffer[++stop] = a;
}

void CKeyboard::Update() {
  if (start > stop) {
    for (SI4 i = start; i <= end; ++i) buffer[i]();
    for (SI4 i = begin; i <= stop; ++i) buffer[i]();
    start = stop = begin;
    return;
  }

  for (SI4 i = start; i <= end; ++i) buffer[i]();
  start = stop = begin;
}

}  // namespace _
#endif  //< #if SEAM >= KABUKI_TEK_1
