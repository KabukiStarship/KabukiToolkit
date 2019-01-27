/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/features/pro/cschedule.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-19 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TOOLKIT_PRO_1
#ifndef HEADER_FOR_KT_PRO_SCHEDULE
#define HEADER_FOR_KT_PRO_SCHEDULE

#include "ctask.h"

namespace _ {

/* A group of Task(string) in temporal order that may repeat.
A Schedule contains a collection of Task objects. It has a starting date,
and it can repeat x number of times. Multiple Schedule(string) can be
combined to create a Calendar. Schedules are designed to minimize the human
time to insert and manipulate the calendar.

The average person will have no more than a handful of Tasks on any given
day. Given 100 years in a life and 365 days in a year, 5*100*365 < 200K
Tasks in a normal person's lifetime. Maybe 1M Task(string) tops per
lifetime.

Where does the Calendar live?
The calendar lives in the cloud in an SQL database.

How is it loaded?
It is loaded chunks at a time.

What happens when you make edits?
The local object is edited, changes staged, and edit's to only single
tasks are written to the server.

What about colliding events?
Colliding events are stored in a linear lined list of collisions.

When does speed matter?
When the users has to sit there. When would this happen? Using a very
large array and inserting into it. That could be a buzz kill. Other than
that, optimize for developer time. Memory footprint doesn't matter.

*/
class Schedule {
 public:
  /* Default constructor creates a schedule with the default number of Tasks
      pointers. */
  Schedule(const CH1* key = "", SI4 num_repeats = 0, SI4 color = ~0);

  /* Destructs the dynamic memory. */
  ~Schedule();

  /* Gets the name. */
  const CH1* GetKey();

  /* Set the name to the new_name. */
  void StealKey(CH1* new_name);

  /* Sets the name to the new name. */
  void SetKey(const CH1* new_name);

  /* Gets the readme. */
  const CH1* GetReadme();

  /* Set the name to the new_readme. */
  void StealReadMe(CH1* new_readme);

  /* Sets the name to the new name.
      @param new_readme A CH1 this object now owns the memory.  */
  void SetReadMe(const CH1* new_readme);

  /* Gets the default schedule color of the child-tasks. */
  SI4 GetColor();

  /* Sets the default schedule color. */
  void SetColor(SI4 new_color);

  /* Add's a new Task to the schedule. */
  void Add(Task* task);

  /* Removes and deletes the Task at the given index.
      @param  index The index to remove.
      @return Returns false if the index is out of bounds. */
  BOL Remove(SI4 index);

  /* Searches for an event with the given time and creates one if it doesn't
      exist.
      @return Returns a pointer to an Event that starts at the given time, and
               a new  Task if no containing Event(string) match the event_time.
   */
  Task* Find(Tss event_time);

  /* Gets the help menu. */
  static const CH1* GetHelpString();

  /* Prints the Schedule to the console. */
  void Out(SI4 indentation = 0);

  /* Parse CH1 input, possibly from the keyboard.
      @param input The (possibly keyboard) input from the user.
      @param stack The stack of Project objects.
      @return Returns null upon success and an error CH1 upon failure. */
  const CH1* Command(CH1* input);

 private:
  CH1 *key_,              //< Name of the schedule.
      *readme_;            //< Readme for the Schedule.
  SI4 color_,              //< Initial color of all of the Tasks.
      num_repeats_;        //< Number of times the Schedule repeats.
  TArray<Task*> tasks_;  //< Array of Task pointers.
};
}       //< namespace _
#endif  //< HEADER_FOR_KT_PRO_SCHEDULE
#endif  //< #if SEAM >= SEAM_00_03_00_00__00
