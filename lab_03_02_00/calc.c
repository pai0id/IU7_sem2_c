#include "sizes.h"
#include "calc.h"

void move_arr(const int old_arr[], int new_arr[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
        new_arr[i] = old_arr[i];
}

void insert_100s_arr(int arr[][M], size_t i_insert, size_t *a_n, size_t a_m)
{
    int arr_100s[M];
    for (size_t i = 0; i < a_m; ++i)
        arr_100s[i] = 100;
    (*a_n)++;
    for (size_t i = *a_n - 1; i > i_insert; --i)
        move_arr(arr[i - 1], arr[i], a_m);
    move_arr(arr_100s, arr[i_insert], a_m);
}

bool check_line(int arr[], size_t size, short num)
{
    int starts = 0, ends = 0;
    int tmp_x;
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] >= 0)
            tmp_x = arr[i];
        else
            tmp_x = -arr[i];
        if (tmp_x % 10 == num)
            ends++;
        while (tmp_x > 9)
            tmp_x /= 10;
        if (tmp_x == num)
            starts++;
    }
    if (ends && starts == ends)
        return true;
    return false;
}

void browse_lines(int arr[][M], size_t *a_n, size_t a_m, short num)
{
    for (size_t i = 0; i < *a_n; ++i)
    {
        if (check_line(arr[i], a_m, num))
        {
            insert_100s_arr(arr, i + 1, a_n, a_m);
            i++;
        }
    }
}
