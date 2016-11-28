/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Impl/_Data/Data.cpp
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

#include <_Data/Data.hpp>

namespace _Data {
    
    /**  An abstract class that stores raw data and metadata about the data. */
    public Data<T>
    {
        T GetData ();       //< Retursn the HAL.void* data.
        const char* DataType ();  //< Function returns a const char* representing the data type.

        void deconstruct (); //< Agnostic deconstructor.

        void Print ();     //< Prints this void* to the console.
        const char* ToString (); //< Returns a text representation of this object.
    }
}
