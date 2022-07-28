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
    /**
     * empty constructor.
     */
    Vec3();

    /**
     * constructor.
     * @param e0 the x component of the vector.
     * @param e1 the y component of the vector.
     * @param e2 the z component of the vector.
     */
    Vec3(double e0, double e1, double e2);


    /**
     * Copy constructor.
     * @param v another vector
     */
    Vec3(const Vec3& v);

    /**
     * x component getter.
     * @return the x component of the vector
     */
    double x() const;

    /**
     * y component getter.
     * @return the y component of the vector
     */
    double y() const;

    /**
     * z component getter.
     * @return the z component of the vector
     */
    double z() const;

    /**
     * x component setter.
     * @param x new x value
     */
    void x(double x);

    /**
     * y component setter.
     * @param y new y value
     */
    void y(double y);

    /**
     * z component setter.
     * @param z new z value
     */
    void z(double z);

    /**
     * the '-' operator.
     * @return the vector reversed
     */
    Vec3 operator-() const;

    /**
     * the '[]' operator.
     * @param i an integer
     * @return the i-th component of the vector
     */
    double operator[](int i) const;

    /**
     * the '+=' operator
     * @param v another vector
     * @return the sum of the LHS and RHS vectors
     */
    Vec3& operator+=(const Vec3& v);

    /**
     * the '*=' operator
     * @param t a scalar
     * @return the vector, multiplied by the scalar t
     */
    Vec3& operator*=(const double t);


    /**
     * the '/=' operator
     * @param t a scalar
     * @return the vector, multiplied by the inverse of the scalar t
     */
    Vec3& operator/=(const double t);

    /**
     * @return the length of the vector, squared
     */
    const Vec3 operator+(const Vec3& u) const;


    /**
     * @return the length of the vector
     */
    const Vec3 operator-(const Vec3& u) const;

    /**
     * the '+' operator.
     * @param u another vector
     * @return the sum of the two vectors
     */
    const Vec3 operator*(double t) const;

    /**
     * the '-' operator.
     * @param u another vector
     * @return the sum of the vector, and the reversed vector u
     */
    const Vec3 operator*(const Vec3& u) const;

    /**
     * the '*' operator.
     * @param t a scalar
     * @return the vector, multiplied by the scalar t
     */
    const Vec3 operator/(double t) const;

    /**
     * the '/' operator.
     * @param t a scalar
     * @return the vector, multiplied by the inverse of the scalar t
     */
    double len() const;

    /**
     * the '*' operator.
     * @param u another vector
     * @return the dot product of the vector and u
     */
    double lenSquared() const;
};

// Other Vec3-related functions

/**
 * the '<<' operator.
 * @param out an output stream
 * @param v a vector
 * @return the output of v's components
 */
const std::ostream& operator<<(std::ostream &out, const Vec3& v);

/**
 * the '*' operator.
 * @param t a scalar
 * @param u a vector
 * @return the product of the scalar t and u
 */
const Vec3 operator*(double t, const Vec3& u);

/**
 * the dot product.
 * @param u a vector
 * @param v a vector
 * @return the dot product of u and v
 */
double dot(const Vec3& u, const Vec3& v);

/**
 * the cross product.
 * @param u a vector
 * @param v a vector
 * @return the cross product of u and v
 */
Vec3 cross(const Vec3& u, const Vec3& v);

/**
 * normalizes a vector.
 * @param v a vector
 * @return the vector v normalized
 */
Vec3 unitVector(Vec3 v);

// Type aliases for Vec3
using Point3 = Vec3;
using Color = Vec3;

#endif
