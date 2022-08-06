cmake_minimum_required(VERSION 3.22)
project(RayTracing)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        "src/ray/Vec3.h"
        "src/ray/Color.h"
        "src/ray/Ray.h"
        "src/hittable/IHittable.h"
        "src/hittable/HitRecord.h"
        "src/hittable/Sphere.h"
        "src/hittable/HittableList.h"
        "src/other/RayTracing.h"
        "src/camera/Camera.h"
        "src/material/Material.h"
        "src/material/Lambertian.h")


        set(PROJECT_SOURCES
        "src/ray/Vec3.cpp"
        "src/ray/Color.cpp"
        "src/ray/Ray.cpp"
        "src/main.cpp"
        "src/hittable/HitRecord.cpp"
        "src/hittable/Sphere.cpp"
        "src/hittable/HittableList.cpp"
        "src/other/RayTracing.cpp"
        "src/camera/Camera.cpp"
        "src/material/Lambertian.cpp")


add_executable(RayTracing ${PROJECT_SOURCES} ${PROJECT_HEADERS})
