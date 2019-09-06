#include "main.h"

int f_in2(int *num, int *degree, int *len, int *mark)
{
    char c_num[41];
    int count;
    int d_len = 0;
    int deg = 1;
    int c_count = 0;
    int c_deg[5];

    int m_mark = 0;
    int p_mark = 0;
    int point = 0;
    int e = 0;
    int E = 0;

    int s_m[2] = {-1, -1};
    int s_p = -1;
    int s_point = -1;
    int s_e = -1;
    int s_E = -1;

    char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    printf("Input second number: ");
    scanf("%40s", c_num);

    while (c_num[*len] != '\0')
    {
        switch (c_num[*len])
        {
        case '-' :
            m_mark++;
            s_m[m_mark-1] = *len;
            break;
        case '+' :
            p_mark++;
            s_p = *len;
            break;
        case '.' :
            point++;
            s_point = *len;
            break;
        case 'e' :
            e++;
            s_e = *len;
            break;
        case 'E' :
            E++;
            s_E = *len;
            break;
        default :
            if (isdigit(c_num[*len]))
            {
                if (c_count == 31)
                {
                    printf("There are more then 30 digits");
                    return ERR_COUNT;
                }

                count = 0;

                if (e > 0 || E > 0)
                {
                    if (d_len == 5)
                    {
                        printf("There are more then 5 elements in degree");
                        return ERR_COUNT;
                    }

                    while (c_num[*len] != arr[count])
                        count++;

                    c_deg[d_len] = count;

                    d_len++;
                }
                else
                {
                    while (c_num[*len] != arr[count])
                        count++;

                    num[c_count] = count;
                    c_count++;
                }

                break;
            }
            else
            {
                printf("There are must be only integer digits");
                return ERR_IN;
            }
        }

        *len += 1;
    }

    if (e != 0 || E != 0)
    {
        if (e + E > 1 || s_e == 0 || s_E == 0 || (s_e == 1 && s_m[0] == 0) \
                || (s_E == 1 && s_m[0] == 0))
        {
            printf("There is error with eps");
            return ERR_IN;
        }

        if (E == 1)
        {
            s_e = s_E;
            e = E;
        }

        if (p_mark > 0 || m_mark > 2 || (s_m[0] > 0 && s_m[1] != -1) || \
                s_m[1] == *len - 1)
        {
            printf("There is error with marks");
            return ERR_IN;
        }

        if (point != 1 || s_point >= s_e - 1 || s_point == 0 || \
                (s_point == 1 && s_m[0] == 0))
        {
            printf("There is error with point");
            return ERR_IN;
        }

        d_len = *len - c_count - m_mark - point - e;

        for (int i = d_len - 1; i > -1; i--)
        {
            *degree += c_deg[i] * deg;
            deg *= 10;
        }

        if ((s_m[0] > 0 && s_m[1] == -1) || s_m[1] > 0)
        {
            *degree *= -1;
            *degree += 1;
        }

        *len -= d_len;

        *len = *len - point - m_mark - e;

        count = 0;

        s_point -= m_mark;

        for (int i = 0; i < s_point; i++)
        {
            if (num[i] == 0)
                count++;
            else
                break;
        }

        if (s_point == count && s_point != *len)
        {
            for (int i = s_point; i < *len; i++)
            {
                if (num[i] == 0)
                    count++;
                else
                    break;
            }
        }

        if (count == *len)
            *degree = 0;
        else if (s_point == *len)
            *degree += *len - count;
        else
            *degree += s_point - count;
    }
    else
    {
        if (point != 1 || m_mark + p_mark > 1 || s_m[0] > 0 || s_p > 0)
        {
            printf("There is error with real number");
            return ERR_IN;
        }

        count = 0;

        *len = *len - point - m_mark - p_mark;

        for (int i = 0; i < s_point; i++)
        {
            if (num[i] == 0)
                count++;
            else
                break;
        }

        if (s_point == count)
        {
            for (int i = s_point; i < *len; i++)
            {
                if (num[i] == 0)
                    count++;
                else
                    break;
            }
        }

        if (count != *len)
            *degree += s_point - count;
        else
            *degree = 0;
    }

    if (s_m[0] == 0)
        *mark = 1;

    return OK;
}
