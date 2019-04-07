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

namespace DojoCardGames
{
    using System;
    using System.Collections.Generic;
    using System.Diagnostics;

    /** Class that represents a hand in a playing card game.
        In most cases, the player will have a visible set of cards, and a non-visible set of cards.
    */
    public class Hand
    {
        /** Constructor. */
        public Hand ()
        {
            Clear ();
        }

        public void Clear ()
        {
            cards = new List<Card> ();           //< This creates an empty list of Card objects.
        }

        /** Deals a new hand. */
        public bool DealHand (Deck stock)
        {
            if (stock.NumCards < 2)     //< There are not enough cards for another hand.
                return false;


            // First, get rid of all of the cards in the current hand.
            cards.Clear ();                     //< Clear () is a function of the List class built into C#.

            // Then draw two cards.
            cards.Add (stock.DrawCard ());
            cards.Add (stock.DrawCard ());

            return true;
        }

        /** Returns the number of Cards in this Hand. */
        public int NumCards
        {
            get { return cards.Count; }
        }

        /** Returns the card at the specified index and bounds index to it's range. */
        public Card GetCard (int index)
        {
            if (NumCards == 0)
                return null;

            if (index < 0)
                index = 0;

            if (index >= NumCards)
                index = NumCards;

            return cards[index];
        }

        /** Removes and returns the card at the specified index and bounds index to it's range. */
        public Card DrawCard (int index)
        {
            if (NumCards == 0)
                return new Card ();

            if (index < 0)
                index = 0;

            if (index >= NumCards)
                index = NumCards;

            var tempCard = cards[index];
            cards.RemoveAt (index);
            return tempCard;
        }

        /** Draws a random card from the stock. */
        public Card DrawRandomCard ()
        {
            if (cards.Count == 0) //< Then there are no cards in the cards.
                return new Card ();

            var randomGenerator = new Random ();

            int randomIndex = randomGenerator.Next (NumCards);
            var returnCard = cards[randomIndex];    //< Store the random card as a temp variable.
            cards.RemoveAt (randomIndex);           //< Remove the randomIndex we saved earlier.
            return returnCard;                      //< Then return the temp variable.
        }

        /** Returns the min score of this hand where Aces are worth 1. */
        public int GetMinScore ()
        {
            return GetScore (1);
        }

        /** Returns the max score of this hand where Aces are worth 11. */
        public int GetMaxScore ()
        {
            return GetScore (11);
        }

        /** Function returns if this hand is 21. */
        public bool Is21 ()
        {
            return GetMinScore () == 21 || GetMaxScore () == 21;
        }

        /** Adds the newCard to this Hand. */
        public void AddCard (Card newCard)
        {
            if (newCard == null)    //< Never add a null card!
                return;
            
            cards.Add (newCard);
        }

        /** Returns a combination of the visible and non-visible cards. */
        public List<Card> Cards
        {
            get { return cards; }
        }

        /** Function returns true if the hand is a bust.
            A hand is a bust if it is over 21 points.
        */
        public bool IsBust ()
        {
            return GetMaxScore () > 21;
        }

        /** Compares the dealers hand to the dealers hand.
            @return Returns 0 if they are equal.
            @return Returns 1 if this hand is greater than the other Hand.
            @return Returns -1 if the other Hand is greater than this Hand.
        */
        public int Compare (Hand playersHand)
        {
            int minScore = GetMinScore (),
                maxScore = GetMaxScore (),
                playersMinScore = playersHand.GetMinScore (),
                playersMaxScore = playersHand.GetMaxScore ();

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

        /** Returns the score of this hand with a given aceValue.
            @param  aceValue    The value of an ace when its either high (worth 11 points), or low (worth 1 point).
            We want to reuse the same code for GetMinScore (), and GetMaxScore () because of the DRY Priciple: Don't 
            Repeat Yourself. The reason for it is that it can introduce bugs into the program if you don't, and in fact,
            there was a bug in my code when I didn't, which is why I'm writting this.

            This function is private because outside of this class, none of the other classes call this function, nor 
            do they care that this function even exists. The other objects only want to know the min and max score.
        */
        public int GetScore (int aceValue)
        {
            int score = 0;  //< Always set the variable before you start using it!!!

            /** Usually we want to verivy that aceValue is either 1 or 11, but this is a private function, so only we 
                can use the function so we know for 100% certainty that the aceValue will be 1 or 11. */

            foreach (Card currentCard in cards)
            {
                if (currentCard.FaceValue == Card.Ace)  //< First check if its an ace.
                    score += aceValue;
                else
                    score += currentCard.FaceValue;
            }

            return score;
        }

        /** Returns a String of either the dealer's, or the player's hand.
            @param  isDealer    Flag that represents if the hand is the dealer's hand or not.  */
        public String ToString (bool isDealer)
        {
            String returnString = "Hand (" + cards.Count + "): ";

            // In blackjack, one of the dealer's cards is face down, so we need to blank out the last card if isDealer 
            // is true.

            int numCards = cards.Count,                         //< The number of cards in this hand.
                lastCard = isDealer ? numCards - 1 : numCards;  //< The index of the last card to print.

            for (int i = 0; i < lastCard; i++)
            {

                if (i != lastCard) //< Used to put commas in the right place
                {
                    returnString += cards[i].ToString ();

                    if (i != numCards-1)  //< On the last card, we need to put a new line ("\n") instead of a comma.
                        returnString += ", ";
                }
            }

            if (isDealer)
                returnString += "???????\n";
            else
                returnString += "\nMin Score: " + GetMinScore () + ", Max Score: " + GetMaxScore () + "\n";

            return returnString;
        }

        /** Returns a String representation of this Object. */
        public override String ToString ()
        {
            return ToString (false);
        }

        private List<Card> cards;                       //< The cards.
    }
















