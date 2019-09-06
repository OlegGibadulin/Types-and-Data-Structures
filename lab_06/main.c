#ifndef MAIN_C
#define MAIN_C

#include "main.h"

int main(int argc, char *argv[])
{
    FILE *f = NULL;
    int num, data, check, c_count = 0, count = 0, c_bst = 0, c_avl = 0;
    node *ptr = NULL;
    node_avl *ptr_avl = NULL;
    node_ht *ptr_ht_r = NULL;
    unsigned long long tb1 = 0, te1, tb2 = 0, te2, tb3 = 0, te3, tb4 = 0, te4;
    int arr[SZ_HT], comp_bst = 0, comp_avl = 0, comp_ht = 0;
    long place;

    if (argc != 2)
    {
        printf("Error cmd");
        return ERR_CMD;
    }

    f = fopen(argv[1], "r");
    if (!f)
    {
        printf("Error exist file");
        return ERR_EXIST_FILE;
    }
    fclose(f);

    printf("BST, AVL, HT, File");

    for (;;)
    {
        printf("\n\nMenu:\n\n"
               "1 - Create BST\n"
               "2 - Show BST\n"
               "3 - Create AVL\n"
               "4 - Show AVL\n"
               "5 - Create HT\n"
               "6 - Show HT\n"
               "7 - Remove from BST\n"
               "8 - Remove from AVL\n"
               "9 - Remove from HT\n"
               "10 - Remove from File\n"
               "11 - Show File\n"
               "12 - Show effectiveness\n"
               "0 - Exit\n\n");

        f_in_int("Input number: ", &num, SZ);

        switch (num)
        {
            case 1:
                free_bst(ptr);
                ptr = NULL;
                f = fopen(argv[1], "r");
                place = ftell(f);
                fseek(f, 0, SEEK_END);
                if (place == ftell(f))
                {
                    printf("File is empty");
                    continue;
                }
                fseek(f, 0, SEEK_SET);
                while ((check = fscanf(f, "%d", &data)) == 1)
                {
                    ptr = insert_bts(ptr, data);
                    c_bst++;
                }
                if (!check)
                {
                    printf("Error input");
                    return ERR_DATA;
                }
                printf("BTS is created succsessfully");
                fclose(f);
                continue;
            case 2:
                if (!c_bst)
                {
                    printf("The BST is empty");
                    continue;
                }
                show_bst(ptr, 0);
                continue;
            case 3:
                free_avl(ptr_avl);
                ptr_avl = NULL;
                f = fopen(argv[1], "r");
                place = ftell(f);
                fseek(f, 0, SEEK_END);
                if (place == ftell(f))
                {
                    printf("File is empty");
                    continue;
                }
                fseek(f, 0, SEEK_SET);
                while ((check = fscanf(f, "%d", &data)) == 1)
                {
                    ptr_avl = insert_avl(ptr_avl, data);
                    c_avl++;
                }
                if (!check)
                {
                    printf("Error input");
                    return ERR_DATA;
                }
                printf("AVL is created succsessfully");
                fclose(f);
                continue;
            case 4:
                if (!c_avl)
                {
                    printf("The AVL is empty");
                    continue;
                }
                show_avl(ptr_avl, 0);
                continue;
            case 5:
                c_count = 0;
                f = fopen(argv[1], "r");
                place = ftell(f);
                fseek(f, 0, SEEK_END);
                if (place == ftell(f))
                {
                    printf("File is empty");
                    continue;
                }
                fseek(f, 0, SEEK_SET);
                while ((check = fscanf(f, "%d", &data)) == 1)
                {
                    insert_ht(data, c_count);
                    c_count++;
                }
                if (!check)
                {
                    printf("Error input");
                    return ERR_DATA;
                }
                printf("HT is created succsessfully");
                fclose(f);
                continue;
            case 6:
                if (!c_count)
                {
                    printf("The HT is empty");
                    continue;
                }
                show_ht();
                continue;
            case 7:
                if (!c_bst)
                {
                    printf("The BST is empty");
                    continue;
                }
                f_in_int("Input element data: ", &num, SZ);
                comp_bst = 0;
                tb1 = tick();
                if (!search_bts(ptr, num, &comp_bst))
                {
                    te1 = tick();
                    printf("The element does not exist\nTime: %llu\n"
                           "Memory: %d b\nCount of compares: %d", \
                           te1 - tb1, c_bst * 20, comp_bst);
                    continue;
                }
                tb1 = tick();
                ptr = remove_bts(ptr, num);
                te1 = tick();
                c_bst--;
                printf("The data is deleted successfully\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d", \
                       te1 - tb1, c_bst * 20, comp_bst);
                continue;
            case 8:
                if (!c_avl)
                {
                    printf("The AVL is empty");
                    continue;
                }
                comp_avl = 0;
                f_in_int("Input element data: ", &num, SZ);
                tb2 = tick();
                if (!search_avl(ptr_avl, num, &comp_avl))
                {
                    te2 = tick();
                    printf("The element does not exist\nTime: %llu\n"
                           "Memory: %d b\nCount of compares: %d", \
                           te2 - tb2, c_avl * 24, comp_avl);
                    continue;
                }
                tb2 = tick();
                ptr_avl = remove_avl(ptr_avl, num);
                te2 = tick();
                c_avl--;
                printf("The data is deleted successfully\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d", \
                       te2 - tb2, c_avl * 24, comp_avl);
                continue;
            case 9:
                if (!c_count)
                {
                    printf("The HT is empty");
                    continue;
                }
                comp_ht = 0;
                f_in_int("Input element data: ", &num, SZ);
                tb3 = tick();
                ptr_ht_r = remove_ht(num, &comp_ht);
                te3 = tick();
                if (!ptr_ht_r)
                {
                    printf("The element does not exist\nTime: %llu\n"
                           "Memory: %d b\nCount of compares: %d", \
                           (te3 - tb3) / 2, SZ_HT * 8, comp_ht);
                    continue;
                }
                c_count--;
                printf("The data is deleted successfully\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d", \
                       (te3 - tb3) / 2, SZ_HT * 8, comp_ht);
                continue;
            case 10:
                count = 0;
                f = fopen(argv[1], "r");
                place = ftell(f);
                fseek(f, 0, SEEK_END);
                if (place == ftell(f))
                {
                    printf("File is empty");
                    continue;
                }
                fseek(f, 0, SEEK_SET);
                while ((check = fscanf(f, "%d", &data)) == 1)
                    arr[count++] = data;
                if (!check)
                {
                    printf("Error input");
                    return ERR_DATA;
                }
                fclose(f);
                f_in_int("Input element data: ", &num, SZ);
                int i;
                f = fopen(argv[1], "w");
                tb4 = tick();
                for (i = 0; i < count && arr[i] != num; i++);
                if (i == count)
                {
                    te4 = tick();
                    for (int j = 0; j < count; j++)
                        fprintf(f, "%d\n", arr[j]);
                    fclose(f);
                    printf("The element does not exist\nTime: %llu\n"
                           "Memory: %d b\nCount of compares: %d", \
                           te4 - tb4, SZ_HT * 4, i);
                    continue;
                }
                for (int j = i; j + 1 < count; j++)
                    arr[j] = arr[j+1];
                for (int j = 0; j + 1 < count; j++)
                    fprintf(f, "%d\n", arr[j]);
                te4 = tick();
                printf("The data is deleted successfully\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d", \
                       te4 - tb4, SZ_HT * 4, i);
                fclose(f);
                continue;
            case 11:
                f = fopen(argv[1], "r");
                place = ftell(f);
                fseek(f, 0, SEEK_END);
                if (place == ftell(f))
                {
                    printf("File is empty");
                    continue;
                }
                fseek(f, 0, SEEK_SET);
                while ((check = fscanf(f, "%d", &data)) == 1)
                    printf("%d\n", data);
                if (!check)
                {
                    printf("Error input");
                    return ERR_DATA;
                }
                fclose(f);
                continue;
            case 12:
                if (!tb1 || !tb2 || !tb3 || !tb4)
                {
                    printf("To show effectiveness push 7, 8, 9, 10");
                    continue;
                }
                printf("\nBST\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d\n\n", \
                       te1 - tb1, c_bst * 20, comp_bst);
                printf("AVL\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d\n\n", \
                       te2 - tb2, c_avl * 24, comp_avl);
                printf("HT\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d\n\n", \
                       (te3 - tb3) / 2, SZ_HT * 8, comp_ht);
                printf("File\nTime: %llu\n"
                       "Memory: %d b\nCount of compares: %d", \
                       te4 - tb4, SZ_HT * 4, i);
                continue;
            case 0:
                free_bst(ptr);
                free_avl(ptr_avl);
                return OK;
            default:
                printf("Error input");
                continue;
        }
    }

    /*ptr = insert_bts(ptr, 10);
    ptr = insert_bts(ptr, 10);
    ptr = insert_bts(ptr, 10);
    ptr = insert_bts(ptr, 100);
    ptr = insert_bts(ptr, 100);
    ptr = insert_bts(ptr, 100);*/

    /*ptr = insert_bts(ptr, 20);
    ptr = insert_bts(ptr, 5);
    ptr = insert_bts(ptr, 1);
    ptr = insert_bts(ptr, 15);
    ptr = insert_bts(ptr, 9);
    ptr = insert_bts(ptr, 7);
    ptr = insert_bts(ptr, 12);
    ptr = insert_bts(ptr, 30);
    ptr = insert_bts(ptr, 25);
    ptr = insert_bts(ptr, 40);
    ptr = insert_bts(ptr, 45);
    ptr = insert_bts(ptr, 42);*/
    /*20
    5
    1
    15
    9
    7
    12
    30
    25
    40
    45
    42*/
    /*root = new_node(20);
        insert(root,5);
        insert(root,1);
        insert(root,15);
        insert(root,9);
        insert(root,7);
        insert(root,12);
        insert(root,30);
        insert(root,25);
        insert(root,40);
        insert(root, 45);
        insert(root, 42);*/

    // ptr = search_bts(ptr, 10);

    // ptr = remove_bts(ptr, 100);
    // show_tree(ptr, 0);

    return OK;
}

#endif // MAIN_C

