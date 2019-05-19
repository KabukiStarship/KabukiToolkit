/** kabuki::cards
    @file       ~/kabuki::cards Library/CardPile.cs
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

    /** A pile of playing cards.

        @see Card class
    */
    public class CardPile
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        /** Constructor. */
        public CardPile ()
        {
            // Create the cards.
            cards = new List<Card> ();
        }

        /** Copy constructor. */
        public CardPile (CardPile other)
        {
            int newNumCards = other.NumCards;
            cards = new List<Card> (newNumCards);
            for (int i = 0; i < newNumCards; i++)
                cards[i] = new Card (other.GetCard (i));
        }

        public void Clear ()
        {
            cards = new List<Card> ();           //< This creates an empty list of Card objects.
        }

        /** Returns the list of cards. */
        public List<Card> Cards
        {
            get { return cards; }
        }

        /** Shuffles the stock. */
        public void Shuffle ()
        {
            int numberOfCards = NumCards;

            var shuffledCards = new List<Card>(NumCards);

            for (int i = 0; i < numberOfCards; i++)
                shuffledCards.Add (DrawRandomCard ());

            cards = shuffledCards;
        }

        /** Returns the number of cards in the cards. */
        public int NumCards
        {
            get { return cards.Count; }
        }

        /** Checks to see if thisCard is in the pile and returns true if it is. */
        public bool Contains (Card thisCard)
        {
            if (thisCard == null)
                return false;

            foreach (Card card in Cards)
                if (Equals (card))
                    return true;
            return false;
        }

        /** Checks to see if the given card pip value and suit is in the pile and returns true if it is. */
        public bool Contains (int thisPipValue, int thisSuit)
        {
            foreach (Card card in Cards)
                if (Equals (thisPipValue, thisSuit))
                    return true;
            return false;
        }

        /** Adds the newCard to this Hand. */
        public virtual int AddCard (Card newCard)
        {
            if (newCard == null)
            {
                Debug.WriteLine ("Error: Tried to add a null card to a CardPile.");
                return -1;
            }
            cards.Add (new Card(newCard));  //< This uses the Card class's copy constructor.
            return 0;
        }

        /** Adds the newCard to this Hand. */
        public virtual int AddCard (int pipValue, int suit)
        {
            if (pipValue < Card.Joker)
                return -1;
            if (pipValue > Card.King)
                return -2;
            if (suit < 1)
                return 1;
            if (suit > Card.NumSuits)
                return 2;

            AddCard (new Card (pipValue, suit));

            return 0;
        }

        /** Adds the newCard to this Hand. */
        public virtual int AddCards (CardPile newCards)
        {
            if (newCards == null)    //< We do not allow Jokers.
            {
                Debug.WriteLine ("Error: Attempted to add a null pile of cards to a CardPile!");
                return -1;
            }

            foreach (Card card in newCards.Cards)
                AddCard (newCards.DrawCard ());

            return 0;
        }

        /** Adds the newCard to this Hand. */
        public virtual int InsertCard (Card newCard, int index)
        {
            if (newCard == null)
                return -1;

            if (index < 0 || index >= NumCards) //< Index out of bounds!
                return - 2;
            
            cards.Insert (index, newCard);

            return 0;
        }

        /** Returns the Card at the specified index.
            @return Returns a black joker if the index is out of bounds.
        */
        public Card GetCard (int index)
        {
            if (index < 0 || index >= cards.Count)
                return null;

            return cards[index];
        }

        /** Draws a random card from the cards. */
        public Card DrawCard ()
        {
            if (cards.Count == 0) // Then there are no cards in the cards.
                return null;

            int lastIndex = cards.Count - 1;
            /*< Golden rule: If you use a variable in a function more than once, store a local copy to get a performance 
                increase. */

            var nextCard = cards[lastIndex];     //< Store the top card on the cards in a temp variable.
            cards.RemoveAt (lastIndex);          //< Now remove the card from the data structure (i.e. the List)

            return nextCard;                    //< The you return the temp variable... You'll see this pattern a lot.
        }

        /** Draws a CardPile with the spcified number of cards.
            @return Return null if there are not enough cards. */
        public CardPile DrawCards (int numCards)
        {
            if (numCards > NumCards)
                return null;

            CardPile newPile = new CardPile ();

            // We have to search the whole cards with a for loop.
            for (int i = 0; i < numCards; i++)
                newPile.AddCard (DrawCard ());

            return newPile;
        }

        /** Returns a Card with the given pip and suit values.
            @return Return a Red Joker with suitValue of 3 (diamons) if the cards doesn't contain the card. */
        public Card DrawCard (int pipValue, int suitValue)
        {
            // We have to search the whole cards with a for loop.
            for (int i = 0; i < cards.Count; i++)
            {
                var currentCard = cards[i];

                if (currentCard.Equals (pipValue, suitValue))
                {
                    cards.RemoveAt (i);
                    return currentCard;
                }
            }
            return null;
        }

        /** Draws a random card from the cards. */
        public Card DrawRandomCard ()
        {
            if (cards.Count == 0) //< Then there are no cards in the cards.
                return null;

            int randomIndex = randomNumberGenerator.Next (NumCards);
            var returnCard = cards[randomIndex];    //< Store the random card as a temp variable.
            cards.RemoveAt (randomIndex);           //< Remove the randomIndex we saved earlier.
            return returnCard;                      //< Then return the temp variable.
        }

        /** Function the returns if the stock is empty. */
        public bool IsEmpty
        {
            get { return cards.Count == 0; }
        }

        /** Returns a String representation of this Object. */
        public override String ToString ()
        {
            int numCards = NumCards;

            String returnString = "Cards: " + numCards + "\n";

            for (int i = 0; i < numCards; i++)
            {
                returnString += cards[i].ToString ();

                if (i != numCards)
                    returnString += ", ";
            }

            return returnString + "\n";
        }
        //--------------------------------------------------------------------------------------------------------------

        private List<Card> cards;               /*< The Array of Card objects.
													The <> is a C++ thing. Its called a template. We just made a Array of Card. */

        private Random randomNumberGenerator = new Random ();
    }
















    public class CardPileTests : UnitTest
    {
        /** Default constructor setups up and runs a test. */
        public CardPileTests ()
        {
            SetupTest ();
            RunTests ();
        }

        /** Sets up the unit test. */
        public override void SetupTest ()
        {
        }

        /** Runs the unit tests. */
        public override void RunTests ()
        {
            Debug.Write ("\nTesting CardPile Class\n" + CardGame.ConsoleLine ('*') + "\n" + 
                "Creating test CardPile...\n\n");
            
            var stock = new CardPile ();

            for (int i = 0; i < Deck.PackSize; i++)
                stock.AddCard (Card.RandomCard ());

            Debug.Assert (stock.NumCards == 52, "Error: There where not 52 cards!\n" + stock.ToString());

            Debug.Write (stock.ToString () + "\n\nShuffling CardPile...\n");
            
            stock.Shuffle ();

            Debug.WriteLine ("\n\n" + stock.ToString () + 
                "\n\nTesting DrawCard () by drawing 42 card...\n");

            for (int i = 0; i < 42; i++)
                Debug.Write (stock.DrawCard ().ToString () + ", ");

            Debug.WriteLine ("\n\nPrinting the last 10 cards...\n\n" + stock.ToString () + 
                "\n\nTesting DrawRandomCard () by drawing 5 stock...\n");

            for (int i = 0; i < 5; i++)
                Debug.Write (stock.DrawRandomCard ().ToString () + ", ");

            int numLoops = 10,
                numExpectedNullstock = numLoops - stock.NumCards,
                counter = 0;

            Debug.WriteLine ("\n\nPrinting last " + numExpectedNullstock + " stock...\n\n" + stock.ToString () +
                "\n\nDrawing 10 more random stock and expecting 5 null stock...\n");

            String drawnstock = "";
            
            for (int i = 1; i <= numLoops; i++)
            {
                var tempCard = stock.DrawRandomCard ();

                if (tempCard != null)
                {
                    Debug.WriteLine (i + ", ");
                    drawnstock += tempCard.ToString () + ", ";
                }
                else
                    counter++;
            }
            Debug.Assert (counter == numExpectedNullstock, "Error: There were supposed to be " + numExpectedNullstock +  
                " null stock and got " + counter + "!\nDraw stock:\n" + drawnstock + "\n" + stock.ToString ());
            
            Debug.Assert (stock.IsEmpty, "Error: After trying to take more stock than the stock had, the stock was " +
                "not empty!");

            Debug.Write ("\n\nPrinting empty CardPile...\n\n" + stock.ToString () + 
                "\n\nShuffling and printing stock...\n");
            
            stock.Shuffle();

            Debug.WriteLine (stock.ToString () + "\n\n");

            Debug.WriteLine ("Done testing the CardPile class.\n");
        }
    }
}