#ifndef ARRAY_ACTIONS_C
#define ARRAY_ACTIONS_C

#include "main.h"

int isfull_array(array *ptr)
{
    if (ptr->len == SZ_BUF)
        return FULL;
    return OK;
}

int isempty_array(array *ptr)
{
    if (ptr->len == 0)
        return FULL;
    return OK;
}

void init_array(array *ptr)
{
    ptr->head = 0;
    ptr->tail = 0;
    ptr->len = 0;
}

void put_array(array *ptr, type data)
{
    if (isfull_array(ptr))
        return;
    ptr->buf[ptr->tail] = data;
    ptr->tail = (ptr->tail + 1) % SZ_BUF;
    ptr->len += 1;
}

void get_array(array *ptr, type *data)
{
    if (isempty_array(ptr))
        return;
    *data = ptr->buf[ptr->head];
    ptr->head = (ptr->head + 1) % SZ_BUF;
    ptr->len -= 1;
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

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

void f_free(char **p, int n)
{
    for (int i = 0; i < n; i++)
        free(p[i]);

    free(p);
}

#endif // ARRAY_ACTIONS_C

