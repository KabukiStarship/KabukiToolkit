/* Cell Evolutionary Interface
@version   0.x
@file      /.../CellEvolutionaryInterface/Host.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

namespace CellEvolutionaryInterface {
    
class Host: public JPanel
{
  public:
    
    Host (SI4 width, SI4 height, SI4 numberOfCells, SI4 numberOfViruses);
    
    SI4 getNumCells ();
    
    VirusPopulation virusPopulation ();
    
    void update ();
    
    void paintComponent (Graphics g);
    
  private:
    
    SI4 numCells;               /< The number of Cell(s)
                
    Cell[] cells;               /< The array of Cell(s)
    
    VirusPopulation viruses;    /< The Virus population array.
    
    Color hostColor,            /< The background color.
        backgroundColor;        /< The off screen
    
    static const Color DefaultHostColor  = Color.gray,  /< The default background color of the 
        DefaultBackgroundColor = Color.black;           /< The default background color. 
}