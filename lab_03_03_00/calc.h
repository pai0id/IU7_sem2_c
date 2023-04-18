#ifndef CALC_H
#define CALC_H

#include <stdio.h>

/// Меняет массивы местами.
/// Массивы существуют, размеры корректны.
///
/// \param one_arr [out] - первый массив
/// \param two_arr [out] - второй массив
/// \param size [in] - размер
///
void swap_arr(int one_arr[], int two_arr[], size_t size);

/// Упорядочивает строки матрицы по возрастанию суммы элементов.
/// Массив существует, размер корректный.
///
/// \param arr [out] - массив
/// \param a_n [in] - количество строчек
/// \param a_m [in] - количество столбцов
///
void sort(int arr[][M], size_t a_n, size_t a_m);

/// Находит сумму элементов массива.
/// Массив существует, размер корректный.
///
/// \param arr [in] - массив
/// \param size [in] - размер
///
/// \return сумма элементов
int calc_sum(const int arr[], size_t size);

#endif
