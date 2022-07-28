// Created by jonathan

#include "../include/Camera.h"

Camera::Camera() {
    auto aspectRatio = 16.0 / 9.0;
    auto viewportHeight = 2.0;
    auto viewportWidth = aspectRatio * viewportHeight;
    auto focalLength = 1.0;

    m_origin = Point3(0, 0, 0);
    m_horizontal = Vec3(viewportWidth, 0, 0);
    m_vertical = Vec3(0, viewportHeight, 0);
    m_lowerLeftCorner = m_origin - m_horizontal / 2 - m_vertical / 2 - Vec3(0, 0, focalLength);
}

Ray Camera::getRay(double u, double v) {
    return Ray(m_origin, m_lowerLeftCorner + u * m_horizontal + v * m_vertical - m_origin);
}