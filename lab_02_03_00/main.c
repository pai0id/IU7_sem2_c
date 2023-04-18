/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая удаляет из массива все числа-палиндромы
 */

#include <stdio.h>
#include <stdbool.h>

#define OK 0         /// Ошибок не возникло
#define ERR_N 1      /// Ошибка размера массива
#define ERR_IO 2     /// Ошибка ввода
#define ERR_RANGE 3  /// Ошибка диапазона
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

/// Вывод массива
void print(const int a[], size_t a_size)
{
    printf("Array: \n");
    for (size_t i = 0; i < a_size; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/// Проверка, является ли число палиндромом
bool is_pali(const int num)
{
    if (num <= 0)
        return false;
    int rev_num = 0;
    for (int i = num; i != 0; i /= 10)
    {
        rev_num = i % 10 + rev_num * 10;
    }
    if (num == rev_num)
        return true;
    return false;
}

/// Удаляет числа-палиндромы
int del_pali(int a[], size_t *a_size)
{
    size_t write_size = 0;
    for (size_t read_size = 0; read_size < *a_size; ++read_size)
    {
        if (! is_pali(a[read_size]))
        {
            a[write_size] = a[read_size];
            write_size++;
        }
    }
    if (write_size == 0)
        return ERR_RANGE;
    *a_size = write_size;
    return OK;
}

int main(void)
{
    int arr[N];
    int code;
    size_t size;
    code = input(arr, &size);
    if (code == ERR_N)
        printf("Incorrect size\n");
    else if (code == ERR_IO)
        printf("Incorrect number\n");
    else if (code == OK)
    {
        code = del_pali(arr, &size);
        if (code == ERR_RANGE)
            printf("Array is empty");
        else if (code == OK)
            print(arr, size);
        else
            printf("Unknown error");
    }
    else
        printf("Unknown error");
    return code;
}
