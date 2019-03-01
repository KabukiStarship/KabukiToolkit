/* Cell Evolutionary Interface @version   0.x
@file      /.../CellEvolutionaryInterface/DNAVirus.hpp
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

namespace CellEvolutionaryInterface {
    
/* Class that represents a DNA Virus.
A DNA Virus is a type of virus that is made of DNA and replicates itself inside of the cell cytoplasm.
@see    http:/en.wikipedia.org/wiki/DNA_virus
*/
class DNAVirus: public Virus
{
  public:
    
    DNAVirus (FP8 initX, FP8 initY);
};
}   //< CellEvolutionaryInterface
