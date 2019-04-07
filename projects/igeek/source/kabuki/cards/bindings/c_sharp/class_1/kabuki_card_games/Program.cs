/** kabuki::cards
    @file       ~/kabuki::cards Console/Program.cs
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

    class Program
    {
        static void Main (string[] args)
        {
            Console.Write ("###############################################################################\n\n" +
                "              Welcome to the kabuki::cards Console!\n\n" +
                "###############################################################################\n\n");

            /** This is your first experience with a UnitTest. Its quiet simple actually. You test each object by 
                itself, and get each object working by itself in isolation. When you have gotten each object working, 
                then when we go to write the game, it will just work because you got the "business logic" right.
             */

            RunUnitTests ();        //< This function runs the Unit Tests, which require no user input.
            RunInteractiveTest ();      //< This function runs the console blackjack game.
        }

        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        public static void RunUnitTests ()
        {
            Console.Write ("\n\nRunning Unit Tests...\n\n");

            CardTests.RunTests ();
            DeckTests.RunTests ();
            HandTests.RunTests ();
            PlayerTests.RunTests ();

            Console.Write ("...Unit tests completed successfully :-)\n\n");
        }

        public static void RunInteractiveTest ()
        {
            Console.Write ("\n\nRunning Interactive Test Console...\n" +
                "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

            int playerStartingPoints = 100,
                dealerStartingPoints = 2 * (int)Math.Pow (10, 9);

            // The default constructor initialises as aR player with 10 points so there is no need to write it here.
            Player player = new Player ("Dojo Jedi", playerStartingPoints, false),
                dealer = new Player ("Dealer", dealerStartingPoints, true);

            bool playAgain = true;

            Console.Write ("Press enter to play blackjack...\n");
            Console.Read ();        //< Function waits for the user to pres enter.

            while (playAgain && PlayGameInConsole (player, dealer))    // Main game loop.
            {

                Console.Write ("\nDo you want to play again?\n" +
                        "\nType yes to continue, or no to quit.\n");

                bool inputValid = false;

                while (!inputValid)
                {
                    String input = Console.ReadLine ().ToLower ();
                    /** This gets gets a string from the console and converts it to lower case.
                        If you wanted to convert the input to a number, you would write 
                        int input = Convert.ToInt32(Console.Readline()). */

                    /* If the user wants to continue, they need to type the letter y, or else we need to exit the program 
                       loop. 
                        We need to convert the input to lower case letters just in case someone capitalizes any of the 
                        letters.
                    */
                    if (input == "yes")
                    {
                        inputValid = true;
                    }
                    else if (input == "no")  //< Then exit the game loop.
                    {
                        playAgain = false;
                        inputValid = true;
                    }
                    else
                    {
                        inputValid = false;
                    }
                }
            }

            Console.Write ("\n\nPress enter to exit...");
            // Now wait for the user to press enter.
            Console.Read ();
        }

        /** Returns the face values for cards in the game Blackjack. */
        public static int[] GetBlackjackFaceValues ()
        {
            int[] faceValues = new int[Card.NumPips];
            for (int i = 0; i < Card.NumPips; i++)
                if (i < 10)
                    faceValues[i] = i;
                else
                    faceValues[i] = 10;

            return faceValues;
        }


        static bool PlayGameInConsole (Player player, Player dealer)
        {
            int numberOfPlayers = 2,        //< The number of players in the game.
                ante = 10,                  //< The ante per round.
                pointsInThePot = 0,         //< The points in the pot.
                roundNumber = 1;            //< The current round number.

            String input;                   //< temp variable for console text input.

            Deck stock = new Deck (Deck.NoJokers, SuitType, 1, GetBlackjackFaceValues ());
            //< Remember to also make a new object before you try to use it or you'll get a null pointer reference bug.

            // You have to have enough points to play the game or else we have to exit.
            if (player.NumPoints < ante)
            {
                Console.Write ("You lose!");
                return false;
            }

            if (dealer.NumPoints < ante)
            {
                Console.Write ("You just wiped out the house!!!\n\n" +
                    "Your the ultimate Blackjack Champion!!!\n\n");
                return false;
            }

            Console.Write ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" +
                "Starting new game and the ante is " + ante + " points.\n\n" + 
                "Initial Stats:\n" +
                player.PointsAndWinsToString () + dealer.PointsAndWinsToString () +
                "\n\nStarting game of Blackjack...\n\n");

            // The fist part of every card game is to shuffle the stock... 

            stock.Shuffle ();

            // ... and to deal a new hand.
            player.DealHand (stock);
            dealer.DealHand (stock);

            while (true)    // Game loop for a round of Blackjack. It loops until we return either true or false.
            {
                // Any player can hold, and sit out a round, but they still need to ante up to stay in the game.

                player.RemovePoints (ante);
                dealer.RemovePoints (ante);

                // Then put the points into the pot.
                pointsInThePot = numberOfPlayers * ante;

                Console.Write ("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" +
                    "Round " + roundNumber + ":\n\n" +
                    player.PointsAndWinsToString () + dealer.PointsAndWinsToString () + "\n");

                Console.Write (player.ToStringBrief ());
                Console.Write (dealer.ToStringBrief () + "\n");

                // The players need to either hit or hold first.

                Console.Write ("hit or hold?\n");

                bool inputValid = false;    //< Yould should always presume the data is false until provend correct.

                while (!inputValid)
                {
                    // Read a line from the terminal, and convert it to lower case letters.
                    input = Console.ReadLine ().ToLower ();

                    if (input == "hit")
                    {
                        player.HitMe (stock);
                        inputValid = true;
                    }
                    else if (input == "hold")
                    {
                        inputValid = true;
                        player.IsHolding = true;
                    }
                    else if (input == "exit" || input == "quit")  //< Then exit the game loop.
                    {
                        Console.Write ("Exiting the game...\n");
                        inputValid = true;
                        return false;
                    }
                    else
                    {
                        Console.Write ("Please input 'hit' or 'hold'\n");
                    }
                }

                // Dealer goes last
                dealer.HitOrHold (stock);

                // Now process the logic for if someone won the round.

                // The way we know that the round is over is when everyone is holding. 

                if (player.IsHolding && dealer.IsHolding) // Then everyone is holding so we need to process the end of round game logic.
                {
                    // If the dealer wins, it trumps all other players.
                    if (dealer.HandWins (player))
                    {
                        Console.Write ("\n\nDealer wins ({:-()\n\n" +
                            dealer.ToStringFinal () + player.ToStringFinal () + "\n\n");
                        dealer.AddPoints (pointsInThePot);
                        dealer.AddWin ();
                    }
                    else if (player.HandWins (dealer))
                    {
                        Console.Write ("\n\nPlayers wins!!!\n\n" +
                            dealer.ToStringFinal () + player.ToStringFinal () + "\n\n");
                        player.AddPoints (pointsInThePot);
                        player.AddWin ();
                    }

                    return true;    // Exits loop and plays another game of Blackjack..
                }

                /** The loop is almost over, so we need to check again if we can still play the next round. We checked 
                    when we first entered the the PlayGameInConsole (Player, Player) function, so this is why we 
                    checked at the end of the loop as opposed to the beginning. */
                if (player.NumPoints < ante)
                {
                    Console.Write ("You lose!");
                    return false;
                }

                if (dealer.NumPoints < ante)
                {
                    Console.Write ("You just wiped out the house!!!\n\n" +
                        "Your the ultimate Blackjack Champion!!!\n\n");
                    return false;
                }

                roundNumber++;
            }
        }

        //--------------------------------------------------------------------------------------------------------------

        private const int SuitType = Card.French;
    }
}
