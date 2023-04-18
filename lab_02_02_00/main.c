/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая создает новый массив с элементами исходного массива,
 *  которые больше среднего арифметического
 */

#include <stdio.h>

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

/// Нахождение среднего арифметического
float find_avrg(const int a[], size_t a_size)
{
    int sum = 0;
    for (size_t i = 0; i < a_size; ++i)
    {
        sum += a[i];
    }
    return sum / (float)a_size;
}

/**
 *  Создает новый массив с элементами исходного массива,
 *  которые больше среднего арифметического
 */
void create_arr(const int a[], size_t a_size, int new_a[], size_t *new_a_size, float avrg)
{
    for (size_t i = 0; i < a_size; ++i)
    {
        if (a[i] > avrg)
        {
            new_a[*new_a_size] = a[i];
            (*new_a_size)++;
        }
    }
}

int main(void)
{
    int arr[N], new_arr[N];
    int code;
    float avrg;
    size_t size, new_size = 0;
    code = input(arr, &size);
    if (code == ERR_N)
        printf("Incorrect size\n");
    else if (code == ERR_IO)
        printf("Incorrect number\n");
    else if (code == OK)
    {
        avrg = find_avrg(arr, size);
        create_arr(arr, size, new_arr, &new_size, avrg);
        if (new_size == 0)
            code = ERR_RANGE;
        else
            code = OK;
    }
    else
        printf("Unknown error");
    if (code == ERR_RANGE)
        printf("Numbers not found");
    else if (code == OK)
        print(new_arr, new_size);
    else
        printf("Unknown error");
    return code;
}