    public class HandTests
    {
        public static void RunTests ()
        {
            Debug.Write ("\nTesting the Hand class\n" +
                "*******************************************************************************\n\n" + 
                "Creating stock...\n");
            int i;  //< Temp looping variable.

            var stock = new Deck ();
            stock.Shuffle ();
            
            Debug.Write ("Printing shuffled stock:\n" + stock.ToString () + "\n\nCreating handA...\n");
            
            var handA = new Hand ();

            Debug.WriteLine ("Drawing 5 cards from the top of the stock...");

            for (i = 0; i < 5; i++)
            {
                var tempCard = stock.DrawCard ();
                Debug.WriteLine ("Drawing Card " +tempCard + "\nstock.NumCards = " + stock.NumCards + 
                    "\nhandA.NumCards = " + handA.NumCards);
                handA.AddCard (tempCard);
            }

            Debug.Assert (handA.NumCards == 5, "Error: There were not 5 cards in handA!!!\n" + 
                handA.ToString () + "\n" + stock.ToString ());

            Debug.WriteLine ("\nTesting DealHand (Deck)...\n");
            
            handA.Clear ();
            handA.DealHand (stock);

            Debug.Write ("Printing handA: " + handA.ToString () + "\n\n");

            Debug.Write ("Attempting to draw more cards than the Deck has...");

            for (i = 0; i < 60; i++)
                handA.AddCard (stock.DrawCard ());

            Debug.Write ("\nPrinting handA:\n\n" + handA.ToString () + "\n\nClearing Hand and shuffling the stock...");

            handA.Clear ();
            stock = new Deck ();

            stock.Shuffle ();

            Debug.Assert (handA.NumCards == 0, "Error: The hand didn't clear right!\n");

            Debug.Write ("\n\nTesting min and max score functions...\n");

            handA.AddCard (stock.DrawCard (10, 3));
            handA.AddCard (stock.DrawCard (1, 4));    //< A 10 + an ace is a 21!
            Debug.Write ("\n\nhandA.Cards[0].FaceValue: " + handA.Cards[0].FaceValue + "\nhandA.Cards[0].PipValue: " + 
                handA.Cards[0].PipValue + "\nhandA.Cards[0].Suit: " + handA.Cards[0].Suit + "\n\n");
            Debug.Assert (handA.GetMinScore () == 11, "Error: The min score didn't calculate properly!\n" +
                "handA.GetMinScore () = " + handA.GetMinScore () + "\n" + 
                handA.ToString ());
            Debug.Assert (handA.GetMaxScore () == 21, "Error: The max score didn't calculate properly!\n" +
                "handA.GetMaxScore () = " + handA.GetMaxScore () + "\n" + 
                handA.ToString ());

            Debug.Assert (handA.GetMinScore () <= handA.GetMaxScore (), "Error: handA's min score (" + 
                handA.GetMinScore () + ") was greater than the max score (" + handA.GetMaxScore () + ")");

            Debug.Write ("\nTesting GetCard (int)...\n\n");

            Debug.Assert (handA.GetCard (0).PipValue == 10, "Error: handA card(0)'s pip value wasn't 10!\n\n" +
                handA.ToString () + "\n\n" +
                handA.GetCard (0).ToString () +
                "\n\nhandA.GetCard (0).PipValue = " + handA.GetCard (1).PipValue + "\n");

            Debug.Assert (handA.GetCard (-10).PipValue == 10, "Error: stock didn't bound right!\n" +
                "handA.GetCard (-10).PipValue = " + handA.GetCard (-10).PipValue);

            var handB = new Hand ();

            handB.AddCard (stock.DrawCard (9, 1));
            handB.AddCard (stock.DrawCard (4, 1));

            Debug.Assert (handB.GetMinScore () == 13 && handB.GetMaxScore () == 13, "Error: Min and Max " + 
                "score we not the same, which should be 13.");

            Debug.Write ("Testing compare function... \n\n");

            Debug.Assert (handA.Compare (handB) > 0, "Error: The ace plus 10 didn't win!");

            Debug.Write ("Compairing 5 plus King to Jack plus queen");

            handA.Clear ();
            handB.Clear ();

            handA.AddCard (stock.DrawCard (5, 1));
            handA.AddCard (stock.DrawCard (13, 1));
            handB.AddCard (stock.DrawCard (11, 1));
            handB.AddCard (stock.DrawCard (13, 1));

            Debug.Assert (handA.GetMinScore () <= handA.GetMaxScore (), "Error: handA's 2nd test min score (" + handA.GetMinScore () + ") was greater than the max score (" + handA.GetMaxScore () + ")");
            Debug.Assert (handB.GetMinScore () <= handB.GetMaxScore (), "Error: handB's min score (" + handB.GetMinScore () + ") was greater than the max score (" + handB.GetMaxScore () + ")");

            Debug.Assert (handA.Compare (handB) > 0, "Error: The handB was over 21 and the score of 15 lost!");

            Debug.Write ("\n\nDone testing the Deck class.\n\n\n");

        }
    }
}
