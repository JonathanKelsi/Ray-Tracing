// Created by jonathan
#include "../header files/RayTracing.h"
#include <random>


double degToRad(double degrees) {
    return degrees * pi / 180.0;
}

double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0, 1);
    static std::mt19937 generator;
    return distribution(generator);
}


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


Vec3 randomUnitVector() {
    auto x = randomDouble();
    auto y = randomDouble();
    auto z = randomDouble() > 0 ? sqrt(1 - x * x - y * y) : -sqrt(1 - x * x - y * y);

    return Vec3(x, y, z);
}



