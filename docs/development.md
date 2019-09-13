# Development

```AsciiArt
     ____           __
    /  /::\        /  /\          __
   /  /:/\:\      /  /:/_        /__/\
  /  /:/  \:\    /  /:/ /\       \  \:\  
 /__/:/ \__\:|  /  /:/ /:/_       \  \:\
 \  \:\ /  /:/ /__/:/ /:/ /\  __  \__\:\
  \  \:\  /:/  \  \:\/:/ /:/ /__/\ |  |:|
   \  \:\/:/    \  \::/ /:/  \  \:\|  |:|
    \  \::/      \  \:\/:/    \  \:\__|:|
     \__\/        \  \::/      \__\::::/
                   \__\/           ~~~~  
```

If you would like to contribute as a developer, way to follow along with development is by viewing the issue commits. Each commit should have a short issue description and #issue_number (@see git commit log). By clicking on the #issue_number it will take you to the issue where the work should be described with some level of detail.

## clang-format

In order to prevent valuable wasted programming hours on formatting, it is required that you run clang-format when you save each C++ source file. For Visual Studio users you will need to install Clang PowerTools or clang-format extensions and set them up to auto-format on save. We're trying to  get a clang-refactor script going to convert all of the code to Google C++  Style Guide.

### Steps

**1.** Fork KT on Github and create an Issue Ticket in the main repo similar to the following:

**Issue Title:** GitHubProject.ModuleTag.Add feature XYZ.

**2.** Create a branch:

```Console
git checkout -b Issue123
```

**3.** Bring the issue to completion with a passing unit test then commit it to your fork:

```Console
git pull origin master
git add --all
git push origin Issue123
```

**4.** Create a Pull Request.

### Updating the HTML API Documentation

**1.** Clone the Kabuki Starship website:

```Console
git clone https://github.com/kabuki-starship/kabuki-starship.github.io.git
```

**2.** Create an issue ticket for to update the API docs:

**Issue Ticket Title:** Update API Reference for kabuki_toolkit.

**Issue Ticket Body:** *Blank*

**3.** Create a branch for the issue.

```Console
git checkout -b Issue123
```

**4.** Open the `/docs/Doxyfile` configuration file in Doxygen and export to the `kabuki-starship.github.io/kt/api` folder.

**5.** Push the changes out to your repo.

```Console
git pull origin master
git add --all
git push origin Issue123
```

**6.** Create a pull request on GitHub.

## License

Copyright 2014-9 (C) [Cale McCollough](https://calemccollough.github.io); all rights reserved (R).

This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0/>.
