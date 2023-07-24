#include "proc.h"
#include "errors.h"

int process(FILE *f, int *cnt)
{
    float min, max, avr, curr;
    *cnt = 0;
    if (fscanf(f, "%f", &min) != 1)
        return ERR_IO;
    max = min;
    while (fscanf(f, "%f", &curr) == 1)
    {
        if (min > curr)
            min = curr;
        else if (max < curr)
            max = curr;
    }
    avr = (max + min) / 2;
    rewind(f);
    while (fscanf(f, "%f", &curr) == 1)
        if (avr < curr)
            (*cnt)++;
    return OK;
}
