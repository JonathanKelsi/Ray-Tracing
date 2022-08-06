#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "../other/RayTracing.h"
#include "../hittable/HitRecord.h"

class Material {
    public:
        virtual bool scatter(const Ray& ray, const HitRecord& rec, Color& attenuation, Ray& scattered) const = 0;
};

#endif
