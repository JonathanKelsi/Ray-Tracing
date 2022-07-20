// Created by jonathan

#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <cmath>
#include <limits>
#include <memory>

// Common headers
#include "Ray.h"
#include "Vec3.h"

// Constants
const double inf = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions
double degToRad(double degrees);
double randomDouble();
double randomDouble(double min, double max);
double clamp(double x, double min, double max);
Vec3 randomVectorInUnitSphere();

#endif
