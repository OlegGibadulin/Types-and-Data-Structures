#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 0
#define ERR_CMD 1
#define ERR_EXIST_FILE 2
#define ERR_DATA 3

#define SZ 31
#define SZ_HT 100

typedef int type;

typedef struct node_bst node;

struct node_bst
{
    type data;
    node *left;
    node *right;
};

typedef struct node_avl node_avl;

struct node_avl
{
    type data;
    node_avl *left;
    node_avl *right;
    int height;
};

typedef struct node_ht node_ht;

struct node_ht
{
    int data;
    int key;
};

node_ht *ht[SZ_HT];

node_avl *init_avl(type data);
node_avl *insert_avl(node_avl *ptr, type data);
int func_max(int x, int y);
int height(node_avl *ptr);
node_avl *single_rotate_right(node_avl *ptr);
node_avl *single_rotate_left(node_avl *ptr);
node_avl *double_rotate_right(node_avl *ptr);
node_avl *double_rotate_left(node_avl *ptr);
void show_avl(node_avl *ptr, int place);
void free_avl(node_avl *ptr);
node_avl *min_avl(node_avl *ptr);
node_avl *search_avl(node_avl *ptr, type data, int *count);
node_avl *remove_avl(node_avl *ptr, type data);

node *init_bts(type data);
node *insert_bts(node *ptr, type data);
node *search_bts(node *ptr, type data, int *count);
node *remove_bts(node *ptr, type data);
node *min_bst(node *ptr);
void show_bst(node *ptr, int place);
void free_bst(node *ptr);
unsigned long long tick(void);

void f_in_str(char *msg, char *str, int n);
void f_in_int(char *msg, int *num, int n);

int hash(int key);
void init_ht(node_ht **ptr);
void insert_ht(int data, int key);
node_ht *remove_ht(int key, int *count);
void show_ht();

#endif // MAIN_H

