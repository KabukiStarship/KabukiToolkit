/** kabuki::cards
    @version 0.x
    @file    ~/source/kabuki/cards/include/card.cs
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
    
    @desc   This called a header. This doesn't do anything in C#, its just some text. Stuff with @ symbols before it 
        are doxygen tags. @desc means a description.

        Rule #1 of Programming: Make your code as easy to understand as possible. Try to write as many comments as you 
        can in easy in easy to read plain-old english and don't use cryptic function variable names. The easiest 
        language to proggram in is english (or your native lanauge). English is the default standard language used 
        around the world for programming.
*/

using System;
using System.Diagnostics;

namespace DojoCardGames
{

    /** Class that represents a card in a card game.
        A card requires two numbers to uniquely identify it, a pip value and a suit. A pip value is the numerical 
        value of the card from 0-13, 0 being a Joker, 1 being an Ace, and 13 being a King. The suits are numbered 
        1-4 by default in the order clubs, diamonds, hearts, and last spades. In some card games such as Hearts, the 
        hearts are worth the most. This is why we store both a suit index and a suit value.
    */
    public class Card
    {
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        
        // Everything in a computer is stored either a number. And in is a whole number like 1, 2, 3, -1, -2, -3, etc.

        public const int NumSuits = 4,      //< The number of suits.
            NumPips = 14,                   //< The number of pips.
            Red = 2,                        //< The suit index for a red joker.
            Black = 1,                      //< The suit index for a black joker.
            NumSuitTypes = 4,               //< The number of suit types: french, german, swiss, and latin.
            // Non-numbertical pips.
            Joker = 0,                      //< The pip value of a Joker.
            Ace = 1,                        //< The pip value of an Ace.
            Jack = 11,                      //< The pip value of a jack.
            Queen = 12,                     //< The pip value of a queen.
            King = 13,                      //< The pip value of a king.
            // The default (french) suits.
            Clubs = 1,                      //< The suit index of a club.
            Diamonds = 2,                   //< The suit index of a diamond.
            Hearts = 3,                     //< The suit index of a heart.
            Spades = 4,                     //< The suit index of a spade.
            // The 4 different suit types.
            French = 1,                     //< A french playing card.
            German = 2,                     //< A german playing card.
            Swiss = 3,                      //< A swiss playing card.
            Latin = 4,                      //< A latin playing card.
            // Alternate suit names.
            Acorns = 1,                     //< The suit index of a acorn.
            Bells = 2,                      //< The suit index of a bell.
            Coins = 2,                      //< The suit index of a coin.
            Roses = 3,                      //< The suit index of a rose.
            Cups = 3,                       //< The suit index of a cup.
            Leaves = 4,                     //< The suit index of a lief.
            Shields = 4,                    //< The suit index of a shield.
            Swords = 4,                     //< The suit index of a sword.
            //  Flag to create the default values for a card.
            Default = -1;                   

        /** The names of the pip values. */
        public static readonly String[] PipNames = { "Joker", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "Jack", "Queen", "King" };
        /** The names of the french suits. */
        public static readonly String[] FrenchSuitNames = { "Clubs", "Diamonds", "Hearts", "Spades" },
        /** The names of the german suits. */
            GermanSuitNames = { "Acorns", "Bells", "Hearts", "Spades" },
        /** The names of the french suits. */
            SwissSuitNames = { "Acorns", "Bells", "Roses", "Shields" },
        /** The names of the french suits. */
            LatinSuitNames = { "Clubs", "Coins", "Cups", "Swords" };

