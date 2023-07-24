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

void get_next_word(char *str, char **pbeg, char **pend)
{
    char *p = str;
    *pbeg = *pend = NULL;
    while (*p && strchr(DELIMS, *p))
        p++;
    if (!*p)
        return;
    *pbeg = p;
    while (*p && !strchr(DELIMS, *p))
        p++;
    *pend = p;
}

int copy_word(char *pbeg, const char *pend, char *word, size_t word_size)
{
    char *p = pbeg;
    if ((size_t)(pend - pbeg) + 1 > word_size)
        return ERR_BUF_TOO_SMALL;
    while (p != pend)
    {
        *word = *p;
        p++;
        word++;
    }
    *word = 0;
    return OK;
}

int parse_string(char *str, char words[][WRD_LEN + 1], size_t *words_n)
{
    char *pbeg, *pend, *pcurr = str;
    size_t n = 0;
    int rc = OK;
    while (!rc && pcurr && *pcurr)
    {
        get_next_word(pcurr, &pbeg, &pend);
        if (pbeg)
        {
            if (n < WRD_CNT)
            {
                rc = copy_word(pbeg, pend, words[n], sizeof(words[n]));
                if (rc == OK)
                    n++;
            }
            else
                rc = ERR_TOO_MANY_WORDS;
        }
        pcurr = pend;
    }
    if (!rc)
        *words_n = n;
    return rc;
}

void get_counts(char words[][WRD_LEN + 1], size_t words_n,
char unique_words[][WRD_LEN + 1], size_t *unique_words_n, int cnt_arr[])
{
    size_t i, j, unique_index;
    int is_unique;
    
    for (i = 0; i < words_n; i++)
        cnt_arr[i] = 0;
    unique_index = 0;
    
    for (i = 0; i < words_n; i++)
    {
        is_unique = 1;
        for (j = 0; j < unique_index; j++)
        {
            if (strcmp(words[i], unique_words[j]) == 0)
            {
                is_unique = 0;
                break;
            }
        }
        if (is_unique)
        {
            strcpy(unique_words[unique_index], words[i]);
            unique_index++;
        }
        cnt_arr[j]++;
    }
    *unique_words_n = unique_index;
}

void print_counts(char uniwords[][WRD_LEN + 1], size_t words_n, int cnt_arr[])
{
    printf("Result:");
    for (size_t i = 0; i < words_n; ++i)
        printf("\n%s %d", uniwords[i], cnt_arr[i]);
}

// void print_counts(char words[][WRD_LEN + 1], size_t words_n)
// {
//     int cnt;
//     char uniq_words[WRD_CNT][WRD_LEN + 1];
//     size_t uniq_words_n;
//     char cnt_words[WRD_CNT];
//     form_word_arr(words, words_n, uniq_words, &uniq_words_n, cnt_words);
//     printf("Result:");
//     for (size_t i = 0; i < uniq_words_n; ++i)
//         printf("\n%s %d", uniq_words[i], cnt_words[i]);
// }
