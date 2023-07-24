/**
 *  \author Андрей ИУ7-22Б
 * 
 *  Программа, которая определяет количество
 *  чисел больших среднего арифметического минимума и максимума
 */

#include "errors.h"
#include "proc.h"

int main(int argc, char **argv)
{
    int rc = OK;
    int cnt;
    FILE *fp;
    if (argc != 2)
        rc = ERR_NO_ARGS;
    if (!rc)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
            rc = ERR_NO_FILE;
    }
    if (!rc)
        rc = process(fp, &cnt);
    if (rc == OK)
        printf("Result: %d\n", cnt);
    if (rc != ERR_NO_ARGS && rc != ERR_NO_FILE)
        fclose(fp);
    print_errmsg(rc);
    return rc;
}
