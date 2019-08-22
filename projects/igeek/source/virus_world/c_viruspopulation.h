/* Cell Evolutionary Interface
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/c_viruspopulation.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "Virus.h"
#include "Host.h"

namespace igeek {

class VirusPopulation {
  static const SI4 DefaultPopulationSize = 100;

  /* Constuctor */
  VirusPopulation (Host thisHost);

  /* Adds the virus to the population. */
  void addVirus (Virus virus);

  /* Returns the virus at the specified index. */
  Virus getVirus (SI4 index);

  /* Selects a random virus from the population. */
  SI4 selectRandomVirus ();
    
  /* Function returns a value greater that -1 if this population contains thisGeneticPolygon.
    @return Returns -1 if the population doesn't contain thisGeneticPolygon. Else it will return the index of the Virus. 
  */ 
  SI4 contains (GeneticPolygon thisGeneticPolygon);

  /* Function that selects the virus  */
  SI4 selectVirus (SI4 x, SI4 y);

  /* Returns the number of viruses. */
  SI4 VirusCount ();
    
  /* Updates the virus population with the new . */
  void Update ();
    
  void Draw (Graphics g);
    
  void BoxCollidingViruses (Graphics g);
    
  void BoxTwoViruses (Graphics g, Virus a, Virus b);
    
  private:
    
  SI4 numViruses;     //< The number of Viruses.
  Virus[] viruses;    //< The array of Virus.
  Host host;          //< A pointer to the Host this VirusPopulation lives on.
}
