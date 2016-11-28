/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Search/Library.hpp
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

#include <string>
#include <map>
using namespace std;

#include "Hit.hpp"

/*< The main library of Hites.
    This class _KabukiSDK owns the memory for the patches.
*/
class _KabukiSDK Library: public IObject
{
    public:
    
    /*< Simple default constructor. */
    Library ();
    
    /*< Adds a patch to the Hites. */
    bool AddHit  (Hit& p);
    
    void SortTags ();
    
    void LoadTestHites ();
    
    /*< Loads a patch from a JSON string. */tre
    void LoadFromJSON  (const char* json);
    
    /*< Converts a patch to a JSON string. */
    string ToJSON ();
    
    /*< Gets true if their is a duplicate patch name. */
    bool FindDuplicateName  (const char* value);
    
    /*< Gets the catagory name at the given index. */
    char* GetCatagoryName  (int index);
    
    Library FindHitesWithTag  (const char* tag);
    
    Library FindHitesWithTags  (vector<string>& tags);
    
    string& GetCatagoryImageName  (string s);
    
    string& GetSubcatagoryImageName  (string s);

    virtual byte GetState ();
    /*< Gets the Inter-process state. */
    
    virtual const char* SetState  (byte Value);
    /*< Sets the Inter-process state.
        @return returns 0 upon success, and an I2P::Errror upon failure. */
    
    virtual const char* Do  (const char* Query, byte index, Roombot* Bot);
    /*< Inter-process oproutines. */
    
    private:

    static int currentUId;              //< The total number of patches.
    
    map<string, Hit> patches;         //< The list of patches.
    
    vector<char*> catagories;         //< The list of catagories.
        tags;                           //< List of tag strings.
    
    string& GetDefaultHitLibrary ();  //< Gets the default library in JSON.

    int InitNumHites ();               //< Gets the number 0.
};
}   //< namespace Librarian

