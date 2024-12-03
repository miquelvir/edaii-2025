#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void assertEquals(const char* found, const char* expected){
    if (strcmp(expected, found) != 0){
        printf("\033[0;31m    Expected '%s' but found '%s'\033[0m\n\n", expected, found);
        assert(0);
    }
}

void assertEqualsInt(int found, int expected){
    if (expected != found){
        printf("\033[0;31m    Expected '%d' but found '%d'\033[0m\n\n", expected, found);
        assert(0);
    }
}

void assertNull(void* found){
    if (NULL != found){
        printf("\033[0;31m    Expected '%p' but found '%p'\033[0m\n\n", NULL, found);
        assert(0);
    }
}

void success(){
    printf("\033[0;32mPASSED\n\033[0m");
}

void running(const char* description){
    printf("\033[0;36mRunning: %s\033[0m\n", description);
}

void successtest(const char* description){
    printf("\033[0;32m    PASSED\033[0m\n");
}

void runningtest(const char* description){
    printf("\033[0;36m  - Running: %s\033[0m\n", description);
}