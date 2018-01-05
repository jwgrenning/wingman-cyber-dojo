//- Copyright (c) 2018 James Grenning --- All rights reserved

#include <stdio.h>
#include "CircularBuffer.h"

//please do not change these messages
const char * writing = "I'm writing and building the code.";
const char * testing = "[  FAILED  ] Testing, with more to do.";
const char * working = "[  PASSED  ] I'm done testing and my code is working.";

int main(int ac, char** av)
{
    unsigned int capacity = 10;
    int empty_value = -1;
    const char * exercise_state = writing;

    struct CircularBuffer * b = CircularBuffer_Create(capacity, empty_value);
    CircularBuffer_Destroy(b);

    printf("%s code\n", exercise_state);
    return 0;
}

