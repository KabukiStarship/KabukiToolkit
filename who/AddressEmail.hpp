/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Who/AddressEmail.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
#ifndef KABUKI_TOOLKIT_WHO_EMAILADDRESS
#define KABUKI_TOOLKIT_WHO_EMAILADDRESS
namespace _ {
/* An email address. */
class TAddressEmail {
 public:
  /* Default constructor. */
  TAddressEmail(const TString<>& address) {}

  /* Gets the address String. */
  TString<>& GetAddress() { return address_; }

  /* Attempts to set the address to the given AString. */
  void SetAddress(const TString<>& AString) {
    // address_ = AString;
  }

  /* Prints this object to a expression. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    return o << "Foo";
  }

 private:
  TString<> address_;  //< The email address.
};
}       // namespace _
#endif
#endif
