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
namespace DojoCardGames
{
    using System;
    using System.Diagnostics;

    public class Player
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        public readonly int MaxNameLength = 20;     //< The max length of a player's name;

        /** Constructor.
            Note: Do not put variables or logic into the constructor. Make a function for them, and call that function
        */
        public Player (String thisPlayerName, int startingPoints, bool playerIsDealer)
        {
            SetPlayerValues (thisPlayerName, startingPoints, playerIsDealer);
        }
		
        /** Function that sets the private variables of this class for the constructor.
            This function does the work from the constructor. It is best practice to not have any logic or variables in  
            the constructor, and to just call functions from the constructor(s). This makes it easier to debug programs 
            when they get large and complex.
        */
        private void SetPlayerValues (String thisPlayerName, int startingPoints, bool playerIsDealer)
        {
            name = thisPlayerName;
            numWins = 0;
            numPoints = startingPoints < 1 ? 1 : startingPoints;
            hand = new Hand ();
            isHolding = false;
            isDealer = playerIsDealer;
        }

        /** Resets the number of wins to 0.
            @return Returns true if the stock had enough cards, and false if it didn't. */
        public bool DealHand (Deck stock)
        {
            isHolding = false;   //< Reset the hold flag so we can play.

            //< And deal a new hand.
            return hand.DealHand (stock);
        }

        /** Function that attempts to take a card from the stock for a player.
            @return Returns 0 upon success.
            @return Returns -1 if there are not enough cards in the deck.
            @return Returns 21 if this players hand is 21.
            @pre    The stock must not be empty.
            @pre    The player must have a max hand score of 21. */
        public int HitMe (Deck stock)
        {
            if (stock.NumCards < 2)    // Always check for error conditions first!
            {
                Debug.Write ("Error: The stock was empty.");
                isHolding = true;
                return -1;
            }
            int minScore = hand.GetMinScore (),
                maxScore = hand.GetMaxScore ();

            if (minScore >= 21)
            {
                isHolding = true;
                return 1;
            }

            if (minScore == 21 || maxScore == 21)
            {
                isHolding = true;
                return 21;
            }

            var newCard = stock.DrawCard ();
            Debug.Write ("Inserting newCard into hand: " + newCard.ToString () + "\n");
            hand.AddCard (newCard);
            Debug.Write ("\n\n" + hand.ToString () + "\n\n");
            
            return 0;
        }

        /** Function that determines if this Player plays, or passes.
            This function performs the dealer's logic. For an extra ninja bonus star, you can use polymorphism to make 
            a sub-class of this object, and override this function to make your own AI computer algorithm! */
        public void HitOrHold (Deck stock)
        {
            if (isHolding)       //< We don't do anything if we are holding.
                return;

            /** The rule for the dealer in blackjack is that if they their hand is less than 17, then then have take a 
                card. */
            if (hand.GetMaxScore () > 17)
            {
                isHolding = true;
                return;
            }

            HitMe (stock);
        }

        /** Getter and setter for the playerName. */
        public String Name
        {
            get { return name; }
            set { name = value; }
        }

        /** Sets the playerName to the newName. */
        public bool SetName (String newName)
        {
            if (newName.Length > MaxNameLength)
                return false;

            name = newName;
            return true;
        }

        /** Returns the player's hand. */
        public Hand Hand
        {
            get { return hand; }
            set { hand = value; }
        }

        /** Returns the point total. */
        public int NumPoints
        {
            get { return numPoints; }
        }

        /** Adds a specified numPoints to the players point total.
            @return Returns 0 upon success, and -1 if num_points is less than 1.
        */
        public int AddPoints (int pointsToAdd)
        {
            if (pointsToAdd < 0)
                return -1;

            numPoints += pointsToAdd;

            return numPoints;
        }

        /** Removes the specified numPoints from the players point total.
            @return Returns 0 upon success, -1 if thesePoints is less than 0, or returns the number of missing points 
                if the player doesn't have enough points to take.
        */
        public int RemovePoints (int pointsToRemove)
        {
            if (pointsToRemove < 0)
                return -1;

            if (pointsToRemove > numPoints)
                return numPoints - pointsToRemove;

            numPoints -= pointsToRemove;

            return 0;
        }

