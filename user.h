/**
 * @file user.h
 * @author Gris-a
 * @brief Contains user.cpp functions declarations.
*/

/**
 * @brief Solves quadratic equation with user input-output.\n
 * Calls get_coefficients(), checks on @b EOF, calls solve_equation() to solve equation and printf_roots() to print the solution.
*/
void solve_equation_user(void);
/**
 * @brief Gets coefficients of equation from @b stdin.
 * @param coef Pointer to coefficients of equation.
 * @return @b 1 if @b EOF, otherwise @b 0.
 * Вызывает check_scanf_double() три раза для @b coef->a, @b coef->b и @b coef->c.\n
 * Выход из функции когда check_scanf_double() находит @b EOF.
*/
int get_coefficients(struct coefficients *const coef);
/**
 * @brief Gets @a double from @b stdout and checks it.
 * @param dbl Pointer to coefficient of equation.
 * @return @b 1 If EOF, otherwise @b 0.
 * Проверяет ввод на переменную типа @a double, иначе вызывает clean_buff() и просит повторить вывод.\n
 * Выход из функции когда clean_buff() находит @b EOF.
*/
int check_scanf_double(double *const dbl);
/**
 * @brief Clears @b stdin buffer.
 * @return First founded @b '\n' or @b EOF.
 * Вызывает getchar() пока не найдёт @b '\n' или @b EOF.
*/
int clean_buff(void);
/**
 * @brief Analyzes the number of roots and prints them properly.
 * @param rts Pointer to roots of the equation.
 * @param nRoots number of roots of the equation.
*/
void printf_roots(const struct roots *const rts, const int nRoots);
