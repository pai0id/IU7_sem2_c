/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, циклически сдвигающая а на n позиций вправо
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

#define OK 0         /// Ошибок не возникло
#define ERR_IO 1     /// Ошибка ввода
#define ERR_RANGE 2  /// Ошибка: a < 0

/**
 *  Функция, переводящая число из десятичной сс в двоичную и печатающая его.
 *  Принимает параметр х.
 */
void dec_to_bin_n_print(uint32_t x)
{
    size_t nbits = sizeof(x) * CHAR_BIT;
    uint32_t mask = (uint32_t)1 << (nbits - 1);
    for (size_t i = 0; i < nbits; ++i)
    {
        if (x & mask)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
    printf("\n");
}

/**
 *  Функция, циклически сдвигающая а на n позиций вправо.
 *  Принимает указатель на а и целое n.
 */
void move(uint32_t *a, int n)
{
    uint32_t nbits = sizeof(*a) * CHAR_BIT;
    uint32_t mask = 1;
    uint32_t num = *a;
    n %= nbits;
    for (int i = 0; i < n; ++i)
        num = (num >> 1) | ((num & mask) << (nbits - 1));
    *a = num;
}

int main(void)
{
    uint32_t a;
    int n;
    printf("Input a and n: ");
    if (scanf("%" SCNu32 "%d", &a, &n) != 2)
    {
        printf("Error: Input Error");
        return ERR_IO;
    }
    if (n < 0)
    {
        printf("Error: Range error");
        return ERR_RANGE;
    }
    move(&a, n);
    printf("Result: ");
    dec_to_bin_n_print(a);
    return OK;
}
