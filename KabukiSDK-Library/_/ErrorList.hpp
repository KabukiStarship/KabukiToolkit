/** Kabuki Software Development Kit
    @file    /.../_/ErrorList.cpp
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

namespace _ {

template<unsigned int MaxNumErrors>
class _KabukiSDK ErrorList
/** An array of error strings.
    @code
    ErrorList<5> errors;

    @endcode
*/
{
    public:

    ErrorList ()
    /** Default simple constructor. */
    :   numErrors  (0)
    {
        /// Nothing to do here! :-)
    }

    void clear () { numErrors = 0; }
    /*< Clears the error list. */

    unsigned int getNumErrors () { return numErrors; }
    /*< Gets the number of errors. */

    void report  (const char* Error)
    /** Reports an error with the given message. */
    {
        if  (numErrors >= MaxNumErrors) return;
        errors[numErrors++] = Error;
        return this;
    }
    
    ErrorList& operator +=  (const char* Error)
    /** Reports an error with the given message. */
    {
        Report  (Error);
        return this;
    }

    const char* getErrors () { return errors; }
    /*< Gets the list of errors. */
    
    inline void print (I2P::Terminal& slot)
    /*< Prints this object to a terminal. */
    {
        for  (int i = 0; i < numErrors; ++i)
            printLine (errors[i]);
    }

    private:

    uint numErrors;

    const char* errors[MaxNumErrors];
};

}   //< namespace _
