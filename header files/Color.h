// Created by jonathan

#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"
#include <iostream>

/**
 * writes the Color of a pixel to the output stream.
 * @param out an output stream
 * @param pixelColor the Color of a pixel
 * @param samplesPerPixel the number of samples that were taken when calculating the pixel's color
 */
void writeColor(std::ostream &out, Color pixelColor, int samplesPerPixel);

#endif
