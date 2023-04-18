#ifndef IO_H
#define IO_H

#include <stdio.h>

/// Ввод двумерного массива.
/// Заполняемый массив существует.
///
/// \param arr [out] - матрица
/// \param a_n [out] - количество строчек
/// \param a_m [out] - количество столбцов
///
/// \return код ошибки (0 - корректно)
int input_matr(int arr[][M], size_t *a_n, size_t *a_m);

#endif
