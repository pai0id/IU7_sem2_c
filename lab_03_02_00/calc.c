#include "sizes.h"
#include "calc.h"

void move_arr(const int old_arr[], int new_arr[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
        new_arr[i] = old_arr[i];
}

void create_100s_arr(int arr[], size_t a_n)
{
    for (size_t i = 0; i < a_n; ++i)
        arr[i] = 100;
}

void insert_arr(int arr[][M], size_t i_insert, size_t *a_n, size_t a_m, int insert_arr[])
{
    (*a_n)++;
    for (size_t i = *a_n - 1; i > i_insert; --i)
        move_arr(arr[i - 1], arr[i], a_m);
    move_arr(insert_arr, arr[i_insert], a_m);
}

void check_num(int num, short digit, int *st, int *ed)
{
    int tmp_x;
    if (num >= 0)
        tmp_x = num;
    else
        tmp_x = -num;
    if (tmp_x % 10 == digit)
        (*ed)++;
    while (tmp_x > 9)
        tmp_x /= 10;
    if (tmp_x == digit)
        (*st)++;
}

bool check_line(int arr[], size_t size, short digit)
{
    int starts = 0, ends = 0;
    for (size_t i = 0; i < size; ++i)
    {
        check_num(arr[i], digit, &starts, &ends);
    }
    if (ends && starts == ends)
        return true;
    return false;
}

void browse_lines(int arr[][M], size_t *a_n, size_t a_m, short num)
{
    int arr_100s[M];
    create_100s_arr(arr_100s, a_m);
    for (size_t i = 0; i < *a_n; ++i)
    {
        if (check_line(arr[i], a_m, num))
        {
            insert_arr(arr, i + 1, a_n, a_m, arr_100s);
            i++;
        }
    }
}
