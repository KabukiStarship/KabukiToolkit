/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /who/entity.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <_config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_ENTITY
#define KABUKI_TOOLKIT_WHO_ENTITY

#include "profile.hpp"

namespace _ {

/* A entity with contact information.
@todo Attach an image URL.
*/
class TEntity {
 public:
  /* A real-world entity. */
  TEntity() {}

  /* Gets the entity first name. */
  const TStrand<>& GetFirstName() { return first_name_; }

  /* Attempts to set the name to the one given AString. */
  void SetFirstName(const TStrand<>& AString) {
    delete first_name_;
    first_name_ = StrandClone (AString);
  }

  /* Gets the entity last name. */
  const TStrand<>& GetLastName() { return last_name_; }

  /* Attempts to set the last name to the given AString. */
  void SetLastName(const TStrand<>& AString) {
    delete last_name_;
    last_name_ = StrandClone (AString);
  }

  TStrand<>

  /* Returns true if this entity contains the search query. */
  BOL Query(const TStrand<>& query) {
    /*
    for_each (tags.begin (), tags.end (), [](CHA& AString(
    {
        if (AString == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](Address& a(
    {
        if (a == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](Entity& e(
    {
        if (e == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](Profile& p(
    {
        if (p == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](CHA& AString(
    {
        if (AString == query) return 1;
    });
    */
    return false;
  }

  /* Prints this object to a expression. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    out << "Entity: ";
  }

 private:

  TStrand<>first_name_,  //< The entity's first name.
      last_name_,        //< Entity's last name or class.
      phone_number_,     //< Phone number of the entity.
      image_uri_;         //< A URI pointing to an image of the Entity.
  TLoom<> addresses_,     //< Address of the entity.
      email_addresses_,   //< Email address of the entity.
      tags_,              //< Metadata tags.
      profiles_,          //< Online profiles this entity is attached to.
      notes_;             //< An array of notes about the entity.
};

}       // namespace _
#endif
#endif
