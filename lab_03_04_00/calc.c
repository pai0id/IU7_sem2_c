#include "sizes.h"
#include "codes.h"
#include "calc.h"

int find_num(int matr[][M], size_t a_n, int *res)
{
    *res = 0;
    for (size_t i = 1; i < a_n ; ++i)
        for (size_t j = 0; j < i ; ++j)
            if (matr[i][j] % 2 != 0 && (*res == 0 || matr[i][j] < *res))
                *res = matr[i][j];
    // res не может остаться равным 0, т.к. 0 % 2 == 0
    if (*res == 0)
        return ERR_NUM_NOT_FOUND;
    return OK;
}
