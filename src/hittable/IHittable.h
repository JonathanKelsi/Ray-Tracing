#ifndef IHITTABLE_H
#define IHITTABLE_H

#include "../ray/Ray.h"
#include "HitRecord.h"

/**
 * this class represents an object hittable by ray.
 */
class IHittable {
public:
    virtual bool hit(const Ray& r, double minT, double maxT, HitRecord& record) const = 0;
};

#endif