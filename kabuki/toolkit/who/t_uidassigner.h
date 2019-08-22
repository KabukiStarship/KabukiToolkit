/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki_toolkit/who/t_uidassigner.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_WHO_1
#ifndef KABUKI_TOOLKIT_WHO_UIDSERVER
#define KABUKI_TOOLKIT_WHO_UIDSERVER


namespace _ {

/* A uid server that can save and load the uid from a file.
Unique ids are indexed using only positive integers. 0 is hence used to
flag when the server doesn't contain a uid. */
template <typename T = UID>
class TUIDAssigner {
 public:
  enum { kInvalidUid = 0 };

  /* Constructs object by setting next_id_ to init_uid and copying the
      filename AString. */
  TUIDAssigner(T init_uid = 1, const TStrand<>& filename = "uid")
      : uid_count_((init_uid == kInvalidUid) ? kInvalidUid + 1 : init_uid),
        filename_(StrandClone(filename)) {
    //                      +---E  +----<||
    // Nothing to do here ({:->)-|------|
    //                           +---E  +----<||
  }

  /* Peeks at the next uid with incrementing it. */
  T PeekNextUid() { return uid_count_; }

  /* Gets the next uid. */
  T UIDCount() {
    if (uid_count_ == kInvalidUid) return kInvalidUid + 1;
    return uid_count_++;
  }

  const TStrand<>& Save() {
    ofstream file;
    file.open(filename);
    file << uid_;
    file.close();
  }

  const TStrand<>& Load() {
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
  T uid_count_;            //< Next unique id.
  const TStrand<>& filename_;  //< Filename to write uid too.
};                        //< class UidServer
}       // namespace _
#endif  //< KABUKI_TOOLKIT_WHO_UIDSERVER
#endif  //< #if SEAM >= KABUKI_TOOLKIT_WHO_1
