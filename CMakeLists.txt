cmake_minimum_required(VERSION 3.22)
project(RayTracing)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        "rays/Vec3.h"
        "rays/Color.h"
        "rays/Ray.h"
        "hittables/IHittable.h"
        "hittables/HitRecord.h"
        "hittables/Sphere.h"
        "hittables/HittableList.h"
        "rays/RayTracing.h"
        "camera/Camera.h"
        "hittables/material/Material.h"
        "hittables/material/Lambertian.h")


        set(PROJECT_SOURCES
        "rays/Vec3.cpp"
        "rays/Color.cpp"
        "rays/Ray.cpp"
        "main.cpp"
        "hittables/HitRecord.cpp"
        "hittables/Sphere.cpp"
        "hittables/HittableList.cpp"
        "rays/RayTracing.cpp"
        "camera/Camera.cpp"
        "hittables/material/Lambertian.cpp")


add_executable(RayTracing ${PROJECT_SOURCES} ${PROJECT_HEADERS})
