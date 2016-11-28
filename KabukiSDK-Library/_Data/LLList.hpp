/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Data/ICollection.hpp
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

class LLList
/*< A linear linked list. */
{
    enum {
        IsNotSpecified = -1,
        size = 0, 
        index = 0, 
        maxSize = IsNotSpecified;
    };
    
    LLNodeedList ();

    LLNodeedList (int maxNumOfElements);


    LLNodeedList (File listHead);

    void resetList ();

    bool add (void* newLLNode);

    bool insert (void* newLLNode);

    bool insert (void* newLLNode, int indexNum);

    bool add (void* newLLNode, LLNode afterHere);

    bool insert (void* newLLNode, LLNode beforeHere);

    LLNode find (void* objectToFind);

    bool remove (void* thisGuy) { return Remove (find (thisGuy)); }

    bool remove (int atIndex);

    bool remove (int index1, int index2);

    bool remove (LLNode thisLLNode);

    bool replace (int atIndex, void* withThis);

    bool keepOnlyThese (int[] indexList);

    bool contains (void* o);

    void* element (int atIndex);
    
    LLNode linkAtIndex (int atIndex);

    bool isEmpty ();

    int getSize ();

    int getMaxSize ()

    const char* randomText (int numChars);

    void increaseMaxSize (int increase);

    void** toArray ();

    IIterator* getIterator ();

    IIterator linearIterator ();

    LLNode headOfList;

    class LLListIterator : IIterator
    {
        public:
        
        LLListIterator ();
        
        void* getCurrentPointer ();
        
        void* getNextPointer ();
        
        void* getPrevPointer ();

        LLNode getCurrentLLNode ();

        LLNode nextLLNode ();
        
        LLNode prevLLNode ();
        
        bool isNotDone ();
        
        bool isNotDone (int forwardsOrBackwards);// Value to be < or > 0
        
        void removeLast ();
        
        void replaceLast (void* withThis);
        
        void insert (void* thisGuy);
        
        int getDirection ();
        
        void setDirection (int positiveNegative);

        bool setIndex (int toHere);

        int getIndex ();

        int getSize ()
        
        private:
        
        LLNode* currentLLNode;
        
        int index = 0,
            inde;
    }
};

}   //< namespace _Data
