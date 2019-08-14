/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/script2_console/itos_algoihrms.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>

#if SEAM >= SCRIPT2_1
#ifndef INCLUDED_SCRIPT_ITOS_TESTS
#define INCLUDED_SCRIPT_ITOS_TESTS

#include "config.h"

TestCase PrintNil(const CH1* args);

CH1* PrintNil(CH1* begin, CH1* end, uint32_t value);

CH1* PrintSprintf(CH1* begin, CH1* end, uint32_t value);

TestCase PrintSprintf(const CH1* args);

CH1* PrintMod10(CH1* begin, CH1* end, uint32_t value);

TestCase PrintMod10(const CH1* args);

CH1* PrintMod100(CH1* begin, CH1* end, uint32_t value);

TestCase PrintMod100(const CH1* args);

CH1* PrintSprintf(CH1* begin, CH1* end, uint32_t value);

TestCase PrintSprintf(const CH1* args);

CH1* PrintStbSprintf(CH1* begin, CH1* end, uint32_t value);

TestCase PrintStbSprintf(const CH1* args);

CH1* PrintMsd10(CH1* begin, CH1* end, uint32_t value);

TestCase PrintMsd10(const CH1* args);

CH1* PrintSizeLut(CH1* begin, CH1* end, uint32_t value);

void TestItoSSizeLut();

void BenchmarkScriptItos();

#endif  //< #ifndef INCLUDED_SCRIPT_ITOS_TESTS
#endif  //< #if SEAM >= SCRIPT2_1
