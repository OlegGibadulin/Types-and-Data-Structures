#ifndef F_EFFECTIVENESS_C
#define F_EFFECTIVENESS_C

#include "main.h"

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

#endif // F_EFFECTIVENESS_C

