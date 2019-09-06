#ifndef F_FREE_C
#define F_FREE_C

void f_free(char **p, int n)
{
    for (int i = 0; i < n; i++)
        free(p[i]);

    free(p);
}

#endif // F_FREE_C

