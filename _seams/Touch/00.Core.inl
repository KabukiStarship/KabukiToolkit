/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /_Seams/Touch/00.Core.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights 
reserved (R). This Source Code Form is subject to the terms of the Mozilla 
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_Config.h>
#if SEAM == KABUKI_TOOLKIT_AV_0
#include "_Debug.inl"
#else
#include "_Release.inl"
#endif
using namespace _;
namespace KT {
namespace Touch {

inline const CHA* Core(CHA* seam_log, CHA* seam_end, const CHA* args) {
#if SEAM >= KABUKI_TOOLKIT_AV_0
  A_TEST_BEGIN;

#endif
  return 0;
}
}  // namespace Touch
}  // namespace KT
