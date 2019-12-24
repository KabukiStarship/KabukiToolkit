/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /code/comment_stripper.inl
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#include <_config.h>
//
//#include <script2/cin.inl>
//
#include "comment_stripper.h"
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//
#include <Windows.h>
using namespace std;

namespace _ {

ISN StripComments(const CHA* directory, const CHA* filename,
                  ISN tab_space_count) {
  if (!directory || !filename) return -1;

  AString filename_in(directory).Star('/') << filename;

  std::string filename_out(directory);
  filename_out += "/sloth/";
  filename_out += filename;

  std::cout << "\nStripping comments from:" << filename_in
            << " to:" << filename_out << "\n\n\n";

  enum {
    cScanningCode = 0,
    cScanningCommentLine,
    cScanningCommentBlock,
  };

  ISN state = cScanningCode;

  string line, result;
  ifstream file_in(filename_in.c_str());
  // ofstream file_out;
  // file_out.open(filename_out);

  if (file_in.is_open()) {
    // std::cout << "\n\nState:ScanningCode\n\n";
    while (getline(file_in, line)) {
      const CHA* cursor = line.c_str();
      CHA c = *cursor++, last_c = 0;
      while (c) {
        // Check if the rest of the line is whitespace.
        // const CHA* whitespace_cursor = cursor;
        // while (c == ' ' || c == cTAB) c = *cursor++;
        // if (!c) break;

        switch (state) {
          case cScanningCode: {
            if (last_c == '/') {
              if (c == '/') {
                std::cout << "//";
                state = cScanningCommentLine;
              } else if (c == '*') {
                std::cout << "/*";
                state = cScanningCommentBlock;
              } else {
                goto PrintC;
              }
            } else {
            PrintC:
              if (last_c == cTAB) {
                for (ISN i = tab_space_count; i > 0; --i) {
                  std::cout << ' ';
                  // file_out << ' ';
                }
              } else {
                std::cout << last_c;
                // file_out << last_c;
              }
            }
            last_c = c;
            break;
          }
          case cScanningCommentLine: {
            break;
          }
          case cScanningCommentBlock: {
            if (last_c == '*') {
              if (c == '/') {
                std::cout << "*/";
                state = cScanningCode;
              }
            }
            break;
          }
        }
        last_c = c;
        c = *cursor++;
      }
      c = '\n';
      if (state == cScanningCommentLine) {
        std::cout << '\n';
        // file_out << '\n';
        state = cScanningCode;
      } else if (state != cScanningCommentBlock) {
        if (last_c != '/') {
          std::cout << last_c;
          // file_out << last_c;
        }
        std::cout << '\n';
        // file_out << '\n';
      }
    }
  } else {
    std::cout << "Unable to open file";
  }

  // file_out.close();
  return 0;
}

std::vector<string> FilenamesInFolder(const CHA* directory) {
  std::vector<std::string> names;
  std::string search_path = directory;
  search_path += "/*.*";
  WIN32_FIND_DATA fd;
  HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
  if (hFind != INVALID_HANDLE_VALUE) {
    do {
      // read all (real) files in current folder
      // , delete '!' read other 2 default folder . and ..
      if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        names.push_back(fd.cFileName);
      }
    } while (::FindNextFile(hFind, &fd));
    ::FindClose(hFind);
  }
  return names;
}

ISN StripComments(const CHA* directory) {
  std::vector<std::string> filenames = FilenamesInFolder(directory);
}

}  // namespace _
