#ifndef MAIN_C
#define MAIN_C

#include "main.h"

int main(int argc, char *argv[])
{
    FILE *f = NULL;
    int num, data, path, check, from, max = 0;
    long place;
    graph *head = NULL;
    unsigned long long tb1, te1, tb2, te2;

    printf("Find all the verticies of the graph, which can be reached from "
           "the given vertex on the path no longer than A\n\n");

    if (argc != 3)
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
    place = ftell(f);
    fseek(f, 0, SEEK_END);
    if (place == ftell(f))
    {
        fclose(f);
        printf("File is empty");
        return ERR_EMPTY_FILE;
    }
    fseek(f, 0, SEEK_SET);

    if (!(check = fscanf(f, "%d", &num)) || check == -1)
    {
        fclose(f);
        printf("Error input");
        return ERR_DATA;
    }

    head = init_graph(num);


    while ((check = fscanf(f, "%d", &from)) == 1)
    {
        if (!(check = fscanf(f, "%d", &data)) || check == -1)
        {
            fclose(f);
            printf("Error input");
            return ERR_DATA;
        }
        if (from > max)
            max = from;
        if (data > max)
            max = data;
        insert_graph(head, from, data);
    }
    fclose(f);

    if (!check)
    {
        printf("Error input");
        return ERR_DATA;
    }

    if (max + 1 != num)
    {
        printf("Error count");
        return ERR_COUNT;
    }

    f = fopen(argv[2], "w");

    tb1 = tick();
    show_graph(f, head);
    te1 = tick();
    printf("Time: %llu\nMemory: %d b\n\n", te1 - tb1, num * 20 + 8);

    fclose(f);

    for (; ;)
    {
        check = 0;
        f_in_int("Input number of vertex: ", &data, SZ);

        if (data < 0 || data >= num)
        {
            printf("There are not element %d\n\n", data);
            continue;
        }

        f_in_int("Input number A: ", &path, SZ);


        if (path < 1)
        {
            printf("Error input\n\n");
            continue;
        }

        printf("\nThe verticies of the graph, which can be reached: ");
        tb2 = tick();
        BFS(head, data, path);
        te2 = tick();

        printf("\nTime: %llu\n", te2 - tb2);

        for (; ;)
        {
            f_in_int("\n\n1 - Change vertex and A\n0 - Exit\n\nInput number: ", \
                     &check, SZ);

            if (!check)
                return OK;
            if (check == 1)
            {
                printf("\n");
                break;
            }
            printf("Error input\n");
        }
    }
}

#endif // MAIN_C

