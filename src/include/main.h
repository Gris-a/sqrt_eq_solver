#include "colors.h"

/**
 * @file main.h
 * @author Gris-a
 * @brief Main header file.
 * Contains all global constants, structures and defines.
*/

/**
 * A measurement error. Used when comparing @a float type.
*/
#define M_ERR 1e-10

/**
 * Length of command line arguments.
*/
#define ARG_LEN 7

/**
 * @brief Constants that determine the number of roots.
*/
enum nRoots
{
    INF_ROOTS = -1, ///< infinite number of roots.
    ZERO_ROOTS = 0, ///< zero roots.
    ONE_ROOT = 1,   ///< one root.
    TWO_ROOTS = 2   ///< two roots.
};

/**
 * @brief Coefficients of the quadratic equation.
*/
struct coefficients
{
    double a; ///< Coefficient before x^2.
    double b; ///< Coefficient before x.
    double c; ///< Free coefficient.
};

/**
 * @brief Roots of the quadratic equation.
*/
struct roots
{
    double x1; ///< First root of the equation.
    double x2; ///< Second root of the equation.
};

/**
 * @brief Test input.\n
 * Contains coefficients and expected output.
*/
struct test_input
{
    struct coefficients coef_exp; ///< Coefficients of equation.
    struct roots rts_exp;         ///< Expected roots of equation.
    int nRoots_exp;               ///< Expected number of roots.
};

/**
 * @brief Command line arguments for program.
*/
struct arguments
{
    char help[ARG_LEN]; ///< For more info.
    char test[ARG_LEN]; ///< For testing.
    char user[ARG_LEN]; ///< For user input-output.
};
const struct arguments my_args = {"--help", "--test", "--user"}; ///< Struct object with command line arguments.

/**
 * @brief Индексы вхождения аргументов my_args в argv.
*/
struct arguments_check
{
    int help; ///< Индекс вхождения my_args.help
    int test; ///< Индекс вхождения аути к файлу с тестами.
    int user; ///< Индекс вхождения my_args.user
};