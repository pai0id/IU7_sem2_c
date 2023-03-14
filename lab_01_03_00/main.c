/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, которая вычисляет нормальный вес и индексы массы тела человека
 */

#include <stdio.h>

int main(void)
{
    const int cm_to_m_index = 100;  // Количество сантиметров в метре
    double h, t, m;
    double m_n, bmi;
    printf("Input h, t, m: ");
    scanf("%lf %lf %lf", &h, &t, &m);
    m_n = h * t / 240.0;
    h /= cm_to_m_index;
    bmi = m / (h * h);
    printf("M_normal, BMI = %f , %f", m_n, bmi);
    return 0;
}
