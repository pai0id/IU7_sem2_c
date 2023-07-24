#include "errors.h"
#include <stdio.h>

void print_err(int rc)
{
    switch (rc)
    {
        case OK:
            break;
        case ERR_IO:
            printf("Input error\n");
            break;
        case ERR_BUF_TOO_SMALL:
            printf("Buffer overflow\n");
            break;
        case ERR_TOO_MANY_WORDS:
            printf("Too many words\n");
            break;
        case ERR_EMPTY_STR:
            printf("No words\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
}
