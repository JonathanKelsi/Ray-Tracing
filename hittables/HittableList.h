// Created by jonathan

#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include "IHittable.h"
#include <memory>
#include <vector>

class HittableList : public IHittable {
private:
    std::vector<std::shared_ptr<IHittable>> m_hittables;
public:
    /**
     * empty constructor.
     */
    HittableList();

    /**
     * constructor.
     * @param hittable a shared_ptr to a hittable object
     */
    HittableList(std::shared_ptr<IHittable> hittable);

    /**
     * hittables getter.
     * @return the hittables vector
     */
    std::vector<std::shared_ptr<IHittable>> hittables();

    /**
     * clears the hittable vectors.
     */
    void clear();

    /**
     * add another shared_ptr to vector.
     * @param hittable
     */
    void add(std::shared_ptr<IHittable> hittable);

    /**
     * indicates whether a ray hit one of the hittables in a specified interval.
     * @param r a ray
     * @param minT minimum value of the hit point
     * @param maxT maximum value of the hit point
     * @param rec a hit record
     * @return whether r hit one of the hittables in the specified interval
     */
    bool hit(const Ray& r, double minT, double maxT, HitRecord& rec) const override;
};

#endif
