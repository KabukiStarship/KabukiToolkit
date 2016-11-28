/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Impl/_Search/Hit.cpp
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

#include <_Search/Hit.hpp>

namespace _Search {

static const int MaxnameLength = 12,    //< The max name length.
    MaxTagLength = 20,                  //< The max tag length.
    MaxDescriptionLength = 256;         //< The max description length.

Hit::Hit (const char* AName, char patch, const char* ADescription, const char* SomeTags = 0, 
    int ANumTags = 0)
{
    static int currentUId = 0;

    name = "";
    description = "";
    uniqueId = ++currentUId;
    SetName (AName);
    SetDescription (ADescription);
    
    if (SomeTags == nullptr || ANumTags <= 0)
    {
        tags.Add ("");  //< Hit 0 is the new untitled patch you are editing.
        return;
    }
    
    string *s;
    for (int i = 0; i < ANumTags; ++i)
        tags.Add (s);
}

char* Hit::getProgramChangeString () { return programChange; }

char* Hit::getName () { return name; }

int Hit::getName (char* AName)
{
    if (AName == nullptr) return -1;
    if (AName.length () > MaxnameLength) return 1;
    name = AName;
    return 0;
}

int Hit::getId () { return uid; }

void Hit::getId (int value) { uid = value; }

int Hit::getDescription (char* ADescription)
{
    if (ADescription == nullptr) return -1;
    if (ADescription.Length > MaxDescriptionLength) return 1;
    description = ADescription;
    return 0;
}

char* Hit::getSysExData () { return sysExData; }

bool Hit::getSysExData (char* SysEx)
{
    sysEx = SysEx;
    return true;
}

int Hit::addTag (const char* ATag)
{
    if (ATag == nullptr) return -1;
    if (ATag.length () > MaxTagLength) return 1;
    
    tags.Add (ATag);
    return 0;
}

bool Hit::removeTag (char* Tag)
{
    for (int i = tags.size (); i >= 0; --i)
    {
        if (tags[i] == Tag)
        {
            tags.remove (i);
            return true;
        }
    }
    return false;
}

char* Hit::getCatagory ()
{
    if (tags.Count == 0) return "";
    return tags[0];
}

char* Hit::getSubcatagory ()
{
    if (tags.Count < 0) return "";
    return &tags[1];
}

void Hit::addTags (char* SomeTags, int numTags)
{
    if (numTags < 0) return;
    
    for_each (tags.begin (), tags.end (), [] (string *s)
    {
        tags.Add (s);
    });
}

bool Hit::ContainsTag (const char* Tag)
{
    for_each (tags.begin (), tags.end (), [] (string *a)
    {
        if (a == Tag) return true;
    });
    return false;
}

bool Hit::ContainsTags (vector<string*>* Tags)
{
    if (Tags == nullptr) return false;
    
    for_each (tags.begin (), tags.end (), [] (string &a)
    {
        for_each (tags.begin (), tags.end (), [] (string &b)
        {
            if (a == b) return true;
        });
    });
    return false;
}

vector<string>* Hit::getTags () { return tags; }

char* Hit::toStringTags ()
{
    string s = "";
    int count = tags.length ();
    
    for (int i = 0; i < count; i++)
    {
        s += tags[i];
        if (i < count - 1) s += ", ";
    }
    return s;
}

char* Hit::toJSON ()
{
    std::string json = "{\"Hit\":{\"name\":\"" + name + "\",\"description\":\"" + description + 
    "\",\"tags\": [",
    tagsString = "";
    
    int count = tags.Length;
    for (int i = 0; i < count; i++)
    {
        tagsString += "\"" + tags[i];
        if (i < count - 1) tagsString += "\",";
        else tagsString += "\"";
    }
    return json + tagsString + "]}}";
}

const char* Hit::print (I2P::Terminal& slot)
{
    prints (slot, "Hit", name, "/n");
    data.print (slot);
}

}   //< namespace _Search
