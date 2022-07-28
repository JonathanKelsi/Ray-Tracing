// Created by jonathan

#ifndef CAMERA_H
#define CAMERA_H

#include "RayTracing.h"

class Camera {
private:
    Point3 m_origin;
    Point3 m_lowerLeftCorner;
    Vec3 m_horizontal;
    Vec3 m_vertical;
public:
    /**
    * Constructor.
    */
    Camera();

    /**
     * Given two values, representing lengths of offset vectors parallel to the screen's sides,
     * this function returns the camera's ray's location.
     * @param u first offset vector length
     * @param v second offset vector length
     * @return the location of the ray
     */
    Ray getRay(double u, double v);
};

#endif
