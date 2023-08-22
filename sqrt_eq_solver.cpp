#include <stdio.h>
#include <math.h>
#include<assert.h>

/*решение квадратного уравнения с действительнами коэффициентами a, b и c и корнями x1 и x2*/

#define M_ERR 0.00000001 //погрешность сравнения float
#define INF_RTS -1 //бесконечное количество корней

#define RUN_TEST(a, b, c, x1_exp, x2_exp, num_exp, counter, counter_true)\
	counter++;\
    if(test_solve_equation(a, b, c, x1_exp, x2_exp, num_exp))\
        counter_true++;

int solve_equation(double a, double b, double c, double *x1, double *x2); //решение уравнения
int quadratic_equation(double a, double b, double c, double *x1, double *x2); //решение квадратного уравнения
int qlinear_equation(double b, double c, double *x1, double *x2); //решение линейного уравнения

void get_coefficients(double *a, double *b, double *c);
void check_scan_f(double *k); //проверка ввода на float
void clean_buff(void);

int test_solve_equation(double a, double b, double c, double x1_exp, double x2_exp, int num_exp);
void run_all_tests(void);

int main(void)
{
    printf("Программа решает квадратное уравнение.\n");
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
    }
}

int solve_equation(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));
    assert(x1 != x2);

    if(fabs(a) < M_ERR)
    {
        return qlinear_equation(b, c, x1, x2);
    }
    return quadratic_equation(a, b, c, x1, x2);
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

void run_all_tests(void)
{
	unsigned long long counter = 0;
	unsigned long long counter_true = 0;

	RUN_TEST(0, 0, 0, 0, 0, INF_RTS, counter, counter_true);
    RUN_TEST(0, 0, 5, 0, 0, 0, counter, counter_true);
    RUN_TEST(0, 2, 5, -2.5, -2.5, 1, counter, counter_true);
    RUN_TEST(1, -4, 4, 2, 2, 1, counter, counter_true);
    RUN_TEST(1, -5, 6, 2, 3, 2, counter, counter_true);
    RUN_TEST(1, 1, 1, 0, 0, 0, counter, counter_true);
    RUN_TEST(1, 0, 0, 0, 0, 1, counter, counter_true);
    RUN_TEST(1, 0, -1, -1, 1, 2, counter, counter_true);

	printf("%llu/%lluu tests passed\n", counter_true, counter);
}
