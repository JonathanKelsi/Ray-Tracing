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
    /**
     * empty constructor.
     */
    Ray();

    /**
     * constructor for the Ray class.
     * @param origin the m_origin point of the Ray
     * @param direction the direction vector of the Ray
     */
    Ray(const Point3& origin, const Vec3& direction);

    /**
     * m_origin getter.
     * @return the m_origin of the Ray
     */
    Point3 origin() const;

    /**
     * direction getter.
     * @return the direction of the Ray
     */
    Vec3 direction() const;

    /**
     * m_origin setter.
     * @param origin a new m_origin point
     */
    void origin(const Point3& origin);

    /**
     * direction setter.
     * @param direction a new direction
     */
    void direction(const Vec3& direction);

    /**
     * evaluate where is the Ray at in a given moment in time.
     * @param t a time stamp
     * @return the location of the Ray
     */
    Point3 at(double t) const;
};

#endif
