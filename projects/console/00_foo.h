/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/script2/benchmark/00_foo.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#if SEAM == BENCHMARK_SCRIPT2_0
#include "../../../script2/test_debug.inl"
#else
#include "../../../script2/test_release.inl"
#endif

using namespace _;

namespace kabuki {
namespace script2_benchmark {
inline const CH1* _0_Foo(CH1* seam_log, CH1* seam_end, const CH1* args) {
#if SEAM >= BENCHMARK_SCRIPT2_0
  TEST_BEGIN;

  PRINT_HEADING("Testing putchar vs stdout");
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) putchar('.');
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds_putchar = end - start;

  start = std::chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) printf(".");
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds_printf = end - start;

  start = std::chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) std::cout << ".";
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds_cout = end - start;

  cout << "\n\nputchar vs printf vs cout benchmark\n\n"
          "512 * 1024 single CH1 calls:\n"
          "putchar (CH1) calls: "
       << elapsed_seconds_putchar.count() << "s\n"
       << "printf (const CH1*) calls: " << elapsed_seconds_printf.count()
       << "s\n"
       << "cout << const CH1* calls: " << elapsed_seconds_cout.count() << "s\n";

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) {
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('.');
    putchar('.');
  }
  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_putchar = end - start;

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) printf("..........");

  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_printf = end - start;

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) cout << "..........";
  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_putchar = end - start;

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) printf("..........");
  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_printf = end - start;

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) cout << "..........";
  end = chrono::system_clock::now();

  cout << "\n512 * 1024 * 10 chars calls:\n"
          "putchar (CH1) calls: "
       << elapsed_seconds_putchar.count() << "s\n"
       << "printf (const CH1*) calls: " << elapsed_seconds_printf.count()
       << "s\n"
       << "cout << const CH1* calls: " << elapsed_seconds_cout.count() << "s\n";

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) printf("..........");

  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_printf = end - start;

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) cout << "..........";
  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_putchar = end - start;

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) printf("%i%i%f%f", GetRandom);
  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_printf = end - start;

  start = chrono::system_clock::now();
  for (SI4 i = 0; i < 512 * 1024; ++i) cout << "..........";
  end = chrono::system_clock::now();

  cout << "\n512 * 1024 * 10 chars calls:\n"
          "putchar (CH1) calls: "
       << elapsed_seconds_putchar.count() << "s\n"
       << "printf (const CH1*) calls: " << elapsed_seconds_printf.count()
       << "s\n"
       << "cout << const CH1* calls: " << elapsed_seconds_cout.count() << "s\n";

#endif
  return 0;
}
}  // namespace script2_benchmark
}  // namespace kabuki
