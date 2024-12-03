#include <stdio.h>
#include "utils.h"
#include "sample_lib_test.c"

int main(){
    {
        // Call all test modules you want to run here
        sample_lib_test();
    }
    allsuccess();
}