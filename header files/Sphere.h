// Created by jonathan

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "IHittable.h"
#include "Vec3.h"

/**
 * This class represents a Sphere in R^3, that is hittable by rays.
 */
class Sphere : public IHittable {
private:
    Point3 m_center;
    double m_radius;
public:
    // Constructors
    Sphere();
    Sphere(Point3 center, double radius);

    // Getters
    Point3 center() const;
    double radius() const;

    // Setters
    void center(Point3 center);
    void radius(double radius);

    // Abstract class functions overriding
    bool hit(const Ray& r, double minT, double maxT, HitRecord& rec) const;
};

#endif