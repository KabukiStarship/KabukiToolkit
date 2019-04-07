/** kabuki::cards
    @file       ~/kabuki::cards Library/Hand.cs
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <calemccollough.github.io>;
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

using System;

namespace DojoCardGames
{
    /** A pile of playing cards.
        This abstract class would be called an interface in java.
    */
    public abstract class Hand : CardPile
    {
        /** Constructor. */
        public Hand () :
            base ()
        {
            // Nothing to do here.
        }

        /** Copy constructor. */
        public Hand (Hand other) :
            base (other)
        {

        }

        /** Returns the score. */
        public abstract int GetScore ();

        /** Returns the score of this hand with a given modifier. */
        public abstract int GetScore (int modifier);

        /** Returns the min score. */
        public abstract int GetMinScore ();

        /** Returns the max score. */
        public abstract int GetMaxScore ();

        /** Deals a new hand from the stock. */
        public abstract int DealHand (Deck stock);

        /** Compares the dealers hand to the dealers hand.
            @return Returns 0 if they are equal.
            @return Returns 1 if this hand is greater than the other Hand.
            @return Returns -1 if the other Hand is greater than this Hand.
        */
        public abstract int Compare (Hand playersHand);

        /** Gets the mid-round string for this round. */
        public virtual String GetMidRoundString ()
        {
            return base.ToString ();
        }
    }
}
