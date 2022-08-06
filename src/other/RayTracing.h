#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <cmath>
#include <limits>
#include <memory>
#include "../material/Material.h"

// Common headers
#include "../rays/Ray.h"
#include "../rays/Vec3.h"

const double pi = 3.1415926535897932385;
const double inf = std::numeric_limits<double>::infinity();

/**
 * This function converts degrees to radians.
 * @param degrees a floating point number representing an angle in degrees
 * @return the angle in radians
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
