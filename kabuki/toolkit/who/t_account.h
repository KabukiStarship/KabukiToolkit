/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki_toolkit/who/t_account.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_ID_ACCOUNT
#define KABUKI_TOOLKIT_ID_ACCOUNT 1

#include "t_handle.h"
#include "t_password.h"
#include "t_roster.h"
#include "t_user.h"

namespace _ {

/* An account with a username and password.
*/
class TAccount {
 public:
  /* Constructs an Account with the given CH1. */
  TAccount(const TStrand<>& username) : name_ (username) {}

  /* Constructs an account from the given CH1 and password. */
  TAccount(const TStrand<>& username, const TStrand<>& password) 
      : name_ (username), password_ (password) {
    // role = new Role ();
  }

  /* Returns true if this is a valid account. */
  BOL IsValid() {
    /*
    if (password == nullptr)
    {
        // The account does not require a password
        if (!name.IsValid ())
            return false;

        return true;
    }
    else // we have to test the password
    if (!name.IsValid () || !password.IsValid ())
        return false;
    */
    return true;
  }

  /* Gets a reference to the name.  */
  const TStrand<>& Name() { return name_.GetKey (); }

  /* Sets the name to the CH1. */
  BOL SetName(const TStrand<>& AString) { return name_.SetKey (AString); }

  /* Returns true if this account requires a password. */
  BOL RequiresPassword() { return password_.Equals (""); }

  /* Sets the password to the new CH1. */
  void SetPassword(const TStrand<>& AString) { password_.SetKey (AString); }

  /* Gets a reverence to the user list. */
  TRoster& Users() { return users_; }

  /* Allows another user to be attached to this account. */
  void AddUser(TUser& user) { users_.Add (user); }

  /* Prints this object to the log. */
  template<typename Printer>
  Printer Print(Printer& o) {
    o << "Account Name:\"" << name_.GetKey ()
      << "\" Password:\"" << password_.GetKey () << '\"';
    return out
  }

 private:
  THandle name_;        //< Account handle/name.
  TPassword password_;  //< Admin password for this account.
  TRoster users_;       //< Account Roster describes User Roles.
};

}       // namespace _
#endif  //< KABUKI_TOOLKIT_ID_ACCOUNT
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
