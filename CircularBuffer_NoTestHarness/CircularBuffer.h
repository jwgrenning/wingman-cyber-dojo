//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#ifndef CIRCULAR_BUFFER_INCLUDED
#define CIRCULAR_BUFFER_INCLUDED

#include <stdbool.h>

struct CircularBuffer;

struct CircularBuffer * CircularBuffer_Create(unsigned int capacity, int default_value);
void CircularBuffer_Destroy(struct CircularBuffer *);
bool CircularBuffer_IsEmpty(struct CircularBuffer *);
bool CircularBuffer_IsFull(struct CircularBuffer *);
bool CircularBuffer_Put(struct CircularBuffer *, int);
int CircularBuffer_Get(struct CircularBuffer *);
unsigned int CircularBuffer_Capacity(struct CircularBuffer *);

#endif
