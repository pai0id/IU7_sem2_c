#include "sizes.h"
#include "calc.h"

int is_descending(int arr[][M], size_t a_n, size_t i_column)
{
    // Если столбец состоит из одного элемента, он не упорядочен ли по убыванию
    if (a_n == 1)
        return 0;
    // Прохожусь по элементам столбца
    for (int (*p)[M] = arr; p < arr + a_n - 1; ++p)
        // Если следующий элемент не строго убывающий, столбец не подходит
        if ((*(p + 1))[i_column] >= (*p)[i_column])
            return 0;
    // Столбец прошел проверку
    return 1;
}

void analyze_matr(int arr[][M], size_t a_n, size_t a_m, int res_arr[])
{
    for (size_t i = 0; i < a_m; ++i)
        res_arr[i] = is_descending(arr, a_n, i);
}
