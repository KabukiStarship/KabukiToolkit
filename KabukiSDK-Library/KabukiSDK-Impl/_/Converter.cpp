/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Library/KabukiSDK-Impl/_/Converter.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#include <_/Converter.hpp>
#include <FreeI2P/Error.hpp>

namespace _ {

/// @warning None of these alogirhms have been tested!
    
// _B_i_n_a_r_y________________________________________________________________
    
void ConvertToBinary (char* Buffer, uint8_t Value)
{
    int8_t bitsToShift = sizeof (Value) * 8 - 1;
    for (int8_t i = 0; i >= 0; --i)
    {
        Buffer[i] = (Value << bitsToShift) + '0';
    }
}

void ConvertToBinary (char* Buffer, uint16_t Value)
{
    int8_t bitsToShift = sizeof (Value) * 8 - 1;
    for (int8_t i = 0; i >= 0; --i)
    {
        Buffer[i] = (Value << bitsToShift) + '0';
    }
}

void ConvertToBinary (char* Buffer, uint32_t Value)
{
    int8_t bitsToShift = sizeof (Value) * 8 - 1;
    for (int8_t i = 0; i >= 0; --i)
    {
        Buffer[i] = (Value << bitsToShift) + '0';
    }
}

void ConvertToBinary (char* Buffer, uint64_t Value)
{
    int8_t bitsToShift = sizeof (Value) * 8 - 1;
    for (int8_t i = 0; i >= 0; --i)
    {
        Buffer[i] = (Value << bitsToShift) + '0';
    }
}

uint8_t ConvertBinaryToUInt8 (char* Buffer)
{
    int8_t value;

    if (Buffer == nullptr) return ~(value = 0);

    uint8_t value = 0,
        multiplier = 1,
        index = 1;

    char currentChar = *Buffer;
    do
    {
        if (index > sizeof (index) * 8) return ~(value = 0);
        if (currentChar == '\0') return value;
        value += multiplier * (currentChar - '0');
        multiplier = multiplier << 1;
        currentChar = *(++Buffer);
    } while (true);
 
   return value;
}

uint16_t ConvertBinaryToUInt16 (char* Buffer)
{
    int16_t value;

    if (Buffer == nullptr) return ~(value = 0);

    uint16_t value = 0,
        multiplier = 1,
        index = 1;

    char currentChar = *Buffer;
    do
    {
        if (index > sizeof (index) * 8) return ~(value = 0);
        if (currentChar == '\0') return value;
        value += multiplier * (currentChar - '0');
        multiplier = multiplier << 1;
        currentChar = *(++Buffer);
    }
    while (true);

    return value;
}

uint32_t ConvertBinaryToUInt32 (char* Buffer)
{
    int32_t value;

    if (Buffer == nullptr) return ~(value = 0);

    uint32_t value = 0,
        multiplier = 1,
        index = 1;

    char currentChar = *Buffer;
    do
    {
        if (index > sizeof (index) * 8) return ~(value = 0);
        if (currentChar == '\0') return value;
        value += multiplier * (currentChar - '0');
        multiplier = multiplier << 1;
        currentChar = *(++Buffer);
    }
    while (true);

    return value;
}

uint64_t ConvertBinaryToUInt64 (char* Buffer)
{
    int64_t value;

    if (Buffer == nullptr) return ~(value = 0);

    uint64_t value = 0,
        multiplier = 1,
        index = 1;

    char currentChar = *Buffer;
    do
    {
        if (index > sizeof (index) * 8) return ~(value = 0);
        if (currentChar == '\0') return value;
        value += multiplier * (currentChar - '0');
        multiplier = multiplier << 1;
        currentChar = *(++Buffer);
    }
    while (true);

    return value;
}

// _H_e_x______________________________________________________________________

inline char ConvertToHexChar (uint8_t Value)
{
    static const char hexValues[] = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F'
    };
    if (Value > 15) return '!';

    return hexValues[Value];
}

