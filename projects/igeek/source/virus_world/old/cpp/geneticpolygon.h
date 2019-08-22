/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki_toolkit.git
@file    /projects/igeek/source/lib/geneticpolygon.h
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace igeek {

/* A class that represents a this that can morph through a genetic algorithm with other shapes.
 */
class GeneticPolygon: public Polygon
{
  public:
    
    static const double maxRandomPoints     = 5.00,     /< And this was for what again?
                        defaultAngle        = 0.00,     /< The default angle of orientation.
                        matingPercent       = 0.10,     /< The percent of the population that mates durring each generation.
                        minorMutationVector = 0.50,     /< Note sure if I need this or what its for because I didn't document it right.
                        majorMutationVector = 1.00,     /< The 
                        minorScalar         = 0.10,     /< The scale of minor mutations.
                        majorScalar         = 0.15,     /< The scale of major mutations.
                        minorMutation       = 0.10,     /< The probability of a minor mutation.
                        majorMutation       = 0.05,     /< The probability of a major mutation.
                        angularMutation     = 0.10;     /< The angular mutation vector.
                                                        /*< When a GP sprouts a new point, the system tries to even out
                                                            the points at equal angles. The angular mutation is the amount that
                                                            the point will move over time. */
    
    static const int defaultNumPoints = 5,              /< The default number of points for a VIrus.
                     defaultLifespan  = 30000,          /< The default life span in milliseconds.
                     defaultSize      = 50,             /< The default size in pixels.
                     minSize          = defaultSize / 2,/< The minimum size in pixels.
                     maxSize          = 2 * defaultSize;/< The maximum size of pixels.

    int lifespan,
        width,                                          /< The width  of this GP in pixels.
        height;                                         /< The height of this GP in pixels.
    
    double age,                                         /< This variable represents the age a GP in generations.
                                                        /*< Initially the age is set to the GP's life span, and is decremented. */
                   angle;                               /< The angle of this GP in radians.
    
    Color color;                                        /< The ARGB color of this GP.
    
    long numPixels;                                     /< The number of pixels in this image.
    
    BufferedImage bitmap;                               /< The bitmap rendering of this object.
    
    GeneticPolygon mother,                              /< The thisMother of this GP.
                           father,                      /< The father of this GP.
                           grandparents;                /< The grandparents of this GP.
    
    static Color getDefaultColor (int numPoints);
    
    GeneticPolygon ();
    
    GeneticPolygon (int thisNumPoints, int thisColorARGB);
    
    GeneticPolygon (int thisNumPoints, int thisWidth, int thisHeight, int thisColorARGB, int thisLifespan, double thisAngle);
    
    GeneticPolygon (GeneticPolygon thisMother, GeneticPolygon thisFather);
    
    void rebound ();
    
    void printGeometry ();
    
    void setupPoints (int numberOfPoints);
    
    bool age (int ageTime);
    
    static Color mixColors (Color motherColor, Color fatherColor);
    
    Color breedColor (Color motherColor, Color fatherColor, Color  matGrandColor, Color patGrandColor);
    
    int mutateInt (int thisValue, int mutateDirection);
    
    double mutateFloat (double thisValue, int mutateDirection);
    
    int breedInt (int motherInt, int fatherInt, int matGrandInt, int patGrandInt);
    
    bool containsGeneticPolygon (GeneticPolygon that);
    
    double breedFloat (double motherInt, double fatherInt, double matGrandInt, double patGrandInt);
    
    /*  @brief  Function that returns the BufferedImage for this this.
    
     */
    
    BufferedImage getBitmap ();
    
    int getWidth ();
    
    int getHeight ();
    
    double getAngle ();
    
    Color getColor ();
    
    long getNumPixels ();
    
    int getLifespan ();
    
    
    int getNumPoints ();
    
    
    / Function that prints out the this to a bitstream
    
    void printGenes (int[] thisStream, int currentIndex);
        
    /* @brief   Function that compares 
     */
    
    bool intersects (Polygon thatPolygon);
        
    bool intersects (GeneticPolygon thatPolygon);
    
    bool intersects (Polygon thatPolygon, double offsetX, double offsetY);
    
    bool intersects (Polygon thatPolygon, int offsetX, int offsetY);
    
    void equalizePoints ();
    
    void renderBitmap ();
    
    static double crossOver (double dominant, double recessive);
    
    void rotate ();
    
    double boundBetween0and1 (double inputValue);
    
    double randomizeDouble (double inputValue);
    
    int randomizeInt (int inputValue);
}
