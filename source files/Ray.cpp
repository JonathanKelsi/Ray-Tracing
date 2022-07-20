// Created by jonathan

#include "../header files/Ray.h"

/**
 * empty constructor.
 */
Ray::Ray() {}

/**
 * constructor for the Ray class.
 * @param origin the origin point of the Ray
 * @param direction the direction vector of the Ray
 */
Ray::Ray(const Point3& origin, const Vec3& direction) : m_origin(origin), m_direction(direction) {}

/**
 * origin getter.
 * @return the origin of the Ray
 */
Point3 Ray::origin() const {
    return m_origin;
}

/**
 * direction getter.
 * @return the direction of the Ray
 */
Vec3 Ray::direction() const {
    return m_direction;
}

/**
 * origin setter.
 * @param origin a new origin point
 */
void Ray::origin(Point3 origin) {
    m_origin.x(origin.x());
    m_origin.y(origin.y());
    m_origin.z(origin.z());
}

/**
 * direction setter.
 * @param direction a new direction
 */
void Ray::direction(Vec3 direction) {
    m_direction.x(direction.x());
    m_direction.y(direction.y());
    m_direction.z(direction.z());
}

/**
 * evaluate where is the Ray at in a given moment in time.
 * @param t a time stamp
 * @return the location of the Ray
 */
Point3 Ray::at(double t) const {
    return m_origin + t * m_direction;
}
