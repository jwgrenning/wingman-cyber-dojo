//- Copyright (c) 2008-2009 James Grenning
//- All rights reserved
//- For use by participants in Wingman Software training courses.

#include "CppUTest/TestHarness.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer)
{
CircularBuffer* buffer;

    void setup()
    {
        buffer = new CircularBuffer(5, -1);
    }

    void teardown()
    {
        delete buffer;
    }

};

TEST(CircularBuffer,CreateDestroy)
{
}

