/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /tek/tek_porttcp.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "c_portaltcb.h"

namespace _ {

PortalTCP::PortalTCP(Expr* expr) : expr_(expr) {
  // Nothing to do here!
}

void PortalTCP::Feed() {
  // while (serial.readable ()) expr_.StreamTxByte ();
}

void PortalTCP::Pull() {
  /*
// Bring up the Ethernet interface
printf ("Ethernet socket example\n");
net.connect ();

// Show the network address
const CH1 *ip = net.get_ip_address ();
printf ("IP address is: %s\n", ip?ip:"No IP");

// Open a socket on the network interface, and create a TCP connection to
// mbed.org
TCPSocket socket;
socket.open (&net);
socket.connect ("developer.mbed.org", 80);

// Send a simple http request
CH1 sbuffer[] = "GET / HTTP/1.1\r\nHost: developer.mbed.org\r\n\r\n";
SI4 scount = socket.send (sbuffer, sizeof sbuffer);
printf ("sent %d [%.*s]\n", scount, strstr (sbuffer, "\r\n") - sbuffer,
      sbuffer);

// Receive a simple http response and print out the response line
CH1 rbuffer[64];
SI4 rcount = socket.recv (rbuffer, sizeof rbuffer);
printf ("recv %d [%.*s]\n", rcount, strstr (rbuffer, "\r\n") - rbuffer,
      rbuffer);

// Close the socket to return its memory and bring down the network
// interface
socket.close ();

// Bring down the Ethernet interface
net.disconnect ();
printf ("Done\n"); */
}

}  // namespace _
