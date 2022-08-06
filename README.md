# Ray Tracing

## Description
A fairly simple ray tracer, made for education purposes.
## Getting Started

### Dependencies

This project uses CMake to generate and build. In a Debian-based system you can install it via:
```bash
sudo apt install cmake
```

### Installation

Clone the repository:
```bash
git clone 'https://github.com/JonathanKelsi/Ray-Tracing'
```

### Executing program

To run the program, the standard CMake workflow can be used:
```bash
mkdir -p build && cd build
cmake ..
make -j && make KNN-RayTracing > res.ppm
open res.ppm
```

## Acknowledgments
This project was made relining on the book *Ray Tracing In One Weekend*, written by Peter Shirley.
