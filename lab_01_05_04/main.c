/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, раскладывающая на простые множители натуральное число
 */

#include <stdio.h>

#define OK 0         /// Ошибок не возникло
#define ERR_IO 1     /// Ошибка ввода
#define ERR_RANGE 2  /// Ошибка: число не натуральное

/**
 *  Функция, раскладывающая натуральное число на простые множители
 *  и печатающая их.
 *  Принимает натуральное число
 */
void decompose_n_print(int n)
{
    int div = 2;
    printf("Res ");
    int isfirst = 1;
    while (n > 1)
    {
        while (n % div == 0)
        {
            if (! isfirst)
            {
                printf("%c %d ", '*', div);
            }
            else
            {
                printf("%c %d ", '=', div);
                isfirst = 0;
            }
            n /= div;
        }
        div++;
    }
}

int main(void)
{
    int num;
    printf("Input number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Input Error");
        return ERR_IO;
    }
    if (num <= 0)
    {
        printf("Range Error");
        return ERR_RANGE;
    }
    if (num != 1)
        decompose_n_print(num);
    return OK;
}
