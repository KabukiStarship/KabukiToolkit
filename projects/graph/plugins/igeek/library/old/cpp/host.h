/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/host.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace CellEvolutionaryInterface {
    
class Host: public JPanel
{
  public:
    
    Host (int thisWidth, int thisHeight, int numberOfCells, int numberOfViruses);
    
    int getNumCells ();
    
    VirusPopulation virusPopulation ();
    
    void update ();
    
    void paintComponent (Graphics g);
    
  private:
    
    int numCells;               /< The number of Cell(s)
                
    Cell[] cells;               /< The array of Cell(s)
    
    VirusPopulation viruses;    /< The Virus population array.
    
    Color hostColor,            /< The background color.
        backgroundColor;        /< The off screen
    
    static const Color DefaultHostColor  = Color.gray,  /< The default background color of the 
        DefaultBackgroundColor = Color.black;           /< The default background color. 
}