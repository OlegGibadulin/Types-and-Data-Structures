#ifndef F_ADD_C
#define F_ADD_C

#include "main.h"

void f_clear_cm(struct table_classic *tc)
{
    if (tc->p != NULL)
    {
        free(tc->p);
        tc->p = NULL;
    }

    tc->n = 0;
}

void f_clean_sm(struct spare_matrix *sm)
{
    if (sm->a && sm->ja && sm->ia)
    {
        free(sm->a);
        sm->a = NULL;
        free(sm->ja);
        sm->ja = NULL;
        free(sm->ia);
        sm->ia = NULL;
    }

    sm->n = 0;
    sm->nz = 0;
}

static int count_ = 0;

int f_add(struct table_classic *tc, struct spare_matrix *sm)
{
    struct classic_matrix cm;
    int h = 0, w = 0, count = 0, r = 0, c = 0;

    f_clear_cm(tc);
    f_clean_sm(sm);

    count_++;

    float dig;

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

    sm->n = w;
    tc->n = w;
    tc->h = h;

    for (;;)
    {
        f_in_int("\nInput count of nonzero elements: ", &count, SZ);

        if (count < 0 || count > MAX_SZ * MAX_SZ || count > h * w)
            printf("Error count\n\n");
        else
            break;
    }

    sm->nz = count;

    int *d = malloc(count * sizeof(int));
    int *wi = malloc(count * sizeof(int));
    int *he = malloc(count * sizeof(int));

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

    int c_check;

    for (int i = 0; i < count; i++)
    {
        f_in_int("\nInput row: ", &r, SZ);
        f_in_int("Input column: ", &c, SZ);
        f_in_float("Input nonzero digit: ", &dig, SZ);

        c_check = 0;

        for (int j = 0; j < i; j++)
        {
            if (r - 1 == he[j] && c - 1 == wi[j])
            {
                printf("Error input\n\n");
                c_check = 1;

                break;
            }
        }

        if (r < 1 || r > h || c < 1 || c > w || dig == 0 || c_check)
        {
            printf("Error input\n\n");
            i--;
        }
        else
        {
            d[i] = dig;
            wi[i] = c - 1;
            he[i] = r - 1;
            sm->a[i] = dig;
            sm->ja[i] = c - 1;
            tmph[i] = r - 1;
        }
    }

    int ee = 0;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < tc->n; j++)
        {
            int k;
            for (k = 0; k < count && (wi[k] != j || he[k] != i); k++);
            if (k == count)
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

    for (int i = 1; i < sm->nz; i++)
        for (int j = 0; j < sm->nz - i; j++)
            if (tmph[j] > tmph[j+1] && sm->ja[j] > sm->ja[j+1])
            {
                int tmp1;
                int tmp2;
                double tmp3;

                tmp1 = tmph[j];
                tmph[j] = tmph[j+1];
                tmph[j+1] = tmp1;

                tmp2 = sm->ja[j];
                sm->ja[j] = sm->ja[j+1];
                sm->ja[j+1] = tmp2;

                tmp3 = sm->a[j];
                sm->a[j] = sm->a[j+1];
                sm->a[j+1] = tmp3;
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
    free(d);
    free(wi);
    free(he);

    return OK;
}

#endif // F_ADD_C
