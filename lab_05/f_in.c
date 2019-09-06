#ifndef F_IN_C
#define F_IN_C

#include "main.h"

void f_in_str(char *msg, char *str, int n)
{
    for (; ;)
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

    for (; ;)
    {
        f_in_str(msg, str, n);

        for (i = 0; str[i] != '\0'; i++)
            if (!isdigit(str[i]) || str[i] == '-')
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

#endif // F_IN_C

