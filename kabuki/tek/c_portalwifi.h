/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /_cportalwifi.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_PORTALWIFI
#define INCLUDED_KABUKI_FEATURE_TEK_PORTALWIFI 1
namespace _ {

class WifiPortal : _::Portal {
 public:
  /* Constructor creates a loop back port. */
  WifiPortal(_::Expr* expr);

  /* Sets the Portal up for a batch of bytes transfer.
    Implementation of this function is not required to do anything, but
    regardless it will be called by the Set. */
  // virtual void Prime ();

  /* Gets the length of current portal.
      @warning Length might not be the actual length, but rather the length
               of the data that is read to be pulled. */
  // virtual uint_t Length ();

  /* Feeds tx messages through the a without scanning them. */
  virtual void Feed();

  /* Pulls rx messages through the a and runs them through the scanner. */
  virtual void Pull();

 private:
  _::Expr* expr;  //< Expr for this Portal.
};                //< class I2CPortal
}  // namespace _
#endif
