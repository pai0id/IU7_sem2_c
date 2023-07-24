#include "errors.h"

void print_errmsg(int rc)
{
    switch (rc)
    {
        case OK:
            break;
        case ERR_IO:
            printf("Input error\n");
            break;
        case ERR_NO_ARGS:
            printf("Incorrect file name\n");
            break;
        case ERR_NO_FILE:
            printf("No such file\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
}
