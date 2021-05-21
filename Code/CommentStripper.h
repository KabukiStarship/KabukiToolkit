/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Code/CommentStripper.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-21 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_Config.h>
#ifndef KABUKI_TOOLKIT_CODE_COMMENTSTRIPPER_DECL
#define KABUKI_TOOLKIT_CODE_COMMENTSTRIPPER_DECL

namespace _ {
ISN StripComments(const CHA* directory, const CHA* filename,
                  ISN tab_space_count = 2);

ISN StripComments(const CHA* directory);

}  // namespace _
#endif
