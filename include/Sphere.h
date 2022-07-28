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
    std::shared_ptr<Material> m_materialPtr;
public:
    /**
     * empty constructor.
     */
    Sphere();

    /**
     * constructor.
     * @param center the center of the Sphere
     * @param radius the radius of the Sphere
     */
    Sphere(Point3 center, double radius, std::shared_ptr<Material> materialPtr);

    /**
     * center getter.
     * @return the center of the Sphere
     */
    Point3 center() const;

    /**
     * radius getter.
     * @return the radius of the Sphere
     */
    double radius() const;

    /**
     * materialPtr getter
     * @return the materialPtr
     */
    std::shared_ptr<Material> materialPtr() const;


    /**
    * center setter.
    * @param center a new center for the Sphere
    */
    void center(const Point3& center);

    /**
     * radius setter.
     * @param radius a new radius for the Sphere
     */
    void radius(double radius);

    /**
     * materialPtr setter
     * @param materialPtr a new materialPtr
     */
    void materialPtr(std::shared_ptr<Material> materialPtr);

    /**
     * indicates whether a ray hit the Sphere in a specified interval.
     * @param r a ray
     * @param minT minimum value of the hit point
     * @param maxT maximum value of the hit point
     * @param rec a hit record
     * @return whether r hit the Sphere in the specified interval
     */
    bool hit(const Ray& r, double minT, double maxT, HitRecord& rec) const;
};

#endif