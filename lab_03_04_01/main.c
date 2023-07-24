/**
 *  Поляков Андрей ИУ7-22Б
 */

#include "sizes.h"
#include "codes.h"
#include "IO.h"
#include "calc.h"

int main(void)
{
    int matr[N][M];
    size_t a_n, a_m;
    int rc = OK;
    rc = input_matr(matr, &a_n, &a_m);
    if (!rc && a_m != a_n)
        rc = ERR_NOT_KV;
    if (!rc)
    {
        m_swap(matr, a_n);
        print_matr(matr, a_n, a_m);
    }
    switch (rc)
    {
        case OK:
            break;
        case ERR_IO:
            printf("Input error\n");
            break;
        case ERR_SIZE:
            printf("Incorrect size\n");
            break;
        case ERR_NOT_KV:
            printf("The matrix is not square\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
    return rc;
}
