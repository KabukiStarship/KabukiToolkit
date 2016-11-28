/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/Label.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright  (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved  (R).

        Licensed under the Apache License, Version 2.0  (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/
 
#pragma once

#include <KabukiSDK-Config.hpp>

namespace _Dev { namespace Controls {

/** An object that has a text label.
    This class _KabukiSDK has a primary label, and a short label.
    A Label has the following rules:
    1.) Labels must be 32 characters or less for a normal label, and 16 characters or less for a short label.
    2.) Labels must contain printable ASCII characters that are HUI compatible.
*/ 
class _KabukiSDK Label
{   
    public:

    enum {
        MaxLabelLength = 20,       //< The max label length of a label
        NonAlphaNumChars                       //< The number of non-alpha-numberic charactors allowed in a label.
    };

    static const char* AllowedSymbols,         //< The non-alpha-numberic charactors allowed in a label.
        UnnamedLabel;                           //< const char* that reads "Unnnamed".
    
    Label  (const char* newLabel = "");
    //< Default constructor.
    
    Label  (const Label& other);
    //< Copy contructor.
    
    virtual ~Label () {}
    //< Virtual destructor.

    const char* GetLabel () const;
    //< Gets th label.
    
    int SetLabel  (const char* newLabel);
    /*< Sets the label to the new label.
        @return Gets 0 upon success and 1 if the newLabel is too long.
        @see    Label::IsValid  (char). */
    virtual int SetLabel  (const Label& newLabel);
    /*< Sets the label to the new label.
        @return Gets 0 upon success and 1 if the newLabel is too long.
        @see    Label::IsValid  (char). */
        
    int Compare  (const char* other) const;
    /*< Compares this label to the other const char*.
        @return Gets  0 if they are identical and1 if the other string is too long. */
        
    int Compare  (const Label& other) const;
    /*< Compares this label to the other Label.
        @return Gets  0 if they are identical and1 if the other string  is too long. */
        
    const char* ToString () const;
    //< Gets a text represenation of this object.
 
    static int IsValid  (const char* label);
    /*< Verifies if thisLabel is a valid label.
        @return Gets 0 if the label is valid.
        @return Gets 1 if the label is too long.
        @return Gets -1 thisLabel is "".
    */

    private:

    const char* label;                               //< This object's text label.

};

#ifdef DEBUG
class _KabukiSDK LabelUnitTest : public UnitTest
{
    public:
    LabelUnitTest () : UnitTest ("Controls::Label Class.\n")
    {
    }

    void runTest ()
    {
        const char* invalidString = "Invalid label ~",
            validString1 = "Valid label 1",
            validString2 = "Valid label !@%^",
            validString3 = "Valid label &* ()";

        auto validLabel1 = Label  (validString1),
            validLabel2  = Label  (validString1),
            validLabel3  = Label  (validString3),
            invalidLabel = Label  (invalidString);

        beginTest ("Testing valid string input.");

        beginTest ("Testing int isValid  (const char* &)");
        LogMessage  (validString1 + ": " + const char*  (Label::IsValid  (validString1)));
        expect  (Label::IsValid  (validString1) == Valid);
        beginTest ("Testing invalid string input.");
        expect  (Label::IsValid  (invalidString) != Valid);
        expect  (Label::IsValid ("") != 0);
        expect  (Label::IsValid ("123456789012345678901") != 0);

        beginTest ("Testing int compare  (const char* &)\n" + invalidLabel.ToString ());
        LogMessage ("Testing valid comparisons...");
        expect (!validLabel1.Compare  (validString1));
        LogMessage ("Testing invalid comparisons...");
        expect  (validLabel1.Compare  (validString2) != Comperable);
        expect  (validLabel2.Compare  (validString3) != Comperable);

        beginTest ("Attempting to setLabel to the invalidString");
        //auto expectedLabel = "Test string 1";
        validLabel1.SetLabel  (invalidString);
        expect (!validLabel1.Compare  (invalidLabel));
        beginTest ("Setting the label to validString3");
        validLabel1.SetLabel  (validString3);
        expect  (validLabel1.GetLabel () == validString3);

        LogMessage ("Done testing Controls::Label class _KabukiSDK.");
    }
};
static LabelUnitTest testUnit_Label;

#endif // DEBUG
}   //< namespace Controls
}   //< namespace _Dev

