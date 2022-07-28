// Created by jonathan

#include "../header files/HitRecord.h"

HitRecord::HitRecord() : m_point(), m_normal(), m_t(0), m_frontFace(false) {}

HitRecord::HitRecord(Point3 p, Vec3 normal, double t, bool frontFace)
        : m_point(p.x(), p.y(), p.z())
        , m_normal(normal.x(), normal.y(), normal.z())
        , m_t(t)
        , m_frontFace(frontFace)
{}

Point3 HitRecord::point() const {
    return m_point;
}

Vec3 HitRecord::normal() const {
    return m_normal;
}

double HitRecord::t() const {
    return m_t;
}

bool HitRecord::frontFace() const {
    return m_frontFace;
}

std::shared_ptr<Material> HitRecord::materialPtr() const {
    return m_materialPtr;
}

void HitRecord::point(const Point3& point) {
    m_point = point;
}

void HitRecord::normal(const Vec3& normal) {
    m_normal = normal;
}

void HitRecord::t(double t) {
    m_t = t;
}

void HitRecord::frontFace(bool frontFace) {
    m_frontFace = frontFace;
}

void HitRecord::materialPtr(std::shared_ptr<Material> materialPtr) {
    m_materialPtr = materialPtr;
}

void HitRecord::faceNormal(const Ray &r, const Vec3 &outwardNormal) {
    // Check whether both the ray and the outward normal are at opposite directions (the ray is outside the Sphere)
    m_frontFace = dot(r.direction(), outwardNormal) < 0;

    // Make sure the normal points against the ray
    m_normal = m_frontFace ? outwardNormal : -outwardNormal;
}
