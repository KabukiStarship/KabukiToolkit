/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/cell.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace CellEvolutionaryInterface {

class Cell: public GeneticPolygon
/* Class represents a cell in the simulation.
*/
{
    static const int DefaultWidth  = 50,
        DefaultHeight = 50,
        circleBuffer  = 20;
    
    int numPointsWeakness,
        shapeAngleWeakness,
        colorWeakness;                      /< The color this Cell is weak to.
                                            /*< Viruses that are of weak to a color will allow a cell to infect it that smaller. */
    
    double x,                               /< The current x position.
        y;                                  /< The current y position.
    
    Host host;                              /< A pointer to the host.
    Virus virus;                            /< The infecting virus.
    long timeOfInfection;                   /< The time that this cell got infected.
    
    Cell (Host cellHost);
    
    Cell (int xPosition, int yPosition, int thisWidth, int thisHeight, int thisNumPoints, int thisColorARGB, 
        int thisLifespan, double thisAngle);
    
    void highlight (Graphics g, Color circleColor);
    
    void update ();
    
    double getX ();
    
    double getY ();
    
    int leftEdge ();
    
    int topEdge ();
    
    int rightEdge ();
    
    void infectCell (Virus thisVirus);
};

}   //< CellEvolutionaryInterface
