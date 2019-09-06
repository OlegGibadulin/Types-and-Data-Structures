#include "main.h"

void f_remove(struct data_table *p, int num)
{
    struct data *ptr = p->p;

    for (int i = 0; i < p->n; i++)
    {
        if (i >= num - 1)
        {
            *ptr = *(ptr + 1);
        }

        ptr++;
    }

    p->n--;

    ptr = NULL;
}
