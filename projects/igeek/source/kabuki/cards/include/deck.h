/** Kabuki Card Games
    @file    ~/source/kabuki/cards/include/deck.h
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

#ifndef KABUKI_CARDS_DECK_H
#define KABUKI_CARDS_DECK_H

#include "Card.h"

namespace kabuki { namespace cards {
    
/** Class that reprents a Deck of Cards.
    A Deck of cards usually has 52 cards, but can also have 2 jokers, a black one, and a red one. Not all card games have this many cards, so
    this class is setup for you to create decks of cards for just about any card game you can think of.
*/
class Deck {
    public:

    enum { kDefaultNumCards        = 52,    //< The default number of playing cards in a deck excluding Jokers.
        kDefaultNumCardsWithJokers = 54,    //< The default number of playing cards in a deck including Jokers.
        kAcesHigh                  = 14,    //< Flag represents if Aces are high (i.e. has a face value of 14).
        kAcesLow                   = 0,     //< Flag represents if Aces are low (i.e. has a face value of 1).
        kAcesHighOrLow             = 1,     //< Flag represents if Aces can be either high or low (i.e. has a point value of 1 or 14).
    };
    static const int kDefaultSuitValues[4]; //< The default suit value order, Clubs=1, Diamonds=2, Hearts=3, and Spades=4.

    static const bool kHasJokers = true,    //< Flag for if this deck contains Jokers.
                      kHasNoJokers = false; //<- Flag for if this deck doesn't contains Jokers.

    static const Deck kStandard,            //< A standard deck of playing cards without Jokers.
                      kStandardWithJokers;  //< A standard deck of playing cards with Jokers.

    /** The default deck art directory. */
    static const char kDefaultDeckArtDirectory[] = "./";
    
    /** The default rear deck image. */
    static const char default_rear_deck_image[] = "card.png";
    
    /** Constructor.
        In most card games, jokers are no used, and aces are high, so we use those are the default values.
        @param  deckContainsJokers True if the deck continas jokers, and false otherwise.
        @param  acesAreHigh 0 means that aces are low,
                    a positive number means that aces are high,
                    a negative number means that aces are low.
        @param  thisCardSuitCulture This paramter is used to determine what suites we are using.
    */
    Deck (bool deckContainsJokers = hasNoJokers, int acesAreHigh = acesHigh,  
        Card::SuitCulture thisCardSuitCulture = Card::french, 
        string& rearDeckImageFilename = string (defaultRearDeckImage), 
        const string& deckArtDirectory = defaultDeckArtDirectory);
        
    /** Destructor. */
    virtual ~Deck () {}

    /** Operator= overlaoder deep copies the state of the other object. */
    Deck& operator= (const Deck& other);
    
    /** Function sets the suit values to the new values.
        @pre    valueN must be between 1-4.
        @return Returns 0 upon success, and a number 1-4 if the valueN is not between 1-4. The number will be negative if the inputed number was, and vice-versa. */
    int SetSuitValues (int value1, int value2, int value3, int value4);
    
    /** Gets the suit value of the given suit.
        @pre    suit must be between 1-4.
        @return Returns a number between 1-4 upon sucess, and -1 if the index was out of bounds. */
    int GetSuitValue (int suit);
    
    /** Returns true if this deck has Jokers. */
    bool DeckHasJokers ();

    /** Returns the number of cards in the deck. */
    int GetNumCards ();
    
    /** Returns the if aces are high or low. */
    int GetAcesHigh ();
    
    /** Returns a pointer to the Card at the spcified index.
        @return Returns nullptr if the index is out of bounds. */
    Card* GetCard (int index);

    /** Sets the frontImage to a new Image from thisFile.
        @pre    thisFile must be a valid existing Image file.
        @return returns -1 if thisFile is not a valid Image. */
    int SetRearImage (const File& thisFile);
        
    /** Loads the art from the deckArtFolder.
        @pre    deckArtFolder must contain all 54 card Images in [1-13]-[1-4].svg/J-1.svg/J-2.svg format format.
        @return Returns 0 upon success, 54 if the directory doesn't contain 54 .svg files, and -x if images are not named correctly, where x is the first failed filename. */
    int SetDeckArt (string& deckArtFolder);
        
    /** Returns a string representation of the suit. */
    string GetSuitstring (Card::Suit suit);
    
    /** Returns a string representation of this Object. */
    void Print (_::Log& log);

private:

    /** Function initializes the deck with a traditional set of playing cards. */
    void Initialise (string& rearDeckImageFilename, const string& deckArtDirectory);

    /** Function that checks the artFolder to see if the it has 54 Images in [1-13]-[1-4].svg/J-1.svg/J-2.svg format. */
    int CheckDeckArtFolder (string& deckArtFolder);

    bool          has_jokers_;          //< Variable represents if this deck has Jokers.
    Card::Culture culture_;             //< The culture of the suits.
    int           acesHigh_,            /*< Variable represeents if this deck is aces high, low, or eighter.
                                            Aces high (acesHigh > 0) means that an ace is worth 14 points. Aces low (acesHigh == 0) means that it is worth 1.
                                            In some games, like blackjack, aces can be either high or low (acesHigh < 0), meaning that they can be worth either a 1, or a 14. */
                  num_cards_,           //< The number of cards in the deck.
                  lowest_card_value_,   //< The lowest allowed card value.
                  highest_card_value_,  //< The highest allowed card value.
                  suit_values_[4];      /*< An array of 4 numbers that represent the values of each suit.
                                            Used for changing the order of the suits */
    Image         rear_image_;          //< The rear Image of the Deck.
    Array<Card>   deck_;                //< The deck of Card objects.
};

}       //< namespace cards
}       //< namespace kabuki
#endif  //< KABUKI_CARDS_DECK_H
