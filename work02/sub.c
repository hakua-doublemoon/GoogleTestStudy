#include <stdio.h>

#include "mystr.h"
#include "sub.h"


int test1(const char* str)
{
    fprintf(stderr, "test print %s\n", str);
    return str_analyze(str, 10);
}

int test2(void)
{
    printf("Hello world\n");
    return 2;
}
