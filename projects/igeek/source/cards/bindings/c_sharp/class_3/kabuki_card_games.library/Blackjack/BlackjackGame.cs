/** kabuki::cards
    @file       ~/kabuki::cards Library/Blackjack/BlackjackGame.cs
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
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DojoCardGames.Blackjack
{
    /** A blackjack card game. */
    public class BlackjackGame : CardGame
    {
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        public const int DefaultAnte = 10;

        public static readonly int[] faceValues = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

        /** Constructor.
            The maximum number of players in Blackjack is set by the house. The more players there are, the greater the
            chance of the house loosing points, so the maximum number we are going to set is 13.
        */
        public BlackjackGame (int initNumPlayers = 2) :
            base ("Blackjack", initNumPlayers, 2, 13)
        {
            minAnte = DefaultAnte;
            if (initNumPlayers < MinNumPlayers)
                ante = initNumPlayers;      //< The ante per round.

            // Set the ante
            ante = minAnte < MinAnte ? MinAnte : minAnte;
            pointsInThePot = 0;         //< The points in the pot.
            RoundNumber = 1;            //< The current round number.

            Stock = new Deck (Deck.NoJokers, Card.French, 1, faceValues);
            NewRound ();                 //< Starts a new game.
        }

        public bool RaiseAnteBy10 ()
        {
            // You have to have enough points to play the game or else we have to exit.
            if (ante + 10 > player.NumPoints)
            {
                return false;
            }

            ante += 10;
            return true;
        }

        /** Returns the ante. */
        public int Ante
        {
            get { return ante; }
            set { ante = value < minAnte ? 1 : value; }
        }

        /** Returns the number of points in the pot. */
        public int PointsInThePot
        {
            get { return pointsInThePot; }
            set { pointsInThePot = value < 0 ? 0 : value; }
        }

        public override void Restart ()
        {
            base.Restart ();
            RoundNumber = 1;
        }

        public override void NewRound ()
        {
            ante = minAnte;
            pointsInThePot = 0;

            player = new BlackjackPlayer ("Dojo Jedi", 200);
            dealer = new BlackjackDealer ();

            pointsInThePot = NumPlayers * ante;

            player.RemovePoints (ante);
            dealer.RemovePoints (ante);

            Stock.RestockDeck ();

            player.DealHand (Stock);
            dealer.DealHand (Stock);
        }

        /** Returns the player.*/
        public BlackjackPlayer Player
        {
            get { return player; }
        }

        /** Returns the dealer. */
        public BlackjackDealer Dealer
        {
            get { return dealer; }
        }

        /** Processes the begining of round logic.
            Any player can hold, and sit out a round, but they still need to ante up to stay in the game.*/
        public override int BeginingOfRoundLogic ()
        {
            if (player.NumPoints < ante)
                return -1;
            if (dealer.NumPoints < ante)
                return -2;

            player.RemovePoints (ante);
            dealer.RemovePoints (ante);

            // Then put the points into the pot.
            pointsInThePot = NumPlayers * ante;

            return 0;
        }

        /** Processes the end of round logic. */
        public override int EndOfRoundLogic ()
        {
            // The fist part of every card game is to shuffle the Deck...
            Stock.Shuffle ();

            // ... and to deal a new hand.
            player.DealHand (Stock);
            dealer.DealHand (Stock);

            return 0;
        }

        /** Deals a round of cards to the players. */
        public override int DealRound ()
        {
            // The fist part of every card game is to shuffle the Deck...
            Stock.Shuffle ();

            // ... and to deal a new hand.
            player.DealHand (Stock);
            dealer.DealHand (Stock);

            return 0;
        }

        /** Returns the text string for the start of each round. */
        public override String GetRoundStatsString ()
        {
            return CardGame.ConsoleLine ('_') +
                "Ante: " + ante + ".\n" +
                "\nInitial Stats:\n" +
                player.GetRoundStatsString () + dealer.GetRoundStatsString () +
                "\n\nStarting round of Blackjack...\n\n";
        }
        
        /** Game loop for card game. */
        public override bool PlayGameInConsole()
        {
            Stock.RestockDeck ();       //< The Deck of cards.
            NewRound ();
            
            String input;                   //< temp variable for console text input.

            // You have to have enough points to play the game or else we have to exit.
            if (player.NumPoints < ante)
            {
                Console.Write("You lose!");
                return false;
            }

            if (dealer.NumPoints < ante)
            {
                Console.Write("You just wiped out the house!!!\n\n" +
                    "Your the ultimate Blackjack Champion!!!\n\n");
                return false;
            }

            Console.Write(GetRoundStatsString ());

            while (true)    // Game loop for a round of Blackjack. It loops until we return either true or false.
            {
                BeginingOfRoundLogic ();

                Console.Write("\n" + CardGame.ConsoleLine ('_') +
                    "\nRound " + RoundNumber + ":\n\n" +
                    dealer.GetRoundStatsString () + player.GetRoundStatsString() + "\n");

                // The players need to either hit or hold first.

                Console.Write("hit or hold?\n");

                bool inputValid = false;    //< Yould should always presume the data is false until provend correct.

                while (!inputValid)
                {
                    // Read a line from the terminal, and convert it to lower case letters.
                    input = Console.ReadLine().ToLower();

                    if (input == "hit")
                    {
                        player.HitMe(Stock);
                        Console.Write("\n" + player.ToString() + "\n\n");
                        inputValid = true;
                    }
                    else if (input == "hold")
                    {
                        inputValid = true;
                        player.IsHolding = true;
                    }
                    else if (input == "exit" || input == "quit")  //< Then exit the game loop.
                    {
                        Console.Write("Exiting the game...\n");
                        inputValid = true;
                        return false;
                    }
                    else
                    {
                        Console.Write("Please input 'hit' or 'hold'\n");
                    }
                }

                // Dealer goes last
                dealer.HitOrHold(Stock);

                // Now process the logic for if someone won the round.

                // The way we know that the round is over is when everyone is holding. 

                if (player.IsHolding && dealer.IsHolding)
                {
                    // Then everyone is holding so we need to process the end of round game logic.

                    if (dealer.HandWins(player)) //< If the dealer wins, it trumps all other players.
                    {
                        Console.Write("\n\nDealer wins ({:-()\n\n" +
                            dealer.ToString () + player.ToString () + "\n\n");
                        dealer.AddPoints(pointsInThePot);
                        dealer.AddWin();
                    }
                    else if (player.HandWins(dealer))
                    {
                        Console.Write("\n\nPlayers wins!!!\n\n" +
                            dealer.ToString () + player.ToString () + "\n\n");
                        player.AddPoints(pointsInThePot);
                        player.AddWin();
                    }

                    return true;    // Exits loop and plays another game of Blackjack..
                }

                /** The loop is almost over, so we need to check again if we can still play the next round. We  
                    checked when we first entered the the PlayBlackjackInConsole (Player, Player) function, so 
                    this is why we checked at the end of the loop as opposed to the beginning. */
                if (player.NumPoints < ante)
                {
                    Console.Write("You lose!");
                    return false;
                }

                if (dealer.NumPoints < ante)
                {
                    Console.Write("You just wiped out the house!!!\n\n" +
                        "Your the ultimate Blackjack Champion!!!\n\n");
                    return false;
                }

                RoundNumber++;
            }
        }

        //--------------------------------------------------------------------------------------------------------------

        private int minAnte,                //< The initial ante.
            ante,                           //< The current ante.
            pointsInThePot;                 //< The current number of points in the pot.

        private BlackjackDealer dealer;     //< The dealer
        private BlackjackPlayer player;     //< The player
    }






    public class BlackjackGameTests : UnitTest
    {
        public BlackjackGameTests ()
        {
            SetupTest ();
            RunTests ();
        }

        public override void SetupTest ()
        {
            // Nothing to do here.
        }
        public override void RunTests ()
        {
            UnitTest handTests = new BlackjackHandTests (),
                playerTests = new BlackjackPlayerTests (),
                dealerTests = new BlackjackHandTests ();
        }
    }
}