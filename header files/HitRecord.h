// Created by jonathan

#ifndef HITRECORD_H
#define HITRECORD_H

#include "Vec3.h"
#include "Ray.h"

/**
 * This class saves the data of an intersection of an 'IHittable' with a ray.
 */
class HitRecord {
private:
    Point3 m_p;
    Vec3 m_normal;
    double m_t;
    bool m_frontFace;
public:
    // Constructor
    HitRecord();
    HitRecord(Point3 p, Vec3 normal, double t, bool frontFace);

    // Getters
    Point3 point() const;
    Vec3 normal() const;
    double t() const;
    bool frontFace() const;

    // Setters
    void point(Point3 point);
    void normal(Vec3 normal);
    void t(double t);
    void frontFace(bool frontFace);

    // Other member functions
    void setFaceNormal(const Ray& r, const Vec3& outwardNormal);
};

#endif
