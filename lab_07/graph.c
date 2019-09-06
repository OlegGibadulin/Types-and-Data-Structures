#ifndef GRAPH_C
#define GRAPH_C

#include "main.h"

graph *init_graph(int data)
{
    graph *ptr = malloc(sizeof(graph));
    ptr->sz = data;
    ptr->arr = malloc(data * sizeof(list_node));
    for (int i = 0; i < data; i++)
        ptr->arr[i].head = NULL;

    return ptr;
}

node *init_node(int data)
{
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void insert_graph(graph *ptr, int from, int data)
{
    node *tmp = init_node(data);
    tmp->next = ptr->arr[from].head;
    ptr->arr[from].head = tmp;

    if (from == data)
        return;

    tmp = init_node(from);
    tmp->next = ptr->arr[data].head;
    ptr->arr[data].head = tmp;
}

void show_graph(FILE *f, graph *head)
{
    node_queue *ptr = NULL;
    node *tmp = NULL;
    int check[100] = { 0 };
    int data;

    insert_queue(&ptr, 0);
    check[0] = 1;

    fprintf(f, "graph name\n{\n");

    while (ptr)
    {
        tmp = head->arr[ptr->data].head;
        data = ptr->data;
        remove_queue(&ptr);
        while (tmp)
        {
            if (data <= tmp->data)
                fprintf(f, "    %d -- %d\n", data, tmp->data);
            if (!check[tmp->data])
            {
                insert_queue(&ptr, tmp->data);
                check[tmp->data] = 1;
            }
            tmp = tmp->next;
        }
    }
    fprintf(f, "}\n");
    printf("The data is writen to file\n\n");
}

void BFS(graph *head, int num, int path)
{
    node_queue *ptr = NULL;
    node_queue *ptr_path = NULL;
    node *tmp = NULL;
    int check[100] = { 0 };

    insert_queue(&ptr, num);
    check[num] = 1;

    for (int i = 0; i < path + 1; i++)
    {
        while (ptr)
        {
            tmp = head->arr[ptr->data].head;
            if (i)
                printf("%d ", ptr->data);
            remove_queue(&ptr);

            while (tmp)
            {
                if (!check[tmp->data] || (i == 0 && num == tmp->data))
                {
                    insert_queue(&ptr_path, tmp->data);
                    check[tmp->data] = 1;
                }
                tmp = tmp->next;
            }
        }
        ptr = ptr_path;
        ptr_path = NULL;
    }
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

#endif // GRAPH_C

