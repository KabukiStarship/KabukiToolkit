/** Kabuki Toolkit
@file    /projects/kabuki_connect/console/connect_item.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>

#include "item.h"

namespace _ {

Item::Item (uid_t uid, const char* name, double cost, int64_t quantity) :
    name_     (StrandClone (name)         ),
    uid_      (uid                        ),
    quantity_ (quantity < 0 ? 0 : quantity),
    cost_     (cost                       ) {
    // Nothing to do here! ({:->)+=<
}

Item::~Item () {
    delete name_;
    delete description_;
    delete supply_uid_;
}

const char* Item::GetName () const {
    return name_;
}

const char* Item::SetName (const char* new_name) {
    if (!new_name) {
        return "new_name can't be nil";
    }
    delete name_;
    name_ = StrandClone (new_name);
    return nullptr;
}

const char* Item::GetDescription () const {
    return description_;
}

const char* Item::SetDescription (const char* new_description) {
    if (!new_description) {
        return "new_description can't be nil";
    }
    delete description_;
    description_ = StrandClone (new_description);
    return nullptr;
}

const char* Item::GetSupplyUid () const {
    return supply_uid_;
}

const char* Item::SetSupplyUid (const char* new_description) {
    if (!new_description) {
        return "new_description can't be nil";
    }
    delete description_;
    description_ = StrandClone (new_description);
    return nullptr;
}

uid_t Item::GetUid () const {
    return uid_;
}

const char* Item::SetUid (uid_t value) {
    if (value == 0) {
        return "uid can't be 0";
    }
    uid_ = value;
    return nullptr;
}

int64_t Item::GetQuantity () const {
    return uid_;
}

const char* Item::AddQuantity (int64_t value) {
    quantity_ += value;
    return nullptr;
}

const char* Item::SetQuantity (int64_t quanity) {
    if (quanity > 0) {
        return "Item quantity can't be negative";
    }
    quantity_ = quanity;
    return nullptr;
}

double Item::GetCost () const {
    return cost_;
}

const char* Item::AddCost (double value) {
    cost_ += value;
    return nullptr;
}

const char* Item::SetCost (double cost) {
    if (cost > 0) {
        return "Item cost can't be negative";
    }
    cost_ = cost;
    return nullptr;
}

double Item::GetTotalCost () const {
    return ((double)quantity_) * cost_;
}

_::Text& Item::Print (_::Text& txt) {
    txt << "\n| Item         :"
        << "\n| Description  : " << name_
        << "\n| Supplier uid : " << supply_uid_
        << "\n| Unique id    : " << uid_
        << "\n| Quantity     : " << quantity_
        << "\n| Cost per item: " << cost_
        << "\n| Cost total   : " << GetTotalCost ();
    return txt;
}

Text& Item::Print (Text& txt) {
    return txt << Print (txt);
}

const Operation* Item::Star (wchar_t index, Expression* expr) {
    static const Operation This = { "Item",
        OperationCount (0), OperationFirst ('A'),
        "A Inventory item.", 0
    };
    //void* args[1];
    switch (index) {
        case '?': return ExpressionOperand (expr, &This);
        case 'A':
        {
            static const Operation Op65 = { "set",
                Params<0> (), Params<0> (),
                "Why does everyone use foo?", 0 };
            if (!expr) return &Op65;
        }
    }
    return nullptr;
}

const char* Item::Sudo (const char* text, const char* strand_end) {
    if (!text) {
        return nullptr;
    }
    if (text > strand_end) {
        return nullptr;
    }
    const char* token;
    char        c;
    enum { kSize = Text::kSize };
    char    buffer[kSize];
    uid_t   uid;
    int64_t quantity;
    double  cost;

    while (++text <= strand_end) {c = *text;
        token = TextSkipSpaces (text, strand_end);
        c = *text;
        if (c == '-') {
            if (++text > strand_end) {
                return nullptr;
            }
            c = *text;
            if (token = TokenEquals (token, strand_end, "name")) {
                if (!(token = TextRead (token + 1, strand_end, buffer,
                                        buffer + kSize))) {
                    return nullptr;
                }
                SetName (buffer);
            } else if (token = TokenEquals (token, strand_end, "description")) {
                if (!(token = TextRead (token + 1, strand_end, buffer,
                                        buffer + kSize))) {
                    return nullptr;
                }
                SetDescription (buffer);
            } else if (token = TokenEquals (token, strand_end, "supply_uid")) {
                if (!(token = TextRead (token + 1, strand_end, buffer,
                                        buffer + kSize))) {
                    return nullptr;
                }
                SetSupplyUid (buffer);
                return token;
            } else if (token = TokenEquals (token, strand_end, "uid")) {
                if (!(token = TextRead (token + 1, strand_end, uid))) {
                    return nullptr;
                }
                SetUid (uid);
            } else if (token = TokenEquals (token, strand_end, "quantity")) {
                if (!(token = TextRead (token + 1, strand_end, quantity))) {
                    return nullptr;
                }
                SetQuantity (quantity);
            } else if (token = TokenEquals (token, strand_end, "cost")) {
                if (!(token = TextRead (token + 1, strand_end, cost))) {
                    return nullptr;
                }
                SetCost (cost);
            }
        } else {
            return nullptr;
        }
    }
    if (token = TokenEquals (text, strand_end, "set")) {

    } else if (token = TokenEquals (text, strand_end, "print")) {
        cout << Print ();
    } else if (token = TokenEquals (text, strand_end, "?")) {
        cout << Star (0, 0)->description;
    }
}

}       //< namespace _
