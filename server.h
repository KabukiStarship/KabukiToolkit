/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Server.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright 2019-20 (C) Kabuki Starship <kabukistarship.com>; all rights 
reserved (R). This Source Code Form is subject to the terms of the Mozilla 
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_Config.h>
#ifndef KABUKI_TOOLKT_WEBSERVER
#define KABUKI_TOOLKT_WEBSERVER
namespace _ {
class Server {
 public:
  Server();

  SIN Run(SIN arg_count, CHA** args);
};
}  // namespace _
#endif
