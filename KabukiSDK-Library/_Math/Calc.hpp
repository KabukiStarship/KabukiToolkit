/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_Math/Calc.hpp
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

#include <KabukiSDK-Config.hpp>
#include <FreeI2P.hpp>

namespace _Math {

static const float  Pi_f = 3.14159265358979f;
/*< Pi as float. */

static const double Pi_d = 3.141592653589793238463;
/*< Pi as double. */

__Inline float AbsValue  (float a);
/*< Gets the absolute Value of a float Value. */

__Inline double AbsValue  (double a);
/*< Gets the absolute Value of the value. */
    
__Inline int AbsValue  (int a);
/*< Gets the absolute Value of an int Value. */
    
__Inline long AbsValue  (long a);
/*< Gets the absolute Value of a long Value. */
    
__Inline float ACos  (float a);
/*< Gets the arc cosine of a Value; the returned angle is in the range 0.0 through pi. */
    
__Inline double ACos  (double a);
/*< Gets the arc cosine of a Value; the returned angle is in the range 0.0 through pi. */
    
__Inline float ASin  (float a);
/*< Gets the arc sine of a Value; the returned angle is in the range -pi/2 through pi/2. */
    
__Inline double ASin  (double a);
/*< Gets the arc sine of a Value; the returned angle is in the range -pi/2 through pi/2. */

__Inline float ATan  (float a);
/*< Gets the arc tangent of a Value; the returned angle is in the range -pi/2 through pi/2. */

__Inline double ATan  (double a);
/*< Gets the arc tangent of a Value; the returned angle is in the range -pi/2 through pi/2. */
    
__Inline float ATan2  (float y, float x);
/*< Gets the angle theta from the conversion of rectangular coordinates  (x, y) to polar coordinates  (r, theta). */
    
__Inline double ATan2  (double y, double x);
/*< Gets the angle theta from the conversion of rectangular coordinates  (x, y) to polar coordinates  (r, theta). */
    
__Inline float Ceiling  (float a);
/*< Gets the smallest  (closest to negative infinity) double Value that is greater than or equal to the argument and is equal to a mathematical integer. */
    
__Inline double Ceiling  (double a);
/*< Gets the smallest  (closest to negative infinity) double Value that is greater than or equal to the argument and is equal to a mathematical integer. */
    
__Inline float CopySign  (float magnitude, float sign);
/*< Gets the first floating-point argument with the sign of the second floating-point argument. */
    
__Inline double CopySign  (double magnitude, double sign);
/*< Gets the first floating-point argument with the sign of the second floating-point argument. */
    
__Inline float Cos  (float a);
/*< Gets the trigonometric cosine of an angle. */
    
__Inline double Cos  (double a);
/*< Gets the trigonometric cosine of an angle. */
    
__Inline float HCos  (float x);
/*< Gets the hyperbolic cosine of the value. */
    
__Inline double HCos  (double x);
/*< Gets the hyperbolic cosine of the value. */

__Inline float eToTheX  (float a);
/*< Gets Euler's number e raised to the power of the value. */

__Inline double eToTheX  (double a);
/*< Gets Euler's number e raised to the power of the value. */

__Inline float OneMinusEToTheX  (float x);
/*< Gets ex -1. */

__Inline double OneMinusEToTheX  (double x);
/*< Gets ex -1. */

__Inline float Floor  (float a);
/*< Gets the largest  (closest to positive infinity) double Value that is less than or equal to the argument and is equal to a mathematical integer. */

__Inline double Floor  (double a);
/*< Gets the largest  (closest to positive infinity) double Value that is less than or equal to the argument and is equal to a mathematical integer. */

__Inline int Exponent  (float d);
/*< Gets the unbiased exponent used in the representation of a float. */

__Inline int Exponent  (double d);
/*< Gets the unbiased exponent used in the representation of a double. */

__Inline float Hypot  (float x, float y);
/*< Gets SquareROot (x2 +y2) without intermediate overflow or underflow. */

__Inline double Hypot  (double x, double y);
/*< Gets SquareRoot (x2 +y2) without intermediate overflow or underflow. */

__Inline float IEEEremainder  (float f1, float f2);
/*< Computes the remainder operation on two arguments as prescribed by the IEEE 754 standard. */

__Inline double IEEEremainder  (double f1, double f2);
/*< Computes the remainder operation on two arguments as prescribed by the IEEE 754 standard. */

__Inline float Ln  (float a);
/*< Gets the natural logarithm  (base e) of the value. */

__Inline double Ln  (double a);
/*< Gets the natural logarithm  (base e) of the value. */

__Inline float Log  (float a);
/*< Gets the base 10 logarithm of the value. */

__Inline double Log  (double a);
/*< Gets the base 10 logarithm of the value. */

__Inline float LogXPlus1  (float x);
/*< Gets the natural logarithm of the sum of the argument and 1. */

__Inline double LogXPlus1  (double x);
/*< Gets the natural logarithm of the sum of the argument and 1. */

__Inline float Max  (float a, float b);
/*< Gets the greater of two float Values. */

__Inline double Max  (double a, double b);
/*< Gets the greater of two double Values. */

__Inline int Max  (int a, int b);
/*< Gets the greater of two int Values. */

__Inline long Max  (long a, long b);
/*< Gets the greater of two long Values. */

__Inline float Min  (float a, float b);
/*< Gets the smaller of two float Values. */

__Inline double Min  (double a, double b);
/*< Gets the smaller of two double Values. */

__Inline int Min  (int a, int b);
/*< Gets the smaller of two int Values. */

__Inline long Min  (long a, long b);
/*< Gets the smaller of two long Values. */

__Inline float NextAfter  (float start, float direction);
/*< Gets the floating-point number adjacent to the first argument in the direction of the second argument. */

__Inline double NextAfter  (double start, double direction);
/*< Gets the floating-point number adjacent to the first argument in the direction of the second argument. */

__Inline float NextUp  (float f);
/*<  Gets the floating-point Value adjacent to f in the direction of positive infinity. */

__Inline double NextUp  (double d);
/*< Gets the floating-point Value adjacent to d in the direction of positive infinity. */

__Inline float Power  (float a, float b);
/*< Gets the Value of the first argument raised to the power of the second argument. */

__Inline double Power  (double a, double b);
/*< Gets the Value of the first argument raised to the power of the second argument. */

__Inline float Random_f ();
/*< Gets the value with a positive sign, greater than or equal to 0.0 and less than 1.0. */

__Inline double Random_d ();
/*< Gets the value with a positive sign, greater than or equal to 0.0 and less than 1.0. */

__Inline float Round  (float a);
/*< Gets the float Value that is closest in Value to the argument and is equal to a mathematical integer. */

__Inline double Round  (double a);
/*< Gets the double Value that is closest in Value to the argument and is equal to a mathematical integer. */

__Inline int RoundToInt  (float a);
/*< Gets the closest int to the argument, with ties Rounding up. */

__Inline long RoundToInt  (double a);
/*< Gets the closest long to the argument, with ties Rounding up. */

__Inline float ScaleB  (float d, int scaleFactor);
/*< Return d × 2scaleFactor Rounded as if performed by a single correctly Rounded floating-point multiply to a member of the double Value set. */

__Inline double ScaleB  (double d, int scaleFactor);
/*< Return d × 2scaleFactor Rounded as if performed by a single correctly Rounded floating-point multiply to a member of the double Value set. */

__Inline float FScaleFactor  (float f, int scaleFactor);
/** Return f × 2scaleFactor.
    Rounded as if performed by a single correctly Rounded floating-point multiply to a member of the float Value set. */

__Inline double FScaleFactor  (double f, int scaleFactor);
/** Return f × 2scaleFactor.
    Rounded as if performed by a single correctly Rounded floating-point multiply to a member of the float Value set. */

__Inline float SignOf  (float f);
/** Gets the signum function of the argument
    @return 0.0 if the argument is 0.0, 1.0 if the argument is greater than 0, -1.0 if the argument is less than zero. */

__Inline double SignOf  (double d);
/*< Gets the signum function of the argument; zero if the argument is zero, 1.0 if the argument is greater than zero, -1.0 if the argument is less than zero. */
    
__Inline float Sin  (float a);
/*< Gets the trigonometric sine of an angle. */
    
__Inline double Sin  (double a);
/*< Gets the trigonometric sine of an angle. */
    
__Inline float HSin  (float x);
/*< Gets the hyperbolic sine of the value. */
    
__Inline double HSin  (double x);
/*< Gets the hyperbolic sine of the value. */

__Inline float SquareRoot  (float a);
/*< Gets the correctly Rounded positive square root of the value. */

__Inline double SquareRoot  (double a);
/*< Gets the correctly Rounded positive square root of the value. */
    
__Inline float CubeRoot  (float a);
/*< Gets the cube root of the value. */
    
__Inline double CubeRoot  (double a);
/*< Gets the cube root of the value. */
    
__Inline float Tan  (float a);
/*< Gets the trigonometric tangent of an angle. */
    
__Inline double Tan  (double a);
/*< Gets the trigonometric tangent of an angle. */
    
__Inline float HTan  (float x);
/*< Gets the hyperbolic tangent of the value. */
    
__Inline double HTan  (double x);
/*< Gets the hyperbolic tangent of the value. */

__Inline float ToDegrees  (float angrad);
/*< Converts an angle measured in radians to an approximately equivalent angle measured in degrees. */

__Inline double ToDegrees  (double angrad);
/*< Converts an angle measured in radians to an approximately equivalent angle measured in degrees. */

__Inline float ToRadians  (float angle);
/*< Converts an angle measured in degrees to an approximately equivalent angle measured in radians. */

__Inline double ToRadians  (double angle);
/*< Converts an angle measured in degrees to an approximately equivalent angle measured in radians. */

__Inline float ULP  (float f);
/*< Gets the size of an ulp of the argument. */
    
__Inline double ULP  (double d);
/*< Gets the size of an ulp of the argument. */

__Inline float Factoral  (float thisNumber);
/*< Method calculates the factorial of thisNumber */

__Inline double Factoral  (double thisNumber);
/*< Method calculates the factorial of thisNumber */

__Inline int Factoral  (int thisNumber);
/*< Method calculates the factorial of thisNumber */

__Inline long Factoral  (long thisNumber);
/*< Method calculates the factorial of thisNumber */

__Inline int GetNextPrime (int thisNumber);
/*< Gets the next prime number at or after thisNumber.
    @param thisNumber The number find.
    @return Gets thisNumber if thisNumber is prime.
    @return Gets the next prime number after thisNumber if it is not prime.
    @return Gets 0 if thisNumber is greater then the biggest prime number in the Numbers array.
*/

class _KabukiSDK Calc: public I2P::Object
/*< An Inter-process calculator for doing math on distributed systems.
    
*/
{
    public:
    
    Calc ();
    /*< Constructs a calculator. */

    virtual const char* Do (I2P::Terminal& Slot, int Index, int Enq);
    /*< Inter-process subroutines. */

    inline void Print (I2P::Terminal& Slot);
    /*< Prints this object to the terminal. */
};

}   //  namespace _Math
