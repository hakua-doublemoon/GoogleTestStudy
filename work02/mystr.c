#include <stdio.h>

int str_analyze(const char* str, int max)
{
    int l;
    for (l = 0; l < max; l++) {
        if (str[l] == '\0') break;
    }
    return l;
}
