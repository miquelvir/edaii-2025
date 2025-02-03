#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assertEquals(const char *found, const char *expected) {
  if (strcmp(expected, found) != 0) {
    fprintf(stderr, "\033[0;31m    Expected '%s' but found '%s'\033[0m\n\n",
            expected, found);
    assert(0);
  }
}

void assertEqualsInt(int found, int expected) {
  if (expected != found) {
    fprintf(stderr, "\033[0;31m    Expected '%d' but found '%d'\033[0m\n\n",
            expected, found);
    assert(0);
  }
}

void assertNull(void *found) {
  if (NULL != found) {
    fprintf(stderr, "\033[0;31m    Expected '%p' but found '%p'\033[0m\n\n",
            NULL, found);
    assert(0);
  }
}

void success() { fprintf(stderr, "\033[0;32mPASSED\n\033[0m"); }

void running(const char *description) {
  fprintf(stderr, "\033[0;36mRunning: %s\033[0m\n", description);
}

void successtest() { fprintf(stderr, "\033[0;32m    PASSED\033[0m\n"); }

void runningtest(const char *description) {
  fprintf(stderr, "\033[0;36m  - Running: %s\033[0m\n", description);
}

void allsuccess() {
  fprintf(stderr, "\033[0;32m--- ALL TESTS PASSED --- \n\033[0m");
}