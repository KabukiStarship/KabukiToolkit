/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /touch/t_tag.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= kabuki.toolkit_AV_1
#ifndef kabuki.toolkit_AV_TAG
#define kabuki.toolkit_AV_TAG


namespace _ {

class Tag {
 public:
  /* Gets the Unique identifier number. */
  virtual SI4 GetUid() = 0;

  /* Sets the Unique identifier number. */
  virtual CH1 SetUid(SI4 value) = 0;

  /* Gets the ID name. */
  virtual CH1 GetName() = 0;

  /* Sets the ID name. */
  virtual CH1 SetName(const TStrand<>& name) = 0;
};
}       // namespace _
#endif  //< kabuki.toolkit_AV_TAG
#endif  //< #if SEAM >= kabuki.toolkit_AV_1
