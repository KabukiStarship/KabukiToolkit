/** Kabuki Toolkit
@file    /projects/kabuki_connect/console/connect_server.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>

#include "server.h"

namespace _ {

Server::Server () :
    inventory_ ("root") {

}

Inventory& Server::GetInventory () {
    return inventory_;
}

const char* Server::Sudo (const char* text, const char* strand_end) {
    if (!text) {
        return nullptr;
    }
    if (text > strand_end) {
        return nullptr;
    }
    if (*text == Inventory::kLexicalDeilimiter) {
        inventory_.Sudo (text + 1, strand_end);
    }
    return nullptr;
}

const Operation* Server::Star (wchar_t index, Expression* expr) {
    static const Operation This = { "Server",
        OperationCount (0), OperationFirst ('A'),
        "Server app hosts data to server to Client app.", 0 };
    //void* args[1];
    switch (index) {
        case '?': return ExpressionOperand (expr, &This);
        case 'A': {
            static const Operation Op65 = { "foo",
                Params<0> (), Params<0> (),
                "Why does everyone use foo?", 0 };
            if (!expr) return &Op65;
        }
    }
    return nullptr;
}

}       //< namespace _
