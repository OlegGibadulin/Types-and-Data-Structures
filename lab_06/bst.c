#ifndef BST_C
#define BST_C

#include "main.h"

node *init_bts(type data)
{
    node *ptr = malloc(sizeof(node));

    if (!ptr)
    {
        printf("Error memory");
        return NULL;
    }

    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

node *insert_bts(node *ptr, type data)
{
    if (!ptr)
        return init_bts(data);

    if (data > ptr->data)
        ptr->right = insert_bts(ptr->right, data);
    else
        ptr->left = insert_bts(ptr->left, data);

    return ptr;
}

/*void show_bts(node *ptr, int place)
{
    if (ptr)
    {
        show_bts(ptr->left, place + 1);
        printf("Level %d - %d\n", place, ptr->data);
        show_bts(ptr->right, place + 1);
    }
}*/

node *search_bts(node *ptr, type data, int *count)
{
    *count += 1;
    if (!ptr || ptr->data == data)
        return ptr;
    else
    {
        if (data > ptr->data)
            return search_bts(ptr->right, data, count);
        else
            return search_bts(ptr->left, data, count);
    }
}

node *remove_bts(node *ptr, type data)
{
    if (!ptr)
        return ptr;
    if (data > ptr->data)
        ptr->right = remove_bts(ptr->right, data);
    else
    {
        if (data < ptr->data)
            ptr->left = remove_bts(ptr->left, data);
        else
        {
            if (!ptr->left && !ptr->right)
            {
                free(ptr);
                return NULL;
            }
            else
            {
                if (!ptr->left || !ptr->right)
                {
                    node *tmp;
                    if (!ptr->left)
                        tmp = ptr->right;
                    else
                        tmp = ptr->left;
                    free(ptr);
                    return tmp;
                }
                else
                {
                    node *tmp = min_bst(ptr->right);
                    ptr->data = tmp->data;
                    ptr->right = remove_bts(ptr->right, tmp->data);
                }
            }
        }
    }
    return ptr;
}

node *min_bst(node *ptr)
{
    if (!ptr)
        return NULL;
    else
        if (ptr->left)
            return min_bst(ptr->left);
    return ptr;
}

void show_bst(node *ptr, int place)
{
    if (ptr)
    {
        show_bst(ptr->left, place + 1);
        for (int i = 0; i < place; i++)
            printf("    ");
        printf("%d\n", ptr->data);
        show_bst(ptr->right, place + 1);
    }
}

void free_bst(node *ptr)
{
    if (ptr)
    {
        free_bst(ptr->left);
        free_bst(ptr->right);
        free(ptr);
    }
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

#endif // BST_C

