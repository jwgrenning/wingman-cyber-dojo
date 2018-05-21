#!/bin/bash 

make clean
make
make CPPUTEST_USE_GCOV=Y  gcov

find . -name "*.cpp.gcov" | xargs cat
find . -name "*.c.gcov"| xargs cat

make clean
