#include "colors.h"

/**
 * A measurement error. Used when comparing @a float type.
*/
#define M_ERR 1e-10

/**
 * @file main.h
 * @author Gris-a
 * @brief Main header file.
 * Contains all global constants, structures and defines.
*/

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
 * @brief Command line arguments for programm.
*/
struct arguments
{
    char help[7]; ///< For more info.
    char test[7]; ///< For testing.
    char user[7]; ///< For user input-output.
};
const struct arguments my_args = {"--help", "--test", "--user"}; ///< Struct object with command line arguments.

/**
 * Max length of argument from my_args.
*/
#define MAX_ARG_LEN 6