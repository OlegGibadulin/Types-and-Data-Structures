#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERR_MEMORY 1
#define ERR_POINTER 2

#define SZ 1000

typedef struct node node_t;

struct node
{
    void *ptr;
    node_t *next;
};

void f_in_str(char *msg, char *str, int n);
void f_in_int(char *msg, int *num, int n);

int f_allocation(void ***p, int n, int m);
void f_free(char **p, int n);

void add_array(void *arr[], int *count, void *ptr);
void pop_array(void *arr[], int *count);
void show_array(void *ptr[], int count);
unsigned long long tick(void);

void add_list(node_t **head);
void show_list(node_t *head);
void pop_list(node_t **head, node_t **arr);
void f_show_free_pointers(node_t *head);

#endif // MAIN_H

