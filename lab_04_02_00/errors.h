#ifndef ERRORS_H
#define ERRORS_H

#define OK 0                    /// Успешное выполнение операции
#define ERR_IO 1                /// Ошибка ввода-вывода
#define ERR_BUF_TOO_SMALL 2     /// Размер буфера превышен
#define ERR_TOO_MANY_WORDS 3    /// Количество слов превышает максимально допустимое значение
#define ERR_EMPTY_STR 4         /// В строке нет слов

/// \brief Вывод сообщения ошибки
void print_err(int rc);

#endif
