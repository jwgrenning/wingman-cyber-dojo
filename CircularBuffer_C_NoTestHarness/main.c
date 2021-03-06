//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#include <stdio.h>
#include "CircularBuffer.h"

//please do not change these messages
const char * writing = "I'm writing and building.";
const char * testing = "[  FAILED  ] Testing, with more to do.";
const char * working = "[  PASSED  ] I'm done testing and my code works!.";

int main(int ac, char** av)
{
    // see the instructions on setting your state in the exercise
    const char * exercise_state = writing;

    unsigned int capacity = 10;
    int empty_value = -1;

    struct CircularBuffer * b = CircularBuffer_Create(capacity, empty_value);
    CircularBuffer_Destroy(b);

    printf("%s\n", exercise_state);
    return 0;
}

