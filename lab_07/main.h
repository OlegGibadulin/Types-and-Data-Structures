#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERR_CMD 1
#define ERR_EXIST_FILE 2
#define ERR_EMPTY_FILE 3
#define ERR_DATA 4
#define ERR_COUNT 5

#define SZ 31

typedef struct node node;
typedef struct list_node list_node;
typedef struct graph graph;
typedef struct node_queue node_queue;

struct node_queue
{
    int data;
    node_queue *next;
};

struct node
{
    int data;
    node *next;
};

struct list_node
{
    node *head;
};

struct graph
{
    int sz;
    list_node *arr;
};

void f_in_str(char *msg, char *str, int n);
void f_in_int(char *msg, int *num, int n);

graph *init_graph(int data);
node *init_node(int data);
void insert_graph(graph *ptr, int from, int data);
void show_graph(FILE *f, graph *head);
void BFS(graph *head, int num, int path);
unsigned long long tick(void);

void insert_queue(node_queue **head, int data);
void show_queue(node_queue *head);
void remove_queue(node_queue **head);

#endif // MAIN_H

