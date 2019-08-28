/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace igeek {

class GeneticPolygonTestPanel: public JPanel
{
  private:
    
    enum {
        panelWidth          = 1024,
        panelHeight         = 700,
        panelMargin         = 10,
        parentPanelSize     = 300,
        childPanelSize      = 400,
        initPopulationSize  = 100,
    };
    
    GeneticPolygonTestPanel ();
    
    void initializePopulation ();
    
    void paintComponent (Graphics g);
    
    void iterateGeneration ();
    
    void mateRandom ();
    
    void addChild (GeneticPolygon newChild);
    
  private:
    
    GeneticPolygonPanel motherPanel, fatherPanel, matGrandPanel, patGrandPanel;
    GeneticPolygonChildPanel childPanel;
    
    GeneticPolygon cell;
    
    GeneticPolygon population[];            /< The population of GeneticPolygon(s)
    
    int timerUpdateInterval  = 1000,        /< The durration of time tha the timer is updated
                populationSize;             /< The size of the pupulation.
    Timer timer;                            /< The timer for the 
    bool timerOn;                           /< Represents if the timer is on or off.
    
    class StartAction: public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }
    
    class StopAction: public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }
    
    class NextAction: public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }
    
    class MateAction: public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }
    
    class TimerAction: public ActionListener
    {
        void actionPerformed (ActionEvent e);
    }
};

}   /< namespace igeek {
