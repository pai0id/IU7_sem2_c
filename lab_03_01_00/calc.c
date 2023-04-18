#include "sizes.h"
#include "calc.h"

int is_descending(int arr[][M], size_t a_n, size_t i_column)
{
    int diff = 0;
    for (int (*p)[M] = arr; p < arr + a_n - 1; ++p)
    {
        if ((*(p + 1))[i_column] >= (*p)[i_column])
            return 0;
        if ((*(p + 1))[i_column] != (*p)[i_column])
            diff = 1;
    }
    if (diff)
        return 1;
    return 0;
}

void analyze_matr(int arr[][M], size_t a_n, size_t a_m, int res_arr[])
{
    for (size_t i = 0; i < a_m; ++i)
        res_arr[i] = is_descending(arr, a_n, i);
}
