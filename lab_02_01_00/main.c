#include <stdio.h>

#define N 10

int input(int a[], size_t *a_size)
{
    printf("Input n: ");
    if (scanf("%zu", a_size) != 1)
        return ERR_IO;
    if (*a_size > N || *a_size == 0)
        return ERR_RANGE;
    for (size_t i = 0; i < *a_size; ++i)
        if (scanf("%d", &a[i]) != 1)
            return ERR_IO;
    return OK;
}

void print(const int a[], size_t a_size)
{
    printf("Array: \n");
    for (size_t i = 0; i < a_size; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[N];
    size_t size;
    input(arr, &size);
    print(arr, size);
}
