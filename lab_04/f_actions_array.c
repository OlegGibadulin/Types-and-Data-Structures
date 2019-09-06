#ifndef F_ACTIONS_ARRAY_C
#define F_ACTIONS_ARRAY_C

#include "main.h"

void add_array(void *arr[1], int *count, void *ptr)
{
    if (*count == SZ)
    {
        printf("The array is full");
        return;
    }

    if (!ptr)
    {
        printf("Error input");
        return;
    }

    arr[*count] = ptr;
    *count += 1;
}

void pop_array(void *arr[1], int *count)
{
    if (!*count)
    {
        printf("The array is empty");
        return;
    }
    *count -= 1;
}

void show_array(void *arr[1], int count)
{
    if (!count)
    {
        printf("The array is empty");
        return;
    }
    printf("\n|Pointers in array|\n"
           "|_________________|\n");

    for (int i = 0; i < count; i++)
        printf("|%-17p|\n", arr[i]);

    printf("|_________________|\n");
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

#endif // F_ACTIONS_ARRAY_C

