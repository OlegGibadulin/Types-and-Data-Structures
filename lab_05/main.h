#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define OK 0
#define ERR_MEMORY 1
#define ERR_POINTER 2
#define FULL 1
#define EMPTY 1
#define SZ 31
#define SZ_ARR 1000
#define SZ_BUF 10000

typedef float type;
typedef struct array array;
typedef struct list list;
typedef struct element element;

struct array
{
    type buf[SZ_BUF];
    int head;
    int tail;
    int len;
};

struct element
{
    type data;
    element *next;
};

struct list
{
    element *start;
    element *ptr;
};

void f_in_str(char *msg, char *str, int n);
void f_in_int(char *msg, int *num, int n);
unsigned long long tick(void);
int f_allocation(void ***p, int n, int m);
void f_free(char **p, int n);

int isfull_array(array *ptr);
int isempty_array(array *ptr);
void init_array(array *ptr);
void put_array(array *ptr, type data);
void get_array(array *ptr, type *data);

void init_list(list *ptr);
void put_list(list *ptr, type data, void **tmp);
void get_list(list *ptr, type *data);
int isempty_list(list *ptr);

#endif MAIN_H
