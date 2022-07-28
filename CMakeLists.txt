cmake_minimum_required(VERSION 3.22)
project(RayTracing)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        "header files/Vec3.h"
        "header files/Color.h"
        "header files/Ray.h")

set(PROJECT_SOURCES
        "source files/Vec3.cpp"
        "source files/Color.cpp"
        "source files/Ray.cpp"
        "main.cpp" "header files/IHittable.h" "header files/HitRecord.h" "source files/HitRecord.cpp" "header files/Sphere.h" "source files/Sphere.cpp" "header files/HittableList.h" "source files/HittableList.cpp" "header files/RayTracing.h" "source files/RayTracing.cpp" "header files/Camera.h" "source files/Camera.cpp" "header files/Material.h" "header files/Lambertian.h" "source files/Lambertian.cpp")


add_executable(RayTracing ${PROJECT_SOURCES} ${PROJECT_HEADERS})
