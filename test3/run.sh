#!/bin/sh
set -xeu

g++ -Wall -Wextra -std=c++17 -Weffc++ test3.cpp
./a.out
