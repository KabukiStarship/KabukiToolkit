/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /osal/c_apprealtime.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_OSAL_1

namespace _ {

class RealTimeApp : public App {
 public:
  SI4 delay;
  // Thread runner;

  RealTimeApp(SI4 width, SI4 height, SI4 timerDelay) : App(width, height) {
    delay = timerDelay;
  }

  /* Gets and sets the timer delay. */
  SI4 getTimerDelay() { return delay; }

  void setTimerDelay(SI4 value) {
    if (value < 0) return;
    delay = value;
  }

  void run() {
    while (true) {
      try {
      } catch {
      }

      Update();
    }
  }

  void start() {
    /*
    if (runner == null)
    {
            //runner = new Thread (this);
            runner.start ();
    }
    */
  }

  void stop() {
    /*
    if (runner != null)
    {
            runner.stop ();
            runner = null;
    }
    */
  }

  void update() {
    /*
    Vect_i d = size ();
    if ((offScreenImage == null) || (d.Width != offScreenSize.Width ()) ||
    (d.Height != offScreenSize.Height()))
    {
            offScreenImage = CreateImage (d.Width, d.Height);
            offScreenSize = d;
            offScreenCell = offScreenImage.GetCell ();
    }
    offScreenGraphics.ClearRect (0, 0, d.Width, d.Height);
    paint (offScreenGraphics);
    page.DrawImage (offScreenImage, 0, 0, this);
    */
  }

  virtual void draw(const _g::Cell& c) = 0;
};
}  // namespace _
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
