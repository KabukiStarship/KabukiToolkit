/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/script/bin.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
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

#ifndef HEADER_FOR_SCRIPT_BIN
#define HEADER_FOR_SCRIPT_BIN

#include "op.h"
#include "slot.h"
#include "error.h"

namespace _ {

/** A*B B-Input Slot.
    A B-Input Slot is functionally identical to a input port in TCP. */
struct KABUKI BIn {

    /** List of Finite BIn States.
        @see Script Protocol RFC for list of states. */
    typedef enum States {
        AddressState = 0,   //< State  0: Scanning address.
        ArgsState,          //< State  1: Scanning arguments.
        Utf8State,          //< State  2: Scanning STR.
        Utf16State,         //< State  3: Scanning ST2.
        Utf32State,         //< State  4: Scanning ST8.
        VarintState,        //< State  5: Scanning varint.
        ObjectState,        //< State  6: 8-bit OB1 state.
        HashState,          //< State  7: Stand the 32-bit hash.
        ErrorState,         //< State  8: Handling an error state.
        kStateDisconnected,  //< State  9: Disconnected state.
        AckState,           //< State 10: Awaiting connection ACK.
        LockedState,        //< State 11: Locked state.
        PodState,           //< State 12: Scanning plain-old-data.
    } State;

    uint_t          size,   //< The size of the buffer.
        start;  //< The starting index of the ring buffer data.
    volatile uint_t stop;   //< The stopping index of the ring buffer data.
    uint_t          read;   //< The read variable.
};

/** Copies the bin to the slot. */
inline void BInSlot (BIn* bin, Slot& slot) {
    if (!bin) {
        return;
    }
    char* begin = reinterpret_cast<char*> (bin) + sizeof (BIn);
    slot.begin = begin;
    slot.start = begin + bin->start;
    slot.stop = begin + bin->stop;
    slot.end = begin + bin->size;
}

/** Get's the B-Input's buffer.*/
inline char* BInBegin (BIn* bin) {
    return reinterpret_cast<char*> (bin) + sizeof (BIn);
}

inline char* BInEnd (BIn* bin) {
    // This will never be nil.
    //if (!bin) {
    //    return nullptr;
    //}
    return BInBegin (bin) + bin->size;
}

/** Gets the rx buffer length. */
inline uint_t BInSpace (BIn* bin) {
    if (!bin) {
        return 0;
    }
    char* txb_ptr = reinterpret_cast<char*>(bin);
    return SlotSpace (txb_ptr + bin->start, txb_ptr + bin->stop,
                      bin->size);
}

inline uint_t BinBufferLength (BIn* bin) {
    if (!bin) {
        return ~0;
    }
    char* base = BInBegin (bin);
    return SlotLength (base + bin->start, base + bin->stop, bin->size);
}

#if USING_SCRIPT_TEXT
/** Gets a a char for printing out the bin_state. */
KABUKI const char** BInState ();
#endif  //< USING_SCRIPT_TEXT

/** Initializes the BIn struct KABUKI to an empty buffer. */
KABUKI BIn* BInInit (uintptr_t* buffer, uint_t size);

/** Gets the end address of the rx buffer. */
KABUKI char* BInEnd (BIn* bin);

/** Returns true if the BIn buffer contains any data.
    @warning Function does not do any error checking for speed. */
KABUKI bool BInIsReadable (BIn* bin);

/** Scans a message with the given params to the given BIn.
    The data in the BIn is word-aligned, unlike the Slot. It also
    doesn't have a hash with an escape sequence.

    @param rx The BIn socket.
    @param params The parameters.
    @param args   The arguments.
    @return       Returns 0 upon success and an ErrorList ticket number upon
                  failure. */
KABUKI const Op* BInRead (BIn* bin, const uint_t* params, void** args);

#if USING_SCRIPT_TEXT
/** Prints the BIn to the Text.
    @param  bin The pin to print.
    @param  text The Text to print the bin to.
    @return The text. */
KABUKI Strand& BInPrint (BIn* bin, Strand& strand);
#endif  //< USING_SCRIPT_TEXT
}       //< namespace _
#endif  //< HEADER_FOR_SCRIPT_BIN