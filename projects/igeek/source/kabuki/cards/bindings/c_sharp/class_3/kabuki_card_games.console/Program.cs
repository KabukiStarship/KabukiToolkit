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

using System;
using System.Diagnostics;

namespace DojoCardGames
{
    using Blackjack;

    class Program
    {
        static void Main (string[] args)
        {
            Console.Write (CardGame.ConsoleLine('#') +
                "              Welcome to the kabuki::cards Console!\n\n" +
                CardGame.ConsoleLine ('#') + "\n");

            /** This is your first experience with a UnitTest. Its quiet simple actually. You test each object by 
                itself, and get each object working by itself in isolation. When you have gotten each object working, 
                then when we go to write the game, it will just work because you got the "business logic" right.
             */

            RunTests ();        //< This function runs the Unit Tests, which require no user input.
            RunInteractiveTest ();      //< This function runs the console blackjack game.

            Console.Write ("\n\nPress enter to exit...");
            Console.Read ();                                //< Wait for the user to press enter before exiting.
        }

        public static void RunTests()
        {
            Console.Write("\n\nRunning Unit Tests...\n\n");

            UnitTest cardTest  = new CardTests (),
                cardPileTest   = new CardPileTests (),
                DeckTest       = new DeckTests (),
                BlackjackTests = new BlackjackGameTests ();

            Console.Write("...Unit tests completed successfully :-)\n\n");
        }

        public static void RunInteractiveTest ()
        {
            Console.Write ("\n\nRunning Interactive Test Console...\n" + CardGame.ConsoleLine('~') + "\n");


            CardGame currentGame = new BlackjackGame();
            //DojoCardGame currentGame = new PokerGame();
            //DojoCardGame currentGame = new SpadesGame();
            //DojoCardGame currentGame = new HeartsGame();

            bool playAgain = true;

            Console.WriteLine ("Press enter to play " + currentGame.Name + "...");
            Console.Read ();        //< Function waits for the user to input a character.

            Debug.WriteLine ("\n\n" + CardGame.ConsoleLine('#') + "Starting a game of " + currentGame.Name);

            /** Play-again loop.
                A play-again loop goes in a loop where the user is asked if they want to play again. The user can
                enter "hit", "hold", "exit", or "quit". The code for the game */
            while (playAgain && currentGame.PlayGameInConsole ())    // Main game loop.
            {
                Console.WriteLine ("Do you want to play again?\n" +
                        "Type yes to continue, or no to quit.");

                bool inputValid = false;

                while (!inputValid)
                {
                    String input = Console.ReadLine ().ToLower ();

                    /* If the user wants to continue, they need to type the letter y, or else we need to exit the program 
                       loop. 
                        We need to convert the input to lower case letters just in case someone capitalizes any of the 
                        letters.
                    */
                    if (input == "yes")     //  Keep playing.
                    {
                        // playAgain is current true.
                        inputValid = true;
                    }
                    else if (input == "no") //< Then exit the play-again loop.
                    {
                        playAgain = false;
                        inputValid = true;
                    }
                    else
                    {
                        Console.Write ("\nPlease type yes to continue, or no to quit.\n");
                    }
                }
            }
        }
    }
}
