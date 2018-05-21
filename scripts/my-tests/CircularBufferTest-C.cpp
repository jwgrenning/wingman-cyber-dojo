//- Copyright (c) 2008-2016 James Grenning --- All rights reserved
//- For exclusive use by participants in Wingman Software training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.wingman-sw.com james@wingman-sw.com

#include "CppUTest/TestHarness.h"

extern "C"
{
#include "CircularBuffer.h"
}

TEST_GROUP(CircularBuffer)
{
    CircularBuffer * buffer;
    const int default_value = -1;

    void setup()
    {
        buffer = CircularBuffer_Create(10, default_value);
    }

    void teardown()
    {
        CircularBuffer_Destroy(buffer);
    }

    void fillTheQueue(unsigned int howMany)
    {
        for (unsigned int i = 0; i < howMany; i++)
            CircularBuffer_Put(buffer, (int)i);
    }

};

TEST(CircularBuffer, is_empty_after_creation)
{
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, is_not_full_after_creation)
{
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
}

TEST(CircularBuffer, is_not_empty_after_put)
{
    CircularBuffer_Put(buffer, 10046);
    CHECK_FALSE(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, is_empty_after_put_then_get)
{
    CircularBuffer_Put(buffer, 4567);
    CircularBuffer_Get(buffer);
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, put_get_one_value)
{
    CircularBuffer_Put(buffer, 4567);
    LONGS_EQUAL(4567, CircularBuffer_Get(buffer));
}

TEST(CircularBuffer, put_get_is_fifo)
{
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Put(buffer, 3);
    LONGS_EQUAL(1, CircularBuffer_Get(buffer));
    LONGS_EQUAL(2, CircularBuffer_Get(buffer));
    LONGS_EQUAL(3, CircularBuffer_Get(buffer));
}

TEST(CircularBuffer, report_capacity)
{
    LONGS_EQUAL(10, CircularBuffer_Capacity(buffer));
}

TEST(CircularBuffer, create_sets_capacity)
{
    CircularBuffer * buffer = CircularBuffer_Create(2, default_value);
    LONGS_EQUAL(2, CircularBuffer_Capacity(buffer));
    CircularBuffer_Destroy(buffer);
}

TEST(CircularBuffer, is_full_when_filled_to_capacity)
{
    fillTheQueue(CircularBuffer_Capacity(buffer));
    CHECK_TRUE(CircularBuffer_IsFull(buffer));
}

TEST(CircularBuffer, is_not_empty_when_filled_to_capacity)
{
    fillTheQueue(CircularBuffer_Capacity(buffer));
    CHECK_FALSE(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, is_not_full_after_get_from_full_buffer)
{
    fillTheQueue(CircularBuffer_Capacity(buffer));
    CircularBuffer_Get(buffer);
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
}

TEST(CircularBuffer, fill_then_empty)
{
    CircularBuffer * buffer = CircularBuffer_Create(2, default_value);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    LONGS_EQUAL(1, CircularBuffer_Get(buffer));
    LONGS_EQUAL(2, CircularBuffer_Get(buffer));
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}

TEST(CircularBuffer, force_a_buffer_wraparound)
{
    CircularBuffer * buffer = CircularBuffer_Create(2, default_value);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Get(buffer);
    CircularBuffer_Put(buffer, 1000);
    CHECK_TRUE(CircularBuffer_IsFull(buffer));
    LONGS_EQUAL(2, CircularBuffer_Get(buffer));
    LONGS_EQUAL(1000, CircularBuffer_Get(buffer));
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}

TEST(CircularBuffer, put_to_full_fails)
{
    CircularBuffer * buffer = CircularBuffer_Create(1, default_value);
    CircularBuffer_Put(buffer, 1);
    CHECK_FALSE(CircularBuffer_Put(buffer, 2));
    CircularBuffer_Destroy(buffer);
}

TEST(CircularBuffer, put_to_full_does_not_damage_contents)
{
    CircularBuffer * buffer = CircularBuffer_Create(1, default_value);
    CircularBuffer_Put(buffer, 1);
    CHECK_FALSE(CircularBuffer_Put(buffer, 2));
    LONGS_EQUAL(1, CircularBuffer_Get(buffer));
    CHECK_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}

TEST(CircularBuffer, get_from_empty_returns_default_value)
{
    LONGS_EQUAL(default_value, CircularBuffer_Get(buffer));
}

