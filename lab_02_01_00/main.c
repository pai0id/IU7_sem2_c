/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, вычисляющая сумму четных элементов массива
 */

#include <stdio.h>
#include <stdlib.h>

#define OK 0         /// Ошибок не возникло
#define ERR_N 1      /// Ошибка размера массива
#define ERR_IO 2     /// Ошибка ввода
#define ERR_SUMM 3   /// В массиве нет целых чисел
#define N 10         /// Максимальный размер массива

/// Ввод массива
int input(int a[], size_t *a_size)
{
    printf("Input n: ");
    if (scanf("%zu", a_size) != 1)
    {
        return ERR_N;
    }
    if (*a_size > N || *a_size <= 0)
    {
        return ERR_N;
    }
    for (size_t i = 0; i < *a_size; i++)
    {
        if (scanf("%d", a + i) != 1)
        {
            return ERR_IO;
        }
    }
    return OK;
}

/// Вычисление суммы четных чисел
int calc_sum_even(const int a[], size_t a_size, int *sum)
{
    *sum = 0;
    int has_evens = 0;
    for (size_t i = 0; i < a_size; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (has_evens == 0)
                has_evens = 1;
            *sum += a[i];
        }
    }
    if (! has_evens)
    {
        return ERR_SUMM;
    }
    return OK;
}

int main(void)
{
    int arr[N];
    int code, sum_even;
    size_t size;
    code = input(arr, &size);

    if (code == ERR_N)
        printf("Incorrect size\n");
    else if (code == ERR_IO)
        printf("Incorrect number\n");
    else if (code == OK)
    {
        code = calc_sum_even(arr, size, &sum_even);
        if (code == ERR_SUMM)
            printf("Array has no even numbers\n");
        else if (code == OK)
            printf("Result: %d \n", sum_even);
        else
            printf("Unknown error");
    }
    else
        printf("Unknown error");
    return code;
}
