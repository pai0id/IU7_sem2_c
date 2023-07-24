/**
 *  \authors Андрей ИУ7-22Б
 * 
 *  Программа, которая разбивает строку на слова и выводит
 *  на экран количество вхождений каждого слова в строке
 * 
 */

#include <stdio.h>
#include "errors.h"
#include "sizes.h"
#include "str_funcs.h"

int main(void)
{
    int rc;
    char str[STR_LEN + 1];
    char words[WRD_CNT][WRD_LEN + 1];
    size_t words_n;
    char uniwords[WRD_CNT][WRD_LEN + 1];
    size_t uniwords_n;
    int cnt_uniwords[WRD_CNT];
    rc = get_line(str, STR_LEN + 1);
    if (!rc)
        rc = parse_string(str, words, &words_n);
    if (!rc && words_n == 0)
        rc = ERR_EMPTY_STR;
    if (!rc)
    {
        get_counts(words, words_n, uniwords, &uniwords_n, cnt_uniwords);
        print_counts(uniwords, uniwords_n, cnt_uniwords);
    }
    print_err(rc);
    return rc;
}
