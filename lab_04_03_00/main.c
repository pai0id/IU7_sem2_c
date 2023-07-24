/**
 *  \authors Андрей ИУ7-22Б
 * 
 *  Программа, которая разбивает строку на слова,
 *  удаляет из каждого все повторения первого символа
 *  и записывает в новую строку в обратном порядке.
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
    char new_str[STR_LEN + 1];
    rc = get_line(str, STR_LEN + 1);
    if (!rc)
        rc = parse_string(str, words, &words_n);
    if (!rc && words_n == 0)
        rc = ERR_EMPTY_STR;
    if (!rc)
        rc = form_string(words, words_n, new_str);
    if (!rc)
        printf("Result:%s\n", new_str);
    print_err(rc);
    return rc;
}
