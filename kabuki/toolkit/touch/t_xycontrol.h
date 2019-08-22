/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /toolkit/touch/t_t_xycontrol.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_AV_1
#ifndef KABUKI_TOOLKIT_AV_XYCONTROL
#define KABUKI_TOOLKIT_AV_XYCONTROL

#include "t_config.h"

namespace _ {

class SDK XyTouchpad : public Component {
 public:
  /* Constructor. */
  XyTouchpad(SI4 x = 0, SI4 y = 0, SI4 left_bounds = 0,
             SI4 right_bounds = 0, SI4 top_bounds = 0,
             SI4 bottom_bounds = 0)
    : x_ (x),
    y_ (y),
    left_bounds_ (left_bounds),
    right_bounds_ (right_bounds),
    top_bounds_ (top_bounds),
    bottom_bounds_ (bottom_bounds) {
  }

  /* Copy constructor. */
  XyTouchpad(const XyTouchpad& other)
    : x_ (other.x_),
    y_ (other.y_),
    left_bounds_ (other.left_bounds_),
    right_bounds_ (other.right_bounds_),
    top_bounds_ (other.top_bounds_),
    bottom_bounds_ (other.bottom_bounds_) {
  }

  /* Gets thisX value. */
  SI4 GetX() { return x_; }

  /* Gets thisY value. */
  SI4 GetY() { return y_; }

  /* Sets thisX to the value. */
  void SetX(SI4 value) {
    SI4 bounds = left_bounds_;
    if (value <= left_bounds_)
      x_ = bounds;
    else if (value >= (bounds = right_bounds_))
      x_ = bounds;
    else
      x_ = value;
  }

  /* Sets thisY to the value. */
  void SetY(SI4 value) {
    SI4 bounds = bottom_bounds_;
    if (value <= bounds)
      y_ = bounds;
    else if (value >= (bounds = top_bounds_))
      y_ = bounds;
    else
      y_ = value;
  }

  /* Gets th left_bounds. */
  SI4 GetLeftBounds() { return left_bounds_; }

  /* Gets th right_bounds. */
  SI4 GetRightBounds() { return right_bounds_; }

  /* Gets th top_bounds. */
  SI4 GetTopBounds() { return top_bounds_; }

  /* Gets th bottom_bounds. */
  SI4 GetBottomBound() { return bottom_bounds_; }

  /* Sets the left_bounds to the newBouds. */ 
    BOL SetLeftBounds(SI4 value) {
      if (value >= right_bounds_) return false;
      left_bounds_ = value;
      return true;
    }

  /* Sets the right_bounds to the new value. */
  BOL SetRightBounds(SI4 value) {
    if (value <= right_bounds_) return false;
    right_bounds_ = value;
    return true;
  }

  /* Sets the top_bounds to the newBouds
  @pre Value > bottom_bounds. */
  BOL SetTopBounds(SI4 value) {
    if (value >= top_bounds_) return false;
    top_bounds_ = value;
    return true;
  }

  /* Sets the bottom_bounds to the newBouds
  @pre Value < top_bounds. */
  BOL SetBottomBounds(SI4 value) {
    if (value >= bottom_bounds_) return false;
    bottom_bounds_ = value;
    return true;
  }

  /* Prints this object to a terminal. */
  template<typename Printer>
  Printer& Print (Printer& o) {
    o << "\nXYControl:\nx: " << x_ << "  y_: " << y_;
  }

 private:
  SI4 x_,              //< X value.
      y_,              //< Y value.
      left_bounds_,    //< Lower x bounds.
      right_bounds_,   //< Upper x bounds.
      top_bounds_,     //< Lower y bounds.
      bottom_bounds_;  //< Upper y bounds.
};
}  // namespace _
#endif  //< KABUKI_TOOLKIT_AV_XYCONTROL
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1
