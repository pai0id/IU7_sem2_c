/*!
    \file
    \brief Заголовочный файл с описанием структуры
*/

#ifndef __STUD_H__
#define __STUD_H__

#define FAM_LEN 25
#define NAME_LEN 10
#define MARKS_N 4

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

struct student_t
{
    char fam[FAM_LEN + 1];
    char name[NAME_LEN + 1];
    uint32_t marks[MARKS_N];
};

/**
 * \brief Выводит информацию о студенте в заданный файл.
 *
 * \param f [in] - указатель на файл, в который будет выведена информация
 * \param s [in] - указатель на структуру, содержащую информацию о студенте
 */
void print_stud(FILE *f, struct student_t *s);

/**
 * \brief Считывает информацию о студенте из файла и сохраняет её в структуру.
 *
 * \param f [in] - указатель на файл, из которого будет считана информация
 * \param sp [out] - указатель на структуру, в которую будет сохранена информация о студенте
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 */
int get_stud(FILE *f, struct student_t *sp);

#endif
