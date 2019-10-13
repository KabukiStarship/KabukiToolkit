/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/authenticatordefault.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_VALIDATORDEFAULT
#define KABUKI_TOOLKIT_WHO_VALIDATORDEFAULT

#include "authenticator.hpp"

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
  ISC MinHandleLength() { return min_handle_length_; }

  /* Gets the max handle length. */
  ISC GetMaxHandleLength() { return max_handle_length_; }

  /* Gets the min password length. */
  ISC GetMinPasswordLength() {
    return min_password_length_;
  }

  /* Gets the max password length. */
  ISC GetMaxPasswordLength() {
    return max_password_length_;
  }

  /* Function validates the handle for correctness.
  @param  handle The handle to validate.
  @return Returns nil upon success and a pointer to an error AString
  if the input is invalid. */
  virtual const CHA* HandleIsValid(const TStrand<>& handle) {
    const TStrand<>& result;

    if (input == nullptr) {
      result = "nil input";
      // cout << "\n| " << result;
      return result;
    }
    ISC length = StrandLength (input);
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
  @return Returns null upon success and a pointer to an error AString
  if the input is invalid. */
  virtual const TStrand<>& PasswordInvalid(const TStrand<>& password) {
    if (input == nullptr) {
      return "nil input";
    }
    const TStrand<>& result;
    // cout << "\n| Checking password:\"" << input << "\"";
    ISC length = StrandLength (input);
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
  ISC min_handle_length_, max_handle_length_, min_password_length_,
      max_password_length_;
};

}       // namespace _
#endif
#endif
