/**
 * @file tests.h
 * @author Gris-a
 * @brief Contains tests.cpp functions declarations
*/

/**
 * @brief Function that tests programm on test_input.
 * @param test Pointer to struct test_input.
 * @param counter counter of runned tests.
 * @param counter_true counter of successful tests.
 * Prints info if test is not succeeded, count succesful tests.
*/
void run_test(const struct test_input *const test, size_t *const counter, size_t *const counter_true);
/**
 * @brief Runs all test and prints number of successful tests.
*/
void run_all_tests(void);
