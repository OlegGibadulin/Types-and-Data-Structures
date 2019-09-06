#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define OK 0
#define ERR_IN 1
#define EMPTY_IN 2
#define ERR_EXIST_OF_FILE 3
#define ERR_TABLE 4
#define ERR_MEMORY 5
#define OPEN 0
#define CLOSE 1
#define SZ 31

struct data
{
    char type[10];
    char name[SZ];
    char gender[5];
    int age;
    float mark;
    int year;

    union
    {
        struct
        {
            char address[SZ];
            int num_house;
            int num_flat;
        } house;

        struct
        {
            int num_hostel;
            int num_room;
        } hostel;
    } condition;
};

struct data_table
{
    struct data *p;
    int sz;
    int n;
};

struct key
{
    int id;
    float value;
};

struct key_table
{
    struct key *p;
    int n;
};

void f_in_str(char *msg, char *str, int n);
void f_in_int(char *msg, int *num, int n);
void f_in_float(char *msg, float *num, int n);

int f_load_table(char *str, struct data_table *d_t);
int f_save_table(char *str, struct data_table *d_t);
int f_show_table(struct data_table *d_t);
int f_add(struct data *table);
void f_remove(struct data_table *p, int num);
int f_create_key_table(struct key_table *p, struct data_table *p_d);
int f_show_key_table(struct key_table *p);
void f_search(struct data_table *p, int num);

void f_clear(struct data_table *d_t);
int f_add_to_table(struct data_table *d_t, struct data *d);
void f_show_data(struct data *p);
int f_check(char *str);
void f_clear_key_table(struct key_table *t_k);
void f_sort_insert_key(struct key_table *t_k);
void f_sort_table(struct data_table *t_k);
void f_show_sorted_key_table(struct data_table *d, struct key_table *k);
void f_sort_bubble_key(struct key_table *t_k);
void f_sort_table_bubble(struct data_table *t_k);
unsigned long long tick(void);
