/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki_toolkit/who/t_address.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_ADDRESS
#define KABUKI_TOOLKIT_WHO_ADDRESS 1

namespace _ {

typedef enum { HomeAddress = 0, WordAddress, OtherAddress } AddressType;

/* A physical address. */
class TAddress {
 public:
  /* Default constructor. */
  TAddress() {
    /// Nothing to do here! :-)
  }

  /* Creates an address with the given parameters. */
  TAddress(const TStrand<>& street, const TStrand<>& aCity, const TStrand<>& aState,
          const TStrand<>& aZip, const TStrand<>& aCcountry, AddressType aType)
    : street_ (StrandClone (street)),
      city_ (StrandClone (city)),
      state_ (StrandClone (state)),
      zip_ (StrandClone (zip)),
      country_ (StrandClone (country)),
      type_ (type) {}

  /* Gets the street address. */
  const TStrand<>& GetStreet() { return street_; }

  /* Sets the street address. */
  void SetStreet(const TStrand<>& AString) {
    delete street_;
    street_ = StrandClone (AString);
  }

  /* Gets the city. */
  const TStrand<>& GetCity() { return city_; }

  /* Sets the city. */
  void SetCity(const TStrand<>& AString) {
    delete city_;
    city_ = StrandClone (AString);
  }

  /* Gets the State. */
  const TStrand<>& GetState() { return state_; }
  

  /* Sets the state. */
  void SetState(const TStrand<>& AString) {
    delete state_;
    state_ = StrandClone (AString);
  }
  

  /* Gets the zip code. */
  const TStrand<>& GetZip();

  /* Sets the zip code. */
  void SetZip(const TStrand<>& AString) {
    delete zip_;
    zip_ = StrandClone (AString);
  }

  /* Gets the country. */
  const TStrand<>& GetCountry() { return country_; }

  /* Sets the country. */
  void SetCountry(const TStrand<>& AString) {
    delete country_;
    country_ = StrandClone (AString);
  }

  /* Gets the address type.
      The address type means street, PO box, etc.
  */
  AddressType GetType() { return type_; }

  /* Sets the address type. */
  void SetType(AddressType t) { type_ = t; }

  /* Prints this object to a Expr. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    out << "Address:"
      << "\n Street         : " << street_ << "\n City           : " << city_
      << "\n State/Province : " << state_ << "\n Zip/Postal Code: " << zip_
      << "\n Country        : " << country_ << "\n";
  }

 private:
  TStrand<> *street_, //< The street address.
      *city_,         //< The city of address
      *state_,        //< The state of address
      *zip_,          //< The zip code of address
      *country_;      //< The country of address
  AddressType type_;  //< The type of address

  static inline const CH1** AddressTypeLabels () {
    static const CH1* labels[] = { "Home", "Work", "Other" };
    return labels;
  }

  static inline const char* AddressTypeLabel (AddressType type) {
    if (type < 0 || type >= 3) return AddressTypeLabels ()[0];
    if (type < 0 || type > 2) return AddressTypeLabels ()[2];
    return AddressTypeLabels ()[type];
  }
};

}  // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_ADDRESS
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
