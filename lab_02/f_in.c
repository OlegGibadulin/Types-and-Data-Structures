#include "main.h"

void f_in_str(char *msg, char *str, int n)
{
    for (;;)
    {
        printf("%s", msg);

        int i;
        char tmp;

        for (i = 0; ((tmp = getchar()) != '\n' && tmp != EOF && i < n); i++)
        {
            if (i == n)
                break;

            str[i] = tmp;
        }

        if (i == n)
        {
            printf("There are more then %d symbols\n\n", n - 1);
            continue;
        }

        if (i == 0)
        {
            printf("Empty input\n\n");
            continue;
        }

        str[i] = '\0';

        break;
    }
}

void f_in_int(char *msg, int *num, int n)
{
    char str[n];
    int i;

    for (;;)
    {
        f_in_str(msg, str, n);

        for (i = 0; str[i] != '\0'; i++)
            if (!isdigit(str[i]))
            {
                printf("Error input\n\n");
                i = 0;
                break;
            }

        if (i == 0)
            continue;

        *num = atoi(str);

        break;
    }
}

void f_in_float(char *msg, float *num, int n)
{
    char str[n];
    char c_str[n];
    int i, count, c_p = 0;
    float c_count = 1.0;

    for (;;)
    {
        f_in_str(msg, str, n);

        count = 0;

        for (i = 0; str[i] != '\0'; i++)
        {
            if (!isdigit(str[i]) && (str[i] != '.' || count == 1))
            {
                printf("Error input\n\n");
                i = 0;
                break;
            }

            if (str[i] == '.')
            {
                count++;
                c_p = i + 1;
            }
        }

        if (i == 0)
            continue;

        count = 0;

        *num = atoi(str) / c_count;

        if (c_p != 0)
        {
            for (i = c_p; str[i] != '\0'; i++)
            {
                c_str[count] = str[i];
                count++;
                c_count *= 10;
            }

            *num += atoi(c_str) / c_count;
        }

        break;
    }
}
