/** Kabuki Card Games
    @file    ~/source/kabuki/cards/include/card.h
    @author  Cale McCollough <http://calemccollough.github.io>
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

#ifndef KABUKI_CARDS_CARD_H
#define KABUKI_CARDS_CARD_H

#include <KabukiTheater.h>

namespace kabuki { namespace cards {

/** Class that represents a card in a card game.
    Cards as we know them originated in Europe. We traditionally think of cards as only being clubs, hearts, diamonds, and spades, but there are also
    some other variations from other European countries. For more information on them, please Wiki "Playing Card Suits". The nifty thing about these extra
    card decks, is that we can make a double deck of cards, and use the suit culture to tell the decks apart.
*/
class Card {
    public:

    /** An enumberated list of the different suites on playing cards in various countries. */
    enum class Suites { 
        club = 1, acorn = 1, coin = 1, black = 1, 
        diamond = 2, rose = 2, cup = 2, red = 2, 
        heart = 3, bell = 3, 
        spade = 4, lief = 4, shield = 4, sword = 4 
    } Suit;

    /** An enumberated list of the different French playing cards suites. */
    enum class FrenchSuits { 
        club = 1, 
        diamond, 
        heart, 
        spade
    } FrenchSuit;

    /** A list of the strings "Clubs", "Diamonds", "Hearts", "Spades" */
    static const string frenchSuit[4];

    /** An enumberated list of the different German playing cards suites. */
    enum class GermanSuits 
    { 
        acorn = 1, 
        bell, 
        heart, 
        lief 
    } GermanSuit;

    /** A list of the strings "Acorns", "Bells", "Hearts", "Lieves" */
    static const string germanSuit[4];

    /** An enumberated list of the different German playing cards suites. */
    enum class SwissGermanSuits
    { 
        acorn = 1, 
        bell, 
        rose, 
        shield 
    } SwissGermanSuit;

    /** A list of the strings "Acorns", "Bells", "Roses", "Shields" */
    static const string swissGermanSuit[4];

    /** An enumberated list of the different Latin playing cards suites. */
    enum class LatinSuits
    { 
        club = 1, 
        coin, cup, 
        sword } LatinSuit;

    /** A list of the strings "Clubs", "Coins", "Cups", "Swords" */
    static const string latinSuit[4];

    /** An enumerated list of different European-style playing card suites.
    Piacentine, Napoletane, Spagnole, Bergamasche suits are also known as Latin suites, because they are from countries that speak Romantic languages. */
    typedef enum SuitCulture
    { 
        french = 1, 
        german, 
        swissGerman, 
        piacentine, 
        napoletane, 
        spagnole, 
        bergamasche 
    };

    /** An array of strings that represnet the 7 different directories for the suit icon file */
    static const string suitCulturestrings[];

    /** Default constructor.
        This constructor creates a simple card with no image. The faceValue will equal the pointValue.

        Setting Default Values:
        When you put the = in the constructor, it sets the default value. This this case, we can make a card lke this: Card newCard = Card ();
        This constructor creates a Black Joker card.
    */
    Card (int thisPipValue = 0, Suit thisSuit = Suit::black);
    
    /** Verbose constructor. */
    Card (int thisPipValue, Suit thisSuit, int thisFaceValue, int thisPointValue, int thisSuitValue, 
        SuitCulture thisCulture, string& imageDirectory);
    
    /** Copy constructor. */
    Card (const Card& other);
    
    /** Virtual destructor just incase we want to make a sub-class later.
    virtual ~Card () {}

    /** Operator= overlaoder deeps copies the other Card. */
    Card& operator= (const Card& other);

    /** Compares this Card to the other Card.
        @return Returns 0 if they are identical.
        @return Returns 1 if this Card is greater than the other Card. */
    virtual int Compare (const Card& other);
                                          
    /** Compares this Card to the other Card and returns true if the two are identical. */     
    bool Equals (const Card& other);

    /** Returns the pip value of this Card.
        The pip value is a number between 0-13 that represents which card it is: J=0, A=1, 2-10, J=11, Q=12, K=13. */
    int GetPipValue ();
                           
    /** Returns the face value of this Card
         The face value represents the rank of the card. */                         
    int GetFaceValue ();
    
    /** Returns the point value of this Card
        The face value represetns how many points this card is worth. */
    int getPointValue ();
                                     
    /** Sets the point value to the value. */          
    void setPointValue (int value);
    
    /** Returns the face value of this Card
        The face value represetns how many points this card is worth. */
    int getSuitValue ();

    /** Returns the Suit of this card. */
    Suit GetSuit ();

    /** Returns the Card::Culture of this Deck.
        Function sets the suitCulture to the newCardCulture. */
    SuitCulture getSuitCulture ();
        
    void SetSuitCulture (SuitCulture newCardCulture);

    /** Returns the suitstring. */
    string& getSuitstring ();

    /** Loads and sets the cardImage to the on in the given directory. */
        @return Returns 0 upon succes.
        @return Returns -1 if the directory was actually a file.
        @return Returns 1 if the directory doesn't exist.
        @return Returns 2 if the file doesn't.
        @return Retruns 3 if the image didn't load right. */
    int SetCardImage (string& directory);
                       
    /** Returns the address of this Card's image. */                            
    Image& GetImage ();
    
    /** Returns a string representation of this Object. */
    void Print (_::Log& log);

private:
    
    //< Sets the values of the cards.
    void SetVCard (int pip_value, int face_value, int point_value, int suit_value, SuitCulture suit_culture, string& image_directory);

    Image LoadCardImage (string& directory);    //< Loads the cardImage from the specified directory.

    int pipValue_,              //< The value of this Card from 0-13.
        faceValue_,             //< The face value of this Card from 1-14.
        pointValue_,            //< The number of points this Card is worth from 0-10.
        suitValue_;             /*< The value of this suit.
                                    Used for changing which suit is worth more. */
    Suit suit_;                 //< The suit of this Card.
    SuitCulture suit_culture_;  //< The culture of this Card.
    string& suit_string_;       //< A string that stores the suit.
    Image card_image_;          //< The Image of this Card.
};

}   //< cards
}   //< kabuki

#endif  //< KABUKI_CARDS_CARD_H
