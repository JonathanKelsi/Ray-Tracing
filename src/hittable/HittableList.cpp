#include "HittableList.h"

HittableList::HittableList() {}

HittableList::HittableList(const std::shared_ptr<IHittable>& hittable) {
    add(hittable);
}

std::vector<std::shared_ptr<IHittable>> HittableList::hittableVec() {
    return m_hittableVec;
}

void HittableList::clear() {
    m_hittableVec.clear();
}

void HittableList::add(const std::shared_ptr<IHittable>& hittable) {
    m_hittableVec.push_back(hittable);
}

bool HittableList::hit(const Ray &r, double minT, double maxT, HitRecord &rec) const {
    HitRecord tempRec;
    bool hitAnything = false;
    auto closestSoFar = maxT;

    for (const auto& hittable : m_hittableVec) {
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






