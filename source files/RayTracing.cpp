// Created by jonathan
#include "../header files/RayTracing.h"
#include <random>

/**
 * This function converts degrees to radians.
 * @param degrees a floating point number representing an angle in degrees
 * @return the angle in radians
 */
double degToRad(double degrees) {
    return degrees * pi / 180.0;
}

/**
 * This function generates a random number in [0,1).
 * @return a random number in [0,1)
 */
double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0, 1);
    static std::mt19937 generator;
    return distribution(generator);
}


/**
 * This function generates a random number in a specified interval.
 * @param min the lower bound for the random
 * @param max the upper bound for the random
 * @return a random number in [min,max)
 */
double randomDouble(double min, double max) {
    return min + (max - min) * randomDouble();
}

double clamp(double x, double min, double max) {
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}

Vec3 randomVectorInUnitSphere() {
    return Vec3(randomDouble(-1,1), randomDouble(-1,1), randomDouble(-1,1));
}

