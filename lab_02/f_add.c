#include "main.h"

int f_check(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
        {
            printf("Error input");
            return ERR_IN;
        }

        if (str[i] == ' ' && str[i + 1] != '\0' && !isupper(str[i + 1]))
        {
            printf("The first letter must be uppercase");
            return ERR_IN;
        }
    }

    if (!isupper(str[0]))
    {
        printf("The first letter must be uppercase");
        return ERR_IN;
    }

    return OK;
}

int f_add(struct data *table)
{
    printf("Input the information about a student\n\n"
           "This student lives in a house or in a hostel\n");

    char str[SZ];
    int num;
    float c_num;

    f_in_str("house / hostel: ", str, SZ);

    if (!strcmp(str, "house"))
        strcpy(table->type, str);
    else if (!strcmp(str, "hostel"))
        strcpy(table->type, str);
    else
    {
        printf("Error input");
        return ERR_IN;
    }

    printf("\nThe one word with uppercase first letter\n");
    f_in_str("The name of the student"
             "\n|______________________________| 30 symbols\n|", str, SZ);

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
        {
            printf("There is must be only one word");
            return ERR_IN;
        }

    if (f_check(str))
        return ERR_IN;

    strcpy(table->name, str);

    printf("\nThe gender of the student\n");

    f_in_str("man / women: ", str, SZ);

    if (!strcmp(str, "man"))
        strcpy(table->gender, "m");
    else if (!strcmp(str, "women"))
        strcpy(table->gender, "w");
    else
    {
        printf("Error input");
        return ERR_IN;
    }

    f_in_int("\nThe age of the student: ", &table->age, SZ);

    if (table->age < 1)
    {
        printf("Error input");
        return ERR_IN;
    }

    printf("\nFrom 2 to 5\n");
    f_in_float("The average score of marks: ", &c_num, SZ);

    if (c_num >= 2 && c_num <= 5)
        table->mark = c_num;
    else
    {
        printf("The mark must be in range from 2 to 5");
        return ERR_IN;
    }

    f_in_int("\nThe year of admission: ", &num, SZ);

    if (num < 2019)
        table->year = num;
    else
    {

    }

    if (!strcmp(table->type, "house"))
    {
        printf("\nThe first letter of each words must be uppercase");
        f_in_str("\nThe street: "
                 "\n|______________________________| 30 symbols\n|", str, SZ);

        if (f_check(str))
            return ERR_IN;

        strcpy(table->condition.house.address, str);

        f_in_int("The number of the house: ", \
                 &table->condition.house.num_house, SZ);

        f_in_int("The number of the flat: ", \
                 &table->condition.house.num_flat, SZ);
    }
    else
    {
        f_in_int("\nThe number of the hostel: ", \
                 &table->condition.hostel.num_hostel, SZ);

        f_in_int("The number of the room: ", \
                 &table->condition.hostel.num_room, SZ);
    }

    return OK;
}
