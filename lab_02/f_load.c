#include "main.h"

int f_load_table(char *str, struct data_table *d_t)
{
    FILE *f;

    if (!(f = fopen(str, "r")))
    {
        printf("File does not exist");
        return ERR_EXIST_OF_FILE;
    }

    f_clear(d_t);

    int num, check = 1;

    if (fscanf(f, "%d", &num) != 1)
        check = 0;

    if (!check)
    {
        printf("The file is empty");
        return ERR_TABLE;
    }

    if (num < 1)
    {
        printf("The table is empty");
        return ERR_TABLE;
    }

    fscanf(f, "\n");

    for (int i = 0; i < num && check; ++i)
    {
        struct data *d = (struct data *) malloc(sizeof(struct data));

        if (!d)
        {
            printf("The memory can not allocated");
            return ERR_MEMORY;
        }

        if (fscanf(f, "%s", d->type) != 1)
            check = 0;

        if (fscanf(f, "%s", d->name) != 1)
            check = 0;

        if (fscanf(f, "%s", d->gender) != 1)
            check = 0;

        if (fscanf(f, "%d", &d->age) != 1)
            check = 0;

        if (fscanf(f, "%f", &d->mark) != 1)
            check = 0;

        if (fscanf(f, "%d", &d->year) != 1)
            check = 0;

        if (!strcmp(d->type, "house"))
        {
            //if (fscanf(f, "%s", d->condition.house.address) != 1)
                //check = 0;

            fscanf(f, "\n");

            char tmp[SZ];
            int k;

            fgets(tmp, 30, f);

            for (k = 0; tmp[k] != '\0'; k++);

            tmp[k - 1] = tmp[k];

            strcpy(d->condition.house.address, tmp);

            if (fscanf(f, "%d", &d->condition.house.num_house) != 1)
                check = 0;

            if (fscanf(f, "%d", &d->condition.house.num_flat) != 1)
                check = 0;
        }
        else
        {
            if (fscanf(f, "%d", &d->condition.hostel.num_hostel) != 1)
                check = 0;

            if (fscanf(f, "%d", &d->condition.hostel.num_room) != 1)
                check = 0;
        }

        fscanf(f, "\n");

        if (f_add_to_table(d_t, d))
            return ERR_TABLE;
    }

    fclose(f);

    if (!check)
    {
        printf("Error in the file");
        return ERR_TABLE;
    }

    return OK;
}
