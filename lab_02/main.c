#include "main.h"

struct data_table d_t = { NULL, 0, 0 };
struct key_table t_k = { NULL, 0 };

int main()
{
    int num;
    char str[SZ];
    int check = 0;

    struct data d_a;

    printf("The table of student\n"
           "Living place, name, gender, age, avarage mark,\n"
           "year of addmision and information about living place\n"
           "All numbers have a maixmum 8 digits\n");

    for (;;)
    {
        printf("\n\nMenu:\n\n"
               "1 - Load table\n"
               "2 - Save table\n"
               "3 - Show table\n"
               "4 - Add to table\n"
               "5 - Remove from table\n"
               "6 - Create key table\n"
               "7 - Show key table\n"
               "8 - Sort key table\n"
               "9 - Sort table\n"
               "10 - Show sorted table by key table\n"
               "11 - Searh in table\n"
               "12 - Show programme effectiveness\n"
               "0 - Exit\n\n");

        f_in_int("Input number: ", &num, SZ);

        switch (num)
        {
        case 1 :
            f_in_str("Input tne name of the file: "
                     "\n|______________________________| 30 symbols\n|", \
                     str, SZ);

            if (f_load_table(str, &d_t))
                continue;

            printf("The table is loaded successfully");

            break;
        case 2 :
            f_in_str("Input tne name of the file: "
                     "\n|______________________________| 30 symbols\n|", \
                     str, SZ);

            if (f_save_table(str, &d_t))
                continue;

            printf("The table is saved successfully");

            break;
        case 3 :
            if (f_show_table(&d_t))
                continue;

            break;
        case  4:
            if (f_add(&d_a))
                continue;

            if (f_add_to_table(&d_t, &d_a))
                continue;

            printf("The information about student is added successfully");

            break;
        case 5 :
            if (d_t.n == 0)
            {
                printf("The table of data is empty");
                continue;
            }
            printf("From 1 to %d\n", d_t.n);

            f_in_int("Input number of the element: ", &num, SZ);

            if (num < 1 || num > d_t.n)
            {
                printf("The number must be in range from 1 to %d", d_t.n);
                continue;
            }

            f_remove(&d_t, num);

            printf("The element is deleted successfully");

            break;
        case 6 :
            if (d_t.n == 0)
            {
                printf("The table of data is empty");
                continue;
            }

            if(f_create_key_table(&t_k, &d_t))
                continue;

            printf("The table of key is created successfully");

            break;
        case 7 :
            if (t_k.n == 0)
            {
                printf("Error key table");
                continue;
            }

            if (f_show_key_table(&t_k))
                continue;

            break;
        case 8 :
            if (t_k.n == 0)
            {
                printf("Error key table");
                continue;
            }

            f_sort_insert_key(&t_k);

            printf("The key table is sorted successfully");

            break;
        case 9 :
            if (d_t.n == 0)
            {
                printf("The table of data is empty");
                continue;
            }

            f_sort_table(&d_t);

            check = 1;

            printf("The data table is sorted successfully");

            break;
        case 10 :
            if (d_t.n == 0 || t_k.n == 0)
            {
                printf("The table of data or key table are empty");
                continue;
            }

            if (check)
            {
                printf("The data table is already sorted");
                continue;
            }

            f_show_sorted_key_table(&d_t, &t_k);

            break;
        case 11 :
            if (d_t.n == 0)
            {
                printf("The table of data is empty");
                continue;
            }

            f_in_int("Input the year of admission: ", &num, SZ);

            if (num > 2018)
            {
                printf("Error input");
                continue;
            }

            f_search(&d_t, num);

            break;
        case 12 :
            f_in_str("Input tne name of the file: "
                     "\n|______________________________| 30 symbols\n|", \
                     str, SZ);

            struct data_table d_t1 = { NULL, 0, 0 };
            struct data_table d_t2 = { NULL, 0, 0 };
            struct key_table t_k1 = { NULL, 0 };
            struct key_table t_k2 = { NULL, 0 };

            if (f_load_table(str, &d_t1))
                continue;

            if (f_load_table(str, &d_t2))
                continue;

            printf("The table is loaded successfully\n");

            if (d_t1.n == 0)
            {
                printf("The table of data is empty");
                continue;
            }

            if(f_create_key_table(&t_k1, &d_t1))
                continue;

            if(f_create_key_table(&t_k2, &d_t2))
                continue;

            printf("The table of key is created successfully\n");
            printf("The key table is sorted successfully\n");
            printf("The data table is sorted successfully\n\n");
            unsigned long long tb1, te1;
            unsigned long long tb2, te2;

            tb1 = tick();
            f_sort_bubble_key(&t_k2);
            te1 = tick();

            printf("The buble sort (key): %llu\n\n", (te1 - tb1));

            tb2 = tick();
            f_sort_table_bubble(&d_t2);
            te2 = tick();

            printf("The buble sort (data): %llu\n\n", (te2 - tb2));

            float sum1 = (float) (te1 - tb1) + (float) (te2 - tb2);
            float sum3 = (float) (te1 - tb1);
            float sum4 = (float) (te2 - tb2);

            tb1 = tick();
            f_sort_insert_key(&t_k1);
            te1 = tick();

            printf("The insert sort (key): %llu\n\n", (te1 - tb1));

            tb2 = tick();
            f_sort_table(&d_t1);
            te2 = tick();

            printf("The insert sort (data): %llu\n\n", (te2 - tb2));

            float sum2 = (float) (te1 - tb1) + (float) (te2 - tb2);

            printf("The efficiency of the insert sort compared to bubble "
                   "sort: %.2f%%\n\n", (sum2 / sum1 * 100));

            printf("The efficiency of the sorted table with key table "
                   "compared to sorted table without key table "
                   "sort: %.2f%%\n\n", (sum3 / sum4 * 100));

            printf("Size of table of students: %lu "
                   "b\n\n", (sizeof(struct data) * d_t1.n));
            printf("Size of table of keys: %lu "
                   "b\n\n", (sizeof(struct key) * t_k1.n));

            printf("Size of table of students: %lu "
                   "b\n\n", (sizeof(struct data)));
            printf("Size of table of keys: %lu "
                   "b", (sizeof(struct key)));

            break;
        case 0 :
            return OK;
        default :
            printf("Error input\n");
            continue;
        }

        printf("\n");
    }
}
