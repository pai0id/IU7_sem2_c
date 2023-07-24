#include "str_funcs.h"
#include "sizes.h"
#include "errors.h"

#define DELIMS "\n \t.,:;?!-"

int get_line(char *buf, size_t buf_size)
{
    char *p;
    if (!fgets(buf, buf_size, stdin))
        return ERR_IO;
    p = strchr(buf, '\n');
    if (p)
    {
        *p = 0;
        return OK;
    }
    return ERR_BUF_TOO_SMALL;
}

int parse_string(char *str, char words[][WRD_LEN + 1], size_t *words_n)
{
    size_t n = 0;
    int rc = OK;
    char *pcurr = strtok(str, DELIMS);
    while (pcurr != NULL && !rc)
    {
        if (n < WRD_CNT)
        {
            if (strlen(pcurr) > sizeof(words[n]))
                rc = ERR_BUF_TOO_SMALL;
            strcpy(words[n], pcurr);
            n++;
        }
        else
            rc = ERR_TOO_MANY_WORDS;
        pcurr = strtok(NULL, DELIMS);
    }
    if (!rc)
        *words_n = n;
    return rc;
}

void process_word(char word[])
{
    char p = word[0];
    size_t i, j = 1;
    for (i = 1; i < strlen(word) + 1; i++)
        if (word[i] != p)
            word[j++] = word[i];
}

int form_string(char words[][WRD_LEN + 1], size_t words_n, char *buf)
{
    buf[0] = 0;
    char no_no_word[WRD_LEN + 1];
    strcpy(no_no_word, words[words_n - 1]);
    for (size_t i = words_n - 1; i + 1 >= 1; i--)
    {
        if (! (strcmp(words[i], no_no_word) == 0))
        {
            process_word(words[i]);
            if (strlen(buf) + strlen(words[i]) > STR_LEN)
                return ERR_BUF_TOO_SMALL;
            strcat(buf, " ");
            strcat(buf, words[i]);
        }
    }
    if (buf[0] == 0)
        return ERR_EMPTY_RES_STR;
    return OK;
}
