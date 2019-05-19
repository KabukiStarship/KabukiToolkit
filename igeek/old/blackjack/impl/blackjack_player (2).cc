/** Dojo Card Games
    @file       ~/Library/KabukiCardGames/Blackjack/Hand.cpp
    @author     Cale McCollough
    @copyright  © CoderDojo 2015 ®
    @license    This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "BlackjackPlayer.h"

#include "../Hand.h"
#include "../CardStack.h"

#include "BlackjackDealer.h"
#include "BlackjackHand.h"

using namespace KabukiCardGames::Blackjack;

BlackjackPlayer::BlackjackPlayer (String thisPlayerName, int startingPoints, bool playerOrDealer) :
    Player (thisPlayerName, startingPoints, playerOrDealer)
{
    // Nothing to do here!
}

BlackjackPlayer::~BlackjackPlayer ()
{
    // Nothing to do here.
}

bool BlackjackPlayer::playOrPass (Dealer& dealer)
{
    BlackjackHand::HighLowScore handTotals = getHighLowScore (),
        otherHandTotals = dealer.getHighLowScore ();

    int highScore = handTotals.high,
        lowScore = handTotals.low,
        otherHighScore = otherHandTotals.high,
        otherLowScore = otherHandTotals.low;

    if (lowScore > 21) //< Then we definitly lost.
        return false;

    if (lowScore == 21 || highScore == 21) //< Then we might have won so don't play again or we'll loose!
        return false;

    if (highScore <= 21 - 10)   //< The highest card value is 10, so if our highest score is less than 11, then we can take any card and not go over 21.
        return true;

    if (highScore < otherHighScore) // Than we have to play or we loose.
        return true;

    /** From here on out, we dont actually have to take another card because we might go over and loose, so we're playing a numbers game.
        At this point in time, we are less than 10 points away from going bust, and each number of points away from 21 we are has an 
        x percent chance loosing. In this case, we should figure out what the percent chance is,
        and only take another card if the chances are high enough. */
    float percentChanceOfWinning;

    if (highScore < 21)
    {
        int numPointsLeft = 21 - highScore;
        const float chanceOfWinning[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 };
        percentChanceOfWinning = chanceOfWinning[numPointsLeft];
    }
    else
    {
        int numPointsLeft = 21 - lowScore;
        const float chanceOfWinning[] = { 0.6, 0.6, 0.5, 0.5, 0.4, 0.4, 0.2, 0.2, 0.2 };
        percentChanceOfWinning = chanceOfWinning[numPointsLeft];
    }

    if (percentChanceOfWinning >= 0.5)
        return true;

    /* To do this, we're going to use a random number between 0 and 1, and multiply it by a number between 1-10 to get a percent.
        For example, a 50 % chance of winning would get the number 5, then if you multiplied that by a random number between 0 and 1, then
        we have a 50 % chance of getting a number greater than 0.5. */
    
    Random generator = Random ();
    float randomNumberBetween0and1 = generator.nextFloat ();            // We want to pick a random number between 0 and 1

    return percentChanceOfWinning * randomNumberBetween0and1 >= 0.5; // If the percent chance is greater than 50%, then we should take another card.
}
 
void BlackjackPlayer::playHand ()
{
    // Nothing to do here. ({:-)
}