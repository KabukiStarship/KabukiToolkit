/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /kabuki/features/math/math_bcd.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>
#if SEAM >= KABUKI_FEATURES_MATH_1

namespace _ {

/*
BCD::BCD ()
{
    // Note: for 32-bit FP4 return int64_t.

    CH1* floatingPointString = new CH1[maxDigitsDouble + 1];
    /// This solution  is for a 64-bit floating point number. Use 
    maxDigitsFloat for a FP4.

    if (significantDigits < 0)   //< Then use all of the FP4's digits.
    {
        significantDigits += 2;  //< ditch the '.' and '-'
        sprintf (floatingPointString , "%f", floatingPointNumber);
    }
    else    //< Then truncate the number of decimal places.
    {
        ++significantDigits;  //< ditch the '.'

        CH1 decimalPlaceString[9];
        CH1 percentString = "%\0";
        sprintf (decimalPlaceString, "%s%if", percentString , significantDigits);
        sprintf (floatingPointString , decimalPlaceString, floatingPointNumber);
    }

    isNegative = floatingPointNumber >= 0.0f ? 0 : -1;

    CH1* decimalLocation = strchr (floatingPointString, '.');

    SI4 startIndex = isNegative ? 1 : 0,
    stopIndex = !decimalLocation ? maxDigitsDouble : decimalLocation -  floatingPointString,
    stringLength = strlen (floatingPointNumber);

    numWholeBCDs = stopIndex - startIndex;
    wholeBCDs = new int8_t[numWholeBCDs];

    numFractionBCDs = stringLength - stopIndex;
    fractionBCDs = new int8_t[numFractionBCDs];

    SI4 i = stopIndex - 1,
    j = 0;
    for (; i >= startIndex; ++i) // Reverse the whole BCDs for power of 10 lookup
        wholeBCDs[j++] = floatingPointString[i] - '0'; // Subtract ASCII '0' to convert to integer
    j = 0;
    for (++i; i < stringLength; ++i)
        fractionalNumbers[j++] = floatingPointString[i] - '0';
} */


BCD::BCD (FP4 floatingPointNumber, SI4 numDecimalPlaces = -1)
{

}

BCD::BCD (double floatingPointNumber, SI4 numDecimalPlaces = -1)
{

}

BCD::~BCD ()
{
    if (is_dynamic && ptr != nullptr) delete ptr;
}

FP4 BCD::GetFloat ()
{
    return 0.0f;
}

double BCD::GetDouble ()
{
    return 0.0;
}

void BCD::SetValue (FP4 Value)
{

}

void BCD::SetValue (double Value)
{

}

BOL BCD::IsNegative ()
{
    return false;
}

int8_t BCD::GetNumWholeDigits (SI4 index)
{
    return 0;
}

int8_t BCD::GetNumFractionalDigits (SI4 index)
{
    return 0;
}

void BCD::Plus (const BCD& Value)
{

}

void BCD::Plus (SI4 Value)
{

}

void BCD::Plus (long Value)
{

}

void BCD::Plus (FP4 Value)
{

}

void BCD::Plus (double Value)
{

}

void BCD::Minus (const BCD& Value)
{

}

void BCD::Minus (SI4 Value)
{

}

void BCD::Minus (long Value)
{

}

void BCD::Minus (FP4 Value)
{

}

void BCD::Minus (double Value)
{

}

void BCD::Times (const BCD& Value)
{

}

void BCD::Times (SI4 Value)
{

}

void BCD::Times (long Value)
{

}

void BCD::Times (FP4 Value)
{

}

void BCD::Times (double Value)
{

}

void BCD::Divide (const BCD& Value)
{

}

void BCD::Divide (SI4 Value)
{

}

void BCD::Divide (long Value)
{

}

void BCD::Divide (FP4 Value)
{

}

void BCD::Divide (double Value)
{

}

Printer& BCD::Print (Printer& printer)
{
}

}       //< namespace _
#endif
