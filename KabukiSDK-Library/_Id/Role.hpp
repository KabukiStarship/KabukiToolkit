/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Id/Role.hpp
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

/** A role that an entinty plays in an organization.
    A role 
*/
class _KabukiSDK Role
{
    Role (const char* aUsername, const char* aPassword);
    /*< Constructs a user with the given username and password. */

    const char* getDescription ();
    /*<  */

    const char* getPassword ();
    /*<  */

    const char* encryptPassword ();
    /*<  */

    bool isValid ();
    /*<  */

    bool verify (string aUsername, string aPassword);

    bool getLogin (Account thisAccount);
    /*<  */
    
    bool equals (Role aUser);
    /*<  */
    
    inline void print (I2P::Terminal& slot);
    /*< Prints this object to a terminal. */

    private:

    const char* description,
        password;

    // Currently the user is able log into more the one account at a time. This could cause a security threat.
    //Account.List activeAccounts;
};
}   //< namespace _Id


