#ifndef F_ACTIONS_LIST_C
#define F_ACTIONS_LIST_C

#include "main.h"

void add_list(node_t **head)
{
    node_t *elem = NULL;
    node_t *ptr = *head;
    /*void *tmp = NULL;

    tmp = malloc(sizeof(void));

    if (!tmp)
    {
        printf("Memory can not be allocated");
        return;
    }*/

    elem = malloc(sizeof(node_t));

    if (!elem)
    {
        printf("Memory can not be allocated");
        return;
    }

    elem->next = NULL;
    elem->ptr = &(elem->ptr);

    if (!*head)
        *head = elem;
    else
    {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = elem;
    }
}

void show_list(node_t *head)
{
    if (!head)
    {
        printf("The list is empty");
        return;
    }
    node_t *ptr = head;

    printf("\n|Pointers in list |\n"
           "|_________________|\n"
           "|Element          |\n");

    while (ptr)
    {
        printf("|%-17p|\n", ptr->ptr);
        ptr = ptr->next;
    }

    printf("|_________________|\n");
}

void pop_list(node_t **head, node_t **arr)
{
    if (!*head)
    {
        printf("The list is empty");
        return;
    }
    node_t *ptr = *head;
    node_t *tmp = *head;
    node_t *elem = NULL;
    node_t *tail = *arr;
    // node_t *elem_ptr = NULL;
    // node_t *tail_ptr = *arr_elem;

    while (ptr->next)
    {
        tmp = ptr;
        ptr = ptr->next;
    }

    elem = malloc(sizeof(node_t));

    if (!elem)
    {
        printf("Memory can not be allocated");
        return;
    }

    elem->next = NULL;
    elem->ptr = ptr->ptr;

    if (!*arr)
        *arr = elem;
    else
    {
        while (tail->next)
            tail = tail->next;
        tail->next = elem;
    }

    if (ptr == tmp)
        *head = NULL;
    else
        tmp->next = NULL;

    // free(ptr->ptr);
    // free(ptr);
}

void f_show_free_pointers(node_t *head)
{
    if (!head)
    {
        printf("The list is empty");
        return;
    }
    printf("\n|Free pointers   |\n"
           "|________________|\n"
           "|Element         |\n");
    while (head)
    {
        printf("|%-16p|\n", head->ptr);
        head = head->next;
    }

    printf("|________________|\n");
}

#endif // F_ACTIONS_LIST_C

