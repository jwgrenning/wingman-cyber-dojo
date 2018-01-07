//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#include "CircularBuffer.h"

struct CircularBufferStruct
{
    int place_holder_delete_me_soon;
};

CircularBuffer * CircularBuffer_Create(unsigned int capacity, int default_value)
{
    CircularBuffer * self = (CircularBuffer *)calloc(1, sizeof(CircularBuffer));
    return self;
}

void CircularBuffer_Destroy(CircularBuffer * self)
{
    free(self);
}



