/*!
    \file
    \brief Заголовочный файл с модулями для работы с структуами в двоичном файле
*/

#ifndef __STUD_BIN_H__
#define __STUD_BIN_H__

#include <stdio.h>
#include <string.h>
#include "codes.h"
#include "stud.h"

/** \brief Читает структуру в заданной позиции.
 *
 * Файловая переменная существует и задана.
 *
 * \param f [in] - файлова переменная
 * \param pos [in] - позиция в файле
 * \param num [out] - структура
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 *         - ERR_RANGE, если позиция некорректна
 */
int get_struct_by_pos(FILE *f, size_t pos, struct student_t *stud);

/** \brief Записывает структуру в позицию.
 *
 * Файловая переменная существует и задана.
 *
 * \param f [out] - файлова переменная
 * \param pos [in] - позиция в файле
 * \param num [in] - структура
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 *         - ERR_RANGE, если позиция некорректна
 */
int put_struct_by_pos(FILE *f, size_t pos, const struct student_t *stud);

/** \brief Выводит содержимое двоичного файла.
 *
 * Файловая переменная существует и задана.
 *
 * \param f [in] - файлова переменная
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 */
int print_file(FILE *f);

/**
 * \brief Сортирует содержимое двоичного файла с информацией о студентах.
 *
 * Функция считывает содержимое двоичного файла, содержащего информацию о студентах, и сортирует его.
 * Сортировка выполняется методом пузырька.
 *
 * \param f [in] - указатель на двоичный файл, который требуется отсортировать
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 *         - ERR_F_EMPTY, если файл пустой
 */
int sort_file(FILE *f);

#endif
