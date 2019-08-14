/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /firmware/c_portali2c.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright 2014-19 (C) Cale Jamison McCollough <<http://calemccollough.github.io>>. 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain 
one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_SPI_PORTAL
#define INCLUDED_KABUKI_FEATURE_TEK_SPI_PORTAL 1

namespace _ {

/* A type of Portal that allows for reading and writing to the local system. */
class SpiPortal : public _::Portal {
public:

  /* Constructs a SpiPortal. */
  SpiPortal (_::Expr* expr, PinName mosi_pin, PinName miso_pin,
	     PinName clock_pin, PinName strobe_pin);

  /* Feeds B-Output bytes through the slot. */
  virtual void Feed ();

  /* Pulls B-Input bytes through the slot. */
  virtual void Pull ();

private:

  _::Expr* expr_;        //< Expr for this Portal.
  SI4            start_index_, //< Start index of the buffer.
		     stop_index_,  //< Stop index of the buffer.
		     buffer_size_; //< Buffer size in bytes.
  SPI            spi_;         //< SPI port.
};
}       //< namespace _
#endif  //< INCLUDED_KABUKI_FEATURE_TEK_SPI_PORTAL
