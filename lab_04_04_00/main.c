/**
 *  \authors Андрей ИУ7-22Б
 * 
 *  Программа, которая проверяет корректность IP адреса.
 * 
 */

#include <stdio.h>
#include "errors.h"
#include "sizes.h"
#include "str_funcs.h"

int main(void)
{
    int rc;
    char str[STR_LEN];
    rc = get_line(str, STR_LEN);
    if (!rc)
        rc = check_string(str);
    if (rc == OK)
        printf("YES");
    else if (rc == ERR_NOT_IP)
    {
        rc = OK;
        printf("NO");
    }
    return rc;
}
