#include "main.h"

void f_sort_insert_key(struct key_table *t_k)
{
    struct key *p = t_k->p;
    struct key tmp;

    int min;
    int n = t_k->n;

    for (int i = 0; i < n; i++)
    {
        min = i;

        for (int j = i; j < n; j++)
        {
            if (p[j].value < p[min].value)
                min = j;
        }
        tmp = p[i];
        p[i] = p[min];
        p[min] = tmp;
    }
}

void f_sort_table(struct data_table *t_k)
{
    struct data *p = t_k->p;
    struct data tmp;

    int min;
    int n = t_k->n;

    for (int i = 0; i < n; i++)
    {
        min = i;

        for (int j = i; j < n; j++)
        {
            if (p[j].mark < p[min].mark)
                min = j;
        }
        tmp = p[i];
        p[i] = p[min];
        p[min] = tmp;
    }
}

void f_show_sorted_key_table(struct data_table *d, struct key_table *k)
{
    struct data *ptr_d = d->p;
    struct key *ptr_k = k->p;

    printf(" ______________________________________\n"
           "|Table                                 |\n"
           "|______________________________________|\n");

    for (int i = 0; i < d->n; i++)
    {
        printf("|%-38d|\n", i + 1);
        printf("|_____________________________________ |\n");
        f_show_data(&ptr_d[ptr_k[i].id - 1]);
        printf("|_____________________________________ |\n");
    }
}

void f_sort_bubble_key(struct key_table *t_k)
{
    struct key *p = t_k->p;
    struct key tmp;

    int i = 0;
    int check = 1;

    while (check)
    {
        check = 0;

        for (int j = 0; j < t_k->n - i - 1; j++)
            if (p[j].value > p[j + 1].value)
            {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
                check = 1;
            }

        i += 1;
    }
}

void f_sort_table_bubble(struct data_table *t_k)
{
    struct data *p = t_k->p;
    struct data tmp;

    int i = 0;
    int check = 1;

    while (check)
    {
        check = 0;

        for (int j = 0; j < t_k->n - i - 1; j++)
            if (p[j].mark > p[j + 1].mark)
            {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
                check = 1;
            }

        i += 1;
    }
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}
