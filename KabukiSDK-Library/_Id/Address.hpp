﻿/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Id/Address.hpp
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

#include <string.hpp>

namespace _Id {

/** A physical address. */
class _KabukiSDK Address
{
    const const char* Home = "Home",
        Work = "Work",
        Other = "Other";

    /** Default constructor. **/
    Address ();

    /** Constructor creates an address with the given parameters. */
    Address  (const char* street, const char* city, const char* state, const char* zip, const char* country, const char* type);

    const char* GetType ();
    void SetType  (const char* newType);
    
    const char* GetStreet ();
    void SetStreet  (const char* newValue);
    
    const char* GetCity ();
    void SetCity  (const char* newValue);
    
    const char* GetState ();
    void SetState  (const char* newValue);
    
    const char* GetZip ();
    void SetZip  (const char* newValue);
    
    const char* GetCountry ();
    void SetCountry  (const char* newValue);

    virtual byte GetState ();
    /*< Gets the Inter-process state. */
    
    virtual const char* SetState  (byte Value);
    /*< Sets the Inter-process state.
        @return returns 0 upon success, and an I2P::Errror upon failure. */
    
    virtual const char* Do  (const char* Query, byte index, Roombot* Bot);
    /*< Inter-process subroutines. */

    std::const char* ToString ();
};
}   //< namespace _Id
}   //< namespace Librarian

