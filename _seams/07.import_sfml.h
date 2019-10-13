/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki.toolkit.git
@file    /_seams/00.test.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright 2019 (C) Kabuki Starship <kabukistarship.com>; all rights 
reserved (R). This Source Code Form is subject to the terms of the Mozilla 
Public License, v. 2.0. If a copy of the MPL was not distributed with this file,
You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_config.h>

#if SEAM >= KABUKI_DOWNLOAD_SFML
#include "../code/code_module.h"
using namespace _;
#if SEAM == KABUKI_DOWNLOAD_SFML
#include "_debug.inl"
#else
#include "_release.inl"
#endif
#endif

namespace kabuki {
namespace toolkit {
inline const CHA* DownloadSFML(const CHA* args) {
#if SEAM >= KABUKI_DOWNLOAD_SFML
  TEST_BEGIN;

  static const CHA* kHeader = "";

  CodeModule module("https://github.com/SFML/SFML.git", kHeader,
                    "C:/workspace/kabuki-starship/kabuki.toolkit/_seams/bin");
  module.Clone();
  module.RepoAddressSet("https://github.com/kabuki-starship/kabuki.vm.git");
  module.Import();

#if DEBUG_THIS
  module.COut();
#endif
  return 0;
}
}  // namespace toolkit
}  // namespace kabuki
