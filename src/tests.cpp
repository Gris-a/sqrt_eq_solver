#include <stdio.h>
#include "./include/main.h"
#include "./include/solve.h"
#include "./include/tests.h"

/**
 * @file tests.cpp
 * @author Gris-a
 * @brief Functions for testing.
*/

unsigned int run_test(const struct test_input *const test, const size_t *const counter)
{
    struct roots rts = {0.0, 0.0};
	int nRoots = solve_equation(&test->coef_exp, &rts);

    if((nRoots == test->nRoots_exp && ((float_cmp(rts.x1, test->rts_exp.x1, M_ERR) && float_cmp(rts.x2, test->rts_exp.x2, M_ERR)) ||
                                       (float_cmp(rts.x1, test->rts_exp.x2, M_ERR) && float_cmp(rts.x2, test->rts_exp.x1, M_ERR)))))
    {
        return 1;
    }
    else
    {
        printf(color_red  ("FAILED TEST №%zu\n"), *counter);
        printf(color_green("EXPECTED: x1= %10lg, x2= %10lg, nRoots=%3d\n"), test->rts_exp.x1, test->rts_exp.x2, test->nRoots_exp);
        printf(color_red  ("RECEIVED: x1= %10lg, x2= %10lg, nRoots=%3d\n"), rts.x1, rts.x2, nRoots);

        return 0;
    }
}

void run_all_tests(FILE *test_file)
{
    size_t counter = 0;
	size_t counter_true = 0;
    struct test_input test_in;

    while(fscanf(test_file, "%lf, %lf, %lf, %lf, %lf, %d",&test_in.coef_exp.a, &test_in.coef_exp.b, &test_in.coef_exp.c,
                                                          &test_in.rts_exp.x1, &test_in.rts_exp.x2, &test_in.nRoots_exp) == 6)
    {
        counter++;
        counter_true += run_test(&test_in, &counter);
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
