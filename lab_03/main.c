#ifndef MAIN_C
#define MAIN_C

#include "main.h"

struct table_classic tc = { NULL, 0};
struct spare_matrix sm = { 0, 0, NULL, NULL, NULL };
struct table_classic tc_ = { NULL, 0};
struct spare_matrix sm_ = { 0, 0, NULL, NULL, NULL };
struct table_classic res = { NULL, 0};
struct spare_matrix res_ = { 0, 0, NULL, NULL, NULL };
struct spare_matrix smt = { 0, 0, NULL, NULL, NULL };
struct table_classic tc1 = { NULL, 0};
struct spare_matrix sm1 = { 0, 0, NULL, NULL, NULL };
struct table_classic tc1_ = { NULL, 0};
struct spare_matrix sm1_ = { 0, 0, NULL, NULL, NULL };

int main()
{
    int num, per;
    unsigned long long tb1 = 0, te1 = 0;
    unsigned long long tb2 = 0, te2 = 0;
    int h = 0, w = 0;
    int t1, t2;
    int b1, b2;

    printf("Matrix-vector multiplication");

    for (;;)
    {
        printf("\n\nMenu:\n\n"
               "1 - Add matrix and vector\n"
               "2 - Generate matrix and vector\n"
               "3 - Show matrix and vector\n"
               "4 - Multiplication\n"
               "5 - Effectiveness\n"
               "0 - Exit\n\n");

        f_in_int("Input number: ", &num, SZ);

        switch (num)
        {
        case 1 :
            f_clear_cm(&tc);
            f_clean_sm(&sm);
            f_clear_cm(&tc_);
            f_clean_sm(&sm_);
            f_clean_sm(&res_);

            if (f_add(&tc, &sm))
                continue;

            if (f_add(&tc_, &sm_))
                continue;

            printf("The data is added successfully");

            continue;
        case 2 :
            f_clear_cm(&tc);
            f_clean_sm(&sm);
            f_clear_cm(&tc_);
            f_clean_sm(&sm_);
            f_clean_sm(&res_);

            f_in_int("Input persent of fullness of matrix: ", &per, SZ);

            if (per < 0 || per > 100)
            {
                printf("Error input");
                continue;
            }

            h = 0;
            w = 0;

            if (f_generate(&tc, &sm, per, h, w))
                continue;

            f_in_int("Input persent of fullness of vector: ", &per, SZ);

            if (per < 0 || per > 100)
            {
                printf("Error input");
                continue;
            }

            if (f_generate(&tc_, &sm_, per, h, w))
                continue;

            printf("\nThe data is generated successfully");

            continue;
        case 3 :
            if (sm.n == 0 || sm_.n == 0)
            {
                printf("There are not any data");
                continue;
            }

            if (sm.n > 10 || sm_.n > 10)
            {
                printf("There is must be lenghth less then 10 for viewing");
                continue;
            }

            f_show(&tc, &tc_);

            f_show_spare(sm, sm_);

            continue;
        case 4 :
            if (sm.n == 0 || sm_.n == 0)
            {
                printf("There are not any data");
                continue;
            }

            if (sm.n != sm_.n)
            {
                printf("The sizes of columns of vector and rows of matrix "
                    "must be same for multiplication");
                continue;
            }

            printf("\nClassic methood of multiplication...\n\n");

            tb1 = tick();
            f_multiplication_classic(&tc, &tc_, 1);
            te1 = tick();

            printf("\n\nSpare methood of multiplication...\n\n");

            tb2 = tick();
            f_multiplication_spare(&sm, &sm_, &res_, 1);
            te2 = tick();

            printf("\n\nThe matrix and vector are multiplicated succesfully\n\n");

            t1 = (int) (te1 - tb1);
            t2 = (int) (te2 - tb2);

            printf("The classic methood: %d\n", t1);
            printf("The spare methood: %d | Ratio : %.2f\n\n", t2, \
                   (float) ((float) t2 / (float) t1));

            b1 = (sizeof(struct classic_matrix) * tc.n) + 12;
            b2 = ((4 + 4) * sm.nz + 4 * (sm.n + 1) + 8);
            printf("Size of classic matrix: %d "
                   "b\n\n", b1);
            printf("Size of spare matrix: %d b | Ratio : %.2f"
                   "\n\n", b2, (float) ((float) b2 / (float) b1));

            continue;
        case 5 :
            f_in_int("\nInput persent of fullnes: ", &per, SZ);

            if (per < 0 || per > 100)
            {
                printf("Error input");
                continue;
            }

            printf("\nFor matrix 100x100\n");

            h = 100;
            w = 100;
            printf("\nPersent of fullnes: %d\n", per);
            if (f_generate(&tc1, &sm1, per, h, w))
                continue;

            h = 1;
            w = 100;
            if (f_generate(&tc1_, &sm1_, per, h, w))
                continue;

            printf("\nClassic methood of multiplication...\n\n");

            tb1 = tick();
            f_multiplication_classic(&tc1, &tc1_, 0);
            f_multiplication_classic(&tc1, &tc1_, 0);
            f_multiplication_classic(&tc1, &tc1_, 0);
            f_multiplication_classic(&tc1, &tc1_, 0);
            f_multiplication_classic(&tc1, &tc1_, 0);
            te1 = tick();

            printf("\n\nSpare methood of multiplication...\n\n");

            int t11 = 0;

            tb2 = tick();
            f_multiplication_spare(&sm1, &sm1_, &res_, 0);
            te2 = tick();

            f_clear_cm(&tc1);
            f_clear_cm(&tc1_);

            t11 += (int) (te2 - tb2);

            if (f_generate(&tc1_, &sm1_, per, h, w))
                continue;

            tb2 = tick();
            f_multiplication_spare(&sm1, &sm1_, &res_, 0);
            te2 = tick();

            f_clear_cm(&tc1);
            f_clear_cm(&tc1_);

            t11 += (int) (te2 - tb2);

            if (f_generate(&tc1_, &sm1_, per, h, w))
                continue;

            tb2 = tick();
            f_multiplication_spare(&sm1, &sm1_, &res_, 0);
            te2 = tick();

            f_clear_cm(&tc1);
            f_clear_cm(&tc1_);

            t11 += (int) (te2 - tb2);

            if (f_generate(&tc1_, &sm1_, per, h, w))
                continue;

            tb2 = tick();
            f_multiplication_spare(&sm1, &sm1_, &res_, 0);
            te2 = tick();

            f_clear_cm(&tc1);
            f_clear_cm(&tc1_);

            t11 += (int) (te2 - tb2);

            if (f_generate(&tc1_, &sm1_, per, h, w))
                continue;

            tb2 = tick();
            f_multiplication_spare(&sm1, &sm1_, &res_, 0);
            te2 = tick();

            f_clear_cm(&tc1);
            f_clear_cm(&tc1_);

            t11 += (int) (te2 - tb2);

            printf("\n\nThe matrix and vector are multiplicated succesfully\n\n");

            t1 = (int) (te1 - tb1) / 5;
            t2 = t11 / 5;

            float ratio = (float) per / 100;
            int sz = w * h;
            int c_per = (int) (sz * ratio);

            printf("The classic methood: %d\n", t1);
            printf("The spare methood: %d | Ratio : %.2f\n\n", t2, \
                   (float) ((float) t2 / (float) t1));

            b1 = (sizeof(struct classic_matrix) * 100) + 12;
            b2 = ((4 + 4) * c_per + 4 * (sm.n + 100 + 1) + 8);
            printf("Size of classic matrix: %d "
                   "b\n\n", b1);
            printf("Size of spare matrix: %d b | Ratio : %.2f"
                   "\n\n", b2, (float) ((float) b2 / (float) b1));

            f_clear_cm(&tc1);
            f_clean_sm(&sm1);
            f_clear_cm(&tc1_);
            f_clean_sm(&sm1_);
            f_clean_sm(&smt);
            f_clean_sm(&res_);

            /*for (int per = 0; per <= 100; per += 2)
            {
                f_clear_cm(&tc1);
                f_clean_sm(&sm1);
                f_clear_cm(&tc1_);
                f_clean_sm(&sm1_);
                f_clean_sm(&smt);
                f_clean_sm(&res_);

                h = 100;
                w = 100;
                printf("\nPersent of fullnes: %d\n", per);
                if (f_generate(&tc1, &sm1, per, h, w))
                    continue;
                h = 1;
                w = 100;
                if (f_generate(&tc1_, &sm1_, per, h, w))
                    continue;

                tb1 = tick();
                if (f_multimplication_classic1(&tc1, &tc1_, sm1.n, 0))
                    continue;
                te1 = tick();

                tb2 = tick();
                if (f_convert(&smt, &sm1, 1))
                    continue;

                if (f_multimplication_spare(&smt, &sm1_, &res_, 0))
                    continue;
                te2 = tick();

                printf("The classic methood: %d\n", (int) (te1 - tb1));
                printf("The spare methood: %d | Ratio : %.2f\n\n", (int) \
                       ((te2 - tb2)), (float) ((float) (te1 - tb1) / (float) \
                                             (te2 - tb2)));

                int b1, b2;
                b1 = (sizeof(struct classic_matrix) * tc1.n) + 8;
                b2 = ((4 + 4) * sm1.nz + 4 * (sm1.n + 1) + 8);
                printf("Size of classic matrix: %d "
                       "b\n\n", b1);
                printf("Size of spare matrix: %d b | Ratio : %.2f"
                       "\n\n", b2, (float) ((float) b2 / (float) b1));

                f_clear_cm(&tc1);
                f_clean_sm(&sm1);
                f_clear_cm(&tc1_);
                f_clean_sm(&sm1_);
                f_clean_sm(&smt);
                f_clean_sm(&res_);
            }

            printf("For matrix 100x100");*/

            continue;
        case 0 :
            f_clear_cm(&tc);
            f_clean_sm(&sm);
            f_clear_cm(&tc_);
            f_clean_sm(&sm_);
            f_clean_sm(&res_);
            return OK;
        default :
            printf("Error input\n");
            continue;
        }
    }
}

#endif // MAIN_C

