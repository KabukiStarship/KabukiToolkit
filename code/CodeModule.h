/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Code/CodeModule.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-20 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_Config.h>
#ifndef KABUKI_TOOLKIT_CODE_CODEMODULE
#define KABUKI_TOOLKIT_CODE_CODEMODULE
namespace _ {
class CodeModule {
  const CHA *header_, repo_address_, output_path_;

 public:
  CodeModule();
};
}  // namespace _
#endif
