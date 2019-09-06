#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 0
#define ERR_MEMORY 1
#define SZ 31
#define MAX_SZ 1000

struct classic_matrix
{
    float data;
    int height;
    int width;
};

struct spare_matrix
{
    int n;
    int nz;
    float *a;
    int *ia;
    int *ja;
};

struct table_classic
{
    struct classic_matrix *p;
    int n;
    int h;
};

void f_in_str(char *msg, char *str, int n);
void f_in_int(char *msg, int *num, int n);
void f_in_float(char *msg, float *num, int n);

int f_add(struct table_classic *tc, struct spare_matrix *sm);
void f_clear_cm(struct table_classic *tc);
void f_clean_sm(struct spare_matrix *sm);

int f_generate(struct table_classic *tc, struct spare_matrix *sm, int per, \
    int h, int w);
int f_generate_effectiveness(struct table_classic *tc, \
                             struct spare_matrix *sm, int per, int h, int w);

void f_show(struct table_classic *tc, struct table_classic *tc_);
void f_show_spare(struct spare_matrix sm, struct spare_matrix sm_);

void f_multiplication_classic(struct table_classic *tc, struct table_classic \
                             *tc_, int check);

void f_multiplication_spare(struct spare_matrix *sm, \
                            struct spare_matrix *sm_, \
                            struct spare_matrix *res, int check);

unsigned long long tick(void);

#endif // MAIN_H

