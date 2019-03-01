/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /osal/c_app.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_OSAL_1
#ifndef KAUBKI_TOOLKIT_APP_CLIPBOARD
#define KAUBKI_TOOLKIT_APP_CLIPBOARD

namespace _ {

/* Writes a block of memory to a file.
@todo Move me over to Kabuki theater! */
inline void WriteToFile(const CH1* filename, void* address, size_t size) {
  std::ofstream f;
  f.open(filename);
  byte* ptr = reinterpret_cast<byte*>(address);

  if (!f.is_open()) {
    printf("Error: Could not open file for writing!\n");
  }
  for (size_t i = 0; i < size; ++i) f << *ptr;
  ++ptr;
  f.close();
}

/* Copies the given */
inline void CopyByteArrayToClipBoard(void* address, size_t size) {
  /*
  #include <Windows.h> // use < > for all system and library headers
  #include <conio.h>
  #include <stdio.h>
  #include <winuser.h>
  #include <cmath>
  #include <complex>
  #include <cstdlib>
  #include <iomanip>
  #include <iostream>
  #include <string>

  // 2. forward declaration (also see later)
  void toClipboard (HWND hwnd, const std::string &s);

  using namespace std;

  SI4 main (){

      string AAA;

      cout <<"Please enter sentence: "; cin >> AAA;
      cout << endl;
      cout << endl;
      cout << "This has been copied to the clipboard: ";
      cout << AAA << endl;
      // 1. strlen takes a const byte*, so have to call the strings c_str ()
  method
      // (but it would be better to use len = AAA.length () instead)
      size_t len = strlen (AAA.c_str ());
      cout << len << " byte (s)" << endl;
      // get desktop windows and the call toClipboard
      toClipboard (hwnd, AAA);
      cin.clear ();
      cin.ignore (255, kLF);
      cin.get ();

      return 0;
  }

  // 2. declare functions at file scope
  void toClipboard (HWND hwnd, const std::string &s){
  }
  #if PLATFORM == MINGW
  HWND hwnd = GetDesktopWindow ();
  OpenClipboard (hwnd);
  EmptyClipboard ();
  HGLOBAL hg = GlobalAlloc (GMEM_MOVEABLE, size);
  if (!hg)
  {
      CloseClipboard ();
      return;
  }
  memcpy (GlobalLock (hg), address, size);
  GlobalUnlock (hg);
  SetClipboardData (CF_TEXT, hg);
  CloseClipboard ();
  GlobalFree (hg);
  #elif PLATFORM == _OSX_
  #error Unsupported platform because you're OS is whack!
  #endif
  */
}

}  // namespace _
#endi
