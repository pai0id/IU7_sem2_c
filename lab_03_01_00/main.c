/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая создает одномерный массив, k-й элемент = 1,
 *  если k-й столбец матрицы упорядочен по убыванию, иначе 0
 */

#include "sizes.h"
#include "codes.h"
#include "calc.h"
#include "IO.h"

int main(void)
{
    int matr[N][M];
    size_t a_n, a_m;
    int res[M];
    int rc = OK;
    rc = input_matr(matr, &a_n, &a_m);
    if (!rc)
    {
        analyze_matr(matr, a_n, a_m, res);
        print_arr(res, a_m);
    }
    print_err(rc);
    return rc;
}
