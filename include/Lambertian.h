// Created by jonathan

#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Vec3.h"
#include "Material.h"

class Lambertian : Material {
private:
    Color m_albedo;
public:
    /**
     * Constructor.
     * @param albedo the albedo of the material
     */
    Lambertian(const Color& albedo);

    /**
     * given a ray, the point where it hit the material's
     * @param ray
     * @param rec
     * @param attenuation
     * @param scattered
     * @return
     */
    bool scatter(const Ray& ray, const HitRecord& rec, Color& attenuation, Ray& scattered) const override;
};

#endif
