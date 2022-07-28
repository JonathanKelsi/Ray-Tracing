// Created by jonathan

#include "../header files/Ray.h"

Ray::Ray() {}

Ray::Ray(const Point3& origin, const Vec3& direction) : m_origin(origin), m_direction(direction) {}

Point3 Ray::origin() const {
    return m_origin;
}

Vec3 Ray::direction() const {
    return m_direction;
}

void Ray::origin(const Point3& origin) {
    m_origin = origin;
}

void Ray::direction(const Vec3& direction) {
    m_direction = direction;
}

Point3 Ray::at(double t) const {
    return m_origin + t * m_direction;
}
