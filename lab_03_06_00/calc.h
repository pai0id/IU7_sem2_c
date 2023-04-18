#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdbool.h>

/// Заполняет матрицу ходом быка.
/// Массив существует, размер правильный.
///
/// \param matr [in] - матрица
/// \param a_n [in] - количество строчек
/// \param a_m [in] - количество столбцов
///
/// \return код ошибки (0 - числа найдены)
void fill_in(int arr[][M], size_t a_n, size_t a_m);

#endif
