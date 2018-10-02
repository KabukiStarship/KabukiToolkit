/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    ~/seam_00/04/01_video_player/00/00/seam.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#include "seam_header.h"

#include <kabuki/f2/test_header.h>

namespace _ {
const char* Seam_00_04_01__00_00(char* seam_log, char* seam_end, 
                          const char* args) {
  if (!TestBegin(seam_log, seam_end, args)) return __FUNCTION__;
  
  
  
  return nullptr;
}
}
#include "seam_footer.h"