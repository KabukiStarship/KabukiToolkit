/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/console/c_shapefinderdemo.h
@author  Cale McCollough <calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

namespace _ {


class LeukocyteWar : public JPanel, public MouseListener, KeyListener // , ActionListener
{
  public:

    enum {
        defaultWidth = 1300, //< The default window width.
        defaultHeight = 700, //< The default window height.
        defaultNumCells = 0, //< The default number of Viruses for the simulation
        defaultNumViruses = 20, //< The default number of Viruses for the simulation
        timerUpdateInterval = 100, //< The durration of time tha the timer is updated.
    };

    LeukocyteWar ();

    void initialize ();

    void paintComponent (Graphics g);

  private:

    Host host; //< The simulated host.
    VirusPopulation viruses; //< The Virus population array.

    Timer timer; //< The timer for the program.
    BOL timerOn, //< The time on status.
        drawCurrentBezierCurve, //< The the Bezier curve for the current selected virus.
        drawCurrentTrail, //< Draws the current selectred virus's trail.
        kill, //< Flag that determines if program is in "Kill Mode"
        breed;

    Virus currentVirus; //< The currently selected virus.

    BezierCurvePanel curvePanel; //< The graphic representation of the currentVirus's Bezier movement curve.

    SI4 curvePanelX,
        curvePanelY,
        currentVirusIndex; //< The index of the currently selected virus.

    Toolbar toolbar;

    class Toolbar : public JPanel
    {
        Toolbar ();
    }

    class TimerAction : public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }

    class StartAction : public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }

    class StopAction : public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }

    void mousePressed (MouseEvent e);

    void mouseReleased (MouseEvent e);

    void mouseEntered (MouseEvent e);

    void mouseExited (MouseEvent e);

    void mouseClicked (MouseEvent e);

    void keyTyped (KeyEvent e);

    void keyPressed (KeyEvent e);

    void keyReleased (KeyEvent e);
}
}
}

