/**
 * @file tests.h
 * @author Gris-a
 * @brief Testing the program.
*/

#ifndef TESTS_H
#define TESTS_H

#include "solve.h" //TODO: если убрать, то порядок подключения в tests.cpp влияет на компиляцию, что делать.

/**
 * @brief Test input.
 * Contains coefficients and expected output.
*/
struct test_input
{
    struct coefficients coef_exp; ///< Coefficients of equation.
    struct roots rts_exp;         ///< Expected roots of equation.
};

/**
 * @brief Tests program on test_input.
 * @param test Pointer to struct test_input.
 * @param counter Pointer to tests counter.
 * @return @b true if test is succeded.
 * Выводит информацию о тесте, если он не прошёл.
*/
unsigned int run_test(const struct test_input *const test, const size_t *const counter);

/**
 * @brief Runs all test from file and prints number of successful tests.
 * @param test_file Pointer to name of the file with test inputs.
*/
void run_all_tests(const char *const file_name);

/**
 * @brief Prints test results.
 * @param counter Counter of tests.
 * @param counter_true Counter of successful tests.
*/
void printf_tests_results(const size_t counter, const size_t counter_true);

#endif //TESTS_H
