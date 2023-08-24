#include <stdio.h>
#include <math.h>
#include<string.h>

/**
 * @mainpage Quadratic equation solver
 * @file sqrt_eq_solver.cpp
 * @author Gris-a.
 * @brief Program solves quadratic equation.
 * @bug If you get two different roots close to zero, then the solution will give @b x1 = 0, @b x2 = 0, @b nRoots = 2.
 * @todo DOPILIT documentation.
*/

/**
 * A measurement error. Used when comparing @a float type.
*/
#define M_ERR 1e-10
/**
 * Macros for comparing @a float variables @a a and @a b. Returns @b 1 if @b a == @b b otherwise @b 0.
*/
#define float_cmp(a, b) (fabs(a - b) < M_ERR)

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
 *
*/
enum errors
{
    IS_INFINITE,
    IS_NULL
};

/**
 * @brief Solves quadratic equation.
 * @param coef Pointer to coefficients of the equation.
 * @param rts Pointer to roots of the equation.
 * @return Returns number of roots of the equation according to @b nRoots.
 * Checks if parameters are valid, then if @b rts->a equal to zero, calls linear_equation(), otherwise quadratic_equation().
*/
int solve_equation(const struct coefficients *const coef, struct roots *rts);
/**
 * @brief Solves quadratic equation with user input-output.
 * Generating coefficients and roots, calls get_coefficients(), checks on @b EOF, calls solve_equation() to solve equation and then printf_roots() to print the solution.
*/
void solve_equation_user(void);
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
 * @brief Gets coefficients of equation from @b stdin.
 * @param coef Pointer on coefficients of equation.
 * @return @b 1 if @b EOF otherwise @b 0.
 * Calls check_scanf_double() three times for @b coef->a, @b coef->b and @b coef->c, breaks when check_scanf_double() finds @b EOF.
*/
int get_coefficients(struct coefficients *const coef);
/**
 * @brief Gets @a double from @b stdout and checks it.
 * @param dbl Pointer on coefficient of equation.
 * @return @b 1 If EOF otherwise @b 0.
 * Checks input for @a double variable otherwise calls clean_buff() and asks to repeat input, breaks when clean_buff() finds @b EOF.
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
 * @param rts roots of the equation.
 * @param nRoots number of roots of the equation.
*/
void printf_roots(const struct roots *const rts, const int nRoots);

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
 * Prints if test is not succeeded.
*/
void run_test(const struct test_input *const test);
/**
 * @brief Function that runs all test and prints number of successful tests.
 * Initialize counter and counter_true for run_test() and run tests.
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
    struct coefficients coef_exp;
    struct roots rts_exp;
    int nRoots_exp;

    size_t *counter;
    size_t *counter_true;
};

/**
 * @brief
 * @param argc
 * @param argv
 * @return
 *
*/
int main(int argc, char *argv[])
{
    printf("This programm solves quadratic equation.\n");
    printf("ZAG, 2023.\n\n");

    if(flag_check(argc, argv, "--help"))
    {
        printf("--test to test the program.\n\n--uio to solve equation with user input-output.\n\n");
    }

    if(flag_check(argc, argv, "--uio"))
    {
        solve_equation_user();
    }

    if(flag_check(argc, argv, "--test"))
    {
        run_all_tests();
    }
}

int solve_equation(const struct coefficients *const coef, struct roots *const rts)
{
    if(!isfinite(coef->a))
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_INFINITE);
    }
    if(!isfinite(coef->b))
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_INFINITE);
    }
    if(!isfinite(coef->c))
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_INFINITE);
    }
    if(rts != NULL)
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_NULL);
    }
    if(coef != NULL)
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_NULL);
    }

    int nRoots = (float_cmp(coef->a, 0.0)) ? linear_equation(coef, rts) : quadratic_equation(coef, rts);

    rts->x1 = (float_cmp(rts->x1, 0.0)) ? 0.0 : rts->x1;
    rts->x2 = (float_cmp(rts->x2, 0.0)) ? 0.0 : rts->x2;
    if(nRoots == 2 && float_cmp(rts->x1, rts->x2))
    {
        nRoots = 1;
        rts->x2 = rts->x1;
    }

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

int quadratic_equation(const struct coefficients *const coef, struct roots *const rts)
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

int linear_equation(const struct coefficients *const coef, struct roots *const rts)
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

int get_coefficients(struct coefficients *const coef)
{
    if(coef != NULL)
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_NULL);
    }

    printf("Введите коэффициент перед x^2: ");
    if(check_scanf_double(&coef->a))
    {
        return 1;
    }

    printf("Введите коэффициент перед x: ");
    if(check_scanf_double(&coef->b))
    {
        return 1;
    }

    printf("Введите свободный член: ");
    if(check_scanf_double(&coef->c))
    {
        return 1;
    }
    return 0;
}

int check_scanf_double(double *const dbl)
{
    if(dbl != NULL)
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_NULL);
    }

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

void printf_roots(const struct roots *const rts, const int nRoots)
{
    if(rts != NULL)
    {
        printf("Error in line %d.\nError code %d.\n", __LINE__, IS_NULL);
    }

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

void run_test(const struct test_input *const test)
{
    struct roots rts = {0.0, 0.0};
	int nRoots = solve_equation(&test->coef_exp, &rts);

	(*test->counter)++;

    if((nRoots == test->nRoots_exp && ((float_cmp(rts.x1, test->rts_exp.x1) && float_cmp(rts.x2, test->rts_exp.x2)) ||
                           (float_cmp(rts.x1, test->rts_exp.x2) && float_cmp(rts.x2, test->rts_exp.x1)))))
    {
        (*test->counter_true)++;
    }
    else
    {
        printf("FAILED TEST №%zu.\n"
               "EXPECTED: x1= %10lg, x2= %10lg, nRoots=%3d.\n"
               "RECEIVED: x1= %10lg, x2= %10lg, nRoots=%3d.\n",
               *test->counter, test->rts_exp.x1, test->rts_exp.x2, test->nRoots_exp, rts.x1, rts.x2, nRoots);
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
                            {{0,  0,  0},  {   0,    0},     INF_ROOTS, &counter, &counter_true},
                            {{0,  0,  5},  {   0,    0},    ZERO_ROOTS, &counter, &counter_true},
                            {{0,  5,  0},  {   0,    0},      ONE_ROOT, &counter, &counter_true},
                            {{0,  2,  5},  {-2.5, -2.5},      ONE_ROOT, &counter, &counter_true},
                            {{1,  0,  5},  {   0,    0},    ZERO_ROOTS, &counter, &counter_true},
                            {{1,  1,  0},  {  -1,    0},     TWO_ROOTS, &counter, &counter_true},
                            {{1, -4,  4},  {   2,    2},      ONE_ROOT, &counter, &counter_true},
                            {{1, -5,  6},  {   2,    3},     TWO_ROOTS, &counter, &counter_true},
                            {{1,  1,  1},  {   0,    0},    ZERO_ROOTS, &counter, &counter_true},
                            {{1,  0,  0},  {   0,    0},      ONE_ROOT, &counter, &counter_true},
                            {{1,  0, -1},  {  -1,    1},     TWO_ROOTS, &counter, &counter_true},
                            {{1,  0, -1},  {  -1,    1},     TWO_ROOTS, &counter, &counter_true},
                            {{1,  0, -1},  {   0,    1},     TWO_ROOTS, &counter, &counter_true} //Expectedly fails
                            };

    for(size_t i = 0; i < sizeof(test_arr)/sizeof(test_input); i++)
    {
        run_test(&test_arr[i]);
    }

	printf("%zu/%zu tests passed\n", counter_true, counter);
}
