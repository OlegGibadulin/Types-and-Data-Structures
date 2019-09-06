#ifndef F_MULTIPLICATION_C
#define F_MULTIPLICATION_C

#include "main.h"

void f_multiplication_classic(struct table_classic *tc, struct table_classic \
                             *tc_, int check)
{
    float *res = calloc(tc->n, sizeof(float));

    for (int i = 0; i < tc->h; i++)
    {
        for (int j = 0; j < tc->n; j++)
        {
            res[i] += tc->p[j * tc->n + i].data * tc_->p[j].data;
        }
    }

    if (check)
        for (int i = 0; i < tc->n; i++)
            printf("%7.2f ", res[i]);

    free(res);
}

void f_multiplication_spare(struct spare_matrix *sm, \
                            struct spare_matrix *sm_, \
                            struct spare_matrix *res, int check)
{
    int *ia = calloc((sm_->n + 1), sizeof(int));

    if (!ia)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    int *ja = calloc(sm_->n, sizeof(int));

    if (!ja)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    float *a = calloc(sm_->n, sizeof(float));

    if (!a)
    {
        printf("The memory can not allocated");
        return ERR_MEMORY;
    }

    res->ia = ia;
    res->ja = ja;
    res->a = a;
    res->n = sm_->n;
    res->nz = 0;

    int count = 0;
    double *res1 = calloc(sm->n, sizeof(double));

    for (int i = 0; i < sm->n; i++)
    {
        if (sm_->ja[count] == i)
        {
            for (int j = sm->ia[i]; j < sm->ia[i+1]; j++)
            {
                int k;
                res->nz = res->nz + 1;
                for (k = 0; k < res->nz && res->ja[k] != sm->ja[j]; k++)
                {
                    if (k != res->nz)
                    {
                        res->ja[count] = sm->ja[j];
                        res->ia[count] += sm->a[j] * sm_->a[count];
                    }
                }
                res1[sm->ja[j]] += sm->a[j] * sm_->a[count];
            }
            count++;
        }
    }

    if (check)
        for (int i = 0; i < sm->n; i++)
            printf("%7.2f ", res1[i]);
}

#endif // F_MULTIPLICATION_C
