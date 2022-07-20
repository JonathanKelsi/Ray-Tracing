// Created by jonathan

#ifndef VEC3_H
#define VEC3_H

#include <iostream>

/**
 * This class represents a vector in R^3.
 */
class Vec3 {
private:
    double e[3];

public:
    // Constructors
    Vec3();
    Vec3(double e0, double e1, double e2);

    // Getters
    double x() const;
    double y() const;
    double z() const;

    // Setters
    void x(double x);
    void y(double y);
    void z(double z);

    // Operators
    Vec3 operator-() const;
    double operator[](int i) const;
    Vec3& operator+=(const Vec3& v);
    Vec3& operator*=(const double t);
    Vec3& operator/=(const double t);
    const Vec3 operator+(const Vec3& u) const;
    const Vec3 operator-(const Vec3& u) const;
    const Vec3 operator*(double t) const;
    const Vec3 operator*(const Vec3& u) const;
    const Vec3 operator/(double t) const;

    // Other member functions
    double len() const;
    double lenSquared() const;
};

// Other Vec3-related functions
const std::ostream& operator<<(std::ostream &out, const Vec3& v);
const Vec3 operator*(double t, const Vec3& u);
double dot(const Vec3& u, const Vec3& v);
Vec3 cross(const Vec3& u, const Vec3& v);
Vec3 unitVector(Vec3 v);

// Type aliases for Vec3
using Point3 = Vec3;
using Color = Vec3;

#endif
