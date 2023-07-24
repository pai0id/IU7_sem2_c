/*!
    \file
    \brief Заголовочный файл с описанием кодов ошибок
*/

#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>

#define OK 0            /// Ошибок не возникло
#define ERR_IO 1        /// Ошибка ввода
#define ERR_NO_ARGS 2   /// Название файла не передано
#define ERR_NO_FILE 3   /// Файл не существует

/** \brief Выводит сообщение соответствующего кода ошибки.
 *
 * \param rc [in] - код ошибки
 */
void print_errmsg(int rc);

#endif
