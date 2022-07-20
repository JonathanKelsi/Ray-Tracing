#include "header files/RayTracing.h"
#include "header files/Color.h"
#include "header files/HittableList.h"
#include "header files/Sphere.h"
#include "header files/Camera.h"
#include <iostream>

Color rayColor(const Ray& r, const IHittable& world, int  depth) {
    HitRecord rec;

    // If we've exceeded the ray bounce limit, no more light is gathered
    if (depth <= 0)
        return Color(0, 0, 0);

    if (world.hit(r, 0, inf, rec)) {
        Point3 target = rec.point() + rec.normal() + randomVectorInUnitSphere(); // Random diffuse bounce ray
        return 0.5 * rayColor(Ray(rec.point(), target - rec.point()), world, depth - 1);
    }

    Vec3 unitDirection = unitVector(r.direction());
    auto t = 0.5 * (unitDirection.y() + 1);
    return (1 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1);
}

int main() {
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samplesPerPixel = 100;
    const int maxDepth = 50;

    // World
    HittableList world;
    world.add(std::make_shared<Sphere>(Point3(0,0,-1), 0.5));
    world.add(std::make_shared<Sphere>(Point3(0,-100.5,-1), 100));

    // Camera
    Camera cam;

    // Render
    std::cout << "P3" << std::endl << image_width << ' ' << image_height << std::endl << "255" << std::endl;

    for (int i = image_height - 1; i >= 0; i--) {
        std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; j++) {
            Color pixelColor(0, 0, 0);
            for (int k = 0; k < samplesPerPixel; k++) {
                auto u = (j + randomDouble()) / (image_width - 1);
                auto v = (i + randomDouble()) / (image_height - 1);
                Ray r = cam.getRay(u, v);
                pixelColor += rayColor(r, world, maxDepth);
            }
            writeColor(std::cout, pixelColor, samplesPerPixel);
        }
    }
}