        /** Default constructor.
            This constructor creates a simple card. If you want to create a Card object, you write: 
            
            @endcode
            Card newCard1 = new Card ();            // Creates a black joker by default.
                newCard2 = new Card (Joker, Black); // Creates a black joker.
                newCard3 = new Card (5, 2);         // Creates a 5 of diamonds.

                // We only need a pip value and a suit to make a standard card, but if we want to make a game with 
                // different rules, we use the 3rd through last parameters.

                newCard4 = new Card (King, Hearts, 4, 13, German);      // Creates a King of hearts for the game 
                // Hearts where the King is worth 13 and the suits say "Acorns", "Bells", "Hearts", and "Spades".
            @endcode
            
            This will create a black joker (Joker, Black). Joker is defined above as 0, and Black is 1.

            @param newPipValue      The pip value of the card.
            @param newSuit          The index number of the suit that never changes.
            @param newSuitValue     The remapped value of the suit for games.
            @param newFaceValue     The face value of the card
            @param newSuitType      The type of suit: French, German, Swiss, or Latin.
        */
        public Card (int newPipValue = Joker, int newSuit = Black, int newFaceValue = Default, 
            int newSuitValue = Default, int newSuitType = French)
        {
            /** Rule #2 of Programming: Always check for errors first!!!
                Rule #3 of Programming: Never let errors mess up your program!
                
                All pip values are from 0-13, and all suits are from 1-4. If these values are ever incorrect,  it will 
                cause the computer to crash. We want to "bound" the number between the minimum and maximum value. For 
                this we use and if else statement to check if the input was too low, or too high.

                Rule #4 of Programming: Don't repeat yourself (DRY). The more you repeat something the more errors you 
                will have.
                @see int BoundNumber (int number, int minValue, int maxValue);
            */
            PipValue = newPipValue;
            Suit     = newSuit;

            // Set suitValue
            if (newSuitValue != Default)        //< In some games, spades are worth the most, other hearts are. 
                SuitValue = suit;
            else
                SuitValue = newSuitValue;

            // Set faceValue.
            if (newFaceValue != Default)        //< This allows the user to remap the face value to whatever they want.
                faceValue = newFaceValue;       //< Note: this one uses the lowercase faceValue.
            else
                FaceValue = pipValue;

            SuitType = newSuitType;
        }

        /** Copy Constuctor
            Quickly copies the state of the other object. */
        public Card (Card other)
        {
            if (other == null)
            {
                suit = Black;
                suitValue = Black;
                pipValue = Joker;
                faceValue = 0;
                suitType = French;
                return;
            }
            
            suit      = other.suit;
            suitValue = other.suitValue;
            pipValue  = other.pipValue;
            faceValue = other.faceValue;
            suitType  = other.suitType;
        }

        /** Returns the index of the given card's pip value and suit in an unshuffled pack of cards. */
        public static int GetPackIndex (int pipValue, int suit)
        {
            if (pipValue == Joker)
            {
                if (suit == Red)
                    return 52;
                else
                    return 53;
            }
            return (pipValue - 1) + ((suit - 1) * NumPips);
        }

        /** Returns the index of this card in an unshuffled pack of cards. */
        public int PackIndex
        {
            get
            {
                return GetPackIndex (pipValue, suit);
            }
        }

        /** Returns the pip value of this Card.
            A pip value is a number between 0-13 that represents which card it is: J=0, A=1, 2-10, J=11, Q=12, K=13. */
        public int PipValue
        {
            get
            {
                return pipValue;
            }
            set
            {
                if (value < Joker)
                    pipValue = Joker;
                else if (value > King)
                    pipValue = King;
                else
                    pipValue = value;
            }
        }
        /** Getter and setter for the face value of this Card.
            The face value is a number between 0-10 in blackjack. */
        public int FaceValue
        {
            get
            {
                return faceValue;
            }
            set
            {
                faceValue = value; 
            }
        }

        /** Gets and sets the suit of this card. */
        public int Suit
        {
            get
            {
                return suit;
            }
            set
            {
                if (value < 1)
                    suit = 1;
                else if (value > NumSuits)
                    suit = NumSuits;
                else
                    suit = value;
            }
        }

        /** Gets and sets the remapped suit value of this card. */
        public int SuitType
        {
            get
            {
                return suitType;
            }
            set
            {
                if (value < 1)
                    suitType = 1;
                else if (value > NumSuits)
                    suitType = NumSuits;
                else
                    suitType = value;
            }
        }

        /** Gets and sets the remapped suit value of this card. */
        public int SuitValue
        {
            get
            {
                return suitValue;
            }
            set
            {
                if (value < 1)
                    suitValue = 1;
                else if (value > NumPips)
                    suitValue = NumSuits;
                else
                    suitValue = value;
            }
        }

        /** Operator compares thisCard to the otherCard and returns true if they are the same. */
        public bool Equals (int otherPipValue, int otherSuit)
        {
            // && means "and".
            return (pipValue == otherPipValue) && (suit == otherSuit);
        }

        /** Operator compares thisCard to the otherCard and returns true if they are the same. */
        public bool Equals (Card other)
        {
            //< Always check to see if an object is null before trying to access any of it's data members!!!

            if ((Object)other == null)
                return false;

            Debug.WriteLine ("other.ToString (): " + other.ToString () + "\nother.PipValue: " + other.pipValue + " other.Suit: " + other.suit);
            return Equals (other.PipValue, other.Suit);
        }

        /** Returns a string representation of the pip value. */
        public String PipName
        {
            get { return PipNames[pipValue]; }
        }

