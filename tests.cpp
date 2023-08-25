#include <stdio.h>
#include "main.h"
#include "solve.h"
#include "tests.h"

/**
 * @file tests.cpp
 * @author Gris-a
 * @brief Functions for testing.
*/

void run_test(const struct test_input *const test, size_t *const counter, size_t *const counter_true)
{
    struct roots rts = {0.0, 0.0};
	int nRoots = solve_equation(&test->coef_exp, &rts);
	(*counter)++;
    if((nRoots == test->nRoots_exp && ((float_cmp(rts.x1, test->rts_exp.x1, M_ERR) && float_cmp(rts.x2, test->rts_exp.x2, M_ERR)) ||
                                       (float_cmp(rts.x1, test->rts_exp.x2, M_ERR) && float_cmp(rts.x2, test->rts_exp.x1, M_ERR)))))
    {
        (*counter_true)++;
    }
    else
    {
        printf(color_red("FAILED TEST №%zu\n"), *counter);
        printf(color_green("EXPECTED: x1= %10lg, x2= %10lg, nRoots=%3d\n"), test->rts_exp.x1, test->rts_exp.x2, test->nRoots_exp);
        printf(color_red("RECEIVED: x1= %10lg, x2= %10lg, nRoots=%3d\n"), rts.x1, rts.x2, nRoots);
    }
}

void run_all_tests(void)
{
    size_t counter = 0;
	size_t counter_true = 0;
    struct test_input test_arr[] = {
                            {{0,  0,  0},  {   0,    0},     INF_ROOTS},
                            {{0,  0,  5},  {   0,    0},    ZERO_ROOTS},
                            {{0,  5,  0},  {   0,    0},      ONE_ROOT},
                            {{0,  2,  5},  {-2.5, -2.5},      ONE_ROOT},
                            {{1,  0,  5},  {   0,    0},    ZERO_ROOTS},
                            {{1,  1,  0},  {  -1,    0},     TWO_ROOTS},
                            {{1, -4,  4},  {   2,    2},      ONE_ROOT},
                            {{1, -5,  6},  {   2,    3},     TWO_ROOTS},
                            {{1,  1,  1},  {   0,    0},    ZERO_ROOTS},
                            {{1,  0,  0},  {   0,    0},      ONE_ROOT},
                            {{1,  0, -1},  {  -1,    1},     TWO_ROOTS},
                            {{1,  0, -1},  {  -1,    1},     TWO_ROOTS},
                            {{1,  0, -1},  {   0,    1},     TWO_ROOTS} //Expectedly fails
                            };
    for(size_t i = 0; i < sizeof(test_arr)/sizeof(test_input); i++)
    {
        run_test(&test_arr[i], &counter, &counter_true);
    }
    printf_tests_results(&counter, &counter_true);
}

void printf_tests_results(const size_t *const counter, const size_t *const counter_true)
{
    if(*counter == *counter_true)
    {
	    printf(color_red("%zu/%zu tests passed\n"), *counter_true, *counter);
    }
    else if(*counter == 0)
    {
        printf(color_red("%zu/%zu tests passed\n"), *counter_true, *counter);
    }
    else
    {
        printf(color_yellow("%zu/%zu tests passed\n"), *counter_true, *counter);
    }
}
