/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая элементы матрицы, которые являются простыми числами
 *  помещает в матрицу в обратном порядке
 */

#include "sizes.h"
#include "codes.h"
#include "IO.h"
#include "calc.h"

int main(void)
{
    int matr[N][M];
    int arr[N * M];
    size_t a_n, a_m, size_arr;
    int rc = OK;
    rc = input_matr(matr, &a_n, &a_m);
    if (!rc)
        rc = find_num(matr, a_n, a_m, arr, &size_arr);
    if (!rc)
    {
        reverse_arr(arr, size_arr);
        insert_arr(matr, a_n, a_m, arr, size_arr);
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
        case ERR_NUM_NOT_FOUND:
            printf("Numbers not found\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
    return rc;
}
