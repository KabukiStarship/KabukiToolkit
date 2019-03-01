/* Sloth @version 0.x
@link    https://github.com/kabuki-starship/sloth.git
@file    ~/projects/seam_2/kabuki_toolkit_updater/sloth.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <stdafx.h>
#if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
#include "sloth.h"

namespace _ {

Sloth::Sloth() : reserved(0) {}

const Op* Sloth::Star(wchar_t index, Expr* expr) {
  switch (index) {
    case '?': {
      static const Op kThis = {"Sloth", 0,       0,      "#CodeSloth",
                               '}',     ';',     ' ',    false,
                               nullptr, nullptr, nullptr};
      return &kThis;
    }
    case ' ': {
      static const Op kUpdate = {
          "Update", 0,
          0,        "Push Operation that occurs upon updating the toolkit.",
          '}',      ';',
          ' ',      false,
          0,        0,
          0};
      if (!expr) return &kUpdate;
    }
  }
  return nullptr;
}

}       //< namespace _
#endif  //< #if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
