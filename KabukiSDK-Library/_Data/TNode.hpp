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

class TNode implements Node
{
    public:
    
    TNode (int initIndex;
    /*<  */
    
    TNode (Text initName);
    /*<  */
    
    TNode (Text initName, int initIndex);
    /*<  */
    
    TNode (TNode rootNodeBranch);
    /*<  */
    
    TNode (TNode rootNodeBranch, int initIndex);
    /*<  */
    
    TNode (TNode rootNodeBranch, Text initName);
    /*<  */
    
    TNode (TNode rootNodeBranch, Text initName, int initIndex);
    /*<  */
    
    TNode left ();
    /*<  */
    
    TNode right ();
    /*<  */
    
    TNode rootNode ();
    /*<  */
    
    void setLeftBranch  (TNode newBranch);
    /*<  */
    
    void setRightBranch (TNode newBranch);
    /*<  */
    
    void setRootNode  (TNode newBranch);
    /*<  */
    
    Object data ();
    /*<  */
    
    void setData (Object newData);
    /*<  */
    
    bool contains (Object Ptr);
    /*<  */
    
    TNode findDepthFirst (Object Ptr);
    /*<  */
    
    
    Text name ();
    /*<  */
    
    void    giveName (Text newName);
    /*<  */
    
    int index ();
    /*<  */
    
    void setIndex (int newIndex);
    /*<  */
    
    Text toText ();
    /*<  */
    
    private:
    
    Object data;
    TNode left, right, rootNode;
    Text name;
    int index;    
    bool haveBeenThisWay,
                   haveBeenThatWay;
};
}   //< namespace _Data