/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая выводит минимальное нечетное число,
 *  расположенное под главной диагональю
 */

#include "sizes.h"
#include "codes.h"
#include "IO.h"
#include "calc.h"

int main(void)
{
    int matr[N][M];
    size_t a_n, a_m;
    int res;
    int rc = OK;
    rc = input_matr(matr, &a_n, &a_m);
    if (!rc)
    {
        rc = find_num(matr, a_n, &res);
        if (!rc)
            printf("%d", res);
    }
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
        case ERR_NOT_KV:
            printf("The matrix is ​​not square\n");
            break;
        case ERR_NUM_NOT_FOUND:
            printf("Number not found\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
    return rc;
}
