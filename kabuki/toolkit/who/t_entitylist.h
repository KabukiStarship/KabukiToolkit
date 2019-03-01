/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/who/t_entitylist.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_ENTITYLIST
#define KABUKI_TOOLKIT_WHO_ENTITYLIST

#include "t_entity.h"

namespace _ {

/* A List of entities.
This is essentially a contact list. */
class TEntityList {
 public:
  /* Creates an empty list. */
  TEntityList() {}

  /* Gets the number of Accounts in the List. */
  SI4 GetSize() { return entities_.GetSize (); }

  /* Adds an Entity to the list. */
  void Add(TEntity* entity) { return entities_.Push (a); }

  /* Adds a list of Entity (string) to the list. */
  void Add(TEntityList& enities) {
    // entities.push_back (l);
  }

  /* Finds an entity in the list by the given search CH1. */
  TEntity* Find(const TStrand<>& string) {
    size_t length = StrandLength (query);
    if (length == 0) return nullptr;

    TEntity* ptr;

    for (SI4 i = 0; i < entities_->GetSize (); i++) {
      ptr = entities_->Element (i);
      if (ptr->Query (query)) return ptr;
    }

    return nullptr;  // static website guest entities
  }

  /* Prints this object to the log. */
   Printer& Print (Printer& o) {
   o << "Number of Accounts: " << entities_->GetCount () << (CH1)13;

   for (SI4 i = 0; i < entities_->GetSize (); i++) {
     o << "Account " << (i + 1) << ": "
       << entities_->Element (i)->GetFirstName () << (CH1)13;
   }
}

 private:
  TArray<TEntity*> entities_;  //< The list of entities.
};

}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_ENTITYLIST
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
