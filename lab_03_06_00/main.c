/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая вводит матрицу ходом быка
 */

#include "sizes.h"
#include "codes.h"
#include "IO.h"
#include "calc.h"

int main(void)
{
    int matr[N][M];
    size_t a_n, a_m;
    int rc = OK;
    rc = input_matr(&a_n, &a_m);
    if (!rc)
    {
        fill_in(matr, a_n, a_m);
        print_matr(matr, a_n, a_m);
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
        default:
            printf("Unknown error\n");
            break;
    }
    return rc;
}
