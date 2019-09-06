#include "main.h"

void f_search(struct data_table *p, int num)
{
    struct data *ptr = p->p;
    int count = 0;

    printf(" ______________________________________\n"
           "|Table                                 |\n"
           "|______________________________________|\n");

    for (int i = 0; i < p->n; i++)
    {
        if (num == ptr->year && !strcmp(ptr->type, "hostel"))
        {
            printf("|%-38d|\n", i + 1);
            printf("|_____________________________________ |\n");
            f_show_data(ptr);
            printf("|_____________________________________ |\n");

            count++;
        }

        ptr++;
    }

    if (!count)
    {
        printf("|%-38s|\n"
               "|_____________________________________ |\n", \
               "There are not such students");
    }
}
