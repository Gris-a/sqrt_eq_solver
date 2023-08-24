/**
 * A measurement error. Used when comparing @a float type.
*/
#define M_ERR 1e-10

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

//tests.cpp

/**
 * @brief Function that tests programm on test_input.
 * @param test Pointer to struct test_input.
 * Prints info if test is not succeeded, count succesful tests.
*/
void run_test(const struct test_input *const test);
/**
 * @brief Runs all test and prints number of successful tests.
*/
void run_all_tests(void);

//solve.cpp

/**
 * @brief Solves quadratic equation.
 * @param coef Pointer to coefficients of the equation.
 * @param rts Pointer to roots of the equation.
 * @return Returns number of roots of the equation according to @b nRoots.
 * Checks if parameters are valid, then if @b rts->a equal to zero, calls linear_equation(), otherwise quadratic_equation().
 * @note If two roots are close to eachother, returns output as one root.
*/
int solve_equation(const struct coefficients *const coef, struct roots *rts);
/**
 * @brief Solves quadratic equation.
 * @param coef Coefficients of the equation.
 * @param rts Pointer on roots of the equation.
 * @return Returns number of roots of the equation  according to @b nRoots.
*/
int quadratic_equation(const struct coefficients *const coef, struct roots *const rts);
/**
 * @brief Solves linear equation.
 * @param coef Coefficients of the equation.
 * @param rts Pointer on roots of the equation.
 * @return Returns number of roots of the equation according to @b nRoots.
*/
int linear_equation(const struct coefficients *const coef, struct roots *const rts);
/**
 * @brief Compares @a float variables @a a and @a b with measurement еrror @b err.
 * @return @b 1 if @b a similar to @b b, otherwise @b 0.
*/
int float_cmp(double a, double b, double err);

//user.cpp

/**
 * @brief Solves quadratic equation with user input-output.
 * Calls get_coefficients(), checks on @b EOF, calls solve_equation() to solve equation and printf_roots() to print the solution.
*/
void solve_equation_user(void);
/**
 * @brief Gets coefficients of equation from @b stdin.
 * @param coef Pointer on coefficients of equation.
 * @return @b 1 if @b EOF, otherwise @b 0.
 * Calls check_scanf_double() three times for @b coef->a, @b coef->b and @b coef->c, breaks when check_scanf_double() finds @b EOF.
*/
int get_coefficients(struct coefficients *const coef);
/**
 * @brief Gets @a double from @b stdout and checks it.
 * @param dbl Pointer on coefficient of equation.
 * @return @b 1 If EOF, otherwise @b 0.
 * Checks input for @a double variable, otherwise calls clean_buff() and asks to repeat input, breaks when clean_buff() finds @b EOF.
*/
int check_scanf_double(double *const dbl);
/**
 * @brief Clears @b stdin buffer.
 * @return First founded @b '\n' or @b EOF.
 * Calls getchar() until @b '\n' or @b EOF.
*/
int clean_buff(void);
/**
 * @brief Analyzes the number of roots and prints them properly.
 * @param rts Pointer to roots of the equation.
 * @param nRoots number of roots of the equation.
*/
void printf_roots(const struct roots *const rts, const int nRoots);

//prog.cpp

/**
 * @brief Checks if @b arg in @b argv[].
 * @param argc Number of command line arguments.
 * @param argv Array with pointers to command line arguments.
 * @param arg Argument that is searching in @b argv.
 * @return @b 1 if @b arg in @b argv, otherwise @b 0.
*/
int flag_check(int argc, char *argv[], const char arg[]);
/**
 * @brief Runs programm.
 * @param argc Number of command line arguments.
 * @param argv Array with pointers on command line arguments.
 * Depending on the arguments calls run_all_tests() or solve_equation_user() or prints info.
*/
void run_prog(const int argc, char *argv[]);
