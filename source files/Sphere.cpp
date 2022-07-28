// Created by jonathan

#include "../header files/Sphere.h"
#include <cmath>

Sphere::Sphere() {}

Sphere::Sphere(Point3 center, double radius, std::shared_ptr<Material> materialPtr) :
    m_center(center), m_radius(radius), m_materialPtr(materialPtr) {}

Point3 Sphere::center() const {
    return m_center;
}

double Sphere::radius() const {
    return m_radius;
}

std::shared_ptr<Material> Sphere::materialPtr() const {
    return m_materialPtr;
}

void Sphere::center(const Point3& center) {
    m_center = center;
}

void Sphere::radius(double radius) {
    m_radius = radius;
}

void Sphere::materialPtr(std::shared_ptr<Material> materialPtr) {
    m_materialPtr = materialPtr;
}

bool Sphere::hit(const Ray &r, double minT, double maxT, HitRecord &rec) const {
    /**
     * a Sphere is the set of all the points P=(x,y,z), who's distance from the center C=(Cx,Cy,Cz) is r.
     * in other words: (x-Cx)^2 + (y-Cy)^2 + (z-Cz)^2 = r^2.
     * using P and C: (P-C)*(P-C) = r^2 (*).
     * another way of thinking of the above equation is "every point P that satisfies (*) is on the Sphere".
     * let P(t) = At+B be the Ray, then we are searching for ts, such that (P(t)-C)*(P(t)-C) = r^2.
     * expanding the last result: (B*B)*t^2 + 2*B*(A-C)*t + (A-C)*(A-C)-r^2 = 0.
     * the amount of solutions with respect to t of the last, is the amount of intersects between the Sphere and the Ray.
     */
    Vec3 oc = r.origin() - m_center; // Vector from the m_origin of the Ray to the center of the Sphere
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - m_radius * m_radius;
    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0) // No intersections
        return false;

    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range
    double root = (-b - sqrtd) / (2 * a); // First root

    if (root < minT || maxT < root) {
        root = (-b + sqrtd) / (2 * a); // Second root

        if (root < minT || maxT < root)
            return false;
    }

    // Update hit record
    rec.t(root); // The intersection time stamp is the root to the above equation
    rec.point(r.at(rec.t())); // The point of intersection is the ray's location at said time

    Vec3 outwardNormal = (rec.point() - m_center) / m_radius; // The normal to the Sphere at the intersection
    rec.faceNormal(r, outwardNormal);
    rec.materialPtr(m_materialPtr);

    return true;
}


