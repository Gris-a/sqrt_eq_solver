/**
 * @file tests.h
 * @author Gris-a
 * @brief Contains tests.cpp functions declarations.
*/

/**
 * @brief Tests programm on test_input.
 * @param test Pointer to struct test_input.
 * @param counter Counter of runned tests.
 * @param counter_true Counter of successful tests.
 * Выводит информацию о тесте, если он не прошёл, считает количество успешных тестов.
*/
void run_test(const struct test_input *const test, size_t *const counter, size_t *const counter_true);
/**
 * @brief Runs all test from tests.txt and prints number of successful tests.
*/
void run_all_tests(void);

/**
 * @brief Prints test results.
 * @param counter Counter of tests.
 * @param counter_true Counter of successful tests.
*/
void printf_tests_results(const size_t counter, const size_t counter_true);
