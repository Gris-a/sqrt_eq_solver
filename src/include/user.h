/**
 * @file user.h
 * @author Gris-a
 * @brief User input-output.
*/

/**
 * @brief Solves quadratic equation with user input-output.
 * Calls get_coefficients(), calls solve_equation() to solve equation and printf_roots() to print the solution.
*/
void solve_equation_user(void);

/**
 * @brief Gets coefficients of equation from @b stdin.
 * @param coef Pointer to coefficients of equation.
 * @return @b true if @b EOF.
 * Вызывает check_scanf_double() три раза для @b coef->a, @b coef->b и @b coef->c.
 * Выход из функции если check_scanf_double() находит @b EOF.
*/
int get_coefficients(struct coefficients *const coef);

/**
 * @brief Gets @a double from @b stdout and checks it.
 * @param dbl Pointer to coefficient of equation.
 * @return @b true If @b EOF.
 * Проверяет ввод на переменную типа @a double, иначе вызывает clean_buff() и просит повторить вывод.
 * Выход из функции если clean_buff() находит @b EOF.
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
*/
void printf_roots(const struct roots *const rts);
