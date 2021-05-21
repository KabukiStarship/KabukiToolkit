/* Kabuki Toolkit @version 0.x
@link    https://github.com/KabukiStarship/KT.git
@file    /Who/UIDAssigner.hpp
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-20 Cale McCollough; all right reserved (R).
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can
obtain one at https://mozilla.org/MPL/2.0/. */
#pragma once
#ifndef KABUKI_TOOLKIT_WHO_UIDSERVER
#define KABUKI_TOOLKIT_WHO_UIDSERVER
#include <_Config.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_CORE
namespace _ {

/* A uid server that can save and load the uid from a file.
Unique ids are indexed using only positive integers. 0 is hence used to
flag when the server doesn't contain a uid. */
template <typename T = IUD>
class TUIDAssigner {
 public:
  enum { cInvalidUid = 0 };

  /* Constructs object by setting next_id_ to init_uid and copying the
      filename AString. */
  TUIDAssigner(T init_uid = 1, const TString<>& filename = "uid")
      : uid_count_((init_uid == cInvalidUid) ? cInvalidUid + 1 : init_uid),
        filename_(StringClone(filename)) {
    //                      +---E  +----<||
    // Nothing to do here ({:->)-|------|
    //                           +---E  +----<||
  }

  /* Peeks at the next uid with incrementing it. */
  T PeekNextUid() { return uid_count_; }

  /* Gets the next uid. */
  T UIDCount() {
    if (uid_count_ == cInvalidUid) return cInvalidUid + 1;
    return uid_count_++;
  }

  const TString<>& Save() {
    ofstream file;
    file.open(filename);
    file << uid_;
    file.close();
  }

  const TString<>& Load() {
    ifstream file(fileanme);
    if (file.is_open()) {
      file << while (getline(file, line)) { cout << line << kLF; }
      file.close();
    } else {
      cout << "Unable to open file";
    }

    return 0;
  }

 private:
  T uid_count_;                //< Next unique id.
  const TString<>& filename_;  //< Filename to write uid too.
};                             //< class UidServer
}  // namespace _
#endif
#endif
