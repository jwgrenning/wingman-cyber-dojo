//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#include "CircularBuffer.h"
#include <stdlib.h>

struct CircularBuffer
{
    // keep compiler from complaining about an empty struct
    int place_holder_delete_me_after_you_add_your_own_members;
};

struct CircularBuffer * CircularBuffer_Create(unsigned int capacity, int default_value)
{
    struct CircularBuffer * self = (struct CircularBuffer *)calloc(1, sizeof(struct CircularBuffer));
    return self;
}

void CircularBuffer_Destroy(struct CircularBuffer * self)
{
    free(self);
}

// PUSH THE TEST BUTTON WHEN YOU START TO WORK
// Pushing the test button saves your work and runs the build.
