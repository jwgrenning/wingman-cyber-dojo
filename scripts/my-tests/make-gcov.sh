#!/bin/bash 

make clean
make -f reference-makefile.mk clean
make CPPUTEST_USE_GCOV=Y -f reference-makefile.mk gcov

find . -name "*.cpp.gcov" | xargs cat
find . -name "*.c.gcov"| xargs cat

make clean
