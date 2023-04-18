/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая вычисляет sum(X[n]*Y[n]),
 *  n = [0 to k-1] X - отрицательные эл. Y - полож. эл.
 */

#include <stdio.h>
#include <stdbool.h>

#define OK 0         /// Ошибок не возникло
#define ERR_N 1      /// Ошибка размера массива
#define ERR_IO 2     /// Ошибка ввода
#define ERR_RANGE 3  /// Ошибка диапазона
#define N 10         /// Максимальный размер массива

/// Ввод массива
int input(int *pa_st, int **pa_ed)
{
    size_t a_size;
    printf("Input n: ");
    if (scanf("%zu", &a_size) != 1)
    {
        return ERR_N;
    }
    if (a_size > N || a_size <= 0)
    {
        return ERR_N;
    }
    *pa_ed = pa_st + a_size;
    int *tmp_p = pa_st;
    while (tmp_p != *pa_ed)
    {
        if (scanf("%d", tmp_p) != 1)
        {
            return ERR_IO;
        }
        tmp_p++;
    }
    return OK;
}

/// Вычисления
int calc(int *pa_st, int *pa_ed, int *summ)
{
    int *tmp_fw, *tmp_bckw;
    *summ = 0;
    tmp_fw = pa_st - 1;
    tmp_bckw = pa_ed;
    while (tmp_fw != pa_ed && tmp_bckw != pa_st - 1)
    {
        do
            tmp_fw++;
        while (tmp_fw != pa_ed && *tmp_fw >= 0);
        do
            tmp_bckw--;
        while (tmp_bckw != pa_st - 1 && *tmp_bckw <= 0);
        if (tmp_fw != pa_ed && tmp_bckw != pa_st - 1)
            *summ += (*tmp_bckw) * (*tmp_fw);
    }
    if (*summ == 0)
        return ERR_IO;
    return OK;
}

int main(void)
{
    int arr[N], summ;
    int *arr_st = arr;
    int *arr_end = arr + N;
    int code;
    code = input(arr_st, &arr_end);
    if (code == ERR_N)
        printf("Incorrect size\n");
    else if (code == ERR_IO)
        printf("Incorrect number\n");
    else if (code == OK)
    {
        code = calc(arr_st, arr_end, &summ);
        if (code == ERR_IO)
            printf("IO error\n");
        else if (code == OK)
            printf("Result: %d\n", summ);
        else
            printf("Unknown error");
    }
    else
        printf("Unknown error");
    return code;
}
