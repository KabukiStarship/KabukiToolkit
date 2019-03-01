/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/data/t_iterator.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_DATA_1
#if SEAM == KABUKI_TOOLKIT_DATA_1
#ifndef INCLUDED_KABUKI_TOOLKIT_DATA_ITERATOR
#define INCLUDED_KABUKI_TOOLKIT_DATA_ITERATOR

#include "config.h"

namespace _ {

/* An interface for an object iterator. */
template<typename T>
struct Iterator {
  /* Iterates to the next item in the sequence. */
  virtual T* Next () = 0;

  /* Resets the iterator to the beginning. */
  virtual void Reset () = 0;

  /* Indicates if the iteration is complete.
  @return Returns 0 when the iteration is complete. */
  virtual SI4 IsDone () = 0;
};

/* Interface for an Iterable Collection of objects. */
template<typename T>
struct Iterable {
  /* Gets an instance of an Iterator. */
  virtual Iterator<T>* GetIterator () = 0;
};      //< Iterable

}       //< namespace _
#endif
#endif
