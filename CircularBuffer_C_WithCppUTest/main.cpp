//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#include "CppUTest/CommandLineTestRunner.h"
#include <stdio.h>

//please do not change these messages
static const char * writing = "I'm writing and building.";
static const char * testing = "[  FAILED  ] Testing, with more to do.";
static const char * working = "[  PASSED  ] I'm done testing and my code works!";
static const char * test_driving = "I'm test-driving.";

int main(int ac, char** av)
{
    // see the instructions on setting your state in the exercise
    const char * exercise_state = writing;

    int result = RUN_ALL_TESTS(ac, av);

    printf("%s\n", exercise_state);

    return result;
}

