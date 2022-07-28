#!/bin/bash
g++ main.cpp 'src/'*.cpp
./a.out > res.ppm
open res.ppm