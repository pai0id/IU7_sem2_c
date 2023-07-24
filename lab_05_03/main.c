/**
 *  \author Андрей ИУ7-22Б
 * 
 *  Программа, создающая, сортирующая и
 *  выводящая на экран двоичные файлы с целыми числами.
 * 
 *  Для решения данной задачи я выбрал целочисленный тип int.
 * 
 *  Формат аргументов командной строки:
 *  1. app.exe c num filename - заполняет файл случайными числами
 *  num - количество заполняемых элементов
 *  2. app.exe p filename - выводит двоичный файл
 *  3. app.exe s filename - сортирует числа в файле
 * 
 *  Функции get_number_by_pos и put_number_by_pos - осмысленные функции.
 * 
 *  Сортировка производится методом пузырька, по возрастанию.
 */

#include <string.h>
#include <stdlib.h>
#include "file_proc.h"
#include "codes.h"

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    int rc = OK;
    int n;
    if (argc == 4 && strcmp(argv[1], "c") == 0)
    {
        fp = fopen(argv[3], "wb");
        n = atoi(argv[2]);
        if (n <= 0)
            rc = ERR_ARGS;
        else
            rc = fill_file(fp, n);
    }
    else if (argc == 3 && strcmp(argv[1], "p") == 0)
    {
        fp = fopen(argv[2], "rb");
        if (fp == NULL)
            rc = ERR_NO_FILE;
        else
            rc = print_file(fp);
    }
    else if (argc == 3 && strcmp(argv[1], "s") == 0)
    {
        fp = fopen(argv[2], "rb+");
        if (fp == NULL)
            rc = ERR_NO_FILE;
        else
            rc = sort_file(fp);
    }
    else
        rc = ERR_ARGS;
    if (fp != NULL)
        fclose(fp);
    return rc;
}
