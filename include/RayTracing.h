// Created by jonathan

#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <cmath>
#include <limits>
#include <memory>
#include "Material.h"

// Common headers
#include "Ray.h"
#include "Vec3.h"

/**
 * This function converts degrees to radians.
 * @param degrees a floating point number representing an angle in degrees
 * @return the angle in radians
 */
const double inf = std::numeric_limits<double>::infinity();


/**
 * This function generates a random number in [0,1).
 * @return a random number in [0,1)
 */
const double pi = 3.1415926535897932385;

/**
 * This function generates a random number in a specified interval.
 * @param min the lower bound for the random
 * @param max the upper bound for the random
 * @return a random number in [min,max)
 */
double degToRad(double degrees);

/**
 * @return a random real number in [0,1)
 */
double randomDouble();

/**
 * @return a random real number in [min,max)
 */
double randomDouble(double min, double max);

/**
 * @param x a value
 * @param min a lower bound
 * @param max an upper bound
 * @return the given value clamped between the bounds
 */
double clamp(double x, double min, double max);

/**
 * @return a random unit vector
 */
Vec3 randomUnitVector();

#endif
