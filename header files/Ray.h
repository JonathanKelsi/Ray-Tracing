// Created by jonathan

#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

/**
 * This class represents a ray.
 */
class Ray {
private:
    Point3 m_origin;
    Vec3 m_direction;
public:
    // Constructors
    Ray();
    Ray(const Point3& origin, const Vec3& direction);

    // Getters
    Point3 origin() const;
    Vec3 direction() const;

    // Setters
    void origin(Point3 origin);
    void direction(Vec3 direction);

    // Other member functions
    Point3 at(double t) const;
};

#endif
