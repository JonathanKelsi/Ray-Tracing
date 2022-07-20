// Created by jonathan

#include "../header files/HitRecord.h"

/**
 * empty constructor.
 */
HitRecord::HitRecord() : m_p(), m_normal(), m_t(0), m_frontFace(false) {}

/**
 * constructor.
 * @param p the point of intersection
 * @param normal the normal to the object in the intersection point
 * @param t the time stamp of the intersection
 * @param frontFace indicates whether the ray hit from outside the object or inside of it
 */
HitRecord::HitRecord(Point3 p, Vec3 normal, double t, bool frontFace)
        : m_p(p.x(), p.y(), p.z())
        , m_normal(normal.x(), normal.y(), normal.z())
        , m_t(t)
        , m_frontFace(frontFace)
{}

/**
 * point of intersection getter.
 * @return the point of intersection
 */
Point3 HitRecord::point() const {
    return m_p;
}

/**
 * normal getter.
 * @return the normal
 */
Vec3 HitRecord::normal() const {
    return m_normal;
}

/**
 * time stamp getter.
 * @return the time stamp
 */
double HitRecord::t() const {
    return m_t;
}

/**
 * frontFace indicator getter.
 * @return whether the ray hit from outside the object or inside of it
 */
bool HitRecord::frontFace() const {
    return m_frontFace;
}

/**
 * point setter.
 * @param point a point
 */
void HitRecord::point(Point3 point) {
    m_p.x(point.x());
    m_p.y(point.y());
    m_p.z(point.z());
}

/**
 * normal setter.
 * @param normal a normal
 */
void HitRecord::normal(Vec3 normal) {
    m_normal.x(normal.x());
    m_normal.y(normal.y());
    m_normal.z(normal.z());
}

/**
 * a time stamp setter.
 * @param t a time stamp.
 */
void HitRecord::t(double t) {
    m_t = t;
}

/**
 * a front face indicator setter.
 * @param frontFace a boolean
 */
void HitRecord::frontFace(bool frontFace) {
    m_frontFace = frontFace;
}

/**
 * given a ray and the outward normal to the intersection point of the object and ray, this function determines
 * whether the ray is inside the object, and changes m_frontFace (the indicator) and m_normal (the normal) accordingly.
 * @param r a ray
 * @param outwardNormal the outward normal to the intersection pint of the object and the ray
 */
void HitRecord::setFaceNormal(const Ray &r, const Vec3 &outwardNormal) {
    // Check whether both the ray and the outward normal are at opposite directions (the ray is outside the Sphere)
    m_frontFace = dot(r.direction(), outwardNormal) < 0;

    // Make sure the normal points against the ray
    m_normal = m_frontFace ? outwardNormal : -outwardNormal;
}

