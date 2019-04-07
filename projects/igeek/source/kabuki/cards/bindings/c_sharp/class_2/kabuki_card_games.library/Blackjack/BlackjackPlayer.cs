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

    public class BlackjackPlayer: Player
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        /** Default constructor creates a dealer with the max number of points.
            Note: Do not put variables or logic into the constructor. Make a function for them, and call that 
            function because it is easier to test.
        */
        public BlackjackPlayer() :
            base("Dealer", 0x7FFFFFFF, true)
        {
            Hand = new BlackjackHand ();
            isHolding = false;
        }

        /** Constructor creates a player. */
        public BlackjackPlayer(String thisPlayerName, int startingPoints) : 
            base(thisPlayerName, startingPoints, false)
        {
            Hand = new BlackjackHand ();
            isHolding = false;
        }

        /** Resets the number of wins to 0.
            @return Returns 0 if the Deck had enough cards, -1 if the stock is null, and false if it didn't. */
        public override int DealHand(Deck stock)
        {
            if (stock == null)
                return -1;
            
            isHolding = false;   //< Reset the isHolding flag so we can play.

            //< And deal a new hand.
            return Hand.DealHand(stock);
        }

        /** Function that attempts to take a card from the Deck for a player.
            @pre    The Deck must not be empty.
            @pre    The player must have a max hand score of 21. */
        public virtual void HitMe(Deck stock)
        {
            Debug.Write (Name + "'s turn.\n");
            if (stock.IsEmpty)    // Always check for error conditions first!
            {
                Debug.Write("Error! The Deck was empty.");
                isHolding = true;
                return;
            }

            BlackjackHand thisHand = (BlackjackHand)Hand;

            if (thisHand.IsBust () || thisHand.Is21 ())
            {
                // If the player's hand is a bust, than the dealer is not allowed to deal that player another card.
                isHolding = true;
                return;
            }

            var newCard = stock.DrawCard();
            Hand.AddCard(newCard);

            if (thisHand.IsBust())
            {
                // If the player's hand is a bust, than the dealer is not allowed to deal that player another card.
                isHolding = true;
            }
        }

        /** Functions sets the isHolding flag to the new value */
        public bool IsHolding
        {
            get { return isHolding; }
            set { isHolding = value; }
        }

        /** Returns a String representation of this object. */
        public override String ToString()
        {
            BlackjackHand thisHand = (BlackjackHand)Hand;

            return CardGame.ConsoleLine ('_') +
                "Player: " + Name +
                "\nNum Points: " + NumPoints + " Num Wins: " + NumWins + 
                "\n" + Hand.ToString () + CardGame.ConsoleLine ('_');
        }

        //--------------------------------------------------------------------------------------------------------------

        private bool isHolding;                                //< Variable stores if the user is isHoldinging.
    }
















    public class BlackjackPlayerTests : UnitTest
    {
        /** Default constructor setups up and runs a test. */
        public BlackjackPlayerTests()
        {
            SetupTest();
            RunTests();
        }

        /** Sets up the Unit Test. */
        public override void SetupTest()
        {
        }

        /** Runs the unit test. */
        public override void RunTests ()
        {
            Debug.Write("Testing the BlackjackPlayer class\n" + CardGame.ConsoleLine ('*') + "\n" + 
                "Creating player1 and printing ToString ()...\n");

            var player1 = new BlackjackPlayer("Player 1", 10);

            Debug.Write(player1.ToString() + "\n\n" +
                "Attempting to take away more points than the user has...\n\n");

            player1.RemovePoints(100);

            Debug.Assert(player1.NumPoints == 10, "Error! The computer took away more points than player1 had!");

            var Deck = new Deck();
            Deck.Shuffle();

            Debug.Write("Dealing hand and testing int Compare (Hand) function...\n\n");

            var player2 = new BlackjackPlayer("Player 2", 999999999);

            player1.Hand.AddCard(Deck.DrawCard(10, 3));
            player1.Hand.AddCard(Deck.DrawCard(1, 4));

            player2.Hand.AddCard(Deck.DrawCard(10, 3));
            player2.Hand.AddCard(Deck.DrawCard(5, 4));

            Debug.Write("Comparing 10 plus ace to 10 plus 5\n");

            Debug.Assert(player1.Hand.Compare(player2.Hand) > 1, "Error ! player1 had 21!");

            player1.Hand.Clear();
            player2.Hand.Clear();

            player1.Hand.AddCard(Deck.DrawCard(13, 3));
            player1.Hand.AddCard(Deck.DrawCard(7, 4));

            player2.Hand.AddCard(Deck.DrawCard(7, 3));
            player2.Hand.AddCard(Deck.DrawCard(4, 4));

            Debug.Assert(player1.HandWins(player2), "Error ! player1 had a hiter point total!");


            Debug.Write("\n\nDone testing the BlackjackPlayer class.\n\n\n");
        }
    }
}




/** Returns a String representation with this Player's name and hand.
public String ToStringBrief ()
{
    BlackjackHand thisHand = (BlackjackHand)Hand;

    var handString = Hand.ToString ();
    // The ? : is a fancy way of saying if else. Its called a ternary operator.

    return CardGame.ConsoleLine ('~') +
        "Player: " + Name + "\n" +
        handString +
        "\n" + CardGame.ConsoleLine ('~');
} */

/** Returns a String representation with this Player's name and hand. 
public String ToStringFinal ()
{
    var handString = Hand.ToString ();
    // The ? : is a fancy way of saying if else. Its called a ternary operator.

    return CardGame.ConsoleLine ('~') +
        "Player: " + Name + "\n" +
        handString + CardGame.ConsoleLine ('~');
}*/
