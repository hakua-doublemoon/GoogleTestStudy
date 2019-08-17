#include <stdio.h>
#include "sub.h"

void main(int argc, char** argv)
{
    if (argc > 1) {
        int r = test1(argv[1]);
        printf("test2 is returned : %d\n", r);
    } else {
        test2();
    }
}

