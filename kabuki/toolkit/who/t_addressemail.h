/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/who/t_addressemail.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_EMAILADDRESS
#define KABUKI_TOOLKIT_WHO_EMAILADDRESS


namespace _ {

/* An email address. */
class TAddressEmail {
 public:
  /* Default constructor. */
  TAddressEmail(const TStrand<>& address) {}

  /* Gets the address strand. */
  TStrand<>& GetAddress() { return address_; }

  /* Attempts to set the address to the given string. */
  void SetAddress(const TStrand<>& string) {
    // address_ = string;
  }

  /* Prints this object to a expression. */
  template<typename Printer>
  Printer& Print (Printer& o) {

  }

 private:
  TStrand<> address_;  //< The email address.
};

}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_EMAILADDRESS
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
