#include "main.h"

int f_show_table(struct data_table *d_t)
{
    struct data *p = d_t->p;

    if (d_t->n == 0)
    {
        printf("The table is empty");
        return ERR_TABLE;
    }

    printf(" ______________________________________\n"
           "|Table                                 |\n"
           "|______________________________________|\n");

    for (int i = 0; i < d_t->n; ++i)
    {
        printf("|%-38d|\n", i + 1);
        printf("|_____________________________________ |\n");
        f_show_data(p);
        printf("|_____________________________________ |\n");

        p++;
    }

    return OK;
}
