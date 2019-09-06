#include "main.h"

int main()
{
    int num1[30];
    int num2[30];
    int res[60] = {0};

    int len1 = 0;
    int len2 = 0;
    int len_res = 0;
    int degree = 0;

    int mark1 = 0;
    int mark2 = 0;

    printf("Production of an integer by a real numbers\n\n");
    printf("The first number is integer : max count of digits is 30 : "
           "0 -0\n\n");
    printf("The second number is real : max count of digits of a mantis "
           "is 30, a degree is 5 : -+0.0 -0e-0 -0E-0\n\n");

    switch (f_in1(num1, &len1, &mark1, &degree))
    {
    case ERR_IN : return ERR_IN;
    case ERR_COUNT : return ERR_COUNT;
    default : break;
    }

    switch (f_in2(num2, &degree, &len2, &mark2))
    {
    case ERR_IN : return ERR_IN;
    case ERR_COUNT : return ERR_COUNT;
    default : break;
    }

    printf("\n");

    if (f_count(num1, num2, res, len1, len2, &degree, &len_res) == ERR_COUNT)
        return ERR_COUNT;

    f_out(res, len_res, degree, mark1, mark2);

    return OK;
}
