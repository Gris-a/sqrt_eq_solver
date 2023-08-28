/**
 * @file tests.h
 * @author Gris-a
 * @brief Contains tests.cpp functions declarations.
*/

/**
 * @brief Tests program on test_input.
 * @param test Pointer to struct test_input.
 * @param counter Pointer to tests counter.
 * @return @b true if test is succeded, otherwise @b false.
 * Выводит информацию о тесте, если он не прошёл.\n
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
