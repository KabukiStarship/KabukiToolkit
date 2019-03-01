# kabuki.drivers

Kabuki Toolkit breaks up boost::asio into two portions, based on the organization of mbed, a hardware abstraction layer and drivers to work on the Hardware Abstraction Layer (HAL).

# Development Strategy

1. Convert boost::asio to kabuki.hal and kabuki.drivers half by hand and half using projects.kabuki.sloth.
1. Repeat the prior step using a fully-automated #Sloth script.
1. Convert boost::filesystem to kabuki.features.filecabinet half by hand and half using projects.kabuki.sloth.
1. Repeat the prior step using a fully-automated #Sloth script.

# The License

Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>; All right reserved (R).

This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/. */
