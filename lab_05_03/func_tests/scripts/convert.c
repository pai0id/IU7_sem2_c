#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERR_ARGS 1
#define ERR_FILE 2
#define ERR_IO 3

/**
 * \brief Преобразует текстовый файл с числами в двоичный файл.
 *
 * \param in [in] - указатель на входной текстовый файл
 * \param out [out] - указатель на выходной двоичный файл
 *
 * \return Код ошибки:
 *         - OK, если ошибок не возникло
 *         - ERR_IO, если произошла ошибка ввода-вывода
 */
int text2bin(FILE *in, FILE *out)
{
    int num;

    while (fscanf(in, "%d", &num) == 1)
        if (fwrite(&num, sizeof(int), 1, out) != 1)
            return ERR_IO;
    return OK;
}

/**
 * \brief Преобразует двоичный файл с числами в текстовый файл.
 *
 * \param in [in] - указатель на входной двоичный файл
 * \param out [out] - указатель на выходной текстовый файл
 */
void bin2text(FILE *in, FILE *out)
{
    int num;

    while (fread(&num, sizeof(int), 1, in) == 1)
        fprintf(out, "%d\n", num);
}

int main(int argc, char **argv)
{
    int rc = OK;
    FILE* in = NULL;
    FILE* out = NULL;

    if (argc != 4)
        rc = ERR_ARGS;
    else if (strcmp(argv[1], "t2b") == 0)
    {
        in = fopen(argv[2], "r");
        out = fopen(argv[3], "wb");

        if (in == NULL || out == NULL)
            rc = ERR_FILE;
        else
            rc = text2bin(in, out);
    }
    else if (strcmp(argv[1], "b2t") == 0)
    {
        in = fopen(argv[2], "rb");
        out = fopen(argv[3], "w");

        if (in == NULL || out == NULL)
            rc = ERR_FILE;
        else
            bin2text(in, out);
    }
    else
        rc = ERR_ARGS;

    if (in != NULL)
        fclose(in);
    if (out != NULL)
        fclose(out);

    return rc;
}

