/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/math/c_bcd.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#ifndef KABUKI_FEATURES_MATH_BCD_C
#define KABUKI_FEATURES_MATH_BCD_C 1

namespace _ {

/* Binary coded decimal for precise math.
This BCD class uses optional dynamic memory. The is_dynamic flag if true 
will trigger the destructor on the ptr. */
class SDK BCD {
    public:

    enum { 
        maxDigitsFloat = 3 + FLT_MANT_DIG - FLT_MIN_EXP,
        maxDigitsDouble = 3 + DBL_MANT_DIG - DBL_MIN_EXP
    };

    /* Constructs a BCD from a FP4. */
    BCD (FP4 floatingPointNumber, SI4 numDecimalPlaces = -1);

    /* Constructs a BCD from a double. */
    BCD (double floatingPointNumber, SI4 numDecimalPlaces = -1);

    /* Destructor destructs if dynamic memory is used. */
    ~BCD ();

    /* Gets the BCD value as a FP4. */
    FP4 GetFloat ();

    /* Gets the BCD value as a double. */
    double GetDouble ();

    /* Sets the BCD value to the new Value. */
    void SetValue (FP4 value);

    /* Sets the BCD value to the new Value. */
    void SetValue (double value);

    /* Returns true of this BCD is negative. */
    BOL IsNegative ();

    /* Gets the number of whole BCDs. */
    int8_t GetNumWholeDigits (SI4 index);

    /* Gets the number of fractional digits. */
    int8_t GetNumFractionalDigits (SI4 index);

    /* Adds the given Value to this BCD. */
    void Plus (const BCD& value);

    /* Adds the given Value to this BCD. */
    void Plus (SI4 value);

    /* Adds the given Value to this BCD. */
    void Plus (long value);

    /* Adds the given Value to this BCD. */
    void Plus (FP4 value);

    /* Adds the given Value to this BCD. */
    void Plus (double value);

    /* Subtracts the given Value to this BCD. */
    void Minus (const BCD& value);

    /* Subtracts the given Value to this BCD. */
    void Minus (SI4 value);

    /* Subtracts the given Value to this BCD. */
    void Minus (long value);

    /* Subtracts the given Value to this BCD. */
    void Minus (FP4 value);

    /* Subtracts the given Value to this BCD. */
    void Minus (double value);

    /* Multiples the given Value to this BCD. */
    void Times (const BCD& value);

    /* Multiples the given Value to this BCD. */
    void Times (SI4 value);

    /* Multiples the given Value to this BCD. */
    void Times (long value);

    /* Multiples the given Value to this BCD. */
    void Times (FP4 value);

    /* Multiples the given Value to this BCD. */
    void Times (double value);

    /* Divides the given Value to this BCD. */
    void Divide (const BCD& value);

    /* Divides the given Value to this BCD. */
    void Divide (SI4 value);

    /* Divides the given Value to this BCD. */
    void Divide (long value);

    /* Divides the given Value to this BCD. */
    void Divide (FP4 value);

    /* Divides the given Value to this BCD. */
    void Divide (double value);

    /* Prints the BCD to the terminal. */
    Printer& Print (Printer& printer);

    private:

    CH1  is_dynamic_,        //< Flag for if using dynamic memory.
          whole_digit_count_, //< The number of whole digits.
          digit_count_,       //< The total length of the BCD string.
          sign_,              //< Flag for it is negative ('-') or not (0).
          buffer_;
};

} // namespace _
#endif
#endif
