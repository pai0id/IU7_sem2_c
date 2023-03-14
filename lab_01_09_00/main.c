/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, вычисляющая значение последовательности неотрицательных чисел
 */

#include <stdio.h>
#include <math.h>

#define OK 0         /// Ошибок не возникло
#define ERR_IO 1     /// Ошибка ввода

/**
 *  Функция, принимающая элементы последовательности и вычисляющая ее.
 *  Принимает указатель на переменную результата.
 */
int g_func(double *g)
{
    double res = 0;
    double x;
    int n = 1;
    if (scanf("%lf", &x) != 1 || x < 0.0)
    {
        return ERR_IO;
    }
    do
    {
        res += x / n;
        if (scanf("%lf", &x) != 1)
        {
            return ERR_IO;
        }
        n++;
    }
    while (x >= 0.0);
    *g = sqrt(res);
    return OK;
}

int main(void)
{
    double g;
    int code;
    printf("Input: ");
    code = g_func(&g);
    if (code == OK)
        printf("Result: %lf", g);
    else
        printf("Input error");
    return code;
}
