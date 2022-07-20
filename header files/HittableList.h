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
    // Constructors
    HittableList();
    HittableList(std::shared_ptr<IHittable> hittable);

    // Getter
    std::vector<std::shared_ptr<IHittable>> hittables();

    // Utility functions
    void clear();
    void add(std::shared_ptr<IHittable> hittable);

    // Abstract class functions overriding
    bool hit(const Ray& r, double minT, double maxT, HitRecord& rec) const override;
};

#endif
