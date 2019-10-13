/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /package.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights
reserved (R). This Source Code Form is subject to the terms of the Mozilla
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_config.h>
#ifndef KABUKI_TOOLKT_PACKAGE
#define KABUKI_TOOLKT_PACKAGE
namespace _ {
class Package {
 public:
  Package();

  SIN Run(SIN arg_count, CHA** args);
};
}  // namespace _
#endif
