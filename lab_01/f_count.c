#include "main.h"

int f_count(int *num1, int *num2, int *res, int count1, \
            int count2, int *degree, int *len_res)
{
    int prod;
    int count;
    int c_count = 1;
    int d_len = 0;

    if (count1 != 30)
        for (int i = 29; i > -1; i--)
        {
            if (count1 > c_count - 1)
            {
                num1[i] = num1[count1 - c_count];
                num1[count1 - c_count] = 0;
                c_count++;
            }
            else
            {
                num1[i] = 0;
            }
        }

    c_count = 1;

    if (count2 != 30)
        for (int i = 29; i > -1; i--)
        {
            if (count2 > c_count - 1)
            {
                num2[i] = num2[count2 - c_count];
                num2[count2 - c_count] = 0;
                c_count++;
            }
            else
            {
                num2[i] = 0;
            }
        }

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            prod = num2[29 - i] * num1[29 - j];

            count = (prod >= 10) ? prod / 10 : 0;

            prod %= 10;

            res[59 - i - j] += prod;
            res[58 - i - j] += count;

            count = 60 - i - j - 1;

            while (res[count] >= 10)
            {
                res[count] %= 10;
                count--;
                res[count] += 1;
            }
        }
    }

    for (int i = 0; i < 60; i++)
    {
        if (res[i] != 0)
        {
            if (i == 0)
                count = 60;
            else
                count = i;
            break;
        }
        else
            count = 30;
    }

    for (int i = 0; i < 60 - count; i++)
    {
        res[i] = res[count+i];
        res[count+i] = 0;
    }

    if (count == 60)
        count = 0;

    for (int i = 59 - count; i > 29; i--)
    {
        if (res[i] >= 5)
        {
            res[i-1] += 1;
        }
        res[i]  = 0;

        *degree += 1;
    }

    c_count = 0;

    for (int i = 59 - count; i > 0; i--)
    {
        if (res[i] != 0)
            break;

        c_count++;
    }

    *len_res = 60 - count - c_count;

    count = *degree;

    while (count > 0)
    {
        d_len += 1;
        count /= 10;
    }

    if (d_len > 5)
    {
        printf("There are more then 5 digits in degree");
        return ERR_COUNT;
    }

    printf("0.m1E0 : The m1 has %d bits\n"
           "0.0Ek1 : The k1 has %d bits\n\n", *len_res, d_len);

    return OK;
}
