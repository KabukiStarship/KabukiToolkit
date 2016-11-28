/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_UI/MacroButton.hpp
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
#include "ButtonControl.hpp"
#include "AVControl.hpp"
#include "DMXControl.hpp"
#include "MIDIControl.hpp"
#include "DMXButton.hpp"
#include "MIDIButton.hpp"

namespace _Dev { namespace Controls {

/*  An Event that can trigger multiple events.
    Controls are stored as pointers in a linear linked list to optimize for speed.
*/
class _KabukiSDK MacroButton : public AVControl, public ButtonControl
{
    public:

    /** Default constructor creates a MacroButton with no controls. 
        A MacroButton without any controls triggers system functions only.*/
    MacroButton  (const char* newName = ""); 
    //MacroButton  (const MacroButton& other);
    //< Copy constructor.
    
    ~MacroButton ();
    //< Destructor.

    int GetNumControls () const;
    //< Gets th number of controls.

    void ClearControls ();
    //< Clears all of the controls from the list.

    int Add  (AVControl* newEvent);
    /*< Adds an Event to the event list.
        @return Gets Success upon success.
        @return Gets -1 if the newEvent is null. */
        
    int Add  (std::vector<AVControl*> newEvents);
    //< Adds an array of newEvents to the list.
    
    int Set  (int index, AVControl* newEvent);
    //< Sets the Event at the given index to the newEvent.

    AVControl* Remove ();
    //< Removes the first removes in the list.
    
    AVControl* Remove  (int index);
    /*< Removes the oldEvent from the list.
        @return Gets nullptr if the index was out of 
            bounds. */
        
    AVControl* Remove  (AVControl* oldEvent);
    /*< Removes the oldEvent from the list.
        @return Gets nullptr if the oldEvent was null or if 
            it not in the list. */

    AVControl* GetControl  (int index);
    /*< Gets th event at the given index.
        @return Gets nullptr if the index is invalid. */
        
    AVControl* GetFirstControl ();
    /*< Gets th first event in the list.
        @return Gets nullptr if list is empty. */

    int maxWordValue () const override;
    //< Gets th max value of a AVControl word.

    const char* label () const override;
    //< Gets th label.
    int setLabel  (const char* newLabel) override;
    /*< Sets the label to the new label.
        @return Gets 0 upon success and 1 if the newLabel is
        too long.
        @see    Label::IsValid  (char). */
    
    void toggle () override;
    //< Toggles the state of the ButtonControl if type is latching.

    virtual void trigger () override;
    //< Triggers all of this macros functions.

    virtual void Press () override {}
    //< Triggered when a mode button is pressed.
    
    virtual void Depress () override {}
    //< Triggered when a mode button is depressed.
    
    virtual void Depress () override {}
    //< Triggered when a user "double clicks" a button.
    
    const char* GetListString () const;
    //< Gets a string of the row strings of the list.
    
    const char* GetHeaderString () const override;
    //< Gets th header for toStringRow ().
    
    const char* ToStringRow () const override;
    //< Gets a column of the values without the labels.
    
    void Print (I2P::Terminal& Slot);
    /*< Prints this object to a terminal. */

    private:

    int numControls;                        //< The number of controls in the list.

    LinearNode<AVControl*>* controls;       //< Pointer to the head of the linear linked list of Events.

    void ClearList  (LinearNode<AVControl*>* thisNode);
    //< Recursivly deletes all of the nodes.

    AVControl* removeAfter  (LinearNode<AVControl*>* thisNode);
    //< Removes the node after thisNode from the list.
};

class _KabukiSDK MacroButtonTests : public UnitTest
{
    public:

    MacroButtonTests () : UnitTest ("Testing Controls::MacroButton class _KabukiSDK:\n" + ConsoleLine ('~')) {}

    void runTest ()
    {
        auto macroA = MacroButton ("Macro Button A");

        beginTest ("Testing const char* ToString ()...");
        LogMessage  (macroA.ToString ());
        beginTest ("Testing add  (AVControl*)");
        macroA.add  (new DMXControl  ("Macro 1"));
        macroA.add  (new MIDIControl ("Macro 2"));
        macroA.add  (new DMXButton   ("Macro 3"));
        macroA.add  (new MIDIButton  ("Macro 4"));
        LogMessage ("Added " + const char*  (macroA.numControls ()) + " test controls.\n" + macroA.ToString ());
        beginTest ("Testing void trigger ()");
        macroA.trigger ();
        beginTest ("Testing AVControl* remove  (index);");
    }
};
static MacroButtonTests testUnit_MacroButton;
}   //< namespace Controls
}   //< namespace _Dev

