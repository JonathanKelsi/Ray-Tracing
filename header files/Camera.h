// Created by jonathan

#ifndef CAMERA_H
#define CAMERA_H

#include "RayTracing.h"

class Camera {
private:
    Point3 origin;
    Point3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;
public:
    // Constructor
    Camera();

    // member functions
    Ray getRay(double u, double v);
};

#endif
