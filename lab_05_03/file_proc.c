#include "file_proc.h"

int fill_file(FILE *f, size_t n)
{
    int x;
    srand(time(NULL));
    for (size_t i = 0; i < n; ++i)
    {
        x = rand();
        if (fwrite(&x, sizeof(int), 1, f) != 1)
            return ERR_IO;
    }
    return OK;
}

int print_file(FILE *f)
{
    long size;
    if (fseek(f, 0, SEEK_END) != 0)
        return ERR_IO;
    size = ftell(f);
    if (size % sizeof(int) != 0)
        return ERR_IO;
    else if (size == 0)
        return ERR_F_EMPTY;
    rewind(f);

    int num;
    while (fread(&num, sizeof(int), 1, f) == 1)
        printf("%d\n", num);
    return OK;
}

int get_number_by_pos(FILE *f, size_t pos, int *num)
{
    int rc;
    rc = fseek(f, pos, SEEK_SET);
    if (!rc)
    {
        if (fread(num, sizeof(int), 1, f) != 1)
            return ERR_IO;
        return OK;
    }
    return ERR_RANGE;
}

int put_number_by_pos(FILE *f, size_t pos, const int *num)
{
    int rc;
    rc = fseek(f, pos, SEEK_SET);
    if (!rc)
    {
        if (fwrite(num, sizeof(int), 1, f) != 1)
            return ERR_IO;
        return OK;
    }
    return ERR_RANGE;
}

int sort_file(FILE *f)
{
    long size;
    if (fseek(f, 0, SEEK_END) != 0)
        return ERR_IO;
    size = ftell(f);
    if (size % sizeof(int) != 0)
        return ERR_IO;
    else if (size == 0)
        return ERR_F_EMPTY;
    size /= sizeof(int);
    rewind(f);

    int num1, num2;
    for (long i = 0; i < size - 1; i++)
    {
        for (long j = 0; j < size - i - 1; j++)
        {
            if (get_number_by_pos(f, j * sizeof(int), &num1) == OK &&
                get_number_by_pos(f, (j + 1) * sizeof(int), &num2) == OK)
            {
                if (num1 > num2)
                {
                    put_number_by_pos(f, j * sizeof(int), &num2);
                    put_number_by_pos(f, (j + 1) * sizeof(int), &num1);
                }
            }
        }
    }
    return OK;
}
