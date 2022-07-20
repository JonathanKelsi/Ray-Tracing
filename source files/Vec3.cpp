// Created by jonathan

#include "../header files/Vec3.h"
#include <cmath>

/**
 * empty constructor.
 */
Vec3::Vec3() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

/**
 * constructor.
 * @param e0 the x component of the vector.
 * @param e1 the y component of the vector.
 * @param e2 the z component of the vector.
 */
Vec3::Vec3(double e0, double e1, double e2) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

/**
 * x component getter.
 * @return the x component of the vector
 */
double Vec3::x() const {
    return e[0];
}

/**
 * y component getter.
 * @return the y component of the vector
 */
double Vec3::y() const {
    return e[1];
}

/**
 * z component getter.
 * @return the z component of the vector
 */
double Vec3::z() const {
    return e[2];
}

/**
 * x component setter.
 * @param x new x value
 */
void Vec3::x(double x) {
    e[0] = x;
}

/**
 * y component setter.
 * @param y new y value
 */
void Vec3::y(double y) {
    e[1] = y;
}

/**
 * z component setter.
 * @param z new z value
 */
void Vec3::z(double z) {
    e[2] = z;
}

/**
 * the '-' operator.
 * @return the vector reversed
 */
Vec3 Vec3::operator-() const {
    return Vec3(-e[0], -e[1], -e[2]);
}

/**
 * the '[]' operator.
 * @param i an integer
 * @return the i-th component of the vector
 */
double Vec3::operator[](int i) const {
    if (0 <= i && i <= 2) {
        return e[i];
    }
    exit(1);
}

/**
 * the '+=' operator
 * @param v another vector
 * @return the sum of the LHS and RHS vectors
 */
Vec3 &Vec3::operator+=(const Vec3& v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
}

/**
 * the '*=' operator
 * @param t a scalar
 * @return the vector, multiplied by the scalar t
 */
Vec3 &Vec3::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

/**
 * the '/=' operator
 * @param t a scalar
 * @return the vector, multiplied by the inverse of the scalar t
 */
Vec3 &Vec3::operator/=(const double t) {
    if (t == 0)
        exit(1);
    *this *= 1 / t;
    return *this;
}

/**
 * @return the length of the vector, squared
 */
double Vec3::lenSquared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}


/**
 * @return the length of the vector
 */
double Vec3::len() const {
    return sqrt(lenSquared());
}

/**
 * the '+' operator.
 * @param u another vector
 * @return the sum of the two vectors
 */
const Vec3 Vec3::operator+(const Vec3& u) const {
    return Vec3(u.e[0] + e[0], u.e[1] + e[1], u.e[2] + e[2]);
}

/**
 * the '-' operator.
 * @param u another vector
 * @return the sum of the vector, and the reversed vector u
 */
const Vec3 Vec3::operator-(const Vec3& u) const {
    return *this + (-u);
}

/**
 * the '*' operator.
 * @param t a scalar
 * @return the vector, multiplied by the scalar t
 */
const Vec3 Vec3::operator*(double t) const {
    return Vec3(t * e[0], t * e[1], t * e[2]);
}

/**
 * the '/' operator.
 * @param t a scalar
 * @return the vector, multiplied by the inverse of the scalar t
 */
const Vec3 Vec3::operator/(double t) const {
    return *this * (1 / t);
}

/**
 * the '*' operator.
 * @param u another vector
 * @return the dot product of the vector and u
 */
const Vec3 Vec3::operator*(const Vec3& u) const {
    return Vec3(u.e[0] * this->e[0], u.e[1] * this->e[1], u.e[2] * this->e[2]);
}

/**
 * the '<<' operator.
 * @param out an output stream
 * @param v a vector
 * @return the output of v's components
 */
const std::ostream& operator<<(std::ostream &out, const Vec3& v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z() << std::endl;
}

/**
 * the '*' operator.
 * @param t a scalar
 * @param u a vector
 * @return the product of the scalar t and u
 */
const Vec3 operator*(double t, const Vec3& u) {
    return u * t;
}

/**
 * the dot product.
 * @param u a vector
 * @param v a vector
 * @return the dot product of u and v
 */
double dot(const Vec3& u, const Vec3& v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

/**
 * the cross product.
 * @param u a vector
 * @param v a vector
 * @return the cross product of u and v
 */
Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

/**
 * normalizes a vector.
 * @param v a vector
 * @return the vector v normalized
 */
Vec3 unitVector(Vec3 v) {
    return v / v.len();
}


