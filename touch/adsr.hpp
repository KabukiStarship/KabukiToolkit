/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/adsr.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_AV_CORE
#ifndef KABUKI_TOOLKIT_AV_ADSR
#define KABUKI_TOOLKIT_AV_ADSR
#include <_Config.h>
namespace _ {

/* A ADSR filter. */
class LIB_MEMBER ADSR : public Op {
 public:
  /* Constructs an ADSR with all zeroed out controls. */
  ADSR();

  /* Script operations. */
  virtual const Op* Star(CHW index, Expr* expr);
};

}  // namespace _
#endif
#endif
