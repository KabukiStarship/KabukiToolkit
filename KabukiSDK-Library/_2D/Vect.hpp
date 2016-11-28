/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_2D/Vect.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright  (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved  (R).

        Licensed under the Apache License, Version 2.0  (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#pragma once

#include <FreeI2P.hpp>
#include <KabukiSDK-Config.hpp>

namespace _2D {

struct _KabukiSDK Vect_i
/*< A 2D vector represented as int. */
{
    int X,          //< The x position.
        Y;          //< The y position.

    Vect_i ();
    /*< Constructs an uninitialized vector. */

    Vect_i  (int InitX = 0, int InitY = 0);
    /*< Default constructor initializes with given component. */

    int GetX ();
    /*< Gets the X component. */

    int GetY ();
    /*< Gets the Y component. */

    void SetX (int Value);
    /*< Sets the X component to the new Value. */

    void SetY (int Value);
    /*< Sets the Y component to the new Value. */

    void Set (int NewX = 0, int NewY = 0);
    /*< Sets the X and Y components to the new Values. */

    void Set (const Vect_i& V);
    /*< Sets the X and Y components to the this Vect_i's X and Y. */

    bool Equals (const Vect_i& V) const;
    /*< Compares this object's Vect_i to a and returns true if the two Positions are identical. */

    void Swap (Vect_i V);
    /*< Swaps this object's Vect_i with thiscomponent. */

    bool operator== (const Vect_i& P) const;
    /** C== Operator== overloader. */

    bool operator!= (const Vect_i& P) const;
    /** C== Operator!= overloader. */

    Vect_i operator- (const Vect_i& P) const;
    /** C== Operator- overloader. */

    Vect_i operator+ (const Vect_i& P) const;
    /** C== Operator+ overloader. */

    Vect_i& operator-= (const Vect_i& P);
    /** C== Operator-= overloader. */

    Vect_i& operator+= (const Vect_i& P);
    /** C== Operator+= overloader. */
};

struct _KabukiSDK Vect_f
/*< A 2D vector represented as float. */
{
    float X,        //< The x position.
        Y;          //< The y position.

    Vect_f ();
    /*< Constructs an uninitialized vector. */

    Vect_f (float InitX = 0.0f, float InitY = 0.0f);
    /*< Default constructor initializes with given component. */

    float GetX ();
    /*< Gets the X component. */

    float GetY ();
    /*< Gets the Y component. */

    void SetX (float Value);
    /*< Sets the X component to the new Value. */

    void SetY (float Value);
    /*< Sets the Y component to the new Value. */

    void Set (float NewX = 0.0f, float NewY = 0.0f);
    /*< Sets the X and Y Values to the new Values. */

    void Set (const Vect_f& V);
    /*< Sets the X and Y Values to the this Vect_f's X and Y. */

    bool Equals (const Vect_f& V) const;
    /*< Compares this object's Vect_f to a and returns true if the two Positions are identical. */

    void Swap (Vect_f V);
    /*< Swaps this object's Vect_f with thiscomponent. */

    bool operator== (const Vect_f& P) const;
    /** C== Operator== overloader. */

    bool operator!= (const Vect_f& P) const;
    /** C== Operator!= overloader. */

    Vect_f operator- (const Vect_f& P) const;
    /** C== Operator- overloader. */

    Vect_f operator+ (const Vect_f& P) const;
    /** C== Operator+ overloader. */

    Vect_f& operator-= (const Vect_f& P);
    /** C== Operator-= overloader. */

    Vect_f& operator+= (const Vect_f& P);
    /** C== Operator+= overloader. */
};

}   //< namespace _2D
