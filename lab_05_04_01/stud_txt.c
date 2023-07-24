#include "stud_txt.h"

int proc_file(FILE *f_in, struct student_t arr[], size_t *n, char *substr)
{
    struct student_t tmp;
    size_t i, j = 0, write = 0;

    if (strlen(substr) > FAM_LEN || strlen(substr) == 0)
        return ERR_ARGS;

    while (!get_stud(f_in, &tmp))
    {
        if (j >= N_STUDS)
            return ERR_IO;
        else
            arr[j++] = tmp;
    }
    if (j == 0)
        return ERR_F_EMPTY;
    for (i = 0; i < j; ++i)
    {
        if (strncmp(arr[i].fam, substr, strlen(substr)) == 0)
            arr[write++] = arr[i];
    }
    if (write != 0)
    {
        *n = write;
        return OK;
    }
    return ERR_F_EMPTY;
}

void print_arr_to_file(FILE *f_out, struct student_t arr[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        print_stud(f_out, &arr[i]);
}
