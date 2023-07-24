/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая определяет количество
 *  локальных максимумов в последовательности
 */

#include "codes.h"
#include "proc.h"

int main(void)
{
    int rc;
    int cnt;
    rc = process(stdin, &cnt);
    if (rc == OK)
        printf("Result: %d\n", cnt);
    else if (rc == ERR_IO)
        printf("Input error\n");
    else
        printf("Unknown error\n");
    return rc;
}
