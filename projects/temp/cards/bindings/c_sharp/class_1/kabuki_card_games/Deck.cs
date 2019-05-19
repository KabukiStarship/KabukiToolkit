/** kabuki::cards
    @file       ~/kabuki::cards Library/Deck.cs
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

    /** A deck of playing cards.
        Termenology:
        - Pack: A pack of cards has 52 cards without jokers and 54 with jokers.
        - Deck: A deck can contain multiple packs of cards.
        - Stock: The main stack of cards is called the stock of cards.

        @see Card class
    */
    public class Deck
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        public const int PackSize = 52,         //< The number of cards in a single pack of cards excluding jokers.
            PackSizeWithJokers = 54;            //< Flag for if the deck doesn't have jokers.

        public const bool Jokers = true,        //< Deck contains jokers.
            NoJokers = false;                   //< Deck contains no jokers.

        /** Constructor. */
        public Deck (bool newDeckHasJokers = false, int newSuitType = Card.French, int newNumPacks = 1, 
            int[] newFaceValues = null, int[] newSuitValues = null)
        {
            hasJokers = newDeckHasJokers;
            numPacks = newNumPacks < 1 ? 1 : newNumPacks;

            int numCardsInPack = hasJokers ? PackSizeWithJokers : PackSize;

            deckSize = numCardsInPack * numPacks;

            // Create the cards.
            cards = new List<Card> ();

            if (newSuitType < 1)
                suitType = 1;
            else if (newSuitType > Card.NumSuitTypes)
                suitType = Card.NumSuitTypes;
            else
                suitType = newSuitType;

            faceValues = new int[Card.NumPips];
            suitValues = new int[Card.NumSuits];

            if (newFaceValues == null || newFaceValues.Length != Card.NumPips)
            {
                for (int i = 0; i < Card.NumPips; i++)
                    faceValues[i] = i;
            }
            else
                for (int i = 0; i < Card.NumPips; i++)
                    faceValues[i] = newFaceValues[i];

            if (newSuitValues == null || newSuitValues.Length != Card.NumSuits)
            {
                for (int i = 1; i <= Card.NumSuits; i++)
                    suitValues[i - 1] = i;
            }
            else
                for (int i = 0; i < Card.NumSuits; i++)
                    suitValues[i] = newSuitValues[i];

            String faceValuesString = "",
                suitValuesString = "";

            for (int i = 0; i < Card.NumPips; i++)
                faceValuesString += faceValues[i] + ", ";

            for (int i = 0; i < Card.NumSuits; i++)
                suitValuesString += suitValues[i] + ", ";

            for (int i = 1; i <= numPacks; i++)
                AddPackToDeck ();
        }

        /** Function the returns if the stock is empty. */
        public bool IsEmpty
        {
            get { return cards.Count == 0; }
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

        /** Returns true if this deck has jokers in it. */
        public bool HasJokers
        {
            get { return hasJokers; }
        }

        /** Returns the Card at the specified index without removing it.
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

        /** Returns a Card witht he given pip and suit values.
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

            int randomIndex = randomGenerator.Next (NumCards);
            var returnCard = cards[randomIndex];    //< Store the random card as a temp variable.
            cards.RemoveAt (randomIndex);           //< Remove the randomIndex we saved earlier.
            return returnCard;                      //< Then return the temp variable.
        }

        /** Gets the number of packs in the deck. */
        public int NumPacks
        {
            get  {  return numPacks; }
        }

        /** Returns the maximum number of cards in a new full deck.
            @warning    The number of cards in the deck may exceed this number. */
        public int DeckSize
        {
            get { return deckSize; }
        }

        /** Adds a packs's worth of cards with this deck. */
        public void AddPackToDeck ()
        {
            /** The order of the pips are A,2,3,4,5,6,7,8,9,10,J,Q,K, and don't want any Jokers. We need to 
                start at 1, and loop through 13 times. */
				
            for (int suit = Card.Ace; suit <= 4; suit++)                    //< 
            {
                for (int pipValue = 1; pipValue <= Card.King; pipValue++) 	// Once for each of the 13 pip values 
                {
                    /** This is called a nested for loop. It makes it so that our cards will be sorted by suit and 
                        value. Note: If we had switched the order of the nested for loops, it would sort the cards by 
                        value then suit.
                    */

                    var newCard = new Card (pipValue, suit, faceValues[pipValue], suitValues[suit - 1], suitType);
                    cards.Add (newCard);
                }
            }

            if (hasJokers)
            {
                cards.Add (new Card (Card.Joker, Card.Red));
                cards.Add (new Card (Card.Joker, Card.Black));
            }
        }

        /** Returns a String representation of this Object. */
        public override String ToString ()
        {
            String returnString = "Deck: numCards: ";

            returnString += cards.Count + "\n";

            for (int i = 0; i < cards.Count; ++i)
            {
                returnString += cards[i].ToString ();

                if (i != cards.Count)
                    returnString += ", ";
                else
                    returnString += "\n";
            }

            return returnString;
        }
        //--------------------------------------------------------------------------------------------------------------

        private int numPacks,                   //< The number of decks.
            deckSize,                       	//< The size of a full deck.
            suitType;                           //< The suit type for this Deck
        private int[] suitValues,               //< The map of suit values.
            faceValues;                         //< The array of faceValues.
        private bool hasJokers;                 //< Stores if this deck has jokers or not.

        private List<Card> cards;               /*< The Array of Card objects.
													The <> is a C++ thing. Its called a template. We just made a Array of Card. */
		/** A Random number generator. */
        private Random randomGenerator = new Random ();
    }
















    public class DeckTests
    {
        public static void RunTests ()
        {
            Debug.Write ("\nTesting Deck Class\n" +
                "*******************************************************************************\n\n" + 
                "Creating test Deck...\n\n");
            
            Deck stock = new Deck ();

            Debug.Assert (stock.NumCards == 52, "Error: There where not 52 stock!\n" + stock.ToString());

            Debug.Write (stock.ToString () + "\n\nShuffling Deck...\n");
            
            stock.Shuffle ();

            Debug.WriteLine ("\n\n" + stock.ToString () + 
                "\n\nTesting DrawCard () by drawing 42 stock...\n");

            for (int i = 0; i < 42; i++)
                Debug.Write (stock.DrawCard ().ToString () + ", ");

            Debug.WriteLine ("\n\nPrinting last 10 stock...\n\n" + stock.ToString () + 
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
            Debug.Assert (counter == numExpectedNullstock, "Error: There were supposed to be " + numExpectedNullstock + " null stock and got " + counter + "!\nDraw stock:\n" + drawnstock + "\n" + stock.ToString ());
            
            Debug.Assert (stock.IsEmpty, "Error: After trying to take more stock than the stock had, the stock was not empty!");

            Debug.Write ("\n\nPrinting empty Deck...\n\n" + stock.ToString () + 
                "\n\nShuffling and printing stock...\n");

            stock.Shuffle();

            Debug.WriteLine (stock.ToString () + "\n\n");

            Debug.WriteLine ("Done testing the Deck class.\n");
        }
    }
}