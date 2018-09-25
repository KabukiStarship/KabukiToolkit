/* Kabuki Toolkit
@version 0.x
@file    $kabuki-toolkit/kabuki/hal/terminal.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-8 Cale McCollough <calemccollough@gmail.com>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <stdafx.h>
#if SEAM_MAJOR > 0 || SEAM_MAJOR == 0 && SEAM_MINOR >= 2
#ifndef HEADER_FOR_CRABS_TCONSOLE
#define HEADER_FOR_CRABS_TCONSOLE

namespace _ {

/* Prints the char to the console. */
void ConsolePrint(char c);

/* Prints the string to the console. */
void ConsolePrint(const char* string);

/* Scans the next char in the input buffer, if there is one.
@return A value 0-255 upon success or -1 if the buffer is empty.
*/
int ConsoleScan();

}  // namespace _

#endif  //< #if SEAM_MAJOR > 0 || SEAM_MAJOR == 0 && SEAM_MINOR >= 5
#endif  //< HEADER_FOR_HAL_TIMER