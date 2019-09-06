#ifndef F_GENERATE_C
#define F_GENERATE_C

#include "main.h"

static int count_ = 0;

int f_generate(struct table_classic *tc, struct spare_matrix *sm, int per, \
    int h, int w)
{
    struct classic_matrix cm;

    f_clear_cm(tc);
    f_clean_sm(sm);

    count_++;

    if (h == 0 && w == 0)
    {
        if (count_ % 2 == 0)
            printf("\nThe vector must has 1 row\n");
        else
            printf("\nThe matrix must be square\n");

        for (;;)
        {
            f_in_int("\nInput height: ", &h, SZ);
            f_in_int("Input width: ", &w, SZ);

            if (w != h && count_ % 2 == 1)
            {
                printf("The matrix must be square\n\n");
                continue;
            }

            if (h != 1 && count_ % 2 == 0)
            {
                printf("The vector must has 1 row\n\n");
                continue;
            }

            if (h < 1 || h > MAX_SZ || w < 1 || w > MAX_SZ)
                printf("Error size of matrix\n\n");
            else
                break;
        }

        if (count_ % 2 == 1)
            printf("\n");
    }

    float ratio = (float) per / 100;
    int sz = w * h;
    int c_per = (int) (sz * ratio);

    tc->n = w;
    tc->h = h;
    sm->nz = c_per;
    sm->n = w;

    int *d = malloc(c_per * sizeof(int));
    int *wi = malloc(c_per * sizeof(int));
    int *he = malloc(c_per * sizeof(int));

    struct classic_matrix *ptr = \
    malloc(tc->n * tc->n * sizeof(struct classic_matrix));

    int *ia = malloc((sm->n + 1) * sizeof(int));

    if (!ia)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    int *ja = malloc(sm->nz * sizeof(int));

    if (!ja)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    float *a = malloc(sm->nz * sizeof(float));

    if (!a)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    sm->ia = ia;
    sm->ja = ja;
    sm->a = a;

    tc->p = ptr;

    if (!ptr)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    int *tmph = malloc(sm->nz * sizeof(int));

    if (!tmph)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    for (int i = 0, count = 0; i < h && count < c_per; i++)
    {
        for (int j = 0; j < w && count < c_per; j++)
        {
            if ((h - i) * (w - j) > c_per - count)
            {
                if (rand() % 100 <= per)
                {
                    int num = rand() % 10 + 1;
                    d[count] = num;
                    wi[count] = j;
                    he[count] = i;
                    sm->a[count] = num;
                    sm->ja[count] = j;
                    tmph[count] = i;
                    count++;
                }
            }
            else
            {
                int num = rand() % 10 + 1;
                d[count] = num;
                wi[count] = j;
                he[count] = i;
                sm->a[count] = num;
                sm->ja[count] = j;
                tmph[count] = i;
                count++;
            }
        }
    }

    int ee = 0;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < tc->n; j++)
        {
            int k;
            for (k = 0; k < c_per && (wi[k] != j || he[k] != i); k++);
            if (k == c_per)
            {
                cm.data = 0;
            }
            else
            {
                cm.data = d[k];
            }

            cm.height = i;
            cm.width = j;

            tc->p[ee++] = cm;
        }

    for (int i = 0; i < sm->n; i++)
    {
        int j;
        for (j = 0; j < sm->nz; j++)
        {
            if (i == tmph[j])
            {
                sm->ia[i] = j;
                break;
            }
        }
        if (j == sm->nz)
            sm->ia[i] = -1;
    }

    sm->ia[sm->n] = sm->nz;

    for (int i = 0; i < sm->n + 1; i++)
    {
        if (sm->ia[i] == -1)
        {
            int j;
            for (j = 0; sm->ia[i+j] == -1; j++);
            sm->ia[i] = sm->ia[i+j];
        }
    }

    free(tmph);

    return OK;
}

#endif // F_GENERATE_C

