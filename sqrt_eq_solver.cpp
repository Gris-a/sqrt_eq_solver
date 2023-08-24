#include <stdio.h>
#include <math.h>
#include<assert.h>
#include<string.h>

/**
 * @mainpage Quadratic equation solver
 * @file sqrt_eq_solver.cpp
 * @author Gris-a.
 * @brief Program solves quadratic equation.
 * @bug If you get two different roots close to zero, then the solution will give @b x1 = 0, @b x2 = 0, @b nRoots = 2.
 * @todo Change assert on if. Check documentation. Check const. defence coding.
*/

/**
 * A measurement error. Used when comparing @a float type.
*/
#define M_ERR 1e-6
/**
 * Macros for comparing @a float variables @a a and @a b. Returns @b 1 if @b a == @b b otherwise @b 0.
*/
#define float_cmp(a, b) (fabs(a - b) < M_ERR)

/**
 * @brief Number of quadratic equasion's roots constants.
*/
enum nRoots{INF_ROOTS = -1,
            ZERO_ROOTS, ///< infinite number of roots
            ONE_ROOT,   ///< one root
            TWO_ROOTS   ///< two roots
            };

/**
 * @brief Solves quadratic equation.
 * @param coef Pointer to coefficients of the equation.
 * @param rts Pointer to roots of the equation.
 * @return Returns number of roots of the equation according to @b nRoots.
 * Checks if parameters are valid, then if @b rts->a equal to zero, calls linear_equation(), otherwise quadratic_equation().
*/
int solve_equation(const struct coefficients *coef, struct roots *rts);
/**
 * @brief Solves quadratic equation with user input-output.
 * @note Generating coefficients and roots, calls get_coefficients(), checks on @b EOF, calls solve_equation() to solve equation and then printf_roots() to print the solution.
*/
void solve_equation_user(void);
/**
 * @brief Solves quadratic equation.
 * @param coef Coefficients of the equation.
 * @param rts Pointer on roots of the equation.
 * @return Returns number of roots of the equation  according to @b nRoots.
*/
int quadratic_equation(const struct coefficients *coef, struct roots *rts);
/**
 * @brief Solves linear equation.
 * @param coef Coefficients of the equation.
 * @param rts Pointer on roots of the equation.
 * @return Returns number of roots of the equation according to @b nRoots.
*/
int linear_equation(const struct coefficients *coef, struct roots *rts);

/**
 * @brief Gets coefficients of equation from @b stdin.
 * @param coef Pointer on coefficients of equation.
 * @return @b 1 if @b EOF otherwise @b 0.
 * @note Calls check_scan_f() three times for @b coef->a, @b coef->b and @b coef->c, breaks when check_scan_f() finds @b EOF.
*/
int get_coefficients(struct coefficients *coef);
/**
 * @brief Gets @a double from @b stdout and checks it.
 * @param dbl Pointer on coefficient of equation.
 * @return @b 1 If EOF otherwise @b 0.
 * @note Checks input for @a double variable otherwise calls clean_buff() and asks to repeat input, breaks when clean_buff() finds @b EOF.
*/
int check_scan_f(double *dbl);
/**
 * @brief Clears @b stdin buffer.
 * @return First founded @b '\n' or @b EOF.
 * @note calls getchar() until @b '\n' or @b EOF.
*/
int clean_buff(void);
/**
 * @brief Analyzes the number of roots and prints them properly.
 * @param rts roots of the equation.
 * @param nRoots number of roots of the equation.
*/
void printf_roots(const struct roots *rts, int nRoots);

/**
 * @brief Checks if @b arg in @b argv[].
 * @param argc Number of command line arguments.
 * @param argv Array with pointers on command line arguments.
 * @param arg Argument that is searching in @b argv.
 * @return @b 1 if @b arg in @b argv otherwise @b 0.
*/
int flag_check(int argc, char *argv[], const char arg[]);
/**
 * @brief Function that tests programm.
 * @param a, b, c Coefficients of quadratic equation.
 * @param x1_exp, x2_exp Expected roots of the equation.
 * @param nRoots_exp Expected number of roots.
 * @param counter Counter of tests.
 * @param counter_true Counter of sucсessful tests.
 * @note  Prints if test is not succeeded.
*/
void run_test(struct test_input *test);
/**
 * @brief Function that runs all test and prints number of successful tests.
 * @note Initialize counter and counter_true for run_test() and run tests.
*/
void run_all_tests(void);

