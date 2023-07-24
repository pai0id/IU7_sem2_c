/**
 *  \author Андрей ИУ7-22Б
 * 
 *  Вариант 1, B - txt, A - bin
 * 
 *  Программа, обрабатывающая файлы с структурами.
 *  Вид структуры:
 *  а) Фамилия (<= 25 симв.)
 *  б) Имя (<= 10 симв.)
 *  в) Оценки по 4 предметам
 * 
 *  Для тестового файла:
 *  Вывод информации о студентах,
 *  фамилии которых начинаются с заданной подстроки, в другой файл.
 *  ./app.exe ft FILE_SRC FILE_DST SUBSTR
 * 
 *  Для бинарного файла:
 *  Сортировка студентов по фамилии, студенты с одинаковыми фамилиями
 *  должны быть упорядочены по имени. Результат выводится на экран.
 *  ./app.exe sb FILE
 */

#include <string.h>
#include <stdio.h>
#include "codes.h"
#include "stud_bin.h"
#include "stud_txt.h"

int main(int argc, char **argv)
{
    FILE *fp_in = NULL, *fp_out = NULL;
    struct student_t arr[N_STUDS];
    size_t n;
    int rc = OK;
    if (argc == 5 && strcmp(argv[1], "ft") == 0)
    {
        fp_in = fopen(argv[2], "r");
        fp_out = fopen(argv[3], "w");
        if (fp_in == NULL || fp_out == NULL)
            rc = ERR_NO_FILE;
        else
            rc = proc_file(fp_in, arr, &n, argv[4]);
        if (!rc)
            print_arr_to_file(fp_out, arr, n);
    }
    else if (argc == 3 && strcmp(argv[1], "sb") == 0)
    {
        fp_in = fopen(argv[2], "r+b");
        if (fp_in == NULL)
            rc = ERR_NO_FILE;
        else
            rc = sort_file(fp_in);
        if (!rc)
            print_file(fp_in);
    }
    else
        rc = ERR_ARGS;
    if (fp_in != NULL)
        fclose(fp_in);
    if (fp_out != NULL)
        fclose(fp_out);
    return rc;
}
