/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/Tag.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_TOUCH_TAG
#define KABUKI_TOOLKIT_TOUCH_TAG
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
namespace _ {

class Tag {
 public:
  /* Gets the Unique identifier number. */
  virtual ISC GetUid() = 0;

  /* Sets the Unique identifier number. */
  virtual CHA SetUid(ISC value) = 0;

  /* Gets the ID name. */
  virtual CHA GetName() = 0;

  /* Sets the ID name. */
  virtual CHA SetName(const TString<>& name) = 0;
};
}       // namespace _
#endif
#endif
