#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdbool.h>

/// Поиск простых чисел и создание массива из них.
/// Исходный массив существует, размер правильный.
///
/// \param matr [in] - матрица
/// \param a_n [in] - количество строчек
/// \param a_m [in] - количество столбцов
/// \param arr [out] - массив
/// \param size_arr [out] - размер
///
/// \return код ошибки (0 - числа найдены)
int find_num(int matr[][M], size_t a_n, size_t a_m, int arr[], size_t *size_arr);

/// Проверяет, является ли число простым.
///
/// \param num [in] - число
///
/// \return true, если простое, false, если нет
bool is_prime(int num);

/// Переворачивает массив.
/// Массив существует, размер корректный.
///
/// \param arr [in] - массив
/// \param size_arr [in] - размер
///
void reverse_arr(int arr[], size_t size_arr);

/// Вставка массива простых чисел в матрицу.
/// Массив и матрица существуют, размер корректный.
///
/// \param matr [in] - матрица
/// \param a_n [in] - количество строчек
/// \param a_m [in] - количество столбцов
/// \param arr [in] - массив
/// \param size_arr [in] - размер
///
void insert_arr(int matr[][M], size_t a_n, size_t a_m, int arr[], size_t size_arr);

#endif
