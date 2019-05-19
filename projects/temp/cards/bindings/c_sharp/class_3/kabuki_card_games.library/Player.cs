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

    public abstract class Player
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        public readonly int MaxNameLength = 20;     //< The max length of a player's name;
        
        /** Constructor.
        */
        public Player(String thisPlayerName, int startingPoints, bool playerIsDealer)
        {
            name = thisPlayerName;
            numWins = 0;
            numPoints = startingPoints < 1 ? 1 : startingPoints;
            isDealer = playerIsDealer;
        }

        /** Getter and setter for the player's name. */
        public String Name
        {
            get { return name; }
            set { name = value; }
        }

        /** Sets the playerName to the newName. */
        public virtual bool SetName (String newName)
        {
            if (newName.Length > MaxNameLength)
                return false;

            name = newName;
            return true;
        }

        /** Getter and setter for the player's hand. */
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
        public int NumWins
        {
            get { return numWins; }
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

        /** Function returns if this is the dealer or not */
        public bool IsDealer { get; }

        /** Functions sets this player as the dealer.
            In games, we will porbably want to do some logic when someone is selected as the dealer so we need
            a virtual function. */
        public virtual void SetDealer ()
        {
            isDealer = true;
        }

        /** Deals a hant worth of card from the stock.
            @return Returns true if the Deck had enough cards, and false if it didn't. */
        public abstract int DealHand (Deck stock);

        /** Returns the string when in the middle of a round. */
        public virtual String GetRoundStatsString () 
        {
            return ToString ();
        }

        /** Returns a String with this player's numPoints and numWins. */
        public override String ToString ()
        {
            return CardGame.ConsoleLine ('_') +
                "Player: " + name + 
                "\nPoints: " + numPoints + " Wins: " + numWins +
                "\n" + hand.ToString ();
        }

        //--------------------------------------------------------------------------------------------------------------

        private String name;                        //< The Player's name.

        private int numPoints,                      //< The number of points.
            numWins;                                //< The total number of wins.

        private bool isDealer,                      //< Flag for if this player is the dealer.
            isPlaying;                              //< Flag for if this player is playing or not.

        private Hand hand;                        //< The Player's Hand.
    }
}
