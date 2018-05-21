//- Copyright (c) 2008-2009 James Grenning
//- All rights reserved
//- For use by participants in Wingman Software training courses.

#include "CppUTest/TestHarness.h"
#include <string>
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer)
{
CircularBuffer* buffer;

    void setup()
    {
        buffer = new CircularBuffer(5);
    }

    void teardown()
    {
        delete buffer;
    }

    void fillTheBuffer(int seed, int count)
    {
        for (int i = 0; i < count; i++)
        buffer->put(seed++);
    }

    void drainAndCheckBuffer(int seed, int capacity)
    {
        for (int j = 0; j < capacity; j++)
        {
            LONGS_EQUAL(j + seed, buffer->get());
            CHECK(!buffer->isFull());
        }
    }
};

using namespace std;

TEST(CircularBuffer,CreateDestroy)
{
}

TEST(CircularBuffer,EmptyAfterCreation)
{
    CHECK(buffer->isEmpty());
}

TEST(CircularBuffer,NotFullAfterCreation)
{
    CHECK(!buffer->isFull());
}

TEST(CircularBuffer,NotEmpty)
{
    buffer->put(10046);
    CHECK(!buffer->isEmpty());
}

TEST(CircularBuffer,NotEmptyThenEmpty)
{
    buffer->put(4567);
    CHECK(!buffer->isEmpty());
    buffer->get();
    CHECK(buffer->isEmpty());
}

TEST(CircularBuffer,GetPutOneValue)
{
    buffer->put(4567);
    LONGS_EQUAL(4567, buffer->get());
}

TEST(CircularBuffer,GetPutAFew)
{
    buffer->put(1);
    buffer->put(2);
    buffer->put(3);
    LONGS_EQUAL(1, buffer->get());
    LONGS_EQUAL(2, buffer->get());
    LONGS_EQUAL(3, buffer->get());
}

TEST(CircularBuffer,Capacity)
{
    CircularBuffer buffer(2);
    LONGS_EQUAL(2, buffer.capacity());
}

TEST(CircularBuffer,IsFull)
{
    fillTheBuffer(100, buffer->capacity());

    CHECK(buffer->isFull());
}

TEST(CircularBuffer,EmptyToFullToEmpty)
{
    fillTheBuffer(100, buffer->capacity());

    drainAndCheckBuffer(100, buffer->capacity());
    CHECK(buffer->isEmpty());
}

TEST(CircularBuffer,WrapAround)
{
    int capacity = buffer->capacity();
    fillTheBuffer(100, capacity);

    LONGS_EQUAL(100, buffer->get());
    buffer->put(1000);
    CHECK(buffer->isFull());

    drainAndCheckBuffer(101, capacity - 1);

    LONGS_EQUAL(1000, buffer->get());
    CHECK(buffer->isEmpty());
}

