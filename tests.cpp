#include <stdio.h>
#include "main.h"
#include "solve.h"
#include "tests.h"

/**
 * @file tests.cpp
 * @author Gris-a
 * @brief Functions for testing.
*/

void run_test(const struct test_input *const test)
{
    struct roots rts = {0.0, 0.0};
	int nRoots = solve_equation(&test->coef_exp, &rts);
	(*test->counter)++;
    if((nRoots == test->nRoots_exp && ((float_cmp(rts.x1, test->rts_exp.x1, M_ERR) && float_cmp(rts.x2, test->rts_exp.x2, M_ERR)) ||
                           (float_cmp(rts.x1, test->rts_exp.x2, M_ERR) && float_cmp(rts.x2, test->rts_exp.x1, M_ERR)))))
    {
        (*test->counter_true)++;
    }
    else
    {
        printf("\033[1;31mFAILED TEST №%zu\033[1;0m.\n"
               "\033[1;32mEXPECTED: x1= %10lg, x2= %10lg, nRoots=%3d\033[1;0m.\n"
               "\033[1;31mRECEIVED: x1= %10lg, x2= %10lg, nRoots=%3d\033[1;0m.\n",
               *test->counter, test->rts_exp.x1, test->rts_exp.x2, test->nRoots_exp, rts.x1, rts.x2, nRoots);
    }
}

void run_all_tests(void)
{
    size_t counter = 0;
	size_t counter_true = 0;
    struct test_input test_arr[] = {
                            {{0,  0,  0},  {   0,    0},     INF_ROOTS, &counter, &counter_true},
                            {{0,  0,  5},  {   0,    0},    ZERO_ROOTS, &counter, &counter_true},
                            {{0,  5,  0},  {   0,    0},      ONE_ROOT, &counter, &counter_true},
                            {{0,  2,  5},  {-2.5, -2.5},      ONE_ROOT, &counter, &counter_true},
                            {{1,  0,  5},  {   0,    0},    ZERO_ROOTS, &counter, &counter_true},
                            {{1,  1,  0},  {  -1,    0},     TWO_ROOTS, &counter, &counter_true},
                            {{1, -4,  4},  {   2,    2},      ONE_ROOT, &counter, &counter_true},
                            {{1, -5,  6},  {   2,    3},     TWO_ROOTS, &counter, &counter_true},
                            {{1,  1,  1},  {   0,    0},    ZERO_ROOTS, &counter, &counter_true},
                            {{1,  0,  0},  {   0,    0},      ONE_ROOT, &counter, &counter_true},
                            {{1,  0, -1},  {  -1,    1},     TWO_ROOTS, &counter, &counter_true},
                            {{1,  0, -1},  {  -1,    1},     TWO_ROOTS, &counter, &counter_true},
                            {{1,  0, -1},  {   0,    1},     TWO_ROOTS, &counter, &counter_true} //Expectedly fails
                            };
    for(size_t i = 0; i < sizeof(test_arr)/sizeof(test_input); i++)
    {
        run_test(&test_arr[i]);
    }
    if(counter == counter_true)
    {
	    printf("\033[1;32m%zu/%zu tests passed\033[1;0m\n", counter_true, counter);
    }
    else if(counter == 0)
    {
        printf("\033[1;31m%zu/%zu tests passed\033[1;0m\n", counter_true, counter);
    }
    else
    {
        printf("\033[1;33m%zu/%zu tests passed\033[1;0m\n", counter_true, counter);
    }

}
