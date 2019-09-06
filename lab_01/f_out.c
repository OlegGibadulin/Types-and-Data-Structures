#include "main.h"

void f_out(int *res, int len_res, int degree, int mark1, int mark2)
{
    printf("Result in the normalized form of a "
           "number in exponential form:\n");

    if ((mark1 + mark2) % 2 == 1)
        printf("-");

    printf("0.");

    for (int i = 0; i < len_res; i++)
        printf("%d", res[i]);

    printf(" E ");

    if (len_res == 1 && res[0] == 0)
        printf("0");
    else
        printf("%d", degree);
}
