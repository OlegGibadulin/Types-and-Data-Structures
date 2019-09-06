#ifndef F_SHOW_C
#define F_SHOW_C

#include "main.h"

void f_show(struct table_classic *tc, struct table_classic *tc_)
{
    printf("\nThe classic matrix\n\n");

    int ce = 0;

    for (int i = 0; i < tc->n; i++)
    {
        for (int j = 0; j < tc->n; j++)
        {
            printf("%7.2f ", tc->p[ce++].data);
        }
        printf("\n");
    }

    printf("\nThe classic vector\n\n");

    for (int j = 0; j < tc->n; j++)
    {
        printf("%7.2f ", tc_->p[j].data);
    }
}

void f_show_spare(struct spare_matrix sm, struct spare_matrix sm_)
{
    printf("\n\nThe spare matrix\n\n");

    for (int i = 0; i < sm.n; i++)
    {
        for (int j = 0; j < sm.n; j++)
        {
            int check = 1;
            for (int k = 0; k < sm.nz; k++)
            {
                if (k >= sm.ia[i] && k < sm.ia[i+1] && sm.ja[k] == j)
                {
                    printf("%7.2f ", sm.a[k]);

                    check = 0;
                    break;
                }
            }

            if (check)
                printf("%7.2f ", 0.0);
        }
        printf("\n");
    }

    printf("\nThe spare vector\n\n");

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < sm_.n; j++)
        {
            int check = 1;
            for (int k = 0; k < sm_.nz; k++)
            {
                if (sm_.ja[k] == j)
                {
                    printf("%7.2f ", sm_.a[k]);

                    check = 0;
                    break;
                }
            }

            if (check)
                printf("%7.2f ", 0.0);
        }
    }
}

#endif // F_SHOW_C

