#ifndef CALC_H
#define CALC_H

#include <stdio.h>

/// Ищет столбцы, упорядоченые по убыванию и заполняет результирующий массив.
/// Матрица существует, размер корректный.
///
/// \param arr [in] - матрица
/// \param a_n [in] - количество строчек
/// \param a_m [in] - количество столбцов
/// \param res_arr [out] - результирующий массив
///
void analyze_matr(int arr[][M], size_t a_n, size_t a_m, int res_arr[]);

/// Проверяет, упорядочен ли по убыванию столбец матрицы.
/// Матрица существует, размер корректный, столбец корректный.
///
/// \param arr [in] - матрица
/// \param a_n [in] - количество строчек
/// \param i_column [in] - номер столбца
///
/// \return 1 - упорядочен, 0 - не упорядочен
int is_descending(int arr[][M], size_t a_n, size_t i_column);

#endif
