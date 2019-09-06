#ifndef AVL_C
#define AVL_C

#include "main.h"

node_avl *init_avl(type data)
{
    node_avl *ptr = malloc(sizeof(node_avl));

    if (!ptr)
    {
        printf("Error memory");
        return NULL;
    }

    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 0;

    return ptr;
}

node_avl *insert_avl(node_avl *ptr, type data)
{
    if (!ptr)
        return init_avl(data);

    if (data > ptr->data)
    {
        ptr->right = insert_avl(ptr->right, data);
        if (height(ptr->right) - height(ptr->left) == 2)
        {
            if (data > ptr->right->data)
                ptr = single_rotate_right(ptr);
            else
                ptr = double_rotate_right(ptr);
        }
    }
    else
    {
        ptr->left = insert_avl(ptr->left, data);
        if (height(ptr->left) - height(ptr->right) == 2)
        {
            if (data < ptr->left->data)
                ptr = single_rotate_left(ptr);
            else
                ptr = double_rotate_left(ptr);
        }
    }

    ptr->height = func_max(height(ptr->left), height(ptr->right)) + 1;

    return ptr;
}

int func_max(int x, int y)
{
    if (x >= y)
        return x;

    return y;
}

int height(node_avl *ptr)
{
    if (ptr)
        return ptr->height;

    return -1;
}

node_avl *single_rotate_right(node_avl *ptr)
{
    if (!ptr || !ptr->right)
        return ptr;
    node_avl *tmp = ptr->right;
    ptr->right = tmp->left;
    tmp->left = ptr;
    ptr->height = func_max(height(ptr->left), height(ptr->right)) + 1;
    tmp->height = func_max(height(tmp->right), ptr->height) + 1;

    return tmp;
}

node_avl *single_rotate_left(node_avl *ptr)
{
    if (!ptr || !ptr->left)
        return ptr;
    node_avl *tmp = ptr->left;
    ptr->left = tmp->right;
    tmp->right = ptr;
    ptr->height = func_max(height(ptr->left), height(ptr->right)) + 1;
    tmp->height = func_max(height(tmp->left), ptr->height) + 1;

    return tmp;
}

node_avl *double_rotate_right(node_avl *ptr)
{
    ptr->right = single_rotate_left(ptr->right);
    return single_rotate_right(ptr);
}

node_avl *double_rotate_left(node_avl *ptr)
{
    ptr->left = single_rotate_right(ptr->left);
    return single_rotate_left(ptr);
}

void show_avl(node_avl *ptr, int place)
{
    if (ptr)
    {
        show_avl(ptr->left, place + 1);
        for (int i = 0; i < place; i++)
            printf("    ");
        printf("%d\n", ptr->data);
        show_avl(ptr->right, place + 1);
    }
}

void free_avl(node_avl *ptr)
{
    if (ptr)
    {
        free_avl(ptr->left);
        free_avl(ptr->right);
        free(ptr);
    }
}

node_avl *min_avl(node_avl *ptr)
{
    if (!ptr)
        return NULL;
    else if (ptr->left)
        return min_avl(ptr->left);
    return ptr;
}

node_avl *search_avl(node_avl *ptr, type data, int *count)
{
    *count += 1;
    if (!ptr || ptr->data == data)
        return ptr;
    else
    {
        if (data > ptr->data)
            return search_avl(ptr->right, data, count);
        else
            return search_avl(ptr->left, data, count);
    }
}

node_avl *remove_avl(node_avl *ptr, type data)
{
    node_avl *tmp;

    if (!ptr)
        return NULL;

    if (data > ptr->data)
        ptr->right = remove_avl(ptr->right, data);
    else if (data < ptr->data)
        ptr->left = remove_avl(ptr->left, data);
    else if (ptr->left && ptr->right)
    {
        tmp = min_avl(ptr->right);
        ptr->data = tmp->data;
        ptr->right = remove_avl(ptr->right, ptr->data);
    }
    else
    {
        tmp = ptr;
        if (!ptr->left)
            ptr = ptr->right;
        else if (!ptr->right)
            ptr = ptr->left;
        free(tmp);
    }
    if (!ptr)
        return ptr;

    ptr->height = func_max(height(ptr->left), height(ptr->right)) + 1;

    if (height(ptr->left) - height(ptr->right) == 2)
    {
        if (height(ptr->left->left) - height(ptr->left->right) == 1)
            return single_rotate_left(ptr);
        else
            return double_rotate_left(ptr);
    }
    else if (height(ptr->right) - height(ptr->left) == 2)
    {
        if (height(ptr->right->right) - height(ptr->right->left) == 1)
            return single_rotate_right(ptr);
        else
            return double_rotate_right(ptr);
    }

    return ptr;
}

#endif // AVL_C