/**
 * @brief Coefficients of the quadratic equation.
 * Contains three @a double variables.
*/
struct coefficients
{
    double a; ///< Coefficient before x^2
    double b; ///< Coefficient before x
    double c; ///< Free coefficient
};
/**
 * @brief Roots of the quadratic equation.
 * Contains two @a double variables.
*/
struct roots
{
    double x1; ///< Smallest root of the equation
    double x2; ///< Biggest root of the equation
};
/**
 *
*/
struct test_input
{
    double a;
    double b;
    double c;

    double x1_exp;
    double x2_exp;
    int nRoots_exp;

    size_t *counter;
    size_t *counter_true;
};

/**
 * @brief
 * @param argc
 * @param argv
 * @return
 * @note
*/
int main(int argc, char *argv[])
{
    printf("This programm solves quadratic equation.\n");
    printf("ZAG, 2023.\n\n");
    printf("--test to test the program.\n\n--uio to solve equation with user input-output");
    if(flag_check(argc, argv, "--uio"))
    {
        solve_equation_user();
    }

    if(flag_check(argc, argv, "--test"))
    {
        run_all_tests();
    }
}

int solve_equation(const struct coefficients *coef, struct roots *rts)
{
    assert(isfinite(coef->a));
    assert(isfinite(coef->b));
    assert(isfinite(coef->c));
    assert(rts != NULL);
    assert(coef != NULL);

    int nRoots = (float_cmp(coef->a, 0.0)) ? linear_equation(coef, rts) : quadratic_equation(coef, rts);
    rts->x1 = (float_cmp(rts->x1, 0.0)) ? 0.0 : rts->x1;
    rts->x2 = (float_cmp(rts->x2, 0.0)) ? 0.0 : rts->x2;

    return nRoots;
}

void solve_equation_user(void)
{
    struct coefficients coef = {0.0, 0.0, 0.0};
    struct roots rts = {0.0, 0.0};

    int nRoots = 0;

    if(get_coefficients(&coef))
    {
        printf("\nEnd of File.\n");
        return;
    }
    nRoots = solve_equation(&coef, &rts);
    printf_roots(&rts, nRoots);
}

int quadratic_equation(const struct coefficients *coef, struct roots *rts)
{
    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    if(float_cmp(D, 0.0))
    {
        rts->x1 = rts->x2 = - (coef->b / (2 * coef->a));

        return ONE_ROOT;
    }
    else if(D < 0.0)
    {
        return ZERO_ROOTS;
    }
    else
    {
        double D_sqrt = sqrt(D);
        rts->x1 = (-coef->b - D_sqrt) / (2 * coef->a);
        rts->x2 = (-coef->b + D_sqrt) / (2 * coef->a);

        return TWO_ROOTS;
    }
}

int linear_equation(const struct coefficients *coef, struct roots *rts)
{
    if(float_cmp(coef->b, 0.0))
    {
        if(float_cmp(coef->c, 0.0))
        {
            return INF_ROOTS;
        }
        return ZERO_ROOTS;
    }
    else
    {
        rts->x1 = rts->x2 = - (coef->c / coef->b);

        return ONE_ROOT;
    }
}

int get_coefficients(struct coefficients *coef)
{
    printf("Введите коэффициент перед x^2: ");
    if(check_scan_f(&coef->a))
    {
        return 1;
    }

    printf("Введите коэффициент перед x: ");
    if(check_scan_f(&coef->b))
    {
        return 1;
    }

    printf("Введите свободный член: ");
    if(check_scan_f(&coef->c))
    {
        return 1;
    }
    return 0;
}

