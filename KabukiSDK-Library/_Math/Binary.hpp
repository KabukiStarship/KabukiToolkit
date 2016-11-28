/** Kabuki Software Development Kit
    @version 0.9
    @file    /.../KabukiSDK/_.hpp
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

#include <KabukiSDK-Config.hpp>

namespace _Math {

inline void ToBinary (char* Result, int8_t Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

inline void ToBinary (char* Result, byte Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

inline void ToBinary (char* Result, int16_t Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

inline void ToBinary (char* Result, uint16_t Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

inline void ToBinary (char* Result, int32_t Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

inline void ToBinary (char* Result, uint32_t Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

inline void ToBinary (char* Result, int64_t Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

inline void ToBinary (char* Result, uint64_t Value);
/*< Converts the Value to ASCII binary string into the given buffer.
    @pre    The Result must be at least 9 bytes in length! 
*/

int8_t BinaryToInt8 (const char* Value);
/*< Converts the given string into an int8_t. */

uint8_t BinaryToUInt8 (const char* Value);
/*< Converts the given string into an uint8_t. */

int16_t BinaryToInt16 (const char* Value);
/*< Converts the given string into an int16_t. */

uint16_t BinaryToUInt16 (const char* Value);
/*< Converts the given string into an uint16_t. */

int32_t BinaryToInt32 (const char* Value);
/*< Converts the given string into an int32_t. */

uint32_t BinaryToUInt32 (const char* Value);
/*< Converts the given string into an uint32_t. */

int64_t BinaryToInt64 (const char* Value);
/*< Converts the given string into an int64_t. */

uint64_t BinaryToUInt64 (const char* Value);
/*< Converts the given string into an uint64_t. */

}   //< namespace _
