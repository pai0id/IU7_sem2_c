#include "proc.h"
#include "codes.h"

int process(FILE *f, int *cnt)
{
    int prev, curr, next;
    *cnt = 0;
    if (fscanf(f, "%d", &prev) != 1 ||
        fscanf(f, "%d", &curr) != 1 ||
        fscanf(f, "%d", &next) != 1)
        return ERR_IO;
    do
    {
        if (prev < curr && curr > next)
            (*cnt)++;
        prev = curr;
        curr = next;
    }while (fscanf(f, "%d", &next) == 1);
    return OK;
}
