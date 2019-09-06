#include "main.h"

int f_save_table(char *str, struct data_table *d_t)
{
    FILE *f;

    if (!(f = fopen(str, "w")))
    {
        printf("File does not exist");
        return ERR_EXIST_OF_FILE;
    }

    int count;

    fprintf(f, "%d\n\n", (count = d_t->n));

    struct data *p = d_t->p;

    for (int i = 0; i < count; ++i)
    {
        fprintf(f, "%s\n", p->type);
        fprintf(f, "%s\n", p->name);
        fprintf(f, "%s\n", p->gender);
        fprintf(f, "%d\n", p->age);
        fprintf(f, "%f\n", p->mark);
        fprintf(f, "%d\n", p->year);

        if (!strcmp(p->type, "house"))
        {
            fprintf(f, "%s\n", p->condition.house.address);
            fprintf(f, "%d\n", p->condition.house.num_house);
            fprintf(f, "%d\n\n", p->condition.house.num_flat);
        }
        else
        {
            fprintf(f, "%d\n", p->condition.hostel.num_hostel);
            fprintf(f, "%d\n\n", p->condition.hostel.num_room);
        }

        p++;
    }

    fclose(f);

    return OK;
}
