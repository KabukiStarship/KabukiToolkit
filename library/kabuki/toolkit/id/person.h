/** Kabuki Toolkit
    @file    ~/source/id/Person.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
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
 
#ifndef KABUKI_ID_PERSON_H
#define KABUKI_ID_PERSON_H

#include "Entity.h"

namespace kabuki { namespace id {

/** Class that represents a person/human. 
    @todo Load a person from social media account using Facebook and OAuth APIs.
*/
class KABUKI Person : public Entity {
    public:

    Person ();
    /**Creates a person with no name. */
    
    void Print (_::Log& log);
    /** Prints this object to a expression. */

    private:

    char* lastName;  //< The last name of the entity.
};
}       //< namespace id
}       //< namespace kabuki
#endif  //< KABUKI_ID_PERSON_H