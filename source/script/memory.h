/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/script/memory.h
    @author  Cale McCollough <https://calemccollough.github.io>
    @license Copyright (C) 2017 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once
#include <stdafx.h>

#ifndef HEADER_FOR_SCRIPT_MEMORY
#define HEADER_FOR_SCRIPT_MEMORY

#include "config.h"

namespace _ {

/** Compute the next highest power of 2.
    @cite https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
    @todo Rewrite for uint16_t. */
KABUKI uint32_t MemoryAlignPowerOf2 (uint32_t value);

/** Compute the next highest power of 2.
    @cite https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
    @todo Rewrite for int16_t. */
KABUKI int32_t MemoryAlignPowerOf2 (int32_t value);

/** Returns the given pointer for use with uncooperative overloaded
    operators. */
inline const void* Memory (const void* pointer) {
    return pointer;
}

/** Converts the pointer to a std::uintptr_t. */
inline std::uintptr_t MemoryValue (const void* value) {
    return reinterpret_cast<std::uintptr_t> (value);
}

/** Converts the std::uintptr_t to a pointer. */
inline void* MemoryValue (std::uintptr_t value) {
    return reinterpret_cast<void*> (value);
}

/** Converts the std::uintptr_t to a pointer. */
inline const void* MemoryValueConst (std::uintptr_t value) {
    return reinterpret_cast<const void*> (value);
}

template<typename T>
inline bool MemoryIsNaN (T value) {
    static const T nan = (sizeof (T) == 8) 
                       ? (T)0xFF
                       : sizeof (T) == 4 ? (T)0xFFFF
                       : sizeof (T) == 2 ? (T)0xFFFFFFFF
                       : sizeof (T) == 1 ? (T)0xFFFFFFFFFFFFFFFF:0;
    return value == nan;
}

/* Returns the inverse of the given value.
For code metadata purposes. */
template<typename T>
T MemoryMax () {
    return ~(T)0;
}

/** Creates/Gets a static buffer of the specified size. */
template<uint_t kBufferSize>
inline uintptr_t* Memory () {
    static uintptr_t buffer[(kBufferSize / sizeof (uintptr_t)) + 1];
    return buffer;
}

/** Creates/Gets one of n static buffers of the specified size. */
template<uint_t kBufferNumber,
         uint_t kBufferSize>
    inline uintptr_t* Memory () {
    static uintptr_t buffer[(kBufferSize / sizeof (uintptr_t)) + 1];
    return buffer;
}

/** Creates/Gets one of n static buffers of the specified size. */
template<typename T,
         uint_t kBufferNumber,
         uint_t kBufferSize>
inline T* Memory () {
    static T buffer[(kBufferSize / sizeof (uintptr_t)) + 1];
    return buffer;
}

/** reinterpret_cast(string) a the given base and offset to an object pointer.
*/
template<typename T>
inline T* MemoryOffset (void* base, uint_t offset) {
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

/** Returns the number to add to word-align the given pointer to a uint_t-bit
    boundary.
    @author Algorithm by Cale McCollough (or as far as I know).
    @param  ptr The address to align.
    @return The offset to add to the ptr to word align it. */
template<typename T>
inline uintptr_t MemoryAlignOffset (const void* ptr) {
    // Algorithm works by inverting the bits, mask of the LSbs and adding 1.
    // This allows the algorithm to word align without any if statements.
    // The algorithm works the same for all memory widths as proven by the
    // truth table bellow.
    // ~000 = 111 => 000 + 111 + 1 = 0x1000
    // ~001 = 110 => 001 + 110 + 1 = 0x1000
    // ~010 = 101 => 010 + 101 + 1 = 0x1000
    // ~011 = 100 => 011 + 100 + 1 = 0x1000
    // ~100 = 011 => 100 + 011 + 1 = 0x1000
    // ~101 = 010 => 101 + 010 + 1 = 0x1000
    // ~110 = 001 => 110 + 001 + 1 = 0x1000
    // ~111 = 000 => 111 + 000 + 1 = 0x1000                 v--- Mask
    return ((~reinterpret_cast<uintptr_t> (ptr)) + 1) & (sizeof (T) - 1);
}

/** Calculates the offset to align the given pointer to a 16-bit word boundary.
    @return A vector you add to a pointer to align it. */
inline uintptr_t MemoryAlign2 (const char* ptr) {
    // Mask off lower bit and add it to the ptr.
    uintptr_t value = reinterpret_cast<uintptr_t> (ptr);
    return value & 0x1;
}

/** Aligns the given pointer to a 32-bit word boundary.
    @return A vector you add to a pointer to align it. */
inline uintptr_t MemoryAlign4 (const char* ptr) {
    return MemoryAlignOffset<int32_t> (ptr);
}

/** Aligns the given pointer to a 64-bit word boundary.
    @return A vector you add to a pointer to align it. */
inline uintptr_t MemoryAlign8 (const char* ptr) {
    return MemoryAlignOffset<int64_t> (ptr);
}

/** Word aligns the given byte pointer up in addresses.
    @param ptr Pointer to align.
    @return Next word aligned up pointer. */
inline char* MemoryAlign (char* ptr) {
    return ptr + (((~reinterpret_cast<uintptr_t> (ptr)) + 1) &
                  (sizeof (char*) - 1));
}

inline uintptr_t* MemoryAlign8 (uintptr_t* buffer) {
    char* byte_ptr = reinterpret_cast<char*> (buffer);
    uintptr_t offset = (((~reinterpret_cast<uintptr_t> (buffer)) + 1) &
                        (sizeof (uint64_t) - 1));
    return reinterpret_cast<uintptr_t*> (byte_ptr + offset);
}

inline uintptr_t MemoryAlignSize (uintptr_t size) {
    // Algorithm works by inverting the bits, mask of the LSbs and adding 1.
    // This allows the algorithm to word align without any if statements.
    // The algorithm works the same for all memory widths as proven by the
    // truth table bellow.
    // ~000 = 111 => 000 + 111 + 1 = 0x1000
    // ~001 = 110 => 001 + 110 + 1 = 0x1000
    // ~010 = 101 => 010 + 101 + 1 = 0x1000
    // ~011 = 100 => 011 + 100 + 1 = 0x1000
    // ~100 = 011 => 100 + 011 + 1 = 0x1000
    // ~101 = 010 => 101 + 010 + 1 = 0x1000
    // ~110 = 001 => 110 + 001 + 1 = 0x1000
    // ~111 = 000 => 111 + 000 + 1 = 0x1000
    //                                       v----- Mask
    return size + (((~size) + 1) & (sizeof (uintptr_t) - 1));
}


//KABUKI uintptr_t AlignSize (uintptr_t size);
inline uintptr_t MemoryAlign8 (uintptr_t size) {
    // Algorithm works by inverting the bits, mask of the LSbs and adding 1.
    // This allows the algorithm to word align without any if statements.
    // The algorithm works the same for all memory widths as proven by the
    // truth table bellow.
    // ~000 = 111 => 000 + 111 + 1 = 0x1000
    // ~001 = 110 => 001 + 110 + 1 = 0x1000
    // ~010 = 101 => 010 + 101 + 1 = 0x1000
    // ~011 = 100 => 011 + 100 + 1 = 0x1000
    // ~100 = 011 => 100 + 011 + 1 = 0x1000
    // ~101 = 010 => 101 + 010 + 1 = 0x1000
    // ~110 = 001 => 110 + 001 + 1 = 0x1000
    // ~111 = 000 => 111 + 000 + 1 = 0x1000
    //                                         v----- Mask
    return size + (((~size) + 1) & (sizeof (uint64_t) - 1));
}

/** Calculates the difference between the begin and end address. */
inline uintptr_t MemoryVector (void* begin, void* end) {
    return static_cast<uintptr_t>(reinterpret_cast<char*> (end) -
                                  reinterpret_cast<char*> (begin));
}

/** Calculates the difference between the begin and end address. */
inline uintptr_t MemoryVector (const void* begin, const void* end) {
    char* start = static_cast<char*> (const_cast<void*> (begin)),
        *stop = static_cast<char*> (const_cast<void*> (end));
    return static_cast<uintptr_t> (stop - start);
}

/** Overwrites the memory with zeros functionally identical to memset. */
KABUKI void MemoryClear (void* address, size_t size);

/** Copies the source to the target functionally identical to memcpy.
    @param  write     Beginning of the write buffer.
    @param  write_end End of the write buffer.
    @param  read      Beginning of the read buffer.
    @param  read_end  End of the read buffer.
    @return Pointer to the last byte written or nil upon failure. */
KABUKI char* MemoryCopy (char* write, char* write_end, const char* read,
                         const char* read_end);

/** Copies the source to the target functionally identical to memcpy.
    @param  write     Beginning of the write buffer.
    @param  write_end End of the write buffer.
    @param  read      Beginning of the read buffer.
    @param  size      Number of bytes to copy.
    @return Pointer to the last byte written or nil upon failure. */
KABUKI char* MemoryCopy (char* write, char* write_end, const char* memory,
                         int size);


/** Copies the source to the target functionally identical to memcpy.
    @param  write     Beginning of the write buffer.
    @param  write_end End of the write buffer.
    @param  read      Beginning of the read buffer.
    @param  size      Number of bytes to copy.
    @return Pointer to the last byte written or nil upon failure. */
KABUKI char* MemoryCopy (char* write, char* write_end, const char* read,
                         const char* read_end, int size);

#if USE_MORE_ROM

/** Converts a single byte a one-byte hex representation. */
KABUKI byte MemoryNibbleToLowerCaseHex (byte b);

/** Converts a single byte a one-byte hex representation. */
KABUKI byte MemoryNibbleToUpperCaseHex (byte b);

/** Converts a single byte a two-byte hex representation. */
KABUKI uint16_t MemoryByteToLowerCaseHex (byte b);

/** Converts a single byte a two-byte hex representation. */
KABUKI uint16_t MemoryByteToUpperCaseHex (byte b);

/** Converts a single hex byte a byte.
@return Returns -1 if c is not a hex byte.
*/
KABUKI int MemoryHexToByte (byte hex_byte);

/** Converts a single byte into a two-byte hex representation.
@return Returns -1 if c is not a hex byte.
*/
KABUKI int MemoryHexToByte (uint16_t hex);

/** Converts a single byte a one-byte hex representation. */
KABUKI byte MemoryNibbleToLowerCaseHex (byte b);

/** Converts a single byte a one-byte hex representation. */
KABUKI byte MemoryNibbleToUpperCaseHex (byte b);

/** Converts a single byte a two-byte hex representation. */
KABUKI uint16_t MemoryByteToLowerCaseHex (byte b);

/** Converts a single byte a two-byte hex representation. */
KABUKI uint16_t MemoryByteToUpperCaseHex (byte b);

/** Converts a single hex byte a byte.
    @return Returns -1 if c is not a hex byte.
*/
KABUKI int MemoryHexToByte (byte c);

/** Converts a single byte into a two-byte hex representation.
    @return Returns -1 if c is not a hex byte.
*/
KABUKI int MemoryHexToByte (uint16_t h);

/** Gets a randomly generated 32-bit hash. */
template<typename T>
KABUKI uint_t MemoryRandom () {
    srand (time (0));
    return static_cast<T> (rand ());
}

#endif  //< USE_MORE_ROM
}       //< namespace _
#endif  //< HEADER_FOR_SCRIPT_MEMORY