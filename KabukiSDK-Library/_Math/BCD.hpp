/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_2D/Vect.hpp
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

#include <float.hpp>

#include <FreeI2P.hpp>
#include <KabukiSDK-Config.hpp>

namespace _Math {

class _KabukiSDK BCD
/*< Binary coded decimal for precise math.
    This BCD class uses optional dynamic memory. The class stores a pointer to a 
    byte array, and this byte array contains four bytes at the begining for the 
    following data. This allows for tigh
    __________________________________
    | Byte 4-N | Is Negative         |
    |----------|---------------------|
    | Byte 3   | Is Negative         |
    |----------|---------------------|
    | Byte 2   | Total Length.       |
    |----------|---------------------|
    | Byte 1   | Num Whole Digits.   |
    |----------|---------------------|
    | Byte 0   | Uses dynamic memory |
    |__________|_____________________|
*/
{
    public:

    enum { 
        maxDigitsFloat = 3 + FLT_MANT_DIG - FLT_MIN_EXP,
        maxDigitsDouble = 3 + DBL_MANT_DIG - DBL_MIN_EXP
    };

    BCD  (float floatingPointNumber, int numDecimalPlaces = -1);
    /*< Constructs a BCD from a float. */

    BCD  (double floatingPointNumber, int numDecimalPlaces = -1);
    /*< Constructs a BCD from a double. */

    ~BCD ();
    /*< Destructor destructs if dynamic memory is used. */

    float GetFloat ();
    /*< Gets the BCD value as a float. */

    float GetDouble ();
    /*< Gets the BCD value as a double. */

    void SetValue (float Value);
    /*< Sets the BCD value to the new Value. */

    void SetValue (double Value);
    /*< Sets the BCD value to the new Value. */

    bool IsNegative ();
    /*< Returns true of this BCD is negative. */

    int8_t GetNumWholeDigits  (int index);
    /*< Gets the number of whole BCDs. */

    int8_t GetNumFractionalDigits  (int index);
    /*< Gets the number of fractional digits. */

    void Plus (const BCD& Value);
    /*< Pluss the given Value to this BCD. */

    void Plus (int Value);
    /*< Pluss the given Value to this BCD. */

    void Plus (long Value);
    /*< Pluss the given Value to this BCD. */

    void Plus (float Value);
    /*< Pluss the given Value to this BCD. */

    void Plus (double Value);
    /*< Pluss the given Value to this BCD. */

    void Minus (const BCD& Value);
    /*< Subtracts the given Value to this BCD. */

    void Minus (int Value);
    /*< Subtracts the given Value to this BCD. */

    void Minus (long Value);
    /*< Subtracts the given Value to this BCD. */

    void Minus (float Value);
    /*< Subtracts the given Value to this BCD. */

    void Minus (double Value);
    /*< Subtracts the given Value to this BCD. */

    void Times (const BCD& Value);
    /*< Multiples the given Value to this BCD. */

    void Times (int Value);
    /*< Multiples the given Value to this BCD. */

    void Times (long Value);
    /*< Multiples the given Value to this BCD. */

    void Times (float Value);
    /*< Multiples the given Value to this BCD. */

    void Times (double Value);
    /*< Multiples the given Value to this BCD. */

    void Divide (const BCD& Value);
    /*< Divides the given Value to this BCD. */

    void Divide (int Value);
    /*< Divides the given Value to this BCD. */

    void Divide (long Value);
    /*< Divides the given Value to this BCD. */

    void Divide (float Value);
    /*< Divides the given Value to this BCD. */

    void Divide (double Value);
    /*< Divides the given Value to this BCD. */

    void Print (I2P::Terminal& Slot);
    /*< Prints the BCD to the terminal. */

    private:

    byte* ptr;              //< Pointer to the BCD string.

    byte isDynamic,         //< Flag for if using dynamic memory.
        numWholeDigits,     //< The number of whole digits.
        totalLength,        //< The total length of the BCD string.
        isNegative;         //< Flag for it is negative or not (0 for positive and '-' for negative.)
};

} // namespace _Math
