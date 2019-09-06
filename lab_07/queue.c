#ifndef QUEUE_C
#define QUEUE_C

#include "main.h"

void insert_queue(node_queue **head, int data)
{
    node_queue *elem = NULL;
    node_queue *ptr = *head;

    elem = malloc(sizeof(node_queue));
    if (!elem)
    {
        printf("Memory can not be allocated");
        return;
    }

    elem->next = NULL;
    elem->data = data;

    if (!*head)
        *head = elem;
    else
    {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = elem;
    }
}

void show_queue(node_queue *head)
{
    if (!head)
    {
        printf("The list is empty");
        return;
    }
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void remove_queue(node_queue **head)
{
    if (!*head)
    {
        printf("The list is empty");
        return;
    }
    node_queue *ptr = *head;

    if (!ptr->next)
        *head = NULL;
    else
        *head = ptr->next;

    free(ptr);
}

#endif // QUEUE_C

