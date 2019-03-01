/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /project/store/cinventory.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#ifndef HEADER_FOR_KABUKI_STORE_INVENTORY
#define HEADER_FOR_KABUKI_STORE_INVENTORY

#include "cart.h"

namespace _ {

/** A set of Items.
    
*/
class Inventory : public _::Op {
    public:

    enum {
        kDefaultSize       = 32,  //< The init size of the list.
        kMaxStringLength   = 32,  //< The name length of a name.
        kLexicalDeilimiter = '.', //< Delimiter for identifying nested objects.
    };

    /** Default constructor creates a list of kDefaultSize. */
    Inventory (const char* category);

    /** Destructs the dynamic memory. */
    ~Inventory ();

    /** Gets the count of Item(s). */
    int Length ();

    /** Adds a new item to the list and adds and updates quantity and cost.
    If the item is new, the item is added with the given information. If the
    Item is already exists in the collection, it will add the new quantity to
    the Item. If the cost is different, then the cost will be updated with
    the new cost.
    @return Returns nil upon success and a pointer to an error string upon
    failure. */
    virtual const char* Add (uid_t uid, const char* name, int64_t quantity,
                             double cost);

    /** Gets the category. */
    const char* GetCategory ();

    /** Gets the category. */
    const char* SetCategory (const char* new_name);

    /** Calculates the total cost of the list. */
    double GetTotalCost ();

    /** Sums the quantities. */
    int64_t GetTotalQuantity ();

    /** Prints the list to the console. */
    _::Text& Out (_::Text& txt);

    /** Parses Script Text Commands.
    @param text     Beginning of the Text buffer.
    @param strand_end End of the Text buffer.
    @return Returns nil upon success and an error string upon failure. */
    virtual const char* Sudo (const char* text, const char* strand_end);

    /** Abstract Script Operation(s).
    @param index The index of the expression.
    @param expr  The Expression to read and write from.
    @return      Returns null upon success, a Set header upon query, and an
    error_t ticket upon Read-Write failure. */
    virtual const _::Op* Star (uint index, _::Expr* expr);

    private:

    char                  * category_;   //< Category string.
    TArray<Inventory*> inventories_;//< Vector of nested Inventory(s).
    TArray<Item*>      items_;      //< Vector of Item(s).
    
};      //< class Inventory
}       //< namespace _
#endif  //< HEADER_FOR_KABUKI_STORE_INVENTORY
