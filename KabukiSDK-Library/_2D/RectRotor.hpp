/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/include/_2D/RectRotor_f.hpp
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
#include "_2D/Rect.hpp"

namespace _2D {

class _KabukiSDK RectRotor_f
/*< Utility class for rotating rectangles. */
{
    public:
    
    RectRotor_f  (bool rotated, const Rect_f& area);
    /*< Constructs a RectRotar with an unrotated rectangle. */

    float GetX () const;
    /*< Gets the X value. */

    float& GetX_ref ();

    float GetY () const;

    float& GetY_ref ();

    unsigned GetWidth () const;

    unsigned& GetWidth_ref ();

    unsigned GetHeight () const;

    unsigned& GetHeight_ref ();

    float GetRight () const;

    float GetBottom () const;

    const Rect_f& Rotate () const;

    void Print (I2P::Terminal& Slot);
    /*< Prints this object to the terminal. */

    private:

    bool rotated;       //< Flag for if rectangle has been rotated.

    Vect_f vector;      //< The unrotated vector.

    Rect_f area;        //< The rotated rectangle.
};  //< class _KabukiSDK RectRotor_f

}   //< namespace _2D
