#include "str_funcs.h"
#include "errors.h"

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

int move_to_num(char **str)
{
    while (isspace(**str))
    {
        (*str)++;
    }
    if (isdigit(**str))
        return OK;
    return ERR_NOT_IP;
}

int move_to_end(char **str)
{
    while (isspace(**str))
    {
        (*str)++;
    }
    if (**str == 0)
        return OK;
    return ERR_NOT_IP;
}

int check_ip(char **str)
{
    long num;
    char *end;
    for (size_t i = 0; i < N - 1; ++i)
    {
        num = strtol(*str, &end, 10);
        if (end == *str || (end - *str) / sizeof(char) > 3)
            return ERR_NOT_IP;
        *str = end;
        if (**str != '.' || num > 255 || num < 0)
            return ERR_NOT_IP;
        (*str)++;
        if (!isdigit(**str))
            return ERR_NOT_IP;
    }
    num = strtol(*str, &end, 10);
    if (end == *str || (end - *str) / sizeof(char) > 3)
        return ERR_NOT_IP;
    *str = end;
    if (num > 255 || num < 0)
        return ERR_NOT_IP;
    return OK;
}

int check_string(const char *str)
{
    int rc;
    char *p = (char*)str;
    rc = move_to_num(&p);
    if (! rc)
        rc = check_ip(&p);
    if (! rc)
        rc = move_to_end(&p);
    return rc;
}
