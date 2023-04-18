/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая сортиирует массив методом вставок
 */

#include <stdio.h>
#include <stdbool.h>

#define OK 0         /// Ошибок не возникло
#define ERR_IO 1     /// Ошибка ввода
#define EXCEEDS 100  /// Ввод закончился принудительно
#define N 10         /// Максимальный размер массива

/// Ввод массива
int input(int arr[], size_t *a_size)
{
    int curr, code = OK;
    size_t size = 0;
    printf("Input arr: \n");
    while (size < N && scanf("%d", &curr) == 1)
    {
        arr[size] = curr;
        size++;
    }
    if (size == 0)
        code = ERR_IO;
    else if (scanf("%d", &curr) == 1)
        code = EXCEEDS;
    *a_size = size;
    return code;
}

/// Вывод массива
void print(const int arr[], size_t a_size)
{
    printf("Array: \n");
    for (size_t i = 0; i < a_size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ///Сортировка вставками
// void insert_sort(int arr[], size_t a_size)
// {
//     int key, j;
//     for (int i = 1; i < (int)a_size; i++)
//     {
//         key = arr[i];
//         j = i - 1;
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

void bubble_w_flag_sort(int arr[], size_t a_size)
{
    int tmp;
    bool flag = true;
    size_t i = 0;
    while (flag)
    {
        flag = false;
        for (size_t j = 0; j < a_size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
                flag = true;
            }
        }
        i++;
    }
}

int main(void)
{
    int arr[N];
    int code;
    size_t size;
    code = input(arr, &size);
    if (code == ERR_IO)
        printf("Array is empty");
    else if (code == OK || code == EXCEEDS)
    {
        bubble_w_flag_sort(arr, size);
        print(arr, size);
    }
    else
        printf("Unknown error");
    return code;
}