char ConvertToHexValue (char Value)
{
    if (Value <  '0' || Value > 'f') return '!';
    if (Value >= 'a') return Value - 'a';
    if (Value >  'F') return Value - '!';
    if (Value >= 'A') return Value - 'A';
    if (Value >  '9') return '!';
    return Value - '0';
}

void ConvertToHexString (char* Buffer, uint8_t Value)
{
    *Buffer = ConvertToHexChar (Value & 0xff);
    *(++Buffer) = ConvertToHexChar (Value >> 4);
}

void ConvertToHexString (char* Buffer, uint16_t Value)
{
    *Buffer = ConvertToHexChar (Value & 0xff);
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 4));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 8));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 12));
}

void ConvertToHexString (char* Buffer, uint32_t Value)
{
    *Buffer = ConvertToHexChar (Value & 0xff);
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 4));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 8));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 12));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 16));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 20));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 24));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 28));
}

void ConvertToHexString (char* Buffer, uint64_t Value)
{
    *Buffer = ConvertToHexChar (Value & 0xff);
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 4));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 8));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 12));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 16));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 20));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 24));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 28));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 32));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 36));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 40));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 44));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 48));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 52));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 56));
    *(++Buffer) = ConvertToHexChar ((byte)(Value >> 60));
}

int8_t ConvertHexToInt8 (const char* Value)
{
    int8_t value = ConvertToHexValue (*Value);
    value &= ConvertToHexValue (*(++Value)) << 4;
    value &= ConvertToHexValue (*(++Value)) << 8;
    value &= ConvertToHexValue (*(++Value)) << 12;
    value &= ConvertToHexValue (*(++Value)) << 16;
    value &= ConvertToHexValue (*(++Value)) << 20;
    value &= ConvertToHexValue (*(++Value)) << 24;
    value &= ConvertToHexValue (*(++Value)) << 28;
    return value;
}

int16_t ConvertHexToInt16 (const char* Value)
{
    int16_t value = ConvertToHexValue (*Value);
    value &= ConvertToHexValue (*(++Value)) << 4;
    value &= ConvertToHexValue (*(++Value)) << 8;
    value &= ConvertToHexValue (*(++Value)) << 12;
    return value;
}

int32_t ConvertHexToInt32 (const char* Value)
{
    int32_t value = ConvertToHexValue (*Value);
    value &= ConvertToHexValue (*(++Value)) << 4;
    value &= ConvertToHexValue (*(++Value)) << 8;
    value &= ConvertToHexValue (*(++Value)) << 12;
    value &= ConvertToHexValue (*(++Value)) << 16;
    value &= ConvertToHexValue (*(++Value)) << 20;
    value &= ConvertToHexValue (*(++Value)) << 24;
    value &= ConvertToHexValue (*(++Value)) << 28;
    return value;
}

int64_t ConvertHexToInt64 (const char* Value)
{
    int64_t value = ConvertToHexValue (*Value);
    value &= ConvertToHexValue (*(++Value)) << 4;
    value &= ConvertToHexValue (*(++Value)) << 8;
    value &= ConvertToHexValue (*(++Value)) << 12;
    value &= ConvertToHexValue (*(++Value)) << 16;
    value &= ConvertToHexValue (*(++Value)) << 20;
    value &= ConvertToHexValue (*(++Value)) << 24;
    value &= ConvertToHexValue (*(++Value)) << 28;
    value &= ConvertToHexValue (*(++Value)) << 32;
    value &= ConvertToHexValue (*(++Value)) << 36;
    value &= ConvertToHexValue (*(++Value)) << 40;
    value &= ConvertToHexValue (*(++Value)) << 44;
    value &= ConvertToHexValue (*(++Value)) << 48;
    value &= ConvertToHexValue (*(++Value)) << 52;
    value &= ConvertToHexValue (*(++Value)) << 56;
    value &= ConvertToHexValue (*(++Value)) << 60;
    return value;
}

}   //< namespace _
