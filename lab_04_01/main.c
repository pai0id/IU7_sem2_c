/**
 *  \authors Андрей ИУ7-22Б
 * 
 *  Сравнение поведения реализованных и 
 *  библиотечных функций работы со строками
 */

#include "tests.h"
#include <stdio.h>

int main(void)
{
    int cnt = 0;
    test_strpbrk(&cnt);
    test_strspn(&cnt);
    test_strcspn(&cnt);
    test_strchr(&cnt);
    test_strrchr(&cnt);
    printf("%d", cnt);
    return cnt;
}
