#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdbool.h>

/// Заменяет элементы одного массива на элементы другого.
/// Старый массив существует, размеры совпадают.
///
/// \param old_arr [in] - старый массив
/// \param new_arr [out] - новый массив
/// \param size [in] - размер
///
void move_arr(const int old_arr[], int new_arr[], size_t size);

/// Вставляет в матрицу строку из 100.
/// Матрица существует.
///
/// \param arr [out] - матрица
/// \param i_insert [in] - позиция вставки
/// \param a_n [out] - количество строчек
/// \param a_m [in] - количество столбцов
///
void insert_100s_arr(int arr[][M], size_t i_insert, size_t *a_n, size_t a_m);

/// Проверяет, равно ли в строке матрицы количество чисел,
/// начинающихся и заканчивающихся на заданную цифру.
/// Массив существует, размер правильный.
///
/// \param arr [in] - массив
/// \param size [in] -  размер
/// \param num [in] -  цифра
///
/// \return true, если количество чисел,
/// начинающихся и заканчивающихся на заданную цифру, равно, иначе false
bool check_line(int arr[], size_t size, short num);

/// Проходится по строкам матрицы и проверяет их,
/// вставляя строки 100 при необходимости.
/// Матрица существует, размер корректный.
///
/// \param arr [in] - матрица
/// \param a_n [out] - количество строчек
/// \param a_m [in] - количество столбцов
/// \param num [in] -  цифра
///
/// \return оценка строки (true - количество чисел,
/// начинающихся и заканчивающихся на заданную цифру, равно)
void browse_lines(int arr[][M], size_t *a_n, size_t a_m, short num);

#endif
