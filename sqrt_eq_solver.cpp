#include <stdio.h>
#include <math.h>
#include<assert.h>

/*решение квадратного уравнения с действительнами коэффициентами a, b и c и корнями x1 и x2*/

#define M_ERR 0.00000001 //погрешность сравнения float
#define INF_RTS -1 //бесконечное количество корней

int solve_equation(double a, double b, double c, double *x1, double *x2); //решение уравнения
int quadratic_equation(double a, double b, double c, double *x1, double *x2); //решение квадратного уравнения
int qlinear_equation(double b, double c, double *x1, double *x2); //решение линейного уравнения

void get_coefficients(double *a, double *b, double *c);
void check_scan_f(double *k); //проверка ввода на float
void clean_buff(void);

int test_solve_equation(double a, double b, double c, double x1_exp, double x2_exp, int num_exp);
void run_test(double a, double b, double c, double x1_exp, double x2_exp, int num_exp, size_t* counter, size_t* counter_true);
void run_all_tests(void);

int main(void)
{
    /*printf("Программа решает квадратное уравнение.\n");
    printf("ZAG, 2023.\n\n");
    //коэффициенты уравнения
    double a = 0;
    double b = 0;
    double c = 0;

    //корни уравнения
    double x1 = 0;
    double x2 = 0;

    int num = 0; //количество корней

    get_coefficients(&a, &b, &c);
    num = solve_equation(a, b, c, &x1, &x2);

    switch(num)
    {
        case INF_RTS:
            printf("Корнем может быть любое действительное число.\n");
            break;
        case 0:
            printf("Нет корней.\n");
            break;
        case 1:
            printf("%lg - корень уравнения.\n", x1);
            break;
        case 2:
            printf("%lg и %lg - корни уравнения.\n", x1, x2);
            break;
        default:
            printf("Не ожидаемое количество корней.\n");
            break;
    }*/
    run_all_tests();
}

int solve_equation(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != x2);

    return (fabs(a) < M_ERR) ? qlinear_equation(b, c, x1, x2) : quadratic_equation(a, b, c, x1, x2);
}

int quadratic_equation(double a, double b, double c, double *x1, double *x2)
{
    double D = b * b - 4 * a * c; //дискриминант

    if(fabs(D) < M_ERR)
    {
        *x1 = *x2 = - (b / (2 * a));

        return 1;
    }
    else if(D < 0)
    {
        return 0;
    }
    else
    {
        *x1 = (-b - sqrt(D)) / (2 * a);
        *x2 = (-b + sqrt(D)) / (2 * a);

        return 2;
    }
}

int qlinear_equation(double b, double c, double *x1, double *x2)
{
    if(fabs(b) < M_ERR && fabs(c) < M_ERR)
    {
        return INF_RTS;
    }
    else if(abs(b) < M_ERR && fabs(c) > 0)
    {
        return 0;
    }
    else
    {
        *x1 = *x2 = - (c / b);

        return 1;
    }
}

void get_coefficients(double *a, double *b, double *c)
{
    printf("Введите коэффициент перед x^2: ");
    check_scan_f(a);

    printf("Введите коэффициент перед x: ");
    check_scan_f(b);

    printf("Введите свободный член: ");
    check_scan_f(c);
}

void check_scan_f(double *k)
{
    char ncheck = '\0';
    int scanf_out = 0;

    while(1)
    {
        scanf_out = scanf("%lf%c", k, &ncheck);
        if((scanf_out != 2) || (ncheck != '\n'))
        {
            printf("Некорректный ввод, попробуйте снова: ");
            clean_buff();
        }
        else
        {
            return;
        }
    }
}

void clean_buff(void)
{
    int ch = 0;

    while(ch != '\n')
    {
        ch = getchar();
    }
}

int test_solve_equation(double a, double b, double c, double x1_exp, double x2_exp, int num_exp)
{
	double x1 = 0;
    double x2 = 0;

	int num = solve_equation(a, b, c, &x1, &x2);
	return (num == num_exp && ((fabs(x1 - x1_exp) < M_ERR && fabs(x2 - x2_exp) < M_ERR) || (fabs(x1 - x2_exp) < M_ERR && fabs(x2 - x1_exp) < M_ERR)));
}

void run_test(double a, double b, double c, double x1_exp, double x2_exp, int num_exp, size_t* counter, size_t* counter_true)
{
	(*counter)++;
    if(test_solve_equation(a, b, c, x1_exp, x2_exp, num_exp))
    {
        (*counter_true)++;
    }
}

void run_all_tests(void)
{
    size_t counter = 0;
	size_t counter_true = 0;

	run_test(0, 0, 0, 0, 0, INF_RTS, &counter, &counter_true);
    run_test(0, 0, 5, 0, 0, 0, &counter, &counter_true);
    run_test(0, 5, 0, 0, 0, 1, &counter, &counter_true);
    run_test(0, 2, 5, -2.5, -2.5, 1, &counter, &counter_true);
    run_test(1, 0, 5, 0, 0, 0, &counter, &counter_true);
    run_test(1, 1, 0, -1, 0, 2, &counter, &counter_true);
    run_test(1, -4, 4, 2, 2, 1, &counter, &counter_true);
    run_test(1, -5, 6, 2, 3, 2, &counter, &counter_true);
    run_test(1, 1, 1, 0, 0, 0, &counter, &counter_true);
    run_test(1, 0, 0, 0, 0, 1, &counter, &counter_true);
    run_test(1, 0, -1, -1, 1, 2, &counter, &counter_true);

	printf("%zu/%zu tests passed\n", counter_true, counter);
}
