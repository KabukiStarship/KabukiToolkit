/* Sloth @version 0.x
@link    https://github.com/kabuki-starship/slot.git
@file    /library/tests_main.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <stdafx.h>

#include "../../../cpputest/include/CppUTest/CommandLineTestRunner.h"
#include "../../../cpputest/include/CppUTest/TestHarness.h"

SI4 main(SI4 args_count, CH1** args) {
  Print ('+');
  for (SI4 i = 81; i > 0; --i) {
    Print ('-');
  }
  std::cout << "\n| Sloth Tests\n+";
  for (SI4 i = 81; i > 0; --i) {
    Print ('-');
  }
  Print (kLF);
  MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
  SI4 result = CommandLineTestRunner::RunAllTests(args_count, args);
  system("PAUSE");
  return result;
}

/*
HANDLE gDoneEvent;

VOID CALLBACK TimerRoutine (PVOID lpParam, BOOLEAN TimerOrWaitFired) {
    if (lpParam == NULL) {
        Printf ("TimerRoutine lpParam is NULL\n");
    }
    else
    {
        // lpParam points to the argument; in this case it is an SI4

        Printf ("Timer routine called. Parameter is %d.\n",
                *(SI4*)lpParam);
        if (TimerOrWaitFired) {
            Printf ("The wait timed out.\n");
        }
        else
        {
            Printf ("The wait event was signaled.\n");
        }
    }

    SetEvent (gDoneEvent);
}
SI4 main () {
    HANDLE hTimer = NULL;
    HANDLE hTimerQueue = NULL;
    SI4 arg = 123;

    // Use an event object to track the TimerRoutine execution
    gDoneEvent = CreateEvent (NULL, TRUE, FALSE, NULL);
    if (!gDoneEvent) {
        Printf ("CreateEvent failed (%d)\n", GetLastError ());
        return 1;
    }

    // Create the timer queue.
    hTimerQueue = CreateTimerQueue ();
    if (hTimerQueue) {
        Printf ("CreateTimerQueue failed (%d)\n", GetLastError ());
        return 2;
    }

    // Set a timer to call the timer routine in 10 seconds.
    if (!CreateTimerQueueTimer (&hTimer, hTimerQueue,
        (WAITORTIMERCALLBACK)TimerRoutine, &arg, 10000, 0, 0)) {
        Printf ("CreateTimerQueueTimer failed (%d)\n", GetLastError ());
        return 3;
    }

    // TODO: Do other useful work here

    Printf ("Call timer routine in 10 seconds...\n");

    // Wait for the timer-queue thread to complete using an event
    // object. The thread will signal the event at that time.

    if (WaitForSingleObj (gDoneEvent, INFINITE) != WAIT_OBJECT_0)
        Printf ("WaitForSingleObj failed (%d)\n", GetLastError ());

    CloseHandle (gDoneEvent);

    // Delete all timers in the timer queue.
    if (!DeleteTimerQueue (hTimerQueue))
        Printf ("DeleteTimerQueue failed (%d)\n", GetLastError ());
}
*/
