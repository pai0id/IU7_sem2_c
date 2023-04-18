#include "sizes.h"
#include "calc.h"


void swap_arr(int one_arr[], int two_arr[], size_t size)
{
    int tmp;
    for (size_t i = 0; i < size; ++i)
    {
        tmp = one_arr[i];
        one_arr[i] = two_arr[i];
        two_arr[i] = tmp;
    }
}

int calc_sum(const int arr[], size_t size)
{
    int res = 0;
    for (size_t i = 0; i < size; ++i)
        res += arr[i];
    return res;
}

void sort(int arr[][M], size_t a_n, size_t a_m)
{
    /// Переменная для отслеживания,
    /// были ли произведены изменения в массиве на текущей итерации
    int flag = 1;
    /// Суммы элементов текущей и следующей строки
    int sum1, sum2;
    /// Уменьшение количества итераций цикла for
    size_t i = 0;
    while (flag)
    {
        flag = 0;
        for (size_t j = 0; j < a_n - i - 1; ++j)
        {
            /// Вычисляем суммы элементов текущей и следующей строк
            sum1 = calc_sum(arr[j], a_m);
            sum2 = calc_sum(arr[j + 1], a_m);
            /// Если сумма текущей строки больше, чем сумма следующей строки,
            /// меняем строки местами и обозначаем, что массив бы изменен
            if (sum1 > sum2)
            {
                swap_arr(arr[j], arr[j + 1], a_m);
                flag = 1;
            }
            /// Если суммы равны
            else if (sum1 == sum2)
            {
                /// Меняем местами, если первый отличающийся элемент
                /// текущей строки больше следующей и обозначаем,
                /// что массив бы изменен
                for (size_t k = 0; k < a_m; ++k)
                {
                    if (arr[j][k] < arr[j + 1][k])
                        break;
                    else if (arr[j][k] > arr[j + 1][k])
                    {
                        swap_arr(arr[j], arr[j + 1], a_m);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        /// Увеличиваем i на каждой итерации
        i++;
    }
}
