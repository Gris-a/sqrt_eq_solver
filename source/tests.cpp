#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "../include/tests.h"

#include "../include/colors.h"
#include "../include/solve.h"

/**
 * @file tests.cpp
 * @author Gris-a
 * @brief Functions for testing.
*/

unsigned int run_test(const struct test_input *const test, const size_t *const counter)
{
    assert(!isnan(*counter));
    assert(test != NULL);
    assert(counter != NULL);

    struct roots rts = {0.0, 0.0, ZERO_ROOTS};
	solve_equation(&test->coef_exp, &rts);

    if((rts.n_roots == test->rts_exp.n_roots && ((float_cmp(rts.x1, test->rts_exp.x1, m_err) && float_cmp(rts.x2, test->rts_exp.x2, m_err)) ||
                                                 (float_cmp(rts.x1, test->rts_exp.x2, m_err) && float_cmp(rts.x2, test->rts_exp.x1, m_err)))))
    {
        return 1;
    }

    printf(color_red  ("FAILED TEST №%zu\n"), *counter);
    printf(color_green("EXPECTED: x1= %.*lg, x2= %.*lg, n_roots=%3d\n"), digits, test->rts_exp.x1,
                                                                         digits, test->rts_exp.x2,
                                                                         test->rts_exp.n_roots);
    printf(color_red  ("RECEIVED: x1= %.*lg, x2= %.*lg, n_roots=%3d\n"), digits, rts.x1,
                                                                         digits, rts.x2,
                                                                         rts.n_roots);

    return 0;
}

void run_all_tests(const char *const file_name)
{
    FILE *test_file = fopen(file_name, "r");
    if(test_file == NULL)
    {
        printf(color_red("File not found.\n"));
        return;
    }
    size_t counter = 0;
	size_t counter_true = 0;
    struct test_input test_in;
    while(fscanf(test_file, "%lf, %lf, %lf, %lf, %lf, %d",&test_in.coef_exp.a, &test_in.coef_exp.b, &test_in.coef_exp.c,
                                                          &test_in.rts_exp.x1, &test_in.rts_exp.x2, (int *)&test_in.rts_exp.n_roots) == 6)
    {
        counter++;
        counter_true += run_test(&test_in, &counter);
    }

    fclose(test_file);

    printf_tests_results(counter, counter_true);
}

void printf_tests_results(const size_t counter, const size_t counter_true)
{
    assert(!isnan(counter));
    assert(!isnan(counter_true));

    if(counter == counter_true)
    {
	    printf(color_green ("%zu/%zu tests passed\n"), counter_true, counter);
    }
    else if(counter == 0)
    {
        printf(color_red   ("%zu/%zu tests passed\n"), counter_true, counter);
    }
    else
    {
        printf(color_yellow("%zu/%zu tests passed\n"), counter_true, counter);
    }
}
