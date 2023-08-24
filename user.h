/**
 * @file user.h
 * @author Gris-a
 * @brief Contains user.cpp functions declarations
*/

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
