#include "stud.h"
#include "codes.h"

void print_stud(FILE *f, struct student_t *s)
{
    fprintf(f, "%s\n%s\n", s->fam, s->name);
    for (size_t i = 0; i < MARKS_N - 1; ++i)
        fprintf(f, "%" PRIu32 " ", s->marks[i]);
    fprintf(f, "%" PRIu32, s->marks[MARKS_N - 1]);
    fprintf(f, "\n");
}

int get_stud(FILE *f, struct student_t *sp)
{
    char fam[FAM_LEN + 1];
    char name[NAME_LEN + 1];
    uint32_t marks[MARKS_N];
    size_t len;
    char tmp[2];
    
    if (!fgets(fam, sizeof(fam), f))
        return ERR_IO;
    len = strlen(fam);
    if (len && fam[len - 1] == '\n')
        fam[len - 1] = '\0';
    else
        return ERR_IO;

    if (!fgets(name, sizeof(name), f))
        return ERR_IO;
    len = strlen(name);
    if (len && name[len - 1] == '\n')
        name[len - 1] = '\0';
    else
        return ERR_IO;

    if (fscanf(f, "%"SCNu32" %"SCNu32" %"SCNu32" %"SCNu32, &marks[0], &marks[1], &marks[2], &marks[3]) != 4)
        return ERR_IO;
    if (!fgets(tmp, sizeof(tmp), f))
        return ERR_IO;

    memset(sp, 0, sizeof(*sp));
    strcpy(sp->fam, fam);
    strcpy(sp->name, name);
    memcpy(sp->marks, marks, sizeof(marks)); 
    return OK;
}
