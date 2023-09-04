#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "../include/tests.h"

#include "../include/colors.h"
#include "../include/solve.h"

/**
 * @file tests.cpp
 * @author Gris-a
 * @brief Functions for testing.
*/

bool run_test(const struct Test_input *const test, const size_t *const counter)
{
    assert(test != NULL);
    assert(counter != NULL);

    struct Roots rts = {0, 0, ZERO_ROOTS};

	solve_equation(&test->coef_exp, &rts);

    if((rts.n_roots == test->rts_exp.n_roots && ((float_cmp(rts.x1, test->rts_exp.x1) && float_cmp(rts.x2, test->rts_exp.x2)) ||
                                                 (float_cmp(rts.x1, test->rts_exp.x2) && float_cmp(rts.x2, test->rts_exp.x1)))))
    {
        return 1;
    }

    printf(color_red  ("FAILED TEST №%zu\n"), *counter);
    printf(color_green("EXPECTED: x1= %.*lg, x2= %.*lg, n_roots=%3d\n"), DIGITS, test->rts_exp.x1,
                                                                         DIGITS, test->rts_exp.x2,
                                                                         test->rts_exp.n_roots);
    printf(color_red  ("RECEIVED: x1= %.*lg, x2= %.*lg, n_roots=%3d\n"), DIGITS, rts.x1,
                                                                         DIGITS, rts.x2,
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
    struct Test_input test_in = {{0, 0, 0},
                                 {0, 0, ZERO_ROOTS}};

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
