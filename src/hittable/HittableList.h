#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include "IHittable.h"
#include <memory>
#include <vector>

/**
 * This class represents a list of hittable objects
 */
class HittableList : public IHittable {
private:
    std::vector<std::shared_ptr<IHittable>> m_hittableVec;

public:
    /**
     * empty constructor.
     */
    HittableList();

    /**
     * constructor.
     * @param hittable a shared_ptr to a hittable object
     */
    HittableList(const std::shared_ptr<IHittable>& hittable);

    /**
     * hittableVec getter.
     * @return the hittable vector
     */
    std::vector<std::shared_ptr<IHittable>> hittableVec();

    /**
     * clears the hittable vector.
     */
    void clear();

    /**
     * add another hittable to the vector.
     * @param hittable
     */
    void add(const std::shared_ptr<IHittable>& hittable);

    /**
     * indicates whether a ray hit one of the hittable in a specified interval.
     * @param r a ray
     * @param minT minimum value of the hit point
     * @param maxT maximum value of the hit point
     * @param rec a hit record
     * @return whether r hit one of the hittable in the specified interval
     */
    bool hit(const Ray& r, double minT, double maxT, HitRecord& rec) const override;
};

#endif
