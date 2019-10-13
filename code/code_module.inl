#pragma once
#include <_config.h>
#ifndef KABUKI_TOOLKIT_SLOTH_API_DECLARATIONS
#define KABUKI_TOOLKIT_SLOTH_API_DECLARATIONS

namespace _ {
class CodeModule {
  const CHA *header_,  //< The repository address.
      repo_address_,   //< The repository address.
      output_path_;    // The path to recreate the repo in.

 public:
  CodeModule();
};
}  // namespace _
#endif
