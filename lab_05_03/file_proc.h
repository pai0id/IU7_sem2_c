/*!
    \file
    \brief Заголовочный файл с описанием модулей работы с файлами
*/

#ifndef FILE_PROC_H
#define FILE_PROC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "codes.h"

/** \brief Заполняет бинарный файл n случайными числами.
 *
 * Файловая переменная существует и задана.
 *
 * \param f [out] - файлова переменная
 * \param n [in] - количество элементов
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 */
int fill_file(FILE *f, size_t n);

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

/** \brief Читает число в заданной позиции.
 *
 * Файловая переменная существует и задана.
 *
 * \param f [in] - файлова переменная
 * \param pos [in] - позиция в файле
 * \param num [out] - число
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 *         - ERR_RANGE, если позиция некорректна
 */
int get_number_by_pos(FILE *f, size_t pos, int *num);

/** \brief Записывает число в позицию.
 *
 * Файловая переменная существует и задана.
 *
 * \param f [out] - файлова переменная
 * \param pos [in] - позиция в файле
 * \param num [in] - число
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 *         - ERR_RANGE, если позиция некорректна
 */
int put_number_by_pos(FILE *f, size_t pos, const int *num);

/** \brief Сортирует числа в файле.
 *
 * Файловая переменная существует и задана.
 *
 * \param f [in] - файлова переменная
 * 
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 */
int sort_file(FILE *f);

#endif
