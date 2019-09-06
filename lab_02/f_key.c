#include "main.h"

int f_create_key_table(struct key_table *p_k, struct data_table *p_d)
{
    struct data *ptr_d;
    struct key *ptr_k;

    f_clear_key_table(p_k);

    p_k->p = (struct key*) malloc(p_d->n * sizeof(struct key));

    if (!p_k->p)
    {
        printf("The memmory can not be allocated");
        return ERR_MEMORY;
    }

    p_k->n = p_d->n;

    ptr_d = p_d->p;
    ptr_k = p_k->p;

    for (int i = 0; i < p_k->n; i++)
    {
        ptr_k->id = i + 1;
        ptr_k->value = ptr_d->mark;

        ptr_k++;
        ptr_d++;
    }

    return OK;
}

void f_clear_key_table(struct key_table *t_k)
{
    if (t_k->p != NULL)
    {
        free(t_k->p);
        t_k->p = NULL;
        t_k->n = 0;
    }
}

int f_show_key_table(struct key_table *p)
{
    struct key *ptr = p->p;
    int count = p->n;

    if (count == 0)
    {
        printf("The table is empty");
        return ERR_TABLE;
    }

    printf(" _________________\n"
           "|Table            |\n"
           "|_________________|\n");

    for (int i = 0; i < count; i++)
    {
        printf("|%-5d |%-10f|\n"
               "|_________________|\n", ptr->id, ptr->value);
        ptr++;
    }

    return OK;
}
