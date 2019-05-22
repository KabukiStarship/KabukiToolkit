/** kabuki::cards
    @file       ~/kabuki::cards Library/Player.cs
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

namespace DojoCardGames.Blackjack
{
    using System;
    using System.Diagnostics;

    public class BlackjackDealer: BlackjackPlayer
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        /** Default Constructor. */
        public BlackjackDealer () :
            base ()
        {
            // Nothing to do here!
        }

        /** Function that determines if this Player plays, or passes.
            This function performs the dealer's logic. For an extra ninja bonus star, you can use polymorphism to make 
            a sub-class of this object, and override this function to make your own AI computer algorithm! */
        public void HitOrHold(Deck Deck)
        {
            if (IsHolding)       //< We don't do anything if we are holding.
                return;

            Debug.Write (Name + "'s turn.\n");

            var thisHand = (BlackjackHand)Hand;

            /** The rule for the dealer in blackjack is that if they their hand is less than 17, then then have take a 
                card. */
            if (thisHand.GetMinScore () > 17 || thisHand.GetMaxScore() > 17)
            {
                IsHolding = true;
                return;
            }

            HitMe (Deck);
        }


        /** Returns the stat string during a round. 
            @pre    Reound must be setup properly before calling this funciton! */
        public override String GetRoundStatsString ()
        {
            String returnString = CardGame.ConsoleLine ('_') +
                "Player: " + Name + 
                "\nWins: " + NumWins + 
                "\nHand: Num Cards:" + Hand.NumCards + "\n";

            // In blackjack, one of the dealer's cards is face down, so we want to start at card 1 instead of 0.

            int numCards = Hand.NumCards;
            if (numCards > 1)
                returnString += "????????, ";

            for (int i = 1; i < numCards; i++)
            {
                returnString += Hand.Cards[i].ToString ();

                if (i == numCards - 1)  // We don't want to put a comma on the last card.
                    break;

                returnString += ", ";
            }

            return returnString + "\n" + CardGame.ConsoleLine ('_');
        }
    }
















    public class BlackjackDealerTests : UnitTest
    {
        /** Default constructor setups up and runs a test. */
        public BlackjackDealerTests()
        {
            SetupTest();
            RunTests();
        }

        /** Sets up the Unit Test. */
        public override void SetupTest()
        {
        }

        /** Runs the unit test. */
        public override void RunTests()
        {
            Debug.Print("Testing the BlackjackDealer class\n" + CardGame.ConsoleLine ('*') +
                "Creating dealer and printing ToString ()...\n\n");

            var dealer = new BlackjackDealer();
            Debug.WriteLine(dealer);
            //< Debug.Write and Debug.WriteLine will call the dealer.ToString() function. Talk about nifty!!! */

            Debug.WriteLine ("Done testing the BlackjackDealer class...");
        }
    }
}
