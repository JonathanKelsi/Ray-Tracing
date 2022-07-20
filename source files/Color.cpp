// Created by jonathan

#include "../header files/Color.h"
#include "../header files/RayTracing.h"

/**
 * writes the Color of a pixel to the output stream.
 * @param out an output stream
 * @param pixelColor the Color of a pixel
 */
void writeColor(std::ostream &out, Color pixelColor, int samplesPerPixel) {
    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    // Divide the color by the number of samples.
    double scale = 1.0 / samplesPerPixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << std::endl;
}