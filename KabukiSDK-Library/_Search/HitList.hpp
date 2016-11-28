/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Search/HitList.hpp
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

namespace Librarian {

#include <KabukiSDK-Config.hpp>
#include "Hit.hpp"

#include <string>
#include <vector>

using namespace std;

/** A collection of pointers to Hites.
*/
class _KabukiSDK HitList: public I2P::IObject
{
    public:

    /** Simple default constructor. */
    HitList ();

    /** Adds a patch to the Hites. */
    bool AddHit  (Hit p);
    
    void SortTags ();

    void LoadTestHites ();

    /** Loads a patch from a JSON string. */
    void LoadFromJSON  (const char* json);

    /** Converts a patch to a JSON string. */
    string ToJSON ();

    /** Gets true if their is a duplicate patch name. */
    bool FindDuplicateName  (const char* value);

    /** Gets the catagory name at the given index. */
    string GetCatagoryName  (int index);
    
    /** Gets a HitList of the given tag. */
    HitList FindHitesWithTag  (const char* tag);
    
    /** Gets a HitList of the given tags. */
    HitList FindHitesWithTags  (vector<string> tags);
    
    /** Ges the catagory image name. */
    string GetCatagoryImageName  (const char* s);
    
    string GetSubcatagoryImageName  (const char* s);
    
    virtual byte GetState ();
    /*< Gets the Inter-process state. */
    
    virtual const char* SetState  (byte Value);
    /*< Sets the Inter-process state.
        @return returns 0 upon success, and an I2P::Errror upon failure. */
    
    virtual const char* Do  (const char* Query, byte index, Roombot* Bot);
    /*< Inter-process oproutines. */
    
    private:

    long uid = 0;
    
    std::vector<Hit*> patches;          //< The list of patches.
    
    std::vector<char*> catagories,    //< The list of catagories.
        tags;                           //< List of tag strings.
};
}   //< namespace Librarian