        /** Returns a string representation of the suit name. */
        public String SuitString
        {
            get
            {
                switch (suitType)
                {
                    case German:
                    return GermanSuitNames[suit - 1];
                    case Swiss:
                    return SwissSuitNames[suit - 1];
                    case Latin:
                    return LatinSuitNames[suit - 1];
                    default:
                    return FrenchSuitNames[suit - 1];
                }
            }
        }

        /** Static funciton returns a new Red Joker. */
        public static Card RedJoker ()
        {
            return new Card (Card.Joker, Card.Red);
        }

        /** Static funciton returns a new Red Joker. */
        public static Card BlackJoker ()
        {
            return new Card (Card.Joker, Card.Black);
        }

        /** Static function returns a randomly generated card. */
        public static Card RandomCard ()
        {
            return new Card (randomGenerator.Next (Card.NumPips-1) + 1, randomGenerator.Next (Card.NumSuits - 1) + 1);
        }

        /** Returns a String representation of this Object. */
        public override String ToString ()
        {
            if (pipValue == Joker)
            {
                if (suit == 1 || suit == 4)
                    return "Black Joker";
                return "Red Joker";
            }

            return PipName + " of " + SuitString;
        }

        //-----------------------------------------------------------------------------------------------------------------

        /** The following are private functions and variables. This means that they can only be viewed by the Card class, 
            and not by anyother classes.
        */

        private int suit,                       //< The suit of this card from 1-4.
            suitValue,                          /*< The value of this suit from 1-4.
                                                    Allows the suit values to be remapped for games like Hearts. */
            pipValue,                           //< The value of this Card from 0-13.
            faceValue,                          //< The face value of this card from 1-11.
            suitType;                            //< The type of suit French, German, Swiss, or Latin.
        /** A random number generator. */
        static Random randomGenerator = new Random ();
    }















    /** The unit tests for the Card class. */
    public class CardTests : UnitTest
    {
        /** Default constructor setups up and runs a test. */
        public CardTests ()
        {
            SetupTest ();
            RunTests ();
        }

        /** Sets up the unit test. */
        public override void SetupTest ()
        {
        }

        /** Runs the unit test. */
        public override void RunTests ()
        {
            Debug.Write ("\nTesting Card Class\n" +
                CardGame.ConsoleLine ('*') +
                "Creating test Card object...\n");

            Card cardA,
                cardB;
            
            cardA = new Card ();
            Debug.Assert (cardA.ToString () == "Black Joker", "Error: Default constructor should produce a black" +
                "joker.\n" + cardA.ToString ());

            cardA = new Card (Card.Joker, Card.Hearts);

            Debug.Assert (cardA.ToString () == "Red Joker", "Error: new Card (Card.Joker, Card.Hearts) " +
                "should produce a black joker.\n" + cardA.ToString ());

            cardA = new Card (Card.Joker, Card.Spades);
            Debug.Assert (cardA.ToString () == "Black Joker", "Error: new Card (Card.Joker, Card.Spades) " +
                "should produce a black joker.\n" + cardA.ToString ());

            cardA = new Card (Card.Ace, Card.Spades);
            Debug.Assert (cardA.ToString () == "Ace of Spades", "Error: new Card (Card.Ace, Card.Spades) " +
                "should produce a black joker.:\n" + cardA.ToString ());

            cardA = new Card (5, Card.Spades);
            Debug.Assert (cardA.ToString () == "5 of Spades", "Error: new Card (5, Card.Spades) " +
                "should produce a black joker.:\n" + cardA.ToString ());

            Debug.Write ("Testing Card.Compare (Card) function...\n" +
                "Creating some test Card object to compare. \n");

            Debug.Write ("Creating some Cards with invalid input and testing Equals (int, int) function.\n");

            cardA = new Card (-4, 6);
            Debug.Assert (cardA.ToString () == "Black Joker", "Error: new Card (-4, 6) didn't create a Black " + 
                "Joker, but created a " + cardA.ToString ());

            cardA = new Card (15, -1);
            Debug.Assert (cardA.ToString () == "King of Clubs", "Error: new Card (15, -1) didn't create a King " +
                "of Clubs, but created a " + cardA.ToString ());

            Debug.Write ("Testing bool Equals (Card other) funciton\n");

            cardA = new Card (5, Card.Spades);

            Debug.Assert (cardA.Equals (5, Card.Spades), "Error: !cardA.Equals(5, Card.Spades) :\ncardA: " +
                cardA.ToString ());

            cardB = new Card (5, Card.Spades);
            Debug.Assert (cardA.Equals(cardB), "Error: !cardA.Equals(cardB) :\ncardA: " + cardA.ToString () + "\ncardB: " + 
                cardB.ToString ());

            Debug.Write ("Done testing the Card class.\n\n");
        }
    }
}
