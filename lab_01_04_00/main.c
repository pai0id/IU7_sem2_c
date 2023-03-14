/**
 *  Поляков Андрей ИУ7-22Б
 *  Программа, вычисляющая наибольшее возможное количество бутылок воды,
 *  которые можно купить
 */

#include <stdio.h>

int main(void)
{
    const int bottle_sell_price = 20;   // Цена продажи бутылки
    const int price_delta = 25;  // Разница цены покупки и продажи бутылки
    int num;
    int res;
    printf("Input amount: ");
    scanf("%d", &num);
    res = (num - bottle_sell_price) / price_delta;
    printf("Result = %d", res);
    return 0;
}

