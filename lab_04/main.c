#ifndef MAIN_C
#define MAIN_C

#include "main.h"

int main()
{
    int num, check;
    node_t *head = { NULL };
    void **ptr = NULL;
    int count = 0;
    node_t *arr = { NULL };
    // node_t *arr_elem = { NULL };
    int tb1, te1;
    void *ptr_elem = NULL;
    int check_ptr;

    if ((check = f_allocation(&ptr, SZ, 1)))
    {
        if (check == ERR_MEMORY)
        {
            printf("Memory can not be allocated");
            return ERR_MEMORY;
        }
        else
        {
            printf("There is error with input data for allocation");
            return ERR_POINTER;
        }
    }

    printf("Adresses");

    for (; ;)
    {
        printf("\n\nMenu:\n\n"
               "Array:\n\n"
               "1 - Add\n"
               "2 - Pop\n"
               "3 - Show\n\n"
               "List:\n\n"
               "4 - Add\n"
               "5 - Pop\n"
               "6 - Show\n\n"
               "7 - Show free pointers\n"
               "8 - Show effectiveness\n"
               "0 - Exit\n\n");

        f_in_int("Input number: ", &num, SZ);

        switch (num)
        {
            case 1:
                printf("Input pointer: ");
                check_ptr = scanf("%p", &ptr_elem);
                if (check_ptr != 1)
                {
                    printf("Error input");
                    continue;
                }
                tb1 = tick();
                add_array(ptr, &count, ptr_elem);
                te1 = tick();
                printf("\nTime add array: %d", (int) (te1 - tb1));
                continue;
            case 2:
                tb1 = tick();
                pop_array(ptr, &count);
                te1 = tick();
                printf("\nTime pop array: %d", (int) (te1 - tb1));
                continue;
            case 3:
                tb1 = tick();
                show_array(ptr, count);
                te1 = tick();
                printf("\nTime show array: %d", (int) (te1 - tb1));
                continue;
            case 4:
                tb1 = tick();
                add_list(&head);
                te1 = tick();
                printf("\nTime add list: %d", (int) (te1 - tb1));
                continue;
            case 5:
                tb1 = tick();
                pop_list(&head, &arr);
                te1 = tick();
                printf("\nTime pop list: %d", (int) (te1 - tb1));
                continue;
            case 6:
                tb1 = tick();
                show_list(head);
                te1 = tick();
                printf("\nTime show list: %d", (int) (te1 - tb1));
                continue;
            case 7:
                f_show_free_pointers(arr);
                continue;
            case 8:;
                int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
                node_t *head1 = { NULL };
                void **ptr1 = NULL;
                int count1 = 0;
                node_t *arr1 = { NULL };
                node_t *arr_elem1 = { NULL };
                int tb1, te1;
                void *ptr_elem1 = NULL;
                f_in_int("Input number of actions: ", &num, SZ);

                if ((check = f_allocation(&ptr1, SZ, 1)))
                {
                    if (check == ERR_MEMORY)
                    {
                        printf("Memory can not be allocated");
                        return ERR_MEMORY;
                    }
                    else
                    {
                        printf("There is error with input data for allocation");
                        return ERR_POINTER;
                    }
                }

                for (int i = 0; i < num; i++)
                {
                    ptr_elem1 = i + 1;
                    tb1 = tick();
                    add_array(ptr1, &count1, ptr_elem1);
                    te1 = tick();
                    t1 += (int) (te1 - tb1);
                }

                tb1 = tick();
                show_array(ptr1, count1);
                te1 = tick();
                t3 += (int) (te1 - tb1);

                for (int i = 0; i < num; i++)
                {
                    tb1 = tick();
                    pop_array(ptr1, &count1);
                    te1 = tick();
                    t2 += (int) (te1 - tb1);
                }

                for (int i = 0; i < num; i++)
                {
                    tb1 = tick();
                    add_list(&head1);
                    te1 = tick();
                    t4 += (int) (te1 - tb1);
                }

                tb1 = tick();
                show_list(head1);
                te1 = tick();
                t6 += (int) (te1 - tb1);

                for (int i = 0; i < num; i++)
                {
                    tb1 = tick();
                    pop_list(&head1, &arr1);
                    te1 = tick();
                    t5 += (int) (te1 - tb1);
                }

                printf("\nTime\n"
                       "Array: add / pop %d %d\n"
                       "List: add / pop %d %d\n"
                       "\nByte\n"
                       "Array: %d\n"
                       "List: %d", t1, t2, t4, t5, SZ, num * \
                       (int) sizeof(node_t));
                continue;
            case 0:
                while (arr)
                {
                    node_t *ptr = arr;
                    arr = arr->next;
                    free(ptr->ptr);
                }
                return OK;
            default:
                printf("Error input");
                continue;
        }
    }
}

#endif // MAIN_C

