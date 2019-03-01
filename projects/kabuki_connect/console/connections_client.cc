/** Kabuki Toolkit
@file    /projects/kabuki_connect/console/connect_client.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>
#include "client.h"

namespace _ {

Client::Client () {

}

Client::~Client () {
}

const char* Client::Reset () {
}

uint Client::GetState () {
    return state_;
}

bool Client::SetState (int state) {
    if (state < 0) {
        return false;
    }
    state_ = state;
    return true;
}

_::Text& Client::Print (_::Text& txt) {
    return txt;
}

const Operation* Client::Star (uint index, _::Expr* expr) {
    static const Operation This = { "Client",
        OperationCount (0), OperationFirst ('A'),
        "kabuki::cards Script client.", 0
    };

    void* args[4];
    PlayerProxy* player;

    switch (index) {
        case '?': return &This;
        case 'A': {
            static const Operation OpA = { "SetState",
                Params<1, UI1> (), Params<0> (),
                "Sets the client state.", 0
            };
            if (!expr) return &OpA;
            byte state;
            if (!ExpressionArgs (expr, Params<1, UI1> (), Args (args, &state)))
                return expr->result;
            SetState (state);
            return nullptr;
        }
        case 'B': {
            static const Operation OpB = { "Print",
                Params<1, STR, kMaxMessageLength + 1> (), Params<0> (),
                "Sets the client state.", 0
            };
            if (!expr) return &OpB;
            char buffer[kMaxMessageLength + 1];
            if (!ExpressionArgs (expr, Params<1, STR, kMaxMessageLength + 1> (),
                           Args (args, buffer)))
                return expr->result;
            std::cout << buffer;
            return nullptr;
        }
        case 'C': {
            static const uint_t* kRxHeaderC = Params<1, SI4,
                STR, User::kMaxStatusLength + 1,
                STR, Handle::kMaxLength + 1> ();
            static const Operation OpC = { "SetPlayer",
                kRxHeaderC, Params<0> (),
                "Sets the player at the given #index to the given "
                "#dislpay_name.", 0
            };
            if (!expr) return &OpC;
            int32_t player_number;
            char status[User::kMaxStatusLength + 1],
                 handle[Handle::kMaxLength];
            if (!ExpressionArgs (expr, kRxHeaderC, Args (args, &player_number,
                                                   status, handle)))
                return expr->result;
            
            
            return nullptr;
        }
    }
    return nullptr;
}

}       //< namespace _
