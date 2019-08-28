/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /projects/igeek/source/host.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <Kabuki_Theater/Cell_IGA/Host.h>

namespace igeek {

Host::Host (int thisWidth, int thisHeight, int numberOfCells, int numberOfViruses)
{
    setPreferredSize (new Dimension (thisWidth, thisHeight));
    setBorder(BorderFactory.createLineBorder(Color.BLACK));
    
    cells   = new Cell[numberOfCells];
    
    numCells = numberOfCells;
    
    for (int i=0; i < numberOfCells; i++)
        cells[i] = new Cell (this);
    
    viruses = new VirusPopulation (this);
    
    hostColor = DefaultHostColor;
    backgroundColor = DefaultBackgroundColor;
}

int Host::getNumCells ()
{
    return numCells;
}
VirusPopulation Host::virusPopulation ()
{
    return viruses;
}

void Host::update ()
{
    viruses.update ();
    
    // Check to see if a Virus occupies a cell.
    
    for (int i=0; i < numCells; i++)
    {
        Cell currentCell = cells[i];
        
        if (viruses.contains (currentCell) >= 0)
        {
            //if (currentCell.getMass ())
            //    ;
        }
    }
}

void Host::paintComponent (Graphics g)
{
    super.paintComponent(g);
        
    setBackground(backgroundColor);
    
    Dimension bounds = getPreferredSize ();
    
    g.setColor (hostColor);
    g.fillRect (0, 0, bounds.width, bounds.height);
    
    viruses.draw (g);
}

}   //< namespace igeek {
    