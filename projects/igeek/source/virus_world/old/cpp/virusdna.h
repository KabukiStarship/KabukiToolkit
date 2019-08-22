/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/virusdna.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace igeek {
    
/* Class that represents a DNA Virus.
A DNA Virus is a type of virus that is made of DNA and replicates itself inside of the cell cytoplasm.
@see    https:/en.wikipedia.org/wiki/DNA_virus
*/
class DNAVirus: public Virus {
  public:
    
    DNAVirus (double initX, double initY);
};
}   //< igeek
