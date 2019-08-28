/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/cell.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "cell.h"

namespace igeek {
    
Cell::Cell (Host cellHost)
{
    super ();
    
    host = cellHost;
}

Cell::Cell (int xPosition, int yPosition, int thisWidth, int thisHeight, int thisNumPoints, 
    int thisColorARGB, int thisLifespan, double thisAngle)
{
    super (thisNumPoints, thisWidth, thisHeight, thisColorARGB, thisLifespan, thisAngle);
    
}

void Cell::highlight (Graphics g, Color circleColor)
{
    g.setColor (circleColor);
    g.drawOval (leftEdge () - circleBuffer, topEdge () - circleBuffer,getWidth () + circleBuffer, getHeight () + circleBuffer);
}

void Cell::update ()
{
    // We only need to do any logic if the cell is infected. 
    
    if (virus == null)
        return;
}

double Cell::getX ()
{
    return x;
}

double Cell::getY ()
{
    return y;
}
int Cell::leftEdge ()
{
    return (int) x;
}

int Cell::topEdge ()
{
    return (int) y;
}

int Cell::rightEdge ()
{
    return (int)x+getWidth ();
}

int Cell::bottomEdge ()
{
    return (int)y+getHeight ();
}

void Cell::infectCell (Virus thisVirus)
{
    virus = thisVirus;
    timeOfInfection = System.currentTimeMillis ();
}

}   //< namespace igeek {
