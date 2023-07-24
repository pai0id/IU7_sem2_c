/*!
    \file
    \brief Заголовочный файл с описанием модуля работы с файлами
*/

#ifndef PROC_H
#define PROC_H

#include <stdio.h>
#include <math.h>

/** \brief Считывает последовательность и считает количество чисел,
 *  больших среднего арифметического минимума и максимума.
 *
 * Файловая переменная существует и задана, счестчик существует.
 *
 * \param f [in] - файлова переменная ввода
 * \param cnt [out] - счетчик
 *
 * \return Код ошибки:
 *         - OK, если файл успешно обработан
 *         - ERR_IO, если произошла ошибка ввода-вывода
 */
int process(FILE *f, int *cnt);

#endif
