/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/kabuki_connect/c_cart.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#ifndef HEADER_FOR_KABUKI_STORE_CART
#define HEADER_FOR_KABUKI_STORE_CART

#include "item.h"

namespace _ {

/** A cart of Items.
    
*/
class Cart : public Op {
 public:
  enum {
    kDefaultSize = 256,       //< Default size of the list.
    kMaxStringLength = 32,    //< Max string length.
    kLexicalDeilimiter = '.'  //< Delimiter for identifying nested objects.
  };

  /** Default constructor creates a cart with count_max and given name. */
  Cart(const char* name, int count_max = kDefaultSize);

  /** Destructs the dynamic memory. */
  ~Cart();

  /** Clears the cart. */
  void Clear();

  /** Gets the count of Item(s). */
  int Length();

  /** Adds a new item to the list and adds and updates quantity and cost.
  @return Returns nil upon success and a pointer to an error string upon
          failure.
  @desc   If the item is new, the item is added with the given information.
  If the Item is already exists in the collection, it will add the new
  quantity to the Item. If the cost is different, then the cost will be
  updated with the new cost. */
  virtual const char* Add(uid_t uid, const char* name, int64_t quantity,
                          double cost);

  /** Calculates the total cost of the list. */
  double GetTotalCost();

  /** Sums the quantities. */
  int64_t GetTotalQuantity();

  /** Gets the name_. */
  const char* GetName();

  /** Gets the name_. */
  const char* SetName(const char* new_name);

  /** Prints this object to the printer. */
  Printer&& Out(Printer&& printer = Printer & ());

  /** Parses Script Text Commands.
      @param text     Beginning of the Text buffer.
      @param strand_end End of the Text buffer.
      @return Returns nil upon success and an error string upon failure. */
  virtual const char* Sudo(const char* text, const char* strand_end);

  /** Abstract Script Operation(s).
      @param index The index of the expression.
      @param expr  The Expression to read and write from.
      @return      Returns null upon success, a Set header upon query, and an
      error_t ticket upon Read-Write failure. */
  virtual const Op* Star(wchar_t index, Expr* expr);

 private:
  char* name_;                //< Cart name string.
  TArray<Item*> items_;  //< Item(s) in the cart.

};  //< class Cart
}  // namespace _
#endif  //< HEADER_FOR_KABUKI_STORE_CART
