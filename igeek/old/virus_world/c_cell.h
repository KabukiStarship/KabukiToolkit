/* Cell Evolutionary Interface
@version   0.x
@file      /.../CellEvolutionaryInterface/Cell.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

namespace CellEvolutionaryInterface {

class Cell: public GeneticPolygon
/* Class represents a cell in the simulation.
*/
{
    static const SI4 DefaultWidth  = 50,
        DefaultHeight = 50,
        circle_buffer  = 20;
    
    SI4 numPointsWeakness,
        shapeAngleWeakness,
        colorWeakness;                      /< The color this Cell is weak to.
                                            /*< Viruses that are of weak to a color will allow a cell to infect it that smaller. */
    
    FP8 x,                               /< The current x position.
        y;                                  /< The current y position.
    
    Host host;                              /< A pointer to the host.
    Virus virus;                            /< The infecting virus.
    long timeOfInfection;                   /< The time that this cell got infected.
    
    Cell (Host cellHost);
    
    Cell (SI4 x_pos, SI4 y_pos, SI4 width, SI4 height, SI4 point_count, SI4 color, 
        SI4 lifespan, FP8 angle);
    
    void highlight (Graphics g, Color circle_color);
    
    void update ();
    
    FP8 getX ();
    
    FP8 getY ();
    
    SI4 Left ();
    
    SI4 Top ();
    
    SI4 rightEdge ();
    
    void infectCell (Virus thisVirus);
};

}   //< CellEvolutionaryInterface
