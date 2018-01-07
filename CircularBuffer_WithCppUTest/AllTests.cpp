//- Copyright (c) 2008-2016 James Grenning --- All rights reserved
//- For exclusive use by participants in Wingman Software training courses.
//- Cannot be used by attendees to train others without written permission.
//- www.wingman-sw.com james@wingman-sw.com


#include "CppUTest/CommandLineTestRunner.h"
#include <stdio.h>

//please do not change these messages
const char * writing = "I'm writing and building the code.";
const char * testing = "[  FAILED  ] Testing, with more to do.";
const char * working = "[  PASSED  ] I'm done testing and my code is working.";
const char * test_driving = "I'm test-driving the code.";

int main(int ac, char** av)
{
    // see the instructions on setting your state in the exercise
    const char * exercise_state = writing;
    printf("%s\n", exercise_state);
    return RUN_ALL_TESTS(ac, av);

}

