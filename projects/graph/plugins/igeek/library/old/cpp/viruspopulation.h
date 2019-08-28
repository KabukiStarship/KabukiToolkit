/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/viruspopulation.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "Virus.h"
#include "Host.h"

namespace CellEvolutionaryInterface {

class VirusPopulation
{
    static const int DefaultPopulationSize = 100;
    
    VirusPopulation (Host thisHost);
    /*< Constuctor */
    
    void addVirus (Virus newVirus);
    /*< Adds the newVirus to the population. */
    
    Virus getVirus (int index);
    /*< Returns the virus at the specified index. */
    
    int selectRandomVirus ();
    /*< Selects a random virus from the population. */
    
    int contains (GeneticPolygon thisGeneticPolygon);
    /*< Function returns a value greater that -1 if this population contains thisGeneticPolygon.
        @return Returns -1 if the population doesn't contain thisGeneticPolygon. Else it will return the index of the Virus. 
    */  
    
    int selectVirus (int mouseX, int mouseY);
    /*< Function that selects the virus  */
    
    int getNumViruses ();
    /*< Returns the number of viruses. */
    
    void update ();
    /*< Updates the virus population with the new . */
    
    void draw (Graphics g);
    
    void boxCollidingViruses (Graphics g);
    
    void boxTwoViruses (Graphics g, Virus a, Virus b);
    
  private:
    
    int numViruses;             /< The number of Viruses.
    Virus[] viruses;            /< The array of Virus.
    Host host;                  /< A pointer to the Host this VirusPopulation lives on.
}