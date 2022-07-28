// Created by jonathan

#include "../header files/Lambertian.h"

Lambertian::Lambertian(const Color &albedo) : m_albedo(albedo) {}

bool Lambertian::scatter(const Ray &ray, const HitRecord &rec, Color &attenuation, Ray &scattered) const {
    return false;
};

