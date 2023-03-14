/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая находит периметр трапеции по ее высоте и основаниям
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, h;
    double t, c, p;
    printf("Input a, b, h: ");
    scanf("%lf %lf %lf", &a, &b, &h);
    t = (b - a) / 2.0;
    c = sqrt(t * t + h * h);
    p = a + b + 2 * c;
    printf("P = %f", p);
    return 0;
}
