#ifndef LIST_ACTIONS_C
#define LIST_ACTIONS_C

#include "main.h"

void init_list(list *ptr)
{
    ptr->start = malloc(sizeof(element));
    if (!ptr->start)
    {
        printf("Memory error");
        return;
    }
    ptr->ptr = ptr->start;
    ptr->ptr->next = NULL;
}

void put_list(list *ptr, type data, void **tmp)
{
    while (ptr->ptr->next)
         ptr->ptr = ptr->ptr->next;
    element *elem = malloc(sizeof(element));
    *tmp = elem;
    if (!elem)
    {
        printf("Memory error");
        return;
    }
    elem->data = data;
    elem->next = ptr->ptr->next;
    ptr->ptr->next = elem;
}

void get_list(list *ptr, type *data)
{
    ptr->ptr = ptr->start;
    if (isempty_list(ptr) || !ptr->ptr->next)
        return;
    element *elem = ptr->ptr->next;
    ptr->ptr->next = elem->next;
    *data = elem->data;
    elem->next = NULL;
    free(elem);
}

int isempty_list(list *ptr)
{
    if (!ptr->ptr->next)
        return EMPTY;
    return OK;
}

#endif // LIST_ACTIONS_C

