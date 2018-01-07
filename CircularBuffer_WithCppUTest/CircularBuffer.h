//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#ifndef CIRCULAR_BUFFER_INCLUDED
#define CIRCULAR_BUFFER_INCLUDED

typedef struct CircularBufferStruct CircularBuffer;

CircularBuffer * CircularBuffer_Create(unsigned int capacity, int default_value);
void CircularBuffer_Destroy(CircularBuffer *);

#endif
