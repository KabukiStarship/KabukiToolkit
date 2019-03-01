# Kabuki Toolkit

```AsciiArt
  /\
 ( /   @ @    ()   _  __     _           _    _   _____           _ _    _ _
  \\ __| |__  /   | |/ /__ _| |__  _   _| | _(_) |_   _|__   ___ | | | _(_) |_
   \/   "   \/    | ' // _` | '_ \| | | | |/ / |   | |/ _ \ / _ \| | |/ / | __|
  /-|       |-\   | . \ (_| | |_) | |_| |   <| |   | | (_) | (_) | |   <| | |_
 / /-\     /-\ \  |_|\_\__,_|_.__/ \__,_|_|\_\_|   |_|\___/ \___/|_|_|\_\_|\__|
  / /-`---'-\ \
   /         \                    ♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪
```

![Under Construction Image](https://github.com/kabuki-starship/kabuki_toolkit/wiki/under_construction.png)

Kabuki Toolkit (KT) is a modern embedded-C++ toolkit for making intelligent connected technologies, apps, plugins, games, servers, firmware, and art with Script2.

[![GitHub version](https://badge.fury.io/gh/kabuki-starship%2Fkabuki_toolkit.svg)](https://badge.fury.io/gh/kabuki-starship%2Fkabuki_toolkit)

## Quick Links

* [Script2 and the SCRIPT Specification](https://github.com/kabuki-starship/script2) - *Serial Chinese Room, Interprocess, and Telemetry (SCRIPT) Script (Script2) is the foundation of KT so it's the best place to start learning.*
* [Documents & FAQ](https://github.com/kabuki-starship/kabuki_toolkit.git/blob/master/docs/faq.md) - *Check out the `/docs/readme.md` for answers to Frequently asked questions and other promotional and learning materials.*
* [Kabuki Starship Website](https://kabuki-starship.github.io/)

## kabuki Modules

| Module    | Description |
|:---------:|:------------|
| toolkit   | Software Development Kit. |
| features  | System features. |
| hal       | Hardware Abstraction Layer. |
| osal      | Operating System Abstraction Layer. |
| platform  | Hardware platform. |
| tek       | Kabuki tek firmware. |

### kabuki.drivers

| Module     | Description |
|:----------:|:------------|
| ethernet   | Basic TCP support. |
| serial     | UART/Serial driver. |
| ...        | Many more drivers coming soon. |

### kabuki.features

| Module      | Description |
|:-----------:|:------------|
|    adsp     | Audio digital signal processing library. |
|  clipboard  | Copy, cut, and paste library. |
| filecabinet | Filesystem abstraction library. |
|   graphics  | Graphics library. |
|    lights   | DMX and LED lighting library. |
|     math    | Math library. |
|     midi    | Musical instrument digital interface. |
|    sound    | Sound and audio library. |
|     tls     | Transport-layer Security. |
|    touch    | Human-Machine Interface input library. |
|    webcam   | Web and video camera library. |

### kabuki.toolkit

| Module   | Description |
|:--------:|:------------|
| ai       | Artificial Intelligence library. |
| av       | Audio-visual library. |
| data     | Database library. |
| draw     | Vector drawing library. |
| gui      | Graphical user interface. |
| plot     | Plotting library. |
| orm      | Object Relational Mapping library. |
| pro      | Project library. |
| uweb     | HTTP server and web microframework. |
| video    | Video library. |
| who      | Identification and authorization library. |

## projects

| Module        | Description |
|:-------------:|:------------|
| experiments   | A project for quickly testing code. |
| script2       | Oversight project for Script2. |

### projects.kabuki

| Module        | Description |
|:-------------:|:------------|
| connect       | Contact list, trading, and chat app. |
| sloth         | Script2 package manager and code, seam tree, and seam graph refactoring utility. |
| anyled        | Universal LED controller for PWM and addressable LEDs. |
| oregon_cooler | Smart-home cooling system and automatic watering system. |
| player        | A video player app and plugin. |
| unicontroller | Universal MIDI, DMX, OSC, and Script2 controller, interprocess host, and plugin system with DSP audio effects and synthesis. |
| autopilot     | Drone autopilot. |
| igeek         | Interactive Graphical Environment for Evolving KabukiNet. |

### 3rd Party APIs

* [ANGLE](https://github.com/google/angle) - Graphics and Windowing System.
* [boost asio](https://www.boost.org/doc/libs/1_68_0/doc/html/boost_asio.html) - Asynchronous IO.
* [boost beast](https://www.boost.org/doc/libs/1_69_0/libs/beast/doc/html/index.html) - C++11 web microframework.
* [boost filesystem](https://www.boost.org/doc/libs/1_68_0/doc/html/boost_filesystem.html) - Cross-platform filesystem.
* [NanoVG](https://github.com/memononen/nanovg) - Minimalistic vector drawing toolkit.
* [NanoGUI](https://github.com/wjakob/nanogui) - Minimalistic vector GUI toolkit.
* [Assimp](https://github.com/assimp/assimp) - 3D model importer.
* [cvPlot](https://github.com/PLplot/PLplot) - Math plotting library.
* [PortAudio](http://www.portaudio.com/) - Cross-platform audio driver.
* [RtMIDI](https://github.com/thestk/rtmidi) - Cross-platform MIDI driver.
* [Eigan](http://eigen.tuxfamily.org) - Math library.
* [MLPack](https://github.com/mlpack/mlpack) - Machine learning library.
* [mbed](https://www.mbed.com/en/) - Firmware abstraction layer and real-time OS.

### Kabuki VM Seam Package Diagram

![Kabuki VM Package Diagram](https://raw.githubusercontent.com/kabuki-starship/kabuki_toolkit/master/docs/kabuki_package_diagram.jpg)

**@note** *Package Diagram uses `C++` dependency inclusion, meaning that when a module/namespace is included all of the module/namespace dependencies are also included.*

#### Kabuki VM Seams

##### 0_0 Frontal Cortex

* 0_0_00 script2
* 0_0_01 kabuki.hal
* 0_0_02 kabuki.drivers
* 0_0_03 kabuki.features.filecabinet
* 0_0_04 kabuki.toolkit.data
* 0_0_05 kabuki.toolkit.who
* 0_0_06 kabuki.toolkit.pro
* 0_0_07 kabuki.features.tls
* 0_0_08 kabuki.toolkit.uweb
* 0_0_09 kabuki.toolkit.orm
* 0_2_10 kabuki.features.midi
* 0_0_11 kabuki.features.math

##### 0_1 Somatosensory Cortex

* 0_1_00 kabuki.features.touch

##### 0_2 Auditory Cortex

* 0_2_01 kabuki.features.sound
* 0_2_02 kabuki.features.adsp
* 0_2_03 kabuki.toolkit.av

##### 0_3 Visual Cortex

* 0_3_00 kabuki.features.lights
* 0_3_01 kabuki.features.graphics
* 0_3_02 kabuki.features.camera
* 0_3_03 kabuki.features.webcam
* 0_3_04 kabuki.features.draw
* 0_3_05 kabuki.toolkit.plot
* 0_3_06 kabuki.toolkit.gui
* 0_3_07 kabuki.toolkit.video

## Vision and Mission Statement

The Vision of KT is to provide a bloat-free DLL-friendly Embedded-C++11 Virtual Machine, Firmware-to-Software Development Kit (F2SDK), dynamic functional programming environment, Jupyter Notebooks, and a real-time smartphone operating system that is the quality of Google Fuchsia, JUCE, Java, and Julia but with a commercially-permissive license that encourages contributions and discourages the community from splitting.

The Mission is minimize the code surface area of the project in order to minimize labor and make the cod more secure.

## The License

Copyright 2014-19 (C) Cale Jamison McCollough <<cale@astartup.net>>. All rights reserved (R).

This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
