#include "stud_bin.h"

int get_struct_by_pos(FILE *f, size_t pos, struct student_t *stud)
{
    int rc;
    memset(stud, 0, sizeof(*stud));
    rc = fseek(f, pos, SEEK_SET);
    if (!rc)
    {
        if (fread(stud, sizeof(struct student_t), 1, f) != 1)
            return ERR_IO;
        return OK;
    }
    return ERR_RANGE;
}

int put_struct_by_pos(FILE *f, size_t pos, const struct student_t *stud)
{
    int rc;
    rc = fseek(f, pos, SEEK_SET);
    if (!rc)
    {
        if (fwrite(stud, sizeof(struct student_t), 1, f) != 1)
            return ERR_IO;
        return OK;
    }
    return ERR_RANGE;
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

    struct student_t s;
    while (fread(&s, sizeof(struct student_t), 1, f) == 1)
        print_stud(stdout, &s);
    return OK;
}

int sort_file(FILE *f)
{
    long size;
    if (fseek(f, 0, SEEK_END) != 0)
        return ERR_IO;
    size = ftell(f);
    if (size % sizeof(struct student_t) != 0)
        return ERR_IO;
    else if (size == 0)
        return ERR_F_EMPTY;
    size /= sizeof(struct student_t);
    rewind(f);

    int res;
    struct student_t stud1, stud2;
    for (long i = 0; i < size - 1; i++)
    {
        for (long j = 0; j < size - i - 1; j++)
        {
            if (get_struct_by_pos(f, j * sizeof(struct student_t), &stud1) == OK &&
                get_struct_by_pos(f, (j + 1) * sizeof(struct student_t), &stud2) == OK)
            {
                res = strcmp(stud1.fam, stud2.fam);
                if (res > 0)
                {
                    put_struct_by_pos(f, j * sizeof(struct student_t), &stud2);
                    put_struct_by_pos(f, (j + 1) * sizeof(struct student_t), &stud1);
                }
                else if (res == 0 && strcmp(stud1.name, stud2.name) > 0)
                {
                    put_struct_by_pos(f, j * sizeof(struct student_t), &stud2);
                    put_struct_by_pos(f, (j + 1) * sizeof(struct student_t), &stud1);
                }
            }
        }
    }
    return OK;
}
