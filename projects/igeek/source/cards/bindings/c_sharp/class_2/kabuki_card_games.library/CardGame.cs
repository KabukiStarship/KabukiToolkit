/** kabuki::cards
    @file       ~/kabuki::cards Library/Blackjack/DojoCardGame.cs
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
using System.Collections.Generic;

namespace DojoCardGames
{
    public abstract class CardGame
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        public const int MinAnte = 1,               //< The minimum ante.
            DefaultConsoleWidth = 80;               //< The number of rows in a DOS console.

        /** Default constructor. */
        public CardGame (String gameName, int newNumPlayers = 1, int newMinNumPlayers = 1, int newMaxNumPlayers = 1)
        {
            name = (gameName == null) ? "Unnamed Game" : gameName;

            if (newNumPlayers < 1)
                newNumPlayers = 1;

            if (newMinNumPlayers < 1)
                newMinNumPlayers = 1;

            if (newMaxNumPlayers < 1)
                newMaxNumPlayers = 1;

            if (newMinNumPlayers > newMaxNumPlayers)
                newMinNumPlayers = newMaxNumPlayers;

            if (newNumPlayers < newMinNumPlayers)
                newNumPlayers = newMinNumPlayers;
            else if (newNumPlayers > newMaxNumPlayers)
                newNumPlayers = newMaxNumPlayers;

            // By process of elimination we know know that numPlayers is bounded safly between the min and max values.

            numPlayers = newNumPlayers;
            minNumPlayers = newMinNumPlayers;
            maxNumPlayers = newMaxNumPlayers;
        }

        /** Returns the name of the game. */
        public String Name
        {
            get  {  return name; }
        }

        /** Getter and settor for the stock (Deck) of cards. */
        public Deck Stock
        {
            get { return stock; }
            set { stock = value; }
        }

        /** The minimum number of players.
            The round number can not be less than 1. */
        public int RoundNumber
        {
            get
            {
                return roundNumber;
            }
            set
            {
                if (value < 1)
                    roundNumber = 1;
                else
                    roundNumber = value;
            }
        }

        /** The the number of players.
            minNumPlayers must be between the min and max number of players. */
        public int NumPlayers
        {
            get { return numPlayers; }
        }

        /** Sets the min number of players to the new value.
            @return Returns 0 upon success.
            @return Returns 1 if the value is greather the number of players
            @return Returns -1 if the new value is less greater than the max value. */
        public virtual int SetNumPlayers (int value)
        {
            if (value < minNumPlayers)
                return -1;
            if (value > maxNumPlayers)
                return 1;

            minNumPlayers = value;
            return 0;
        }

        /** The minimum number of players.
            minNumPlayers can not be greater than maxNumPlayers. */
        public int MinNumPlayers
        {
            get { return minNumPlayers; }
        }

        /** Sets the min number of players to the new value.
            @return Returns 0 upon success and -1 if the new value is less greater than or equal the max value. */
        public int SetMinPlayers (int value)
        {
            if (value >= maxNumPlayers)
                return -1;

            minNumPlayers = value;
            return 0;
        }

        /** The maximum number of players. */
        public int MaxNumPlayers
        {
            get { return maxNumPlayers; }
        }

        /** Sets the max number of players to the new value.
            @return Returns 0 upon success and -1 if the new value is less than the min value. */
        public int SetMaxPlayers (int value)
        {
            if (value < minNumPlayers)
                return -1;

            maxNumPlayers = value;
            return 0;
        }

        /** Restart the game to a new state with a preset number of players. */
        public virtual void Restart ()
        {
            roundNumber = 1;
            NewRound ();
        }
        
        /** Starts a new game. */
        public abstract void NewRound ();

        /** Game loop for card game. */
        public abstract bool PlayGameInConsole();

        /** Processes the begining of round logic. */
        public abstract int BeginingOfRoundLogic ();

        /** Processes the end of round logic. */
        public abstract int EndOfRoundLogic ();

        /** Deals a new round of cards. */
        public abstract int DealRound ();

        /** Gets the console width in chars. */
        public static int ConsoleWidth
        {
            get { return consoleWidth; }
            set { consoleWidth = value < 1 ? 1 : value; }
        }

        /** Returns an full console line of the token character. */
        public static String ConsoleLine (char token)
        {
            String returnString = "";

            for (int row = 0; row < ConsoleWidth; row++)
                returnString += token;
            return returnString + '\n';
        }

        /** Returns an repeated line of the token character. */
        public static String CharLine (char token, int repeat)
        {
            String returnString = "";
            if (repeat < 1)
                return returnString;

            for (int row = 0; row < repeat; row++)
                returnString += token;

            return returnString + '\n';
        }

        /** Returns the text string for the start of each round. */
        public virtual String GetRoundStatsString ()
        {
            String returnString = ConsoleLine ('~') + 
                "Round: " + roundNumber + "\n";

            foreach (Player player in players)
                returnString += player.ToString ();

            return returnString + ConsoleLine ('~');
        }

        public override String ToString ()
        {
            String returnString = ConsoleLine ('_') +
                "Card Game: " + name + "\n" +
                "Num Players:" + numPlayers + ", Min: " + minNumPlayers + ", Max: " + maxNumPlayers + "\n" +
                "Round Number: " + roundNumber + "\n" +
                "Num Players: " + players.Count + "\n";

            foreach (Player player in players)
                returnString += player.ToString ();
            
            return returnString + ConsoleLine ('_');
        }

        //--------------------------------------------------------------------------------------------------------------

        // The number of rows in the console.
        private static int consoleWidth = DefaultConsoleWidth;

        private String name;            //< The name of this game.

        private int numPlayers,         //< The number of players.
            minNumPlayers,              //< The minimum number of players.
            maxNumPlayers,              //< The maximum number of players.
            roundNumber,                //< The current round number.
            suitType;                   //< The suit type of the playing cards.

        private Deck stock;             /*< The stock of cards.
                                            A Deck is a full Deck of cards, and a stock is whats left of the Deck. */
        List<Player> players;           //< The list of players.
    }
}
