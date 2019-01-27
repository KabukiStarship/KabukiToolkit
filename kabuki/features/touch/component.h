/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/features/touch/touch_component.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-19 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_FEATURES_TOUCH_1
#ifndef HEADER_FOR_KT_HMI_HMICOMPONENT
#define HEADER_FOR_KT_HMI_HMICOMPONENT

#include "config.h"

namespace _ {

typedef enum {
  HMITypeMIDI = 0,
  HMITypeDMX,

} HMIComponentType;

//< The non-alpha-numeric characters allowed in a label.
const CH1* GetAllowedSymbols();

/* Sets the allowed symbols to the given string. */
void SetAllowedSymbols(const CH1* s);

/* Checks the given CH1 c to see if any of the chars contain it. */
inline BOL ContainsChar(const CH1* chars, CH1 c);

/* Checks the given string s to see if any of the chars are in it. */
inline BOL ContainsChar(const CH1* chars, const CH1* s);

/* Verifies if thisLabel is a valid label.
    @return Returns 0 if the label is valid.
    @return Returns 1 if the label is too uint32_t.
    @return Returns -1 thisLabel is "".
*/
SI4 IsValidLabel(const CH1* label);

/* All unnamed labels share the same CH1* pointer. */
const CH1* GetUnnamedLabel();

/* A list of the most common Parameter types. */
typedef enum ParameterTypes {
  ControlDmx = 0,
  MidiControl,
  OSCControl,
  DMXButton,
  MIDIButton,
  OSCButton,
  ButtonMacro
} ParameterType;

/* A component in a Human-Machine Interface that may be referenced by name or
   UID. A HmiComponent has the following rules: 1.) Labels must be 255
   characters or less for a normal label, and 16 characters or less for a short
   label. 2.) Labels must contain printable ASCII characters that are HUI
   compatible.
*/
class SDK HmiComponent {
 public:
  enum {
    MaxLabelLength = 20,  //< The max label length of a label.
  };

  /* Default constructor. */
  HmiComponent(const CH1* newLabel = "");

  /* Copy constructor. */
  HmiComponent(const HmiComponent& other);

  /* Virtual destructor. */
  virtual ~HmiComponent() {}

  /* Gets the unique ID for the object. */
  UID GetUid();

  /* Gets the unique string of the component type. */
  const CH1* GetHMIComponentType();

  /* Gets the label. */
  const CH1* GetLabel() const;

  /* Sets the label to the given string.
      @return Returns 0 upon success and 1 if the newLabel is too uint32_t.
      @see    HmiComponent::isValid (CH1). */
  virtual SI4 SetLabel(const CH1* s);

  /* Compares this label to the given string.
      @return Returns 0 if they are identical and1 if the other CH1* is too
     uint32_t. */
  SI4 Compare(const CH1* s) const;

  /* Prints this object to a string. */
  virtual ::_::UtfN& Print(_::Utf& print) const;

 private:
  UID uid_,          //< Unique id.
      type_;           //< Type of HMI component.
  const CH1* label_;  //< This object's text label.
};                     //< class HmiComponent
}  // namespace _
#endif  //< HEADER_FOR_KT_HMI_HMICOMPONENT
#endif  //< #if SEAM >= KABUKI_FEATURES_TOUCH_1
