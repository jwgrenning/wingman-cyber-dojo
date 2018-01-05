//- Copyright (c) 2018 James Grenning --- See license.txt

#include "CircularBuffer.h"
#include <stdlib.h>

struct CircularBuffer
{
    // keep compiler from complaining about an empty struct
    int place_holder;
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



