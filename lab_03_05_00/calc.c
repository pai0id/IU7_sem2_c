#include "sizes.h"
#include "codes.h"
#include "calc.h"

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    for (int del = 2; del <= num / 2; ++del)
        if (num % del == 0)
            return false;
    return true;
}

int find_num(int matr[][M], size_t a_n, size_t a_m, int arr[], size_t *size_arr)
{
    *size_arr = 0;
    for (size_t i = 0; i < a_n ; ++i)
        for (size_t j = 0; j < a_m ; ++j)
            if (is_prime(matr[i][j]))
                arr[(*size_arr)++] = matr[i][j];
    if (!(*size_arr))
        return ERR_NUM_NOT_FOUND;
    return OK;
}

void reverse_arr(int arr[], size_t size_arr)
{
    int tmp;
    for (size_t i = 0; i < size_arr / 2; ++i)
    {
        tmp = arr[i];
        arr[i] = arr[size_arr - 1 - i];
        arr[size_arr - 1 - i] = tmp;
    }
}

void insert_arr(int matr[][M], size_t a_n, size_t a_m, int arr[], size_t size_arr)
{
    size_t i_insert = 0;
    for (size_t i = 0; i < a_n ; ++i)
    {
        for (size_t j = 0; j < a_m ; ++j)
        {
            if (is_prime(matr[i][j]))
                matr[i][j] = arr[i_insert++];
            if (i_insert == size_arr)
                break;
        }
    }
}