        /** Returns the number of wins. */
        public int GetNumWins ()
        {
            return numWins;
        }

        /** Adds a win to the players numWins. */
        public void AddWin ()
        {
            ++numWins;
        }

        /** Resets the numWins to 0. */
        public void ResetWins ()
        {
            numWins = 0;    //< Reset the numWins.
        }

        /** Hand that compares this player's hand to the opponent's hand and returns true if this player wins. */ 
        public bool HandWins (Player opponent)
        {
            return hand.Compare (opponent.hand) > 0;
        }

        /** Function returns if this player is holding. */
        public bool IsHolding
        {
            get { return isHolding; }
            set { isHolding = value; }
        }

        /** Function returns if this is the dealer or not */
        public bool IsDealer
        {
            get { return isDealer; }
            set { isDealer = value; }
        }

        /** Returns a String with this player's numPoints and numWins. */
        public String PointsAndWinsToString ()
        {
            return "/------------------------------\n" +
                "| Player: " + name + "\n" +
                "| Points: " + numPoints + "\n" + 
                "| Wins: "   + numWins + 
                "\n\\------------------------------\n";
        }

        /** Returns a String representation with this Player's name and hand. */
        public String ToStringBrief ()
        {
            var handString = isDealer ? hand.ToString (true) : hand.ToString ();
            // The ? : is a fancy way of saying if else. Its called a ternary operator.

            return "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" + 
                "Player: " + name + "\n" +
                handString +
                "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; ;
        }

        /** Returns a String representation with this Player's name and hand. */
        public String ToStringFinal ()
        {
            var handString = hand.ToString ();
            // The ? : is a fancy way of saying if else. Its called a ternary operator.

            return "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" +
                "Player: " + name + "\n" +
                handString +
                "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; ;
        }

        /** Returns a String representation of this object. */
        public override String ToString ()
        {
            var handString = isDealer ? hand.ToString (true) : hand.ToString ();

            return "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" + 
                "Player: " + name + "\n" + 
                "numPoints: " + numPoints + "\n" + 
                "numWins: " + numWins + "\n\n" +
                handString +
                "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }

        //-----------------------------------------------------------------------------------------------------------------

        private String name;                        /** The Player's name. */

        private int numPoints,                      /** The number of points. */
            numWins;                                /** The total number of wins. */

        private bool isDealer,                      /** Represents if this player is the Dealer. */
            isHolding;                              /** Variable stores if the user is holding. */

        private Hand hand;                          /** The Player's Hand. */
    }
















    public class PlayerTests
    {
        public static void RunTests ()
        {
            Debug.Write ("\nTesting the Player class\n" + 
                          "*******************************************************************************\n\n" + 
                          "Creating player1 and printing ToString ()...\n\n");

            var player1 = new Player ("Player 1", 10, false);

            Debug.Write (player1.ToString () + "\n\n" + 
                "Attempting to take away more points than the user has...\n\n");

            player1.RemovePoints (100);

            Debug.Assert (player1.NumPoints == 10, "Error: The computer took away more points than player1 had!");

            var stock = new Deck ();
            stock.Shuffle ();

            Debug.Write ("Dealing hand and testing int Compare (Hand) function...\n\n");
            
            var player2 = new Player ("Player 2", 200000000, false);

            player1.Hand.AddCard (stock.DrawCard (10,3));
            player1.Hand.AddCard (stock.DrawCard (1,4));

            player2.Hand.AddCard (stock.DrawCard (10,3));
            player2.Hand.AddCard (stock.DrawCard (5,4));

            Debug.Write ("Comparing 10 plus ace to 10 plus 5\n");

            Debug.Assert (player1.Hand.Compare (player2.Hand) > 1, "Error ! player1 had 21!");

            player1.Hand.Clear ();
            player2.Hand.Clear ();

            player1.Hand.AddCard (stock.DrawCard (13,3));
            player1.Hand.AddCard (stock.DrawCard (7,4));

            player2.Hand.AddCard (stock.DrawCard (7,3));
            player2.Hand.AddCard (stock.DrawCard (4,4));

            Debug.Assert (player1.HandWins (player2), "Error ! player1 had a hiter point total!");


            Debug.Write ("\n\nDone testing the Player class.\n\n\n");
        }
    }
}