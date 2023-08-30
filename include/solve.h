/**
 * @file solve.h
 * @author Gris-a
 * @brief Solving equation.
*/

#ifndef SOLVE_H
#define SOLVE_H

/**
 * A measurement error. Used when comparing @a float type.
*/
const double M_ERR = 1e-10;

/**
 * Максимальное количество отображаемых цифр после запятой.
*/
const int DIGITS = 10; // MAX_DIGITS

/**
 * @brief Constants that determine the number of roots.
*/
enum NRoots
{
    INF_ROOTS  = -1, ///< infinite number of roots.
    ZERO_ROOTS =  0, ///< zero roots.
    ONE_ROOT   =  1, ///< one root.
    TWO_ROOTS  =  2  ///< two roots.
};

/**
 * @brief Coefficients of the quadratic equation.
*/
struct Coefficients
{
    double a; ///< Coefficient before x^2.
    double b; ///< Coefficient before x.
    double c; ///< Free coefficient.
};

/**
 * @brief Roots of the quadratic equation.
*/
struct Roots
{
    double x1;           ///< First root of the equation.
    double x2;           ///< Second root of the equation.
    enum NRoots n_roots; ///< Number of roots.
};

/**
 * @brief Solves equation.
 * @param coef Pointer to coefficients of the equation.
 * @param rts Pointer to roots of the equation.
 * Если @b rts->a равно нулю, вызывает linear_equation(), иначе quadratic_equation().
*/
void solve_equation(const struct Coefficients * const coef, struct Roots *const rts);

/**
 * @brief Solves quadratic equation.
 * @param coef Pointer to coefficients of the equation.
 * @param rts Pointer to roots of the equation.
*/
void quadratic_equation(const struct Coefficients * const coef, struct Roots *const rts);

/**
 * @brief Solves linear equation.
 * @param coef Pointer to coefficients of the equation.
 * @param rts Pointer to roots of the equation.
*/
void linear_equation(const struct Coefficients * const coef, struct Roots *const rts);

/**
 * @brief Compares @a float variables @a a and @a b with measurement еrror @b ERR.
 * @return @b true if @b a is equal to @b b with an error of @b ERR.
*/
bool float_cmp(const double a, const double b, const double ERR);

#endif //SOLVE_H
