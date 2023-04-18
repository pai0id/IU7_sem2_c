#ifndef IO_H
#define IO_H

#include <stdio.h>

/// Ввод двумерного массива.
/// Заполняемый массив существует.
///
/// \param arr [out] - матрица
/// \param a_n [out] - количество строчек
/// \param a_m [out] - количество столбцов
/// \param num [out] - цифра для анализа строк
///
/// \return код ошибки (0 - корректно)
int input_matr(int arr[][M], size_t *a_n, size_t *a_m, short *num);

/// Вывод двумерного массива.
/// Массив существует, размер корректный.
///
/// \param arr [in] - массив
/// \param a_n [in] - количество строчек
/// \param a_m [in] - количество столбцов
///
void print_matr(int arr[][M], size_t a_n, size_t a_m);

#endif
