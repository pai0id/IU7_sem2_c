#ifndef CALC_H
#define CALC_H

#include <stdio.h>

/// Ищет минимальное нечетное число, расположенное под главной диагональю.
/// Матрица квадратная и существует, размер корректный.
///
/// \param arr [in] - матрица
/// \param a_n [in] - количество строчек
/// \param res [out] - искомое число
///
/// \return код ошибки (0 - число найдено)
int find_num(int matr[][M], size_t a_n, int *res);

#endif
