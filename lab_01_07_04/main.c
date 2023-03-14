/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, вычисляющая приближённое и точное значения функции 1/(1+х)^3,
 *  абсолютную и относительную погрешности
 */

#include <stdio.h>
#include <math.h>

#define OK 0         /// Ошибок не возникло
#define ERR_IO 1     /// Ошибка ввода
#define ERR_RANGE 2  /// Ошибка: |x|>=1 или eps<=0 или eps>1

/**
 *  Функция, вычисляющая точное значение функции.
 *  Принимает параметр х.
 */
double f_func(double x)
{
    return 1.0 / pow(1 + x, 3);
}

/**
 *  Функция, вычисляющая приближённое значение функции.
 *  Принимает параметр х и точность eps.
 */
double s_func(double x, double eps)
{
    double sum = 1.0, prev_x = 1.0;
    int n = 0;
    while (fabs(prev_x) >= eps)
    {
        n++;
        prev_x *= -x * (n + 2) / n;
        sum += prev_x;
    }
    return sum;
}

int main(void)
{
    double x, eps;
    double f, s, abs_delt, relative_delt;
    printf("Input x and eps: ");
    if (scanf("%lf %lf", &x, &eps) != 2)
    {
        printf("Input Error");
        return ERR_IO;
    }
    if (fabs(x) >= 1 || eps <= 0 || eps > 1)
    {
        printf("Range error");
        return ERR_RANGE;
    }
    f = f_func(x);
    s = s_func(x, eps);
    abs_delt = fabs(f - s);
    relative_delt = abs_delt / fabs(f);
    printf("s(x) = %f \nf(x) = %f \nabs_delt = %f \nrelative_delt = %f",
    s, f, abs_delt, relative_delt);
    return OK;
}
