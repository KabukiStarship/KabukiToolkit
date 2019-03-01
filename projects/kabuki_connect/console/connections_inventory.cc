/** Kabuki Toolkit
@file    /projects/kabuki_connect/console/connect_inventory.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>

#include "inventory.h"

namespace _ {

Inventory::Inventory (const char* category) :
    category_  (StrandClone (category)),
    items_     () {
}

Inventory::~Inventory () {
    // We used some dynamic memory for the name strings.
    int count = Length ();
    if (count == 0) {
        return;
    }
    for (int i = Length () - 1; i > 0; --i) {
        delete items_[i];
    }
    delete[] category_;
}

int Inventory::Length () {
    return items_.size ();
}

const char* Inventory::Add (uid_t uid, const char* name, int64_t quantity,
                           double cost) {
    if (!name) {
        return "name can't be nil";
    }
    // Search for the item.
    for (int i = Length () - 1; i > 0; --i) {
        Item* item = items_[i];
        if (StrandEquals (name, item->GetName ())) {
      // It's a duplicate so update the quantity and price.
            item->AddQuantity (quantity);
            if (item->GetCost () != cost) {
                item->SetCost (cost);
            }
            return nullptr;
        }
    }
    // Add an Item.
    items_.push_back (new Item (uid, name, cost, quantity));
    return nullptr;
}

double Inventory::GetTotalCost () {
    double total = 0.0;
    int count = Length ();
    if (!count) {
        return total;
    }
    for (; count > 0; --count) {
        Item* item = items_[count];
        total += ((double)item->GetQuantity ()) * item->GetCost ();
    }
    return total;
}

const char* Inventory::GetCategory () {
    return category_;
}

const char* Inventory::SetCategory (const char* new_catetory) {
    if (!new_catetory) {
        return nullptr;
    }
    delete category_;
    category_ = StrandClone (new_catetory);
    return ;
}

int64_t Inventory::GetTotalQuantity () {
    int64_t quanity = 0;
    for (int i = Length () - 1; i > 0; --i) {
        quanity += items_[i]->GetQuantity ();
    }
    return quanity;
}

/*
void Inventory::WriteToOpenFile (std::ofstream& file) {
    if (category_[0] != '$')
        file << '$';
    file << category_ << "," << GetCount () << ",\n";
    for (int i = 0; i < GetCount (); ++i) {
        Item* item = items_[i];
        file << item->GetName () << ", " << item->GetQuantity () << ", "
             << item->GetPrice () << " \n";
    }
}*/

Text& Inventory::Print (Text& txt) {
    txt << "\n| Inventory Category: " << GetCategory ();
    enum { kSize = 32 };
    double quantity,   //< Temp var.
           price;      //< Temp var.
    char   buffer[kSize]; //< Temp buffer.

    txt << txt.Centered (category_, 20)
        << GetTotalQuantity ()
        << txt.Centered (buffer, 20)
        << txt.Centered ("", 20)
        << GetTotalCost ()
        << txt.Centered (buffer, 20, true)
        << txt.Lines (4);

    for (int i = 0; i < Length (); ++i) {
        Item* item = items_[i];
        price = item->GetCost ();
        quantity = (double)item->GetQuantity ();
        txt << txt.Centered (item->GetName (), 20)
            << item->GetQuantity ()
            << txt.Centered (buffer, 20)
            << price
            << txt.Centered (buffer, 20)
            << quantity * price
            << txt.Centered (buffer, 20, true);
    }
    return txt.Break ("|", '-', 0);
}

const char* Inventory::Sudo (const char* strand, const char* strand_end) {
    if (!strand) {
        return nullptr;
    }
    if (strand > strand_end) {
        return nullptr;
    }
    const char* next_token;
    if (*strand == kLexicalDeilimiter) {
        for (int i = Length () - 1; i > 0; --i) {
            Inventory* inventory = inventories_[i];
            next_token = TokenEquals (strand, strand_end,
                                      inventory->GetCategory ());
            if (next_token) {
                return inventory->Sudo (next_token + 1, strand_end);
            }
        }
    }
    for (int i = Length () - 1; i > 0; --i) {
        Item* item = items_[i];
        next_token = TokenEquals (strand, strand_end,  item->GetName ());
        if (next_token) {
            return item->Sudo (next_token + 1, strand_end);
        }
    }
    return "couldn't find item or inventory";
}

const Operation* Inventory::Star (wchar_t index, Expression* expr) {
    static const Operation This = { "Inventory",
        OperationCount (0), OperationFirst ('A'),
        "", 0 };
    switch (index) {
        case '?': return ExpressionOperand (expr, &This);
        case 'A': {
            static const Operation OpA = { "Inventory",
                OperationCount (0), OperationFirst ('A'),
                "", 0 };
        }
    }
    return nullptr;
}

}       //< namespace _
