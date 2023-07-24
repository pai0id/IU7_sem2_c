#include "sizes.h"
#include "calc.h"

void swap_arr(int one_arr[], int two_arr[], size_t size)
{
    int tmp;
    for (size_t i = 0; i < size; ++i)
    {
        tmp = one_arr[i];
        one_arr[i] = two_arr[i];
        two_arr[i] = tmp;
    }
}

void m_swap(int matr[][M], size_t a_n)
{
    for (size_t i = 0; i < a_n / 2; ++i)
        swap_arr(matr[i] + i, matr[a_n - i - 1] + i, a_n - i * 2);
}
