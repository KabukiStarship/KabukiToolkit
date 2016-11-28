/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Impl/_Search/HitList.cpp
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

#include <_Search/HitList.hpp>

namespace _Search {

HitList::HitList ()
{
    LoadTestHites ();
}

HitList::HitList (const Hit& o)
{

}

bool HitList::addHit (Hit p)
{
    if (p == nullptr) return false;

    patches.Add (p);

    /// Check the tags for duplicates and add to tags if no duplicates exist.
    string tagCatagory = p.Catagory;
    foreach (string s in tags) if (s == tagCatagory) return true;
    tags.Add (tagCatagory);
    sort (tags.begin (), tags.end ());
    return true;
}

void HitList::sortTags () { sort (tags.begin (), tags.end ());

void HitList::LoadTestHites ()
{
    patches = new vector<Hit> (9);
    
    AddHit (new Hit ("Claranet", "Default claranet patch.", new string[] { "Woodwind", "Claranet", "Reed" }));
    AddHit (new Hit ("Oboe", "Default oboe patch.", new string[] { "Woodwind", "Oboe", "Reed" }));
    AddHit (new Hit ("Tenor Sax", "Default tenor sax patch.", new string[] { "Woodwind", "Tenor Sax", "Reed", "Tenor" }));
    AddHit (new Hit ("Recorder", "Default recorder patch.", new string[] { "Woodwind", "Recorder", "Flute" }));
    AddHit (new Hit ("Flute", "Default flute patch.", new string[] { "Woodwind", "Flute" }));
    
    AddHit (new Hit ("Trumpet", "Default trumpet patch.", new string[] { "Brass", "Trumpet" }));
    AddHit (new Hit ("FlugleHorn","Default flugle horn patch.", new string[] { "Brass", "Flugle Horn" }));
    AddHit (new Hit ("FrenchHorn", "Default french horn patch.", new string[] { "Brass", "French Horn" }));
    AddHit (new Hit ("Trombone", "Default trombone patch.", new string[] { "Brass", "Trombone" }));
}

void HitList::LoadFromJSON (string json)
{
    /*
    try
    {
        patches = new vector<Hit> ();
        JArray a = JArray.Parse (json);
        foreach (JObject o in a.Children<JObject> ())
        {
            Hit p = o.ToObject<Hit> ();
        }
    }
    catch (Exception e)
    {
        Debug.Assert (false, e.ToString ());
    }
     */
}

char* HitList::toJSON ()
{
    string json = new string "[";
    int count = patches.Count;
    for (int i = 0; i < count; i++)
    {
        json += patches[i].ToJSON ();
        if (i < count - 1) json += ", ";
    }
    return json + "]";
}

bool HitList::findDuplicateName (char* value)
{
    foreach (Hit a in patches)
    if (a.Name == value)
        return true;
    return false;
}

string HitList::getCatagoryName (int index)
{
    if (index >= catagories.Count) return nullptr;
    
    return catagories[index];
}

HitList HitList::findpatchesWithTag (char* tag)
{
    vector<Hit> patchList = new vector<Hit> ();
    foreach (Hit patch in patches)
    if (patch.ContainsTag (tag))
        patchList.Add (patch);
    return patchList;
}

HitList HitList::findpatchesWithTags (vector<string> tags)
{
    HitList
    vector<Hit> patchList = new vector<Hit> ();
    for_each (patches.begin (), patches.end (), [] (Hit& p)
              {
                  if (patch.ContainsTags (tags)) patchList.Add (patch);
              });
    return patchList;
}

char* HitList::getCatagoryImageName (string s)
{
    if (s == nullptr || s == "") return nullptr;
    return "Catagory" + Regex.Replace (s, @"\s+", "");// + ".png";
}

char* HitList::getSubcatagoryImageName (string s)
{
    if (s == nullptr || s == "") return nullptr;
    return "Subcatagory" + Regex.Replace (s, @"\s+", "");// + ".png";
}

char* HitList::defaultHitList ()
{
    return "";
}

void HitList::print (I2P::Terminal& slot)
{
}

}   //< namespace _Search
