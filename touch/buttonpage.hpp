/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/ButtonPage.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R). 
This Source Code Form is subject to the terms of the Mozilla Public License, 
v. 2.0. If a copy of the MPL was not distributed with this file, You can 
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#ifndef KABUKI_TOOLKIT_TOUCH_BUTTONPAGE
#define KABUKI_TOOLKIT_TOUCH_BUTTONPAGE
#include "Button.hpp"
#include "ControlLayer.hpp"
#include "WidgetPage.hpp"
namespace _ {

/* A type of Button that loads a WidgetPage into a Control Layer
The difference between a page and a macro button is that a page button
swtiches between pages in a template and a PageButton will be able to
perform other tasks in a virtual instrument such as loading one of the
sub-menus. Not sure if this class is neccissary yet. */
class LIB_MEMBER PageButton : public Button {
 public:
  /* Constructor. */
  PageButton(const WidgetPage& thePage = WidgetPage())
    : Button (initPage.label (), Control::PAGE_BUTTON, MOMENTARY),
    thisPage (TemplatePage (initPage)) {
    // Nothing to do here :-)
  }

  /* Copy constructor. */
  PageButton(const PageButton& o)
    : Button (o.label (), Control::PAGE_BUTTON, MOMENTARY),
    thisPage (TemplatePage (o.thisPage)) {}

  /* Destructor. */
  virtual ~PageButton () {}

  /* The action  (s) performed when this button gets pressed. */
  void Press(const ControlLayer& parentLayer) { Button::Press (); }

  /* The action  (s) performed when this button gets FPD pressed. */
  void Depress(const ControlLayer& parentLayer) {
    Button::DoublePress ();
  }

  /* Gets thw WidgetPage. */
  WidgetPage* GetPage() { return page_; }

  /* Sets thisPage to the newPage.
  void SetPage(WidgetPage* newPage);

  /* Prints this object to a terminal. */
  template<typename Printer>
  Printer& Print(Printer& o) const {
    return o << "\nButtonPage:\n" << page_.Print (o);
  }

 private:
  WidgetPage* page_;  //< The page to load.
};
}  // namespace _
#endif
#endif
