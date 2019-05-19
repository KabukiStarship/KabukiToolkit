/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/gui/t_toolbutton.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */
/*
    /kabuki_toolkit/gui/toolbutton.h -- Simple radio+toggle button with an icon

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/


#pragma once
#include <pch.h>


#include "t_button.h"

namespace _ {

/*
 * \class ToolButton toolbutton.h /kabuki_toolkit/gui/toolbutton.h
 *
 * @brief Simple radio+toggle button with an icon.
 */
class ToolButton : public Button {
public:
  ToolButton (Widget *parent, int icon,
    const std::string &caption = "")
    : Button (parent, caption, icon) {
    setFlags (Flags::RadioButton | Flags::ToggleButton);
    setFixedSize (Vector2i (25, 25));
  }
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

} //< namespace _
