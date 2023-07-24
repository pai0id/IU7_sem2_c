#include <stdio.h>
#include "codes.h"

void print_err(int rc)
{
    switch (rc)
    {
        case OK:
            break;
        case ERR_IO:
            printf("Input error\n");
            break;
        case ERR_SIZE:
            printf("Incorrect size\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
} 
