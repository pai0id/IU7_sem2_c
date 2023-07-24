#include "my_funcs.h"

const char *find_char(const char *str, char ch)
{
    while (*str != 0)
    {
        if (*str == ch)
            return (char*)str;
        str++;
    }
    if (ch == 0)
        return (char*)str;
    return NULL;
}

char *my_strpbrk(const char *str, const char *sym)
{
    const char *tmp;
    while (*str != 0)
    {
        tmp = find_char(sym, *str);
        if (tmp != NULL)
            return (char*)str;
        str++;
    }
    return NULL;
}

size_t my_strspn(const char *str, const char *sym)
{
    size_t len = 0;
    while (*str != 0)
    {
        if (find_char(sym, *str) != NULL)
            len++;
        else
            return len;
        str++;
    }
    return len;
}

size_t my_strcspn(const char *str, const char *sym)
{
    size_t len = 0;
    while (*str != 0)
    {
        if (find_char(sym, *str) != NULL)
            return len;
        else
            len++;
        str++;
    }
    return len;
}

char *my_strchr(const char *str, int ch)
{
    str = find_char(str, ch);
    return (char*)str;
}

char *my_strrchr(const char *str, int ch)
{
    const char *res = NULL;
    do
    {
        if (*str == ch)
            res = str;
    }while (*str++);

    return (char*)res;
}
