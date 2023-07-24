#include "tests.h"
#include "my_funcs.h"
#include "sizes.h"
#include <string.h>

void test_strpbrk(int *cnt)
{
    const char tests[][2][STR_LEN] = {
        { "I am string", "rev01" },
        { "I was string", "bc" },
        { "I will be string", "" },
        { "I was made a string", "ggg" },
        { "Istring", "aioI" },
        { "", "abc" } };
    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
    {
        if (strpbrk(tests[i][0], tests[i][1]) != my_strpbrk(tests[i][0], tests[i][1]))
            (*cnt)++;
    }
}

void test_strspn(int *cnt)
{
    const char tests[][2][STR_LEN] = {
        { "abccbbdeabcc", "acb" },
        { "abcde", "bc" },
        { "abcdef", "afe" },
        { "abcdd", "" },
        { "", "abc" } };
    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
    {
        if (strspn(tests[i][0], tests[i][1]) != my_strspn(tests[i][0], tests[i][1]))
            (*cnt)++;
    }
}

void test_strcspn(int *cnt)
{
    const char tests[][2][STR_LEN] = {
        { "abccbbdefabcc", "ef" },
        { "abcde", "bc" },
        { "abcdef", "abc" },
        { "abcdd", "" },
        { "", "abc" } };
    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
    {
        if (strcspn(tests[i][0], tests[i][1]) != my_strcspn(tests[i][0], tests[i][1]))
            (*cnt)++;
    }
}

void test_strchr(int *cnt)
{
    const char strs[][STR_LEN] = { "abccbbdefabcc", "abcda", "abcdef", "abcdde", "abc", "" };
    const char chars[] = { 'e', 'a', 'r', 'e', 0, 'a' };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i)
    {
        if (strchr(strs[i], chars[i]) != my_strchr(strs[i], chars[i]))
            (*cnt)++;
    }
}

void test_strrchr(int *cnt)
{
    const char strs[][STR_LEN] = { "abccbbdefabcc", "abcde", "abcdef", "ebcdde", "abc", "" };
    const char chars[] = { 'e', 'a', 'r', 'e', 0, 'a' };
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); ++i)
    {
        if (strrchr(strs[i], chars[i]) != my_strrchr(strs[i], chars[i]))
            (*cnt)++;
    }
}
