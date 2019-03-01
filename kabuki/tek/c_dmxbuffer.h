/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /firmware/c_dmxbuffer.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2014-19 (C) Cale Jamison McCollough <<cale@astartup.net>>. 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain 
one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#ifndef KABUKI_DMX_DMX_BUFFER_H
#define INCLUDED_KABUKI_DMX_DMX_BUFFER_H

namespace _ {

class DMXBuffer {
 public:
  enum {
    kBufferCount = 512,
  };
  DMXBuffer() {}

 private:
  UI1 buffer_[kBufferCount];
};
}  // namespace _
#endif  //< INCLUDED_KABUKI_DMX_BUFFER_H
