/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/touch/c_keyboard.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TEK_1
namespace _ {

/* A computer keyboard.
 */
class CKeyboard {
  enum {
    DefaultBufferSize = 256,    //< The default buffer size.
    MinBufferSize = 64,         //< Min buffer size.
    MaxBufferSize = 1024 * 10,  //< Max buffer size.
  };

  /* Default constructor. **/
  CKeyboard(SI4 a = DefaultBufferSize) {
    if (a < MinBufferSize)
      bufferSize = MinBufferSize;
    else if (a > MaxBufferSize)
      bufferSize = MaxBufferSize;
    else
      bufferSize = a;

    start = stop = begin;
  }

  /* Resets the event buffer. */
  void Clear() { start = stop = begin; }

  /* Inserts an event into the buffer. */
  void Insert(Event a) {
    if (stop + 1 > end) {
      Debug.Assert(start != begin, "Insert  (byte): Buffer overflow.");
      stop = begin;
      buffer[stop] = a;
    }
    Debug.Assert(stop + 1 == start, "Insert  (byte): Buffer overflow.");

    buffer[++stop] = a;
  }

  /* Updates the  */
  void Update() {
    if (start > stop) {
      for (SI4 i = start; i <= end; ++i) buffer[i]();
      for (SI4 i = begin; i <= stop; ++i) buffer[i]();
      start = stop = begin;
      return;
    }

    for (SI4 i = start; i <= end; ++i) buffer[i]();
    start = stop = begin;
  }

 private:
  SI4 begin,       //< The begning of the
      end,         //< The end of the
      start,       //< The start of the events.
      stop,        //< The stop of the events.
      bufferSize;  //< The buffer size.

  CKeyEvent buffer[];  //< An ring-buffer of real-time events from the keyboard.
};                    //< CKeyboard
}  // namespace _
}  //< namespace _ {tek
#endif  //< #if SEAM >= KABUKI_TEK_1
