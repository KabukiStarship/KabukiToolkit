/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_/Converter.hpp
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

namespace _ {
    
// _B_i_n_a_r_y________________________________________________________________
    
__Inline void convertToBinary  (char* Buffer, uint8_t Value);
/*< converts the given value to a binary string. */

__Inline void convertToBinary  (char* Buffer, uint16_t Value);
/*< converts the given value to a binary string. */

__Inline void convertToBinary  (char* Buffer, uint32_t Value);
/*< converts the given value to a binary string. */

__Inline void convertToBinary  (char* Buffer, uint64_t Value);
/*< converts the given value to a binary string. */

__Inline uint8_t convertBinaryToUInt8 (char* Buffer);
/*< converts a binary number stored as a string to a uint8_t. */

__Inline uint16_t convertBinaryToUInt16 (char* Buffer);
/*< converts a binary number stored as a string to a uint16_t. */

__Inline uint32_t convertBinaryToUInt32 (char* Buffer);
/*< converts a binary number stored as a string to a uint32_t. */

__Inline uint64_t convertBinaryToUInt64 (char* Buffer);
/*< converts a binary number stored as a string to a uint64_t. */

// _H_e_x______________________________________________________________________

inline char convertToHexChar (uint8_t Value);
/*< An array of hex strings for ASCII '0' - '9' an 'A' - 'F'. */

inline char convertToHexValue (char Value);
/*< converts to a hex value. */

__Inline void convertToHexString (char* Buffer, uint16_t Value);
/*< converts the given Value to a hex string. */

__Inline void convertToHexString  (char* Buffer, uint8_t Value);
/*< converts the given value to a string. */

__Inline int8_t convertHexToInt8 (const char* Value);
/*< converts from hex string to an int. */

__Inline int16_t convertHexToInt16 (const char* Value);
/*< converts from hex string to an int. */

__Inline int32_t convertHexToInt32 (const char* Value);
/*< converts from hex string to an int. */

__Inline int64_t convertHexToInt64 (const char* Value);
/*< converts from hex string to an int. */

}   //< namespace _
