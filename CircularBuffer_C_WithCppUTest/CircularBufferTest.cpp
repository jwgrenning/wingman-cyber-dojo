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

// PUSH THE TEST BUTTON WHEN YOU START TO WORK
// Pushing the test button saves your work and runs the build.

// each test gets a fresh CurcularBuffer
TEST(CircularBuffer, create_destroy)
{
    FAIL("Start here");
}

// Each test in a group has a unique name
// Make as many tests as you like
TEST(CircularBuffer, test_with_all_the_macros_you_should_need_for_this_exercise)
{
    LONGS_EQUAL(1, 1);
    CHECK_TRUE(true);
    CHECK_FALSE(false);
    // If you are not used to a xUnit style of test harness,
    // please do the other exercise offered in the invitation.
    // find more about CppUTest at cpputest.org
}
