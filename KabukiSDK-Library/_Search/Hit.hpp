/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Search/Hit.hpp
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

#include <FreeI2P.hpp>
#include <KabukiSDK-Config.hpp>
#include <stdint.hpp>
#include <const char*>
#include <vector>

namespace Librarian {

class HitList;

/** A list of saerch hits.
    Each patch has a name and catagory, and type strings, and a list of tags that desribe the sound.
*/
class _KabukiSDK Hit
{
    public:
    
    enum {
        MaxnameLength = 12,             //< The max name length.
        MaxTagLength = 20,              //< The max tag length.
        MaxDescriptionLength = 256      //< The max description length.
    };

    Hit (const char* aName = "", char patch = 0, const char* aDescription = "", const char* aCatagory = "", const char* aType = "", char* someTags = 0, int ANumTags = 0);
    /** Simple constructor. 
        User produces the SomeTags list as a new array of strings, and this object cosumes it and is responsible for the deallocation of the memory.
    */

    char* getProgramChangeString () noexcept;
    /** Gets and sets the program hange integer. */

    char* getName () noexcept;
    /** Gets the name. */

    int setName  (const char* AName) noexcept;
    /** Sets the name.
        @return returns 0 upon success, -1 if the input is nullptr, and 1 if the label is too long. */

    int getId () noexcept;
    /** Gets the Id. */
    
    void setId  (int value) noexcept;
    /** Sets the Id. */
    
    int setDescription  (const char* ADescription) noexcept;
    /** Sets the description.
        @return returns 0 upon success and 1 if the label is too long. */

    int addTag  (const char* ATag) noexcept;
    /** Addsa tag to the tag list.
        @return returns 0 upon success, -1 if the input is nullptr, and 1 if the label is too long. */
    
    bool removeTag  (const char* Tag) noexcept;
    /** Removes the given tag if it exists.
        @return Gets true upon success, -1 if the input is nullptr, and false if the tag doesn't exist. */
    
    char* getCatagory () noexcept;
    /** Gets the catagory const char*.
        @return Gets an empty const char* no tags exist. */

    char* getSubcatagory () noexcept;
    /** Gets the opcatagory const char*.
        @return Gets an empty const char* no tags exist. */

    void addTags (char* SomeTags, int numTags);
    /*< Adds a collection of tags to the hit-list. */

    bool containsTag  (const char* Tag);
    /** Gets true if this patch contains the given tag. */

    bool containsTags  (HitList* Tags);
    /** Gets true if this patch contains any of the given tags. */
    
    vector<char*> getTags ();
    /** Gets the tags. */
    
    char* toStringTags ();
    /** Gets a comma seperated const char* of the tags. */

    char* toJSON ();
    /** Serializes to JSON const char*. */
    
    private:

    const char* name,               //< The name of the patch.
        * description;              //< Description of the patch. 
    
    const char** catagory,          //< Pointer to the catagory const char*.
        * type;                     //< Pointer to the type of instrument  (i.e. Flute, claranet).
    
    int uniqueId;                   //< The unique identifier.

    std::vector<const char*> tags;  //< List of tags.
};
}   //< namespace Librarian

