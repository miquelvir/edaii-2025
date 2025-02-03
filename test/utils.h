#ifndef ASSERTS_H
#define ASSERTS_H

void assertEquals(const char *found, const char *expected);
void assertEqualsInt(int found, int expected);
void success();
void running(const char *description);
void successtest();
void runningtest(const char *description);
void allsuccess();

#endif