/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/AVControl.hpp
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

#include <FreeI2P.hpp>
#include <KabukiSDK-Config.hpp>
#include "Label.hpp"
#include "Event.hpp"

namespace _UI { namespace Controls {

class _KabukiSDK AVControl, public Label, public Event
/** An audio-visual control.
    
*/
{
    public:

    /** A list of the different types of Control  (s). */
    enum Types { DMXControl = 0, MIDIControl, OSCControl, DMXButton, MIDIButton, OSCButton, MacroButton } ;

    static const char* MacroHeader;        //< const char* for printing multiple AVControls with other opclasses.
    static const int MacroHeaderLength;     //< The length of the MacroHeader

    AVControl  (int newType, const char* &newLabel = "", int newChannel = 0, int initValue = 0, int newMinValue = 0,
        int newMaxValue = 1, int newWordSize = 1);
    /*< Default constructor. */

    AVControl  (const AVControl& other);
    /*< Copy contructor. */

    virtual ~AVControl () {}
    /*< Virtual destructor. */

    int GetType () const;
    /*< Gets what type of control this is. */

    const char* GetTypeString () const;
    /*< Gets a const char* that says what type of AVControl this is. */

    int GetChannel () const;
    /*< Gets th output channel of this control. */

    int GetNumChannels () const;
    /*< Gets th number of channels. */

    int GetWordSize () const;
    /*< Gets th number of bits of in a control word. */

    int GetMinWordSize () const;
    /*< Gets th minimum word size. */

    int GetMinWordValue () const;
    /*< Gets th minimum integer value of a word. */

    int GetMaxWordSize () const;
    /*< Gets th maximum word size. */

    int GetMaxWordValue () const;
    /*< Gets th maximum integer value of a word. */

    int GetValue () const;
    /*< Gets th current value of this control. */

    int GetLSBValue () const;
    /*< Gets th LSB of this value. */

    int GetMSBValue () const;
    /*< Gets th MSB of this value. */

    int GetInitValue () const;
    /*< Gets th default MIDI value of this control. */

    int GetMinValue () const;
    /*< Gets th min value of this control. */

    int GetMaxValue () const;
    /*< Gets th max value of this control. */
    
    void SetLSBValue  (int value);
    /*< Sets the LSB value to the value. */

    void SetMSBValue  (int value);
    /*< Sets the MSB value to the value. */

    void SetChannel  (int value);
    /*< Sets the output channel to value. */

    void SetWordSize  (int value);
    /*< Sets the control word size to the new value. */

    void SetValue  (int value);
    /*< Sets this control's value of the parameter to the value. */

    void SetInitValue  (int value);
    /*< Sets the initial value of a new control to the value. */

    virtual void SetMinMaxValues  (int newMin, int newMax);
    /*< Sets the min and max values.
    @pre    The word size must be set before calling this function! */

    virtual void SetMinValue  (int value);
    /*< Sets the min value to the value. */

    virtual void SetMaxValue  (int value);
    /*< Sets the max value to the value. */

    virtual void Trigger () {}
    /*< Triggers the Control to fire. */

    virtual void Toggle ();
    /*< Toggles between the min and the max values. */

    virtual int Compare  (const AVControl& other) const;
    /*< Compares this Control to the other.
    @return Gets 0 if both Controls are the same.
    @return Gets 1 if the controls are not identical. */

    virtual const char* GetHeaderString () const;
    /*< Gets th header for toStringRow (). */

    virtual const char* ToStringRow () const;
    /*< Gets a column of the values without the labels. */

    virtual const char* ToString () const;
    /*< Gets a text represenation of this Conrol. */

    private:
    
    int type,                                      //< The type of Control. @see Types
        channel,                                   //< The output channel.
        numChannels,                               //< The number of channels.
        wordSize,                                  //< The word-size of a parameter value in bits.
        wordValue,                                 //< The maximum value of a word-sized parameter.
        minWordSize,                               //< The min size of a control word.
        maxWordSize,                               //< The max size of a control word.
        minWordValue,                              //< The min value of a parameter.
        maxWordValue,                              //< The max value of a parameter.
        value,                                     //< The parameter value.
        initValue,                                 //< The initial value.
        minValue,                                  //< The min value.
        maxValue;                                  //< The max value.

    void SetType  (int value);
    //< Sets the type to the new value. */
};
}   //< namespace Controls
}   //< namespace _Dev