int check_scan_f(double *dbl)
{
    char ncheck = '\0';
    int scanf_out = 0;
    while(1)
    {
        scanf_out = scanf("%lg%c", dbl, &ncheck);
        if((scanf_out != 2) || (ncheck != '\n'))
        {
            if(clean_buff())
            {
                return 1;
            }
            printf("Некорректный ввод, попробуйте снова: ");
        }
        else
        {
            return 0;
        }
    }
}

int clean_buff(void)
{
    int ch = 0;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        ;
    }
    return ch;

}

void printf_roots(const struct roots *rts, int nRoots)
{
    switch(nRoots)
    {
        case INF_ROOTS:
            printf("Корнем может быть любое действительное число.\n");
            break;
        case ZERO_ROOTS:
            printf("Нет корней.\n");
            break;
        case ONE_ROOT:
            printf("%lg - корень уравнения.\n", rts->x1);
            break;
        case TWO_ROOTS:
            printf("%lg и %lg - корни уравнения.\n", rts->x1, rts->x2);
            break;
        default:
            printf("Квадратное уравнение не может иметь %d корней.\n", nRoots);
            break;
    }
}

void run_test(struct test_input *test)
{
    struct coefficients coef = {test->a, test->b, test->c};
    struct roots rts = {0.0, 0.0};

	int nRoots = solve_equation(&coef, &rts);

	(*test->counter)++;

    if((nRoots == test->nRoots_exp && ((float_cmp(rts.x1, test->x1_exp) && float_cmp(rts.x2, test->x2_exp)) ||
                           (float_cmp(rts.x1, test->x2_exp) && float_cmp(rts.x2, test->x1_exp)))))
    {
        (*test->counter_true)++;
    }
    else
    {
        printf("FAILED TEST №%zu.\n"
               "EXPECTED: x1= %10lg, x2= %10lg, nRoots=%3d.\n"
               "RECEIVED: x1= %10lg, x2= %10lg, nRoots=%3d.\n",
               *test->counter, test->x1_exp, test->x2_exp, test->nRoots_exp, rts.x1, rts.x2, nRoots);
    }
}

int flag_check(int argc, char *argv[], const char arg[])
{
    int i = 0;
    if(argc > 1)
    {
        while(--argc > 0)
        {
            i++;
            if(!strncmp(arg, argv[i], (strlen(arg) <= strlen(argv[i])) ? strlen(arg) : strlen(argv[i])))
            {
                return 1;
            }
        }
    }
    return 0;
}

void run_all_tests(void)
{
    size_t counter = 0;
	size_t counter_true = 0;
    struct test_input test_arr[] = {
                            {0,  0,  0,    0,    0,    INF_ROOTS, &counter, &counter_true},
                            {0,  0,  5,    0,    0,   ZERO_ROOTS, &counter, &counter_true},
                            {0,  5,  0,    0,    0,     ONE_ROOT, &counter, &counter_true},
                            {0,  2,  5, -2.5, -2.5,     ONE_ROOT, &counter, &counter_true},
                            {1,  0,  5,    0,    0,   ZERO_ROOTS, &counter, &counter_true},
                            {1,  1,  0,   -1,    0,    TWO_ROOTS, &counter, &counter_true},
                            {1, -4,  4,    2,    2,     ONE_ROOT, &counter, &counter_true},
                            {1, -5,  6,    2,    3,    TWO_ROOTS, &counter, &counter_true},
                            {1,  1,  1,    0,    0,   ZERO_ROOTS, &counter, &counter_true},
                            {1,  0,  0,    0,    0,     ONE_ROOT, &counter, &counter_true},
                            {1,  0, -1,   -1,    1,    TWO_ROOTS, &counter, &counter_true},
                            {1,  0, -1,   -1,    1,    TWO_ROOTS, &counter, &counter_true},
                            {1,  0, -1,    0,    1,    TWO_ROOTS, &counter, &counter_true} //Expectedly fails
                            };

    for(size_t i = 0; i < sizeof(test_arr)/sizeof(test_input); i++)
    {
        run_test(&test_arr[i]);
    }
	printf("%zu/%zu tests passed\n", counter_true, counter);
}
