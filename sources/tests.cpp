#include <stdio.h>
#include "./include/main.h"
#include "./include/solve.h"
#include "./include/tests.h"

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
    FILE *test_file = fopen("tests.txt", "r");
    struct test_input testo;
    while(fscanf(test_file, "%lf, %lf, %lf, %lf, %lf, %d",&testo.coef_exp.a, &testo.coef_exp.b, &testo.coef_exp.c,
                                                          &testo.rts_exp.x1, &testo.rts_exp.x2, &testo.nRoots_exp) == 6)
    {
        run_test(&testo, &counter, &counter_true);
    }
    fclose(test_file);
    printf_tests_results(counter, counter_true);
}

void printf_tests_results(const size_t counter, const size_t counter_true)
{
    if(counter == counter_true)
    {
	    printf(color_green("%zu/%zu tests passed\n"), counter_true, counter);
    }
    else if(counter == 0)
    {
        printf(color_red("%zu/%zu tests passed\n"), counter_true, counter);
    }
    else
    {
        printf(color_yellow("%zu/%zu tests passed\n"), counter_true, counter);
    }
}
