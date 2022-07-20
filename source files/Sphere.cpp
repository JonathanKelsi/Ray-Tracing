// Created by jonathan

#include "../header files/Sphere.h"
#include <cmath>

/**
 * empty constructor.
 */
Sphere::Sphere() {}

/**
 * constructor.
 * @param center the center of the Sphere
 * @param radius the radius of the Sphere
 */
Sphere::Sphere(Point3 center, double radius)  : m_center(center), m_radius(radius) {}

/**
 * center getter.
 * @return the center of the Sphere
 */
Point3 Sphere::center() const {
    return m_center;
}

/**
 * radius getter.
 * @return the radius of the Sphere
 */
double Sphere::radius() const {
    return m_radius;
}

/**
 * center setter.
 * @param center a new center for the Sphere
 */
void Sphere::center(Point3 center) {
    m_center.x(center.x());
    m_center.y(center.y());
    m_center.z(center.z());
}

/**
 * radius setter.
 * @param radius a new radius for the Sphere
 */
void Sphere::radius(double radius) {
    m_radius = radius;
}

/**
 * indicates whether a ray hit the Sphere in a specified interval.
 * @param r a ray
 * @param minT minimum value of the hit point
 * @param maxT maximum value of the hit point
 * @param rec a hit record
 * @return whether r hit the Sphere in the specified interval
 */
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
    Vec3 oc = r.origin() - m_center; // Vector from the origin of the Ray to the center of the Sphere
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
    rec.setFaceNormal(r, outwardNormal);

    return true;
}



