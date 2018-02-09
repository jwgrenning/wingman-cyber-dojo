//- Copyright (c) 2008-2009 James Grenning
//- All rights reserved
//- For use by participants in Wingman Software training courses.

#ifndef D_CircularBuffer_H
#define D_CircularBuffer_H

#include <string>

class CircularBuffer
{
  public:
    CircularBuffer(int capacity, int default_value);
    virtual ~CircularBuffer();

    bool isEmpty() const;
    bool isFull() const;
    void put(int);
    int get();
    int capacity() const;

  private:

    CircularBuffer(const CircularBuffer&);
    CircularBuffer& operator=(const CircularBuffer&);
};

#endif  // D_CircularBuffer_H
