#include "main.h"

void f_clear(struct data_table *d_t)
{
    if (d_t->p != NULL)
    {
        free(d_t->p);
        d_t->p = NULL;
    }

    d_t->n = 0;
    d_t->sz = 0;
}

int f_add_to_table(struct data_table *d_t, struct data *d)
{
    if (d_t->sz <= d_t->n)
    {
        struct data* p_f = d_t->p;
        struct data* p_tmp = d_t->p;

        d_t->sz += 10;

        struct data *ptr = (struct data *) malloc(d_t->sz * sizeof(struct data));

        if (!ptr)
        {
            printf("The memory can not allocated");
            return ERR_MEMORY;
        }

        d_t->p = ptr;

        for (int i = 0; i < d_t->n; i++)
        {
            *ptr = *p_tmp;
            ptr++;
            p_tmp++;
        }

        free(p_f);
    }

    d_t->n++;
    d_t->p[d_t->n - 1] = *d;

    return OK;
}

void f_show_data(struct data *p)
{
    printf("|Type   |%-30s|\n", p->type);
    printf("|Name   |%-30s|\n", p->name);
    printf("|Gender |%-30s|\n", p->gender);
    printf("|Age    |%-30d|\n", p->age);
    printf("|Mark   |%-30f|\n", p->mark);
    printf("|Year   |%-30d|\n", p->year);

    if (!strcmp(p->type, "house"))
    {
        printf("|Street |%-30s|\n", p->condition.house.address);
        printf("|House  |%-30d|\n", p->condition.house.num_house);
        printf("|Flat   |%-30d|\n", p->condition.house.num_flat);
    }
    else
    {
        printf("|Hostel |%-30d|\n", p->condition.hostel.num_hostel);
        printf("|Room   |%-30d|\n", p->condition.hostel.num_room);
    }
}
