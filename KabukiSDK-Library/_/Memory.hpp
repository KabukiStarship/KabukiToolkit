/** Kabuki Software Development Kit
    @file    /.../_/Memory.hpp
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

inline int WordAlign  (int16_t Value);
/*< Word-aligns the given value. */

inline int WordAlign  (uint16_t Value);
/*< Word-aligns the given value. */

inline int WordAlign  (int32_t Value);
/*< Word-aligns the given value. */

inline int WordAlign  (uint32_t Value);
/*< Word-aligns the given value. */

inline int WordAlign  (int64_t Value);
/*< Word-aligns the given value. */

inline int WordAlign  (uint64_t Value);
/*< Word-aligns the given value. */

}   //< namespace _
