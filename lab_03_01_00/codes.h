#ifndef CODES_H
#define CODES_H

#define OK 0  /// Ошибок не возникло
#define ERR_IO 1  /// Ошибка ввода
#define ERR_SIZE 2  /// Неверный размер массива

/// \brief Вывод сообщения об ошибке.
///
/// \param rc [in] - код ошибки
///
void print_err(int rc);

#endif
