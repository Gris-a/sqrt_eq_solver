/**
 * @file solve.h
 * @author Gris-a
 * @brief Contains solve.cpp functions declarations
*/

/**
 * @brief Solves quadratic equation.
 * @param coef Pointer to coefficients of the equation.
 * @param rts Pointer to roots of the equation.
 * @return Returns number of roots of the equation according to @b nRoots.
 * Проверяет корректность параметров, еслиf @b rts->a равно нулю, вызывает linear_equation(), иначе quadratic_equation().
 * @note Если два корня близки друг к другу, возвращает вывод как один корень.
*/
int solve_equation(const struct coefficients *const coef, struct roots *const rts);
/**
 * @brief Solves quadratic equation.
 * @param coef Coefficients of the equation.
 * @param rts Pointer to roots of the equation.
 * @return Returns number of roots of the equation  according to @b nRoots.
*/
int quadratic_equation(const struct coefficients *const coef, struct roots *const rts);
/**
 * @brief Solves linear equation.
 * @param coef Coefficients of the equation.
 * @param rts Pointer to roots of the equation.
 * @return Returns number of roots of the equation according to @b nRoots.
*/
int linear_equation(const struct coefficients *const coef, struct roots *const rts);
/**
 * @brief Compares @a float variables @a a and @a b with measurement еrror @b err.
 * @return @b 1 if @b a similar to @b b, otherwise @b 0.
*/
int float_cmp(const double a, const double b, const double err);
