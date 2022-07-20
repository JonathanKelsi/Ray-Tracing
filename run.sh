#!/bin/bash
g++ main.cpp 'source files/'*.cpp
./a.out > res.ppm
open res.ppm