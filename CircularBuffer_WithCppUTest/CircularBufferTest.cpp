//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#include "CppUTest/TestHarness.h"

extern "C"
{
#include "CircularBuffer.h"
}

// Everything in the test group is available
// to associated test cases
TEST_GROUP(CircularBuffer)
{
    CircularBuffer * buffer;
    unsigned int capacity = 10;
    int empty_value = -1;

    // setup runs before each test
    void setup()
    {
        buffer = CircularBuffer_Create(capacity, empty_value);
    }

    // teardown runs after each test
    void teardown()
    {
        CircularBuffer_Destroy(buffer);
    }
};

// each test gets a fresh CurcularBuffer
TEST(CircularBuffer, create_destroy)
{
    FAIL("Start here");
// These are all the macros you will need.
//    LONGS_EQUAL(0, 1); // will fail
//    CHECK_TRUE(false); // will fail
//    CHECK_FALSE(true); // will fail
}
