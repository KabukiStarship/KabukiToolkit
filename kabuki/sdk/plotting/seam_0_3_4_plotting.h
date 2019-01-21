/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/3/3_pl/seam_pl.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */
#pragma once
#include <pch.h>

#include "header.h"

namespace _ {
const char* Kabuki__Sight___Kabuki__F2SDK__Plotting(char* seam_log, char* seam_end, 
                                     const char* args) {
#if SEAM >= SEAM_0_3_3
  if (!TestBegin(seam_log, seam_end, args)) return __FUNCTION__;
#endif
  return TestTree<Seam_0_3_3__0>(seam_log, seam_end, args);
}
}  // namespace _

#include "footer.h"