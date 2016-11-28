/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Id/EntityGroup.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright  (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved  (R).

        Licensed under the Apache License, Version 2.0  (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/
 
#pragma once

#include <FreeI2P.hpp>
#include <KabukiSDK-Config.hpp>

namespace _Id {

/** A group of entities.
*/
class _KabukiSDK EntityGroup
{
    EntityGroup  (const char* Name)
    {
        name = new Name  (Name);
        accounts = new _Id.Account.Account[0];
    }

    bool isValid ()
    {
    return name.IsValid ();
    }

    const char* GetName ()
    {
        return name.ToString ();
    }

    void SetName  (const char* newName)
    {
        name.rename  (newName);
    }

    void ApplyPrivilages  (Privilages P)
    {
        if  (P == null)
            return;
        for  (int i = 0; i < base.Num_Accounts (); i++)
            accounts[i].Role ().Apply_Privilages  (P);
    }
    
    void Print (I2P::Terminal& Slot);
    /*< Prints this object to a terminal. */

    const char* ToString ()
    {
        return "Group: " + name.ToString () + " " + base.ToString ();
    }
};
}   //< namespace _Id
}   //< namespace Librarian

