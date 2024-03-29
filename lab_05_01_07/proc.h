#ifndef PROC_H
#define PROC_H

#include <stdio.h>

/** \brief Считывает последовательность и считает количество локальных максимумов.
 *
 * Файловая переменная существует и задана, счестчик существует.
 *
 * \param f [in] - файлова переменная ввода
 * \param cnt [out] - счетчик локальных максимумов
 *
 * \return Код ошибки:
 *         - OK, если файл успешно обработан
 *         - ERR_IO, если произошла ошибка ввода-вывода
 */
int process(FILE *f, int *cnt);

#endif
