#include "sizes.h"
#include "codes.h"
#include "IO.h"
 
int input_matr(size_t *a_n, size_t *a_m)
{
    printf("Input n, m: ");
    if (scanf("%zu %zu", a_n, a_m) != 2)
        return ERR_IO;
    if (*a_n > N || *a_n == 0 || *a_m > M || *a_m == 0)
        return ERR_SIZE;
    return OK;
}

void print_matr(int arr[][M], size_t a_n, size_t a_m)
{
    printf("Array: \n");
    for (size_t i = 0; i < a_n ; ++i)
    {
        for (size_t j = 0; j < a_m ; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
