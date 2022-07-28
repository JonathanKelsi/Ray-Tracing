// Created by jonathan
#include "HittableList.h"

HittableList::HittableList() {}

HittableList::HittableList(std::shared_ptr<IHittable> hittable) {
    add(hittable);
}

std::vector<std::shared_ptr<IHittable>> HittableList::hittables() {
    return m_hittables;
}

void HittableList::clear() {
    // Since we're using shared_ptr there's no need to call destructors
    m_hittables.clear();
}

void HittableList::add(std::shared_ptr<IHittable> hittable) {
    m_hittables.push_back(hittable);
}

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






