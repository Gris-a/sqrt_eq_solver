/**
 * A measurement error. Used when comparing @a float type.
*/
#define M_ERR 1e-10
/**
 * Macros for soft assert of expression. Shows line and code of error.
*/
# define soft_assert(expr, err_code) if(!(expr))\
    {\
        printf("Error in line %d.\nError code %d.\n", __LINE__, err_code);\
    }\

/**
 * @file main.h
 * @author Gris-a
 * @brief Main header file.
 * Contains all global constants
*/

/**
 * @brief Number of quadratic equasion's roots constants.
*/
enum nRoots
{
    INF_ROOTS = -1, ///< infinite number of roots
    ZERO_ROOTS,     ///< zero roots
    ONE_ROOT,       ///< one root
    TWO_ROOTS       ///< two roots
};
/**
 * @brief Errors output code.
*/
enum errors
{
    IS_INFINITE, ///< variable is @a infinite
    IS_NULL      ///< NULL pointer
};

/**
 * @brief Coefficients of the quadratic equation.
 * Contains three coefficients.
*/
struct coefficients
{
    double a; ///< Coefficient before x^2
    double b; ///< Coefficient before x
    double c; ///< Free coefficient
};
/**
 * @brief Roots of the quadratic equation.
 * Contains two roots.
*/
struct roots
{
    double x1; ///< Smallest root of the equation
    double x2; ///< Biggest root of the equation
};
/**
 * @brief Test input.
 * Contains coefficients, expected output of programm and counters.
*/
struct test_input
{
    struct coefficients coef_exp; ///< Coefficients of equation.
    struct roots rts_exp;         ///< Expected roots of equation.
    int nRoots_exp;               ///< Expected number of roots.

    size_t *counter;              ///< Counter of tested inputs.
    size_t *counter_true;         ///< Counter of successfully tested inputs.
};
