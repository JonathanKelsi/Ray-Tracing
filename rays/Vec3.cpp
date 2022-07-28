// Created by jonathan

#include "Vec3.h"
#include <cmath>

Vec3::Vec3() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

Vec3::Vec3(double e0, double e1, double e2) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

Vec3::Vec3(const Vec3& v) {
    e[0] = v.e[0];
    e[1] = v.e[1];
    e[2] = v.e[2];
}

double Vec3::x() const {
    return e[0];
}

double Vec3::y() const {
    return e[1];
}

double Vec3::z() const {
    return e[2];
}

void Vec3::x(double x) {
    e[0] = x;
}

void Vec3::y(double y) {
    e[1] = y;
}

void Vec3::z(double z) {
    e[2] = z;
}

Vec3 Vec3::operator-() const {
    return Vec3(-e[0], -e[1], -e[2]);
}

double Vec3::operator[](int i) const {
    if (0 <= i && i <= 2) {
        return e[i];
    }
    exit(1);
}

Vec3 &Vec3::operator+=(const Vec3& v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
}

Vec3 &Vec3::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vec3 &Vec3::operator/=(const double t) {
    if (t == 0)
        exit(1);
    *this *= 1 / t;
    return *this;
}

double Vec3::lenSquared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

double Vec3::len() const {
    return sqrt(lenSquared());
}

const Vec3 Vec3::operator+(const Vec3& u) const {
    return Vec3(u.e[0] + e[0], u.e[1] + e[1], u.e[2] + e[2]);
}

const Vec3 Vec3::operator-(const Vec3& u) const {
    return *this + (-u);
}

const Vec3 Vec3::operator*(double t) const {
    return Vec3(t * e[0], t * e[1], t * e[2]);
}

const Vec3 Vec3::operator/(double t) const {
    return *this * (1 / t);
}

const Vec3 Vec3::operator*(const Vec3& u) const {
    return Vec3(u.e[0] * this->e[0], u.e[1] * this->e[1], u.e[2] * this->e[2]);
}

const std::ostream& operator<<(std::ostream &out, const Vec3& v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z() << std::endl;
}

const Vec3 operator*(double t, const Vec3& u) {
    return u * t;
}

double dot(const Vec3& u, const Vec3& v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

Vec3 unitVector(Vec3 v) {
    return v / v.len();
}


