/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /client.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_config.h>
#ifndef KABUKI_TOOLKT_CLIENT
#define KABUKI_TOOLKT_CLIENT
namespace _ {
class Client {
 public:
  Client();

  ISN Run(ISN arg_count, CHA** args);
};
}  // namespace _
#endif
