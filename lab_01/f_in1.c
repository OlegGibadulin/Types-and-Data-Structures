#include "main.h"

int f_in1(int *num, int *len, int *mark, int *degree)
{
    char c_num[32];
    int count;

    char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    printf("Input first number: ");
    scanf("%31s", c_num);

    if (c_num[0] == '-')
    {
        *mark = 1;
        *len += 1;
    }

    while (c_num[*len] != '\0')
    {
        if (*len == 30)
        {
            printf("There are more then 30 digits");
            return ERR_COUNT;
        }

        if (isdigit(c_num[*len]))
        {
            count = 0;

            while (c_num[*len] != arr[count])
                count++;

            num[*len - *mark] = count;
        }
        else
        {
            printf("There are can be only integer digits and minus");
            return ERR_IN;
        }

        *len += 1;
    }

    *len -= *mark;

    count = 0;

    for (int i = 0; i < *len; i++)
    {
        if (num[i] == 0)
            count++;
        else
            break;
    }

    *degree += *len - 1 - count;

    return OK;
}
