#ifndef TREE_C
#define TREE_C

#include "main.h"

int hash(int key)
{
    return (key) % SZ_HT;
}

void insert_ht(int data, int key)
{
    node_ht *tmp = malloc(sizeof(node_ht));
    int i = hash(key);
    int c_count = 0;

    tmp->data = data;
    tmp->key = key;

    while(ht[i] && ht[i]->key != -1)
    {
        c_count++;
        i++;
        i = (i) % SZ_HT;
        tmp->key = i;
    }

    ht[i] = tmp;
}

void show_ht()
{
    for (int i = 0; i < SZ_HT; i++)
    {
        if (ht[i])
            printf("%d %d\n", ht[i]->key, ht[i]->data);
    }
}

node_ht *remove_ht(int key, int *count)
{
    int i = 0;

    for (i = 0; ht[i]; i++)
    {
        if (ht[i]->data == key)
        {
            *count = 1;
            node_ht *tmp = ht[i];
            node_ht *p = NULL;
            ht[i] = p;
            return tmp;
        }
    }
    *count = 0;
    return NULL;
    /*int i = hash(key);
    int c_count = i;

    while (ht[i])
    {
        *count += 1;
        while (ht[c_count] && c_count < 4)
        {
            *count += 1;
            c_count--;
        }
        if (ht[i]->key == key)
        {
            node_ht *tmp = ht[i];
            node_ht *p = NULL;
            ht[i] = p;
            return tmp;
        }
        i++;
        i %= SZ_HT;
        *count += 1;
    }

    return NULL;*/
}

#endif // TREE_C

