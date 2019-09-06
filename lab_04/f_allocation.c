#ifndef F_ALLOCATION_C
#define F_ALLOCATION_C

#include "main.h"

int f_allocation(void ***p, int n, int m)
{
    void **b = NULL;

    m++;

    if (*p != NULL)
        return ERR_POINTER;

    b = malloc(n);

    if (!b)
        return ERR_MEMORY;

    *p = b;

    for (int i = 0; i < n; i++)
    {
        b[i] = malloc(m);

        if (!b[i])
            return ERR_MEMORY;
    }

    return OK;
}

#endif // F_ALLOCATION_C

