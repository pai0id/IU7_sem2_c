/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая вставляет строчки 100 после строк,
 *  в которых равно количество чисел,
 *  начинающихся и заканчивающихся на заданную цифру
 */

#include "codes.h"
#include "sizes.h"
#include "IO.h"
#include "calc.h"

int main(void)
{
    int matr[N][M];
    size_t a_n, a_m;
    short num;
    int rc = OK;
    rc = input_matr(matr, &a_n, &a_m, &num);
    if (!rc)
    {
        browse_lines(matr, &a_n, a_m, num);
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
