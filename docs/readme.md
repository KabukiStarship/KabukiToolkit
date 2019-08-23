# Kabuki Toolkit Documentation

## Docs

Please **@see** `~/kabuki_toolkit.mdj` using [StarUML](https://staruml.io) for object models. Documents are split between the Wiki and the `~/docs/` folder and additional documents can be found in the [script2 repo](https://github.com/kabuki-starship/script2). 

* [Script Specification RFC](https://github.com/kabuki-starship/script2) - Serial Chinese Room, Interprocess, and Telemetry (SCRIPT) Specification Release for Comment and SCRIPT Script (Script2).
* [ASCII C++ Style Guide](https://github.com/ascii_cpp_style_guide) - A combination of the Google C++ Style Guide and the ASCII Data Specification in Markdown format.
* [Frequently Asked Questions](#faq) - The best place the start.
* [Quick Start Guide](#quick-start-guide) - The second best place the start.
* [Contributing] (./CONTRIBUTING.md]
* Templates
  * [Bug Report Template](./BUG_REPORT_TEMPLATE.md)
  * [Feature Request Template](./FEATURE_REQUST_TEMPLATE.md)
  * [Issue Template](./ISSUE_TEMPLATE.md)
  * Pull Request Template](./PULL_REQUEST_TEMPLATE.md)

## Frequently Asked Questions

```AsciiArt
__/\\\\\\\\\\\\\\\_____/\\\\\\\\\___________/\\\_______
 _\/\\\///////////____/\\\\\\\\\\\\\______/\\\\/\\\\____
  _\/\\\______________/\\\/////////\\\___/\\\//\////\\\__
   _\/\\\\\\\\\\\_____\/\\\_______\/\\\__/\\\______\//\\\_
    _\/\\\///////______\/\\\\\\\\\\\\\\\_\//\\\______/\\\__
     _\/\\\_____________\/\\\/////////\\\__\///\\\\/\\\\/___
      _\/\\\_____________\/\\\_______\/\\\____\////\\\//_____  
       _\/\\\_____________\/\\\_______\/\\\_______\///\\\\\\__
        _\///______________\///________\///__________\//////___
```

The Doxyfile is used to create the [Kabuki Starship API Docs](https://kabuki-starship.github.io/api/). You may build these yourself for offline viewing. The UML diagrams can be found in the "Kabuki Toolkit Diagrams.mdj" file.

---

* Where should I start?
  * The best place to start is with the [Quickstart Guide](#quick-start-guide).

---

* How do I get started as a developer?
  * The best way to get started as a developer is to go through and clean up the code. This SDK was created from a hodgepodge of various open-source commercial-friendly BSD-style licensed software. There is still a lot of mess to clean up from the integration process. Whatever questions you have other people will no doubt ask as well. Please add these questions to this FAQ and to relevant example projects and API docs.

---

* What is the documentation and documentation process?
  * This SDK uses [Doxygen](https://www.stack.nl/~dimitri/doxygen/). The project is currently setup using D:\Workpace. API docs get exported to the [Kabuki Theater website].

---

* Why does the website look all messed up?
  * The [Kabuki Toolkit website](https://kabuki.github.io/) needs to get fixed ASAP. The CSS is messed up in full-screen mode, but works right in less than about 1024 pixel widths. It's something about the @media section in the CSS.

---

* What is the style guide?
  * The [ASCII C++ Style Guide](https://github.com/kabuki-starship/ascii_cpp_style_guide), which is based on the Google C++ Style Guide and the ASCII Data Specification.

---

* Is there any UML?
  * We're using [StarUML 2.x](https://staruml.io/). The models can be found in the file "~/Documents/Kabuki Starship.mdj". Most of the included modules were not documented correctly and will need to be back annotated. This is a back burner project and is only done when needed. Please feel free to help us write use cases and scenario.

---

## Quick Start Guide

```AsciiArt
________       _____      ______            _____              _____
___  __ \___  ____(_)________  /__   _________  /______ _________  /_
__  / / /  / / /_  /_  ___/_  //_/   __  ___/  __/  __ `/_  ___/  __/
 / /_/ // /_/ /_  / / /__ _  ,<      _(__  )/ /_ / /_/ /_  /   / /_
 \___\_\\__,_/ /_/  \___/ /_/|_|     /____/ \__/ \__,_/ /_/    \__/
```

**1.** Clone the kabuki_toolkit and script2 repos into your workspace or project 3rd-party dependencies directory:

```Console
git clone https://github.com/kabuki-starship/kabuki_toolkit.git
cd kabuki_toolkit
git clone https://github.com/kabuki-starship/script2.git
```

**2.** Open the `kabuki_toolkit.sln` Visual Studio Project.

**3.** Start by looking in the `0_0_00.experiments` project. Open the `global_config.inl` and look at the typedef(s) and seam macros, then set the seam number in the `pch.h` file to one in the `global_config.inl`. Then look through the `test_debug.inl` and `test_release.inl`, the look through the seam tree tests in the files that start with numbers and see how the tests tree builds seams layer by layer.

**4.** In order to save the stack debug data when an DASSERT occurs, set breakpoint in the file `script2_test.cc` at the return line for:

```C++
BOL TestWarn(const CH1* function, const CH1* file, SI4 line);
```

## License

Copyright (C) 2014-9 [Cale McCollough](https://calemccollough.github.io); all right reserved (R).

This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0/>.
