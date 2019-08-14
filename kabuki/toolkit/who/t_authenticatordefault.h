/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/who/t_authenticatordefault.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_VALIDATORDEFAULT
#define KABUKI_TOOLKIT_WHO_VALIDATORDEFAULT

#include "t_authenticator.h"

namespace _ {

class TAuthenticatorDefault : public TAuthenticator {
 public:
  /* Constructs a Foo. */
  TAuthenticatorDefault()
    : min_handle_length_ (THandle::kDefaultMinLength),
    max_handle_length_ (THandle::kMaxLength),
    min_password_length_ (TPassword::kDefaultMinLength),
    max_password_length_ (TPassword::kMaxLength) {
    // Nothing to do here. :-)
  }

  /* Gets the min handle length. */
  SI4 MinHandleLength() { return min_handle_length_; }

  /* Gets the max handle length. */
  SI4 GetMaxHandleLength() { return max_handle_length_; }

  /* Gets the min password length. */
  SI4 GetMinPasswordLength() {
    return min_password_length_;
  }

  /* Gets the max password length. */
  SI4 GetMaxPasswordLength() {
    return max_password_length_;
  }

  /* Function validates the handle for correctness.
  @param  handle The handle to validate.
  @return Returns nil upon success and a pointer to an error string
  if the input is invalid. */
  virtual const CH1* HandleIsValid(const TStrand<>& handle) {
    const TStrand<>& result;

    if (input == nullptr) {
      result = "nil input";
      // cout << "\n| " << result;
      return result;
    }
    SI4 length = StrandLength (input);
    // cout << "\n| Checking handle:\"" << input << "\"";

    if (length < min_handle_length_) {
      result = "Handle too short";
      // cout << "\n| " << result;
      return result;
    }
    // cout << '.';
    if (length > max_handle_length_) {
      result = "Handle too uint32_t";
      // cout << "\n| " << result;
      return result;
    }
    if (length == 0) {  //< min
      return nullptr;
    }
    // cout << ". ";
    for (--length; length > 0; --length) {
      // cout << length << ' ';
      if (isspace (input[length])) {
        result = "password can't contain whitespace.";
        // cout << "\n| " << result;
        return result;
      }
    }
    // cout << "\n| Handle is valid.";
    return nullptr;
  }

  /* Function validates the password for correctness.
  @param  password The password to validate.
  @return Returns null upon success and a pointer to an error string
  if the input is invalid. */
  virtual const TStrand<>& PasswordInvalid(const TStrand<>& password) {
    if (input == nullptr) {
      return "nil input";
    }
    const TStrand<>& result;
    // cout << "\n| Checking password:\"" << input << "\"";
    SI4 length = StrandLength (input);
    if (length < min_password_length_) {
      result = "Password too short";
      // cout << "\n| " << result;
      return result;
    }
    // cout << '.';
    if (length > max_password_length_) {
      result = "password too uint32_t";
      // cout << "\n| " << result;
      return result;
    }
    // cout << '.';
    // if (length == 0) { //< Min password length never less than 1.
    //    return nullptr;
    //}
    for (--length; length > 0; --length) {
      if (isspace (input[length])) {
        result = "password can't contain whitespace.";
        // cout << "\n| " << result;
        return result;
      }
    }
    // cout << "\n| Password is valid.";
    return nullptr;
  }

 private:
  SI4 min_handle_length_, max_handle_length_, min_password_length_,
      max_password_length_;
};

}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_VALIDATORDEFAULT
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
