/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, определяющая, принадлежит ли точка отрезку
 */

#include <stdio.h>
#include <math.h>

#define OK 0         /// Ошибок не возникло
#define ERR_IO 1     /// Ошибка ввода
#define ERR_LINE 2   /// Ошибка: концы отрезка совпадают
#define GOOD_RES 1  
#define BAD_RES 0

/**
 *  Функция, вычисляющая длину отрезка по координатам его концов.
 *  Принимает координаты концов отрезка.
 */
double len_line(double xa, double ya, double xb, double yb)
{
    return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

/**
 *  Функция, вычисляющая, принадлежит ли точка отрезку.
 *  Принимает координаты концов отрезка и точки.
 */
int is_inside(double xq, double yq, double xr, double yr, double xp, double yp, double eps)
{
    double len_of_segment, first_len_to_dot, second_len_to_dot;
    len_of_segment = len_line(xq, yq, xr, yr);
    first_len_to_dot = len_line(xq, yq, xp, yp);
    second_len_to_dot = len_line(xr, yr, xp, yp);
    if (fabs(len_of_segment - (first_len_to_dot + second_len_to_dot)) < eps)
        return GOOD_RES;
    else
        return BAD_RES;
}

int main(void)
{
    const double eps = 0.0000001;
    int res;
    double xq, yq, xr, yr, xp, yp;
    printf("Input coordinates(xq, yq, xr, yr, xp, yp): ");
    if (scanf("%lf %lf %lf %lf %lf %lf", &xq, &yq, &xr, &yr, &xp, &yp) != 6)
    {
        printf("Input Error");
        return ERR_IO;
    }
    if (fabs(xq - xr) < eps && fabs(yq - yr) < eps)
    {
        printf("Segment is a dot");
        return ERR_LINE;
    }
    res = is_inside(xq, yq, xr, yr, xp, yp, eps);
    printf("Result: %d\n", res);
    return OK;
}

