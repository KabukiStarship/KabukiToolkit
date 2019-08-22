/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /c_dmxanimation.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#ifndef INCLUDED_KABUKI_FEATURE_TEK_DMX_ANIMATION
#define INCLUDED_KABUKI_FEATURE_TEK_DMX_ANIMATION 1

namespace _ {

/*< @fn    UpdateHandler  (UI4, UI4, UI1);
@brief C function Update handler for DMXAnimation.
@code
UI4 ExampleAnimation1  (num_channels, num_chases, num_variants);
@endcode */
typedef void (*UpdateHandler)  (UI4 Chase, UI4 Frame, UI1 Scene);

//inline BOL IsInvalidFrame  (UI4 Index);

/* A simple DMX animation with variant.

*/
class DmxAnimation {
      public:
    
    enum {
        FPS         = 30    //< The target frames per second.
    };
    
    /* Simple default constructor. */
    DmxAnimation  (UI4 num_channels, UI4 num_chases, UI4 num_variants);

    /* Resets the animation to the first frame */
    void ResetAnimation ();
    
    /* Sets the currentChase to the given Index. */
    void SetChaseNumber  (UI4 Index);
    
    /* Function sends out DMX data for the given channel. */
    void SetChannelData  (UI2 Channel, UI1 value);
    
    /* Function sets an RGB color starting at the given channel. */
    void SetRGBColor  (UI2 Channel, CRGBAUI4 value);
    
    /* Randomizes the currentVariant */
    void RandomizeVariant ();

    void SendScene ();
    void SetChase  (UI1 chaseNumber);
    void RandomizeSceneVariant ();
    void SetColor  (UI2 channel, UI1 red, UI1 green, UI1 blue);
    void SetColor  (UI2 channel, CRGBAUI4 color);
    void SetAllColors  (CRGBAUI4 color);
    CRGBAUI4 IncreaseBrightness  (CRGBAUI4 color, UI1 brightness_change);
    CRGBAUI4 DecreaseBrightness  (CRGBAUI4 color, UI1 brightness_change);
    
    protected:

    UI1  param1_,              //< Animation parameter 1/Red.
          param2_,              //< Animation parameter 2/Green.
          param3_,              //< Animation parameter 3/Blue.
          param4_;              //< Animation parameter 4/White.
    UI4  current_chase_,       //< Current chase number.
          current_chase_length_,//< Length of the current chase.
          current_variant_,     //< Current variant.
          channel_count_,        //< The number of DMX channels.
          num_chases_,          //< The number of DMX chases.
          num_variants_;        //< The number of variations of the animation.
    UI1* data_;                //< Pointer to the DMX data for the current scene.
};
}       //< namespace _
#endif  //< INCLUDED_KABUKI_FEATURE_TEK_DMX_ANIMATION
