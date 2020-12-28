/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KabukiToolkit.git
@file    /Touch/ControlXY.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_TOUCH_CORE
#ifndef KABUKI_TOOLKIT_TOUCH_XYCONTROL
#define KABUKI_TOOLKIT_TOUCH_XYCONTROL
#include <_Config.h>
namespace _ {

class LIB_MEMBER XyTouchpad : public Component {
 public:
  /* Constructor. */
  XyTouchpad(ISC x = 0, ISC y = 0, ISC left_bounds = 0, ISC right_bounds = 0,
             ISC top_bounds = 0, ISC bottom_bounds = 0)
      : x_(x),
        y_(y),
        left_bounds_(left_bounds),
        right_bounds_(right_bounds),
        top_bounds_(top_bounds),
        bottom_bounds_(bottom_bounds) {}

  /* Copy constructor. */
  XyTouchpad(const XyTouchpad& other)
      : x_(other.x_),
        y_(other.y_),
        left_bounds_(other.left_bounds_),
        right_bounds_(other.right_bounds_),
        top_bounds_(other.top_bounds_),
        bottom_bounds_(other.bottom_bounds_) {}

  /* Gets thisX value. */
  ISC GetX() { return x_; }

  /* Gets thisY value. */
  ISC GetY() { return y_; }

  /* Sets thisX to the value. */
  void SetX(ISC value) {
    ISC bounds = left_bounds_;
    if (value <= left_bounds_)
      x_ = bounds;
    else if (value >= (bounds = right_bounds_))
      x_ = bounds;
    else
      x_ = value;
  }

  /* Sets thisY to the value. */
  void SetY(ISC value) {
    ISC bounds = bottom_bounds_;
    if (value <= bounds)
      y_ = bounds;
    else if (value >= (bounds = top_bounds_))
      y_ = bounds;
    else
      y_ = value;
  }

  /* Gets th left_bounds. */
  ISC GetLeftBounds() { return left_bounds_; }

  /* Gets th right_bounds. */
  ISC GetRightBounds() { return right_bounds_; }

  /* Gets th top_bounds. */
  ISC GetTopBounds() { return top_bounds_; }

  /* Gets th bottom_bounds. */
  ISC GetBottomBound() { return bottom_bounds_; }

  /* Sets the left_bounds to the newBouds. */
  BOL SetLeftBounds(ISC value) {
    if (value >= right_bounds_) return false;
    left_bounds_ = value;
    return true;
  }

  /* Sets the right_bounds to the new value. */
  BOL SetRightBounds(ISC value) {
    if (value <= right_bounds_) return false;
    right_bounds_ = value;
    return true;
  }

  /* Sets the top_bounds to the newBouds
  @pre Value > bottom_bounds. */
  BOL SetTopBounds(ISC value) {
    if (value >= top_bounds_) return false;
    top_bounds_ = value;
    return true;
  }

  /* Sets the bottom_bounds to the newBouds
  @pre Value < top_bounds. */
  BOL SetBottomBounds(ISC value) {
    if (value >= bottom_bounds_) return false;
    bottom_bounds_ = value;
    return true;
  }

  /* Prints this object to a terminal. */
  template <typename Printer>
  Printer& Print(Printer& o) {
    o << "\nXYControl:\nx: " << x_ << "  y_: " << y_;
  }

 private:
  ISC x_,              //< X value.
      y_,              //< Y value.
      left_bounds_,    //< Lower x bounds.
      right_bounds_,   //< Upper x bounds.
      top_bounds_,     //< Lower y bounds.
      bottom_bounds_;  //< Upper y bounds.
};
}  // namespace _
#endif
#endif
