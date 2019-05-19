/** kabuki::cards
    @file       ~/kabuki::cards Library/Blackjack/BlackjackHand.cs
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
    using System.Collections.Generic;
    using System.Diagnostics;

    /** Class that represents a hand in a playing card game.
        In most cases, the player will have a visible set of cards, and a non-visible set of cards.
    */
    public class BlackjackHand : Hand
    {
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        /** Constructor. */
        public BlackjackHand() :
            base ()
        {
            Clear();
        }

        /** Deals a new hand. */
        public override int DealHand(Deck stock)
        {
            if (stock.NumCards < 2)     //< There are not enough cards for another hand.
                return -2;
            
            // First, get rid of all of the cards in the current hand.
            Cards.Clear();

            // Then draw two cards.
            Cards.Add(stock.DrawCard());
            Cards.Add(stock.DrawCard());

            return 0;
        }

        /** Returns the score of this hand with a given aceValue.
            @param  aceValue    The value of an ace when its either high (worth 11 points), or low (worth 1 point).

            We want to reuse the same code for GetMinScore (), and GetMaxScore () because of the DRY Priciple: 
            Don't Repeat Yourself. The reason for it is that it can introduce bugs into the program if you don't, and in fact,
            there was a bug in my code when I didn't, which is why I'm writting this.

            This function is private because outside of this class, none of the other classes call this function, nor 
            do they care that this function even exists. The other objects only want to know the min and max score.
        */
        public override int GetScore (int aceValue)
        {
            int score = 0;  //< Always set the variable before you start using it!!!

            foreach (Card currentCard in Cards)
            {
                if (currentCard.FaceValue == Card.Ace)    //< First check if its an ace.
                    score += aceValue;
                else
                    score += currentCard.FaceValue;
            }

            return score;
        }

        /** Returns the score. */
        public override int GetScore ()
        {
            return GetMinScore ();
        }

        /** Returns the min score of this hand where Aces are worth 1. */
        public override int GetMinScore()
        {
            return GetScore(1);
        }

        /** Returns the max score of this hand where Aces are worth 11. */
        public override int GetMaxScore()
        {
            return GetScore(11);
        }

        /** Function returns if this hand is 21. */
        public bool Is21()
        {
            return GetMinScore() == 21 || GetMaxScore() == 21;
        }

        /** Function returns true if the hand is a bust.
            A hand is a bust if it is over 21 points.
        */
        public bool IsBust()
        {
            return GetMaxScore() > 21;
        }

        /** Compares the dealers hand to the dealers hand.
            @return Returns 0 if they are equal.
            @return Returns 1 if this hand is greater than the other Hand.
            @return Returns -1 if the other Hand is greater than this Hand.
        */
        public override int Compare(Hand playersHand)
        {
            BlackjackHand otherPlayersHand = (BlackjackHand)playersHand;

            int minScore = GetMinScore(),
                maxScore = GetMaxScore(),
                playersMinScore = otherPlayersHand.GetMinScore(),
                playersMaxScore = otherPlayersHand.GetMaxScore();

            if (minScore == 21 || maxScore == 21)
                if (playersMinScore == 21 || playersMaxScore == 21) // We both got 21!
                    return 2;
                else
                    return 3;   //< We won!

            if (playersMinScore == 21 || playersMaxScore == 21)     //< The we lost.
                return -2;

            // The following is called a "Ternary operator". It can set values with less typing.
            int bestScore = maxScore > 21 ? minScore : maxScore,
                otherBestScore = playersMaxScore > 21 ? playersMinScore : playersMaxScore;
            /** Another way of writting this would be:

                if (maxScore > 21)
                    bestScore = minScore;
                else
                    bestScore = maxScore;

                But thats a lot of extra typing. The Ternary is much slicker.
            */
            if (bestScore > 21)             //< Than we lost :-(
                if (otherBestScore > 21)    //< Than we both lost!
                    return -2;
                else
                    return -1;  //< Than 

            if (otherBestScore > 21)        //< We won!!!
                return 1;

            if (bestScore > otherBestScore)
                return 1;

            // if (bestScore == otherBestScore)
            return 0;
        }

        /** Returns a String of either the dealer's, or the player's hand.
            @param  isDealer    Flag that represents if the hand is the dealer's hand or not.  */
        public String ToString(bool isDealer)
        {
            String returnString = "Hand (" + Cards.Count + "): ";

            // In blackjack, one of the dealer's cards is face down, so we need to blank out the last card if isDealer 
            // is true.

            int numCards = Cards.Count,                         //< The number of cards in this hand.
                lastCard = isDealer ? numCards - 1 : numCards;  //< The index of the last card to print.

            for (int i = 0; i < lastCard; i++)
            {

                if (i != lastCard) //< Used to put commas in the right place
                {
                    returnString += Cards[i].ToString();

                    if (i != numCards - 1)  //< On the last card, we need to put a new line ("\n") instead of a comma.
                        returnString += ", ";
                }
            }

            if (isDealer)
                returnString += "???????\n";
            else
                returnString += "\nMin Score: " + GetMinScore() + ", Max Score: " + GetMaxScore() + "\n";

            return returnString;
        }

        /** Returns a String representation of this Object. */
        public override String ToString()
        {
            return ToString(false);
        }
    }
















    public class BlackjackHandTests : UnitTest
    {
        /** Default constructor setups up and runs a test. */
        public BlackjackHandTests()
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
            Debug.Write ("Testing the Blackjack Hand class\n" + CardGame.ConsoleLine ('*') +
                            "Creating stock...\n");
            int i;  //< Temp looping variable.

            var stock = new Deck();
            stock.Shuffle();

            Debug.Write("Printing shuffled stock:\n" + stock.ToString() + "\nCreating handA...\n");

            var handA = new BlackjackHand();

            Debug.Write("Drawing 2 cards from the top of the stock...");

            for (i = 0; i < 5; i++)
                handA.AddCard(stock.DrawCard ());

            Debug.Assert(handA.NumCards == 5, "Error: There were not 5 cards in the stock!!!");

            Debug.Write("\nTesting DealHand (Deck)...\n\n");

            handA.Clear();
            handA.DealHand(stock);

            Debug.Write("Printing handA: " + handA.ToString() + "\n\n");

            Debug.WriteLine("Attempting to draw more cards than the stock has... Expect to see a bunch of add null card to CardPile errors.");

            for (i = 0; i < 60; i++)
                handA.AddCard(stock.DrawCard());

            Debug.Write("\nPrinting handA:\n\n" + handA.ToString() + "\n\nClearing Hand and shuffling the stock...");

            handA.Clear();
            stock.Shuffle();

            Debug.Assert(handA.NumCards == 0, "Error! The hand didn't clear right!\n");

            Debug.Write("\n\nTesting min and max score functions...\n");

            handA.AddCard(new Card(10, 3));
            handA.AddCard(new Card (1, 4));    //< A 10 + an ace is a 21!

            Debug.Assert(handA.GetMinScore() == 11, "Error! The min score didn't calculate properly!\n" +
                "handA.GetMinScore () = " + handA.GetMinScore() + "\n" +
                handA.ToString());
            Debug.Assert(handA.GetMaxScore() == 21, "Error! The max score didn't calculate properly!\n" +
                "handA.GetMaxScore () = " + handA.GetMaxScore() + "\n" +
                handA.ToString());

            Debug.Assert(handA.GetMinScore() <= handA.GetMaxScore(), "Error! handA's min score (" + handA.GetMinScore() + ") was greater than the max score (" + handA.GetMaxScore() + ")");

            Debug.Write("\nTesting GetCard (int)...\n\n");

            Debug.Assert(handA.GetCard(0).PipValue == 10, "Error! handA card(0)'s pip value wasn't 10!\n\n" +
                handA.ToString() + "\n\n" +
                handA.GetCard(0).ToString() +
                "\n\nhandA.GetCard (0).GetPipValue () = " + handA.GetCard(1).PipValue + "\n");

            Debug.Assert(handA.GetCard(-10) == null, "Error! Invalid card index didn't return null Card!");

            var handB = new BlackjackHand ();

            handB.AddCard(new Card (9, 1));
            handB.AddCard(new Card (4, 1));

            Debug.Assert(handB.GetMinScore() == 13 && handB.GetMaxScore() == 13, "Error! Min and Max " +
                "score we not the same, which should be 13.\n" + handA.ToString () + handB.ToString ());

            Debug.Write("Testing compare function... \n\n");

            Debug.Assert(handA.Compare(handB) > 0, "Error! The ace plus 10 didn't win!");

            Debug.Write("Compairing 5 plus King to Jack plus queen");

            handA.Clear();
            handB.Clear();

            handA.AddCard(new Card (5, 1));
            handA.AddCard(new Card (13, 1));
            handB.AddCard(new Card (11, 1));
            handB.AddCard(new Card (13, 1));

            Debug.WriteLine ("Testing the GetMaxScore () and GetMinScore ():\n" + handA.ToString () + handB.ToString ());

            Debug.Assert(handA.GetMinScore() <= handA.GetMaxScore(), "Error! handA's 2nd test min score (" + handA.GetMinScore() + ") was greater than the max score (" + handA.GetMaxScore() + ")\n" + handA.ToString () + handB.ToString ());
            Debug.Assert(handB.GetMinScore() <= handB.GetMaxScore(), "Error! handB's min score (" + handB.GetMinScore() + ") was greater than the max score (" + handB.GetMaxScore() + ")\n" + handA.ToString () + handB.ToString ());


            Debug.WriteLine ("Testing the compare functions:\n" + handA.ToString () + handB.ToString ());

            Debug.Assert(handA.Compare(handB) > 0, "Error! The handB was over 21 and the score of 15 lost!\n" + handA.ToString () + handB.ToString ());

            Debug.Write("\n\nDone testing the BlackjackHand class.\n\n\n");

        }
    }
}
