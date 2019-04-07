/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /project/store/cserver.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#ifndef HEADER_FOR_KABUKI_STORE_SERVER
#define HEADER_FOR_KABUKI_STORE_SERVER

#include "inventory.h"

namespace _ {

class Server: public _::Room {
    public:

    typedef enum States {
        kStateShuttingDown = 0, //< Server State 0: Shutting down.
        kStateBooting      = 1, //< Server state 1: Booting.
        kStateServing      = 2, //< Server state 2: Serving.
    } State;

    /* Constructs the default server. */
    Server ();

    /** Gets the inventory. */
    Inventory& GetInventory ();

    /** Handles Script Commands.
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

    Inventory inventory_; //< Inventory root.

};      //< class Server
}       //< namespace _
#endif  //< HEADER_FOR_KABUKI_STORE_SERVER
