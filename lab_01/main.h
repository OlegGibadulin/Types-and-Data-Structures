#include <stdio.h>
#include <ctype.h>

#define OK 0
#define ERR_IN 1
#define ERR_COUNT 2

int f_in1(int *num, int *len, int *mark, int *degree);
int f_in2(int *num, int *degree, int *len, int *mark);
int f_count(int *num1, int *num2, int *res, int count1, \
            int count2, int *degree, int *len_res);
void f_out(int *res, int len_res, int degree, int mark1, int mark2);
