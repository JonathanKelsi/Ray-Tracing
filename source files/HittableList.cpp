// Created by jonathan
#include "../header files/HittableList.h"

/**
 * empty constructor.
 */
HittableList::HittableList() {}

/**
 * constructor.
 * @param hittable a shared_ptr to a hittable object
 */
HittableList::HittableList(std::shared_ptr<IHittable> hittable) {
    add(hittable);
}

/**
 * hittables getter.
 * @return the hittables vector
 */
std::vector<std::shared_ptr<IHittable>> HittableList::hittables() {
    return m_hittables;
}

/**
 * clears the hittable vectors.
 */
void HittableList::clear() {
    // Since we're using shared_ptr there's no need to call destructors
    m_hittables.clear();
}

/**
 * add another shared_ptr to vector.
 * @param hittable
 */
void HittableList::add(std::shared_ptr<IHittable> hittable) {
    m_hittables.push_back(hittable);
}

/**
 * indicates whether a ray hit one of the hittables in a specified interval.
 * @param r a ray
 * @param minT minimum value of the hit point
 * @param maxT maximum value of the hit point
 * @param rec a hit record
 * @return whether r hit one of the hittables in the specified interval
 */
bool HittableList::hit(const Ray &r, double minT, double maxT, HitRecord &rec) const {
    HitRecord tempRec;
    bool hitAnything = false;
    auto closestSoFar = maxT;

    for (const auto& hittable : m_hittables) {
        if (hittable->hit(r, minT, closestSoFar, tempRec)) {
            hitAnything = true;
            closestSoFar = tempRec.t();

            rec.t(tempRec.t());
            rec.point(tempRec.point());
            rec.normal(tempRec.normal());
            rec.frontFace(tempRec.frontFace());
        }
    }

    return hitAnything;
}






