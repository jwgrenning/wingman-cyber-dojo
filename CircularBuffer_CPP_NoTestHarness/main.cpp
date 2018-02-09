//- Copyright (c) 2018 James Grenning -- See license.txt at https://github.com/jwgrenning/wingman-cyber-dojo

#include "CircularBuffer.h"
#include <iostream>

//please do not change these messages
const char * writing = "I'm writing and building.";
const char * testing = "[  FAILED  ] Testing, with more to do.";
const char * working = "[  PASSED  ] I'm done testing and my code works!.";

int main(int ac, char** av)
{
    // see the instructions on setting your state in the exercise
    const char * exercise_state = writing;

    unsigned int capacity = 10;
    int empty_value = -1;

    CircularBuffer buffer(capacity, empty_value);

    std::cout << exercise_state << std::endl;
    
    return 0;
}

