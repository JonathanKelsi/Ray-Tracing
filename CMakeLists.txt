cmake_minimum_required(VERSION 3.22)
project(RayTracing)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        "include/Vec3.h"
        "include/Color.h"
        "include/Ray.h"
        "include/IHittable.h"
        "include/HitRecord.h"
        "include/Sphere.h"
        "include/HittableList.h"
        "include/RayTracing.h"
        "include/Camera.h"
        "include/Material.h"
        "include/Lambertian.h")


        set(PROJECT_SOURCES
        "src/Vec3.cpp"
        "src/Color.cpp"
        "src/Ray.cpp"
        "main.cpp"
        "src/HitRecord.cpp"
        "src/Sphere.cpp"
        "src/HittableList.cpp"
        "src/RayTracing.cpp"
        "src/Camera.cpp"
        "src/Lambertian.cpp")


add_executable(RayTracing ${PROJECT_SOURCES} ${PROJECT_HEADERS})
