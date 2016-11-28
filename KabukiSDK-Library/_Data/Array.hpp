/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Data/Array.hpp
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

namespace _Data {
    
void 
    
class Array
/*< An collection of owned items stored in a packed array. */
{
    public:
    
    Array (size_t elementSize, int initBufferSize);
    /*< Constructs an array with the given element and buffer size. */
    
    ~Array ();
    
    void clear ();
    /*< Resets the Collection without deleting the contents. */
    
    bool add (void* ptr);
    /*< Adds the given object from the given pointer. */
    
    bool add (const ICollection& C);
    /*< Adds the given array to this one. */
    
    bool contains (void* Data);
    /*< Returns true if this array contains the given data. */
    
    bool contains (const ICollection& c);
    /*< Returns true if this array contains the given collection. */
    
    bool contains (const Array& c);
    /*< Returns true if this Collection contains thatCollection. */
    
    bool equals (void* Data);
    /*< Returns true if this Collection contains only the given data. */
    
    hash_t getHash ();
    /*< Generates a hash for this Collection. */
    
    bool isEmpty ();
    /*< Returns true of this Collection is empty. */

    bool remove (void* Data);
    /*< Removes that object from the collection. */
    
    bool remove (ICollection& C);
    /*< Removes that object from the collection. */

    bool retain (ICollection& C);
    /*< Removes all but the given collection from this collection. */

    IIterator* getIterator ();
    /*< Gets an iterator for this collection. */
    
    size_t getSize ()
    /*< Gets the size_t of the object being stored. */

    void* toArray ();
    /*< Returns a pointer to a packed array of the collection. */
    
    private:
    
    size_t elementSize;     //< The sizeof this object size.
    int numItems;           //< The number of items.
    
    void* base;             //< Pointer to the dynamic memory.
};
}
