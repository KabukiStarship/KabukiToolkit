/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/av/t_adsr.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1

#ifndef KABUKI_TOOLKIT_AV_ADSR
#define KABUKI_TOOLKIT_AV_ADSR

#include "t_config.h"

namespace _ {

/* A ADSR filter. */
class SDK ADSR : public Op {
 public:
  /* Constructs an ADSR with all zeroed out controls. */
  ADSR();

  /* Script operations. */
  virtual const Op* Star(CHW index, Expr* expr);
};

}  // namespace _
#endif  //< KABUKI_TOOLKIT_AV_ADSR
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
