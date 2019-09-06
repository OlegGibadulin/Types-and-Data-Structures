#ifndef MAIN_C
#define MAIN_C

#include "main.h"

int main()
{
    int num;

    array type1;
    type b1;
    array type2;
    type b2;

    list type11;
    type b11;
    list type12;
    type b12;

    void **arr = NULL;

    int min1 = 1, max1 = 5;
    int min2 = 0, max2 = 3;
    int min3 = 0, max3 = 4;
    int min4 = 0, max4 = 1;

    float t1, t2;
    float time_stay = 0;
    float time_move = 0;
    float count = 0;
    float tmp = 0;
    float oe = 0;
    float include_t1, include_t2;
    int check;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int tmpt = 0;
    int tmpi = 0;
    int isfull = 0;
    int c_count = 0;
    unsigned long long tb1, te1, tb2, te2;
    void *ptr = NULL;

    printf("The 2 queues and 1 OA");

    for (; ;)
    {
        printf("\n\nT1 %d..%d T2 %d..%d T3 %d..%d T4 %d..%d", min1, max1, \
              min2, max2, min3, max3, min4, max4);
        printf("\n\nMenu:\n\n"
               "1 - Calculate\n"
               "2 - Change borders\n"
               "0 - Exit\n\n");

        f_in_int("Input number: ", &num, SZ);

        switch (num)
        {
            case 1:
                printf("\nArray\n\n");

                t1 = 0, t2 = 0;
                time_stay = 0;
                time_move = 0;
                oe = 0;
                count1 = 0;
                count2 = 0;
                count3 = 0;
                count4 = 0;
                count = 0;
                tmp = 0;
                tmpi = 0;
                isfull = 0;

                int check11;

                if ((check11 = f_allocation(&arr, SZ_ARR, 1)))
                {
                    if (check11 == ERR_MEMORY)
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

                tb1 = tick();
                init_array(&type1);
                init_array(&type2);

                srand(time(NULL));
                t1 = (float) rand() / RAND_MAX * (max1 - min1) + min1;
                srand(time(NULL));
                t2 = (float) rand() / RAND_MAX * (max2 - min2) + min2;

                count += t1;

                for (int i = 0; i < 1000;)
                {
                    if (i % 100 == 0 && tmpi != i)
                    {
                        tmpi = i;
                        printf("\n%d ELEMENTS\n\n", i);
                        printf("Count of including applications T1: %d\n", count1);
                        printf("Count of including applications T2: %d\n", count2);
                        printf("Count of released applications T1: %d\n", count3);
                        printf("Count of released applications T2: %d\n", count4);
                        printf("Lenth T1: %d\n", type1.len);
                        printf("Lenth T2: %d\n\n", type2.len);
                    }
                    if (isempty_array(&type1) && isempty_array(&type2))
                    {
                        if (t1 > t2)
                        {
                            time_move += t2;
                            time_stay += t2;
                            t1 -= t2;
                            put_array(&type2, t2);
                            count2++;
                            srand(time(NULL) + tmpt++);
                            t2 = (float) rand() / RAND_MAX * (max2 - min2) + min2;
                            tmp += t2;
                            check = 2;
                        }
                        else
                        {
                            time_move += t1;
                            time_stay += t1;
                            t2 -= t1;
                            put_array(&type1, t1);
                            count1++;
                            srand(time(NULL) + tmpt++);
                            t1 = (float) rand() / RAND_MAX * (max1 - min1) + min1;
                            count += t1;
                            check = 1;
                        }
                    }

                    if (check == 1)
                    {
                        srand(time(NULL) + tmpt++);
                        oe = (float) rand() / RAND_MAX * (max3 - min3) + min3;
                        time_move += oe;
                        get_array(&type1, &b1);
                        count3++;
                        i++;
                    }
                    else
                    {
                        srand(time(NULL) + tmpt++);
                        oe = (float) rand() / RAND_MAX * (max4 - min4) + min4;
                        time_move += oe;
                        get_array(&type2, &b2);
                        count4++;
                    }

                    while (oe)
                    {
                        t1 -= oe;
                        t2 -= oe;
                        oe = 0;

                        if (t1 < 0)
                        {
                            oe = t1 * -1;
                            t2 += oe;
                            t1 = 0;
                            put_array(&type1, t1);
                            count1++;
                            srand(time(NULL) + tmpt++);
                            t1 = (float) rand() / RAND_MAX * (max1 - min1) + min1;
                            count += t1;
                        }

                        if (t2 < 0)
                        {
                            oe = t2 * -1;
                            t1 += oe;
                            t2 = 0;
                            put_array(&type2, t2);
                            count2++;
                            srand(time(NULL) + tmpt++);
                            t2 = (float) rand() / RAND_MAX * (max2 - min2) + min2;
                            tmp += t2;
                        }
                    }

                    if (isempty_array(&type1))
                    {
                        if (isempty_array(&type2))
                        {
                            if (t1 > t2)
                            {
                                check = 2;
                            }
                            else
                            {
                                check = 1;
                            }
                        }
                        else
                            check = 2;
                    }
                    else
                    {
                        if (isempty_array(&type2))
                            check = 1;
                    }
                    if (count1 - count3 > 10000)
                    {
                        printf("The queue T1 is full");
                        isfull = 1;
                        break;
                    }
                    if (count2 - count4 > 10000)
                    {
                        printf("The queue T2 is full");
                        isfull = 1;
                        break;
                    }
                }
                te1 = tick();

                if (isfull)
                    continue;

                printf("Simulation time: %.2f\n", time_move);
                printf("Downtime: %.2f\n", time_stay);
                printf("Count of including applications T1: %d\n", count1);
                printf("Count of including applications T2: %d\n", count2);
                printf("Count of released applications T1: %d\n", count3);
                printf("Count of released applications T2: %d\n", count4);
                printf("Amount of work performed of OA: %d\n", \
                       count3 + count4);
                printf("Time of working of OA: %d units of time\n\n", \
                       (count3 + count4) * 1);

                include_t1 = (float) (min1 + max1) / 2;
                include_t2 = (float) (min2 + max2) / 2;

                float res1 = fabs(100 * (time_move - (((include_t1 + \
                include_t2) / 2) * ((count1 + count2) / 2))) / time_move);

                float res2 = fabs(100 * (time_move - (time_stay + count3 + \
                                                      count4)) / time_move);

                printf("System check by inclusion: %.2f%%\n", res1);
                printf("System check by conclusion: %.2f%%\n\n", res2);

                printf("\nList\n\n");

                t1 = 0, t2 = 0;
                time_stay = 0;
                time_move = 0;
                oe = 0;
                count1 = 0;
                count2 = 0;
                count3 = 0;
                count4 = 0;
                count = 0;
                tmp = 0;
                tmpi = 0;
                isfull = 0;
                c_count = 0;

                tb2 = tick();
                init_list(&type11);
                init_list(&type12);

                srand(time(NULL));
                t1 = (float) rand() / RAND_MAX * (max1 - min1) + min1;
                srand(time(NULL));
                t2 = (float) rand() / RAND_MAX * (max2 - min2) + min2;

                count += t1;

                for (int i = 0; i < 1000;)
                {
                    if (i % 100 == 0 && tmpi != i)
                    {
                        tmpi = i;
                        printf("\n%d ELEMENTS\n\n", i);
                        printf("Count of including applications T1: %d\n", count1);
                        printf("Count of including applications T2: %d\n", count2);
                        printf("Count of released applications T1: %d\n", count3);
                        printf("Count of released applications T2: %d\n", count4);
                        printf("Lenth T1: %d\n", count1 - count3);
                        printf("Lenth T2: %d\n\n", count2 - count4);

                        for (int j = 0; j < 10 && arr[j]; j++)
                            printf("%p\n", arr[j]);
                        printf("\n");
                        c_count = 0;
                    }
                    if (isempty_list(&type11) && isempty_list(&type12))
                    {
                        if (t1 > t2)
                        {
                            time_move += t2;
                            time_stay += t2;
                            t1 -= t2;
                            put_list(&type12, t2, &ptr);
                            arr[c_count++] = ptr;
                            count2++;
                            srand(time(NULL) + tmpt++);
                            t2 = (float) rand() / RAND_MAX * (max2 - min2) + min2;
                            tmp += t2;
                            check = 2;
                        }
                        else
                        {
                            time_move += t1;
                            time_stay += t1;
                            t2 -= t1;
                            put_list(&type11, t1, &ptr);
                            arr[c_count++] = ptr;
                            count1++;
                            srand(time(NULL) + tmpt++);
                            t1 = (float) rand() / RAND_MAX * (max1 - min1) + min1;
                            count += t1;
                            check = 1;
                        }
                    }

                    if (check == 1)
                    {
                        srand(time(NULL) + tmpt++);
                        oe = (float) rand() / RAND_MAX * (max3 - min3) + min3;
                        time_move += oe;
                        get_list(&type11, &b11);
                        count3++;
                        i++;
                    }
                    else
                    {
                        srand(time(NULL) + tmpt++);
                        oe = (float) rand() / RAND_MAX * (max4 - min4) + min4;
                        time_move += oe;
                        get_list(&type12, &b12);
                        count4++;
                    }

                    while (oe)
                    {
                        t1 -= oe;
                        t2 -= oe;
                        oe = 0;

                        if (t1 < 0)
                        {
                            oe = t1 * -1;
                            t2 += oe;
                            t1 = 0;
                            put_list(&type11, t1, &ptr);
                            arr[c_count++] = ptr;
                            count1++;
                            srand(time(NULL) + tmpt++);
                            t1 = (float) rand() / RAND_MAX * (max1 - min1) + min1;
                            count += t1;
                        }

                        if (t2 < 0)
                        {
                            oe = t2 * -1;
                            t1 += oe;
                            t2 = 0;
                            put_list(&type12, t2, &ptr);
                            arr[c_count++] = ptr;
                            count2++;
                            srand(time(NULL) + tmpt++);
                            t2 = (float) rand() / RAND_MAX * (max2 - min2) + min2;
                            tmp += t2;
                        }
                    }

                    if (isempty_list(&type11))
                    {
                        if (isempty_list(&type12))
                        {
                            if (t1 > t2)
                            {
                                check = 2;
                            }
                            else
                            {
                                check = 1;
                            }
                        }
                        else
                            check = 2;
                    }
                    else
                    {
                        if (isempty_list(&type12))
                            check = 1;
                    }

                    if (count1 - count3 > 10000)
                    {
                        printf("The queue T1 is full");
                        isfull = 1;
                        break;
                    }
                    if (count2 - count4 > 10000)
                    {
                        printf("The queue T2 is full");
                        isfull = 1;
                        break;
                    }
                }
                te2 = tick();

                if (isfull)
                    continue;

                printf("Simulation time: %.2f\n", time_move);
                printf("Downtime: %.2f\n", time_stay);
                printf("Count of including applications T1: %d\n", count1);
                printf("Count of including applications T2: %d\n", count2);
                printf("Count of released applications T1: %d\n", count3);
                printf("Count of released applications T2: %d\n", count4);
                printf("Amount of work performed of OA: %d\n", \
                       count3 + count4);
                printf("Time of working of OA: %d units of time\n\n", \
                       (count3 + count4) * 1);

                res1 = fabs(100 * (time_move - (((include_t1 + \
                include_t2) / 2) * ((count1 + count2) / 2))) / time_move);

                res2 = fabs(100 * (time_move - (time_stay + count3 + \
                                                      count4)) / time_move);

                printf("System check by inclusion: %.2f%%\n", res1);
                printf("System check by conclusion: %.2f%%\n\n", res2);

                array test1;
                type test11;

                list test2;
                type test22;

                tb1 = tick();
                init_array(&test1);
                for (int i = 0; i < 1000; i++)
                {
                    put_array(&test1, 10);
                    get_array(&test1, &test11);
                }
                te1 = tick();
                tb2 = tick();
                init_list(&test2);
                for (int i = 0; i < 1000; i++)
                {
                    put_list(&test2, 10, &ptr);
                    get_list(&test2, &test22);
                }
                te2 = tick();

                printf("Array %llu\n", (te1 - tb1));
                printf("List   %llu", (te2 - tb2));
                continue;
            case 2:
                f_in_int("Input MIN time of inclusion T1: ", &min1, SZ);
                f_in_int("Input MAX time of inclusion T1: ", &max1, SZ);
                f_in_int("Input MIN time of inclusion T2: ", &min2, SZ);
                f_in_int("Input MAX time of inclusion T2: ", &max2, SZ);
                f_in_int("Input MIN time of processing T1: ", &min3, SZ);
                f_in_int("Input MAX time of processing T1: ", &max3, SZ);
                f_in_int("Input MIN time of processing T2: ", &min4, SZ);
                f_in_int("Input MAX time of processing T2: ", &max4, SZ);
                continue;
            case 0:
                return OK;
            default:
                printf("Error input");
                continue;
        }
    }
}

#endif // MAIN_C

