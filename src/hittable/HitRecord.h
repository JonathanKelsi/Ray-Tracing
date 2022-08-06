#ifndef HITRECORD_H
#define HITRECORD_H

#include "../ray/Vec3.h"
#include "../ray/Ray.h"
#include "../other/RayTracing.h"

/**
 * This class saves the data of an intersection of an 'IHittable' with a ray.
 */
class HitRecord {
private:
    Point3 m_point;
    Vec3 m_normal;
    double m_t;
    bool m_frontFace;
    std::shared_ptr<Material> m_materialPtr;

public:
    /**
     * empty constructor.
     */
    HitRecord();

    /**
     * constructor.
     * @param p the point of intersection
     * @param normal the normal to the object in the intersection point
     * @param t the time stamp of the intersection
     * @param frontFace indicates whether the ray hit from outside the object or inside of it
     */
    HitRecord(Point3 p, Vec3 normal, double t, bool frontFace);

    /**
     * point of intersection getter.
     * @return the point of intersection
     */
    Point3 point() const;

    /**
     * normal getter.
     * @return the normal
     */
    Vec3 normal() const;

    /**
     * time stamp getter.
     * @return the time stamp
     */
    double t() const;

    /**
     * frontFace indicator getter.
     * @return whether the ray hit from outside the object or inside of it
     */
    bool frontFace() const;

    /**
     * materialPtr getter.
     * @return the materialPtr
     */
    std::shared_ptr<Material> materialPtr() const;

    /**
     * point setter.
     * @param point a point
     */
    void point(const Point3& point);

    /**
     * normal setter.
     * @param normal a normal
     */
    void normal(const Vec3& normal);

    /**
     * a time stamp setter.
     * @param t a time stamp.
     */
    void t(double t);

    /**
     * a front face indicator setter.
     * @param frontFace a boolean
     */
    void frontFace(bool frontFace);

    /**
     * materialPtr setter.
     * @param materialPtr a new materialPtr
     */
    void materialPtr(std::shared_ptr<Material> materialPtr);

    /**
     * given a ray and the outward normal to the intersection point of the object and ray, this function determines
     * whether the ray is inside the object, and changes m_frontFace (the indicator) and m_normal (the normal) accordingly.
     * @param r a ray
     * @param outwardNormal the outward normal to the intersection pint of the object and the ray
     */
    void faceNormal(const Ray& r, const Vec3& outwardNormal);
};

#endif
