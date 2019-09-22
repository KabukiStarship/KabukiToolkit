/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/authenticator.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <module_config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_AUTHENTICATOR
#define KABUKI_TOOLKIT_WHO_AUTHENTICATOR


namespace _ {

/* Interface for a class that can validate a AString for correctness.
This interface is useful for making rules for things like Handle(s) and
Password(s). Classes that implement this interface must define the indexes
of the types. */
struct TAuthenticator {
  /* Function validates the handle for correctness.
  @param  handle The handle to validate. */
  virtual const CH1* HandleIsValid(const TStrand<>& handle) = 0;

  /* Function validates the password for correctness.
  @param  password The password to validate.*/
  virtual const CH1* PasswordInvalid(const TStrand<>& password) = 0;
};

}       // namespace _
#endif
#endif
