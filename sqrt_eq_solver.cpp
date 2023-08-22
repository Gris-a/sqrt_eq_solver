#include <stdio.h>
#include <math.h>
#include<assert.h>

/*решение квадратного уравнения с действительнами коэффициентами a, b и c и корнями x1 и x2*/

#define M_ERR 0.00000001 //погрешность сравнения float

enum nRoots{INF_RTS = -1, ZERO_RTS, ONE_RT, TWO_RTS};

int solve_equation(struct coefficients coef, struct roots *rts); //решение уравнения
int quadratic_equation(struct coefficients coef, struct roots *rts); //решение квадратного уравнения
int qlinear_equation(struct coefficients coef, struct roots *rts); //решение линейного уравнения

int float_comp(double a, double b);

void get_coefficients(struct coefficients *coef);
void check_scan_f(double *k); //проверка ввода на float
void clean_buff(void);

void run_test(struct coefficients coef, struct roots rts_exp, int num_exp, size_t* counter, size_t* counter_true);
void run_all_tests(void);

struct coefficients
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
};

struct roots
{
    double x1 = 0.0;
    double x2 = 0.0;
};

int main(void)
{
    printf("Программа решает квадратное уравнение.\n");
    printf("ZAG, 2023.\n\n");
    //коэффициенты уравнения
    struct coefficients coef = {0.0, 0.0, 0.0};
    //корни уравнения
    struct roots rts = {0.0, 0.0};
    //количество корней
    int num = 0;

    get_coefficients(&coef);
    num = solve_equation(coef, &rts);

    switch(num)
    {
        case INF_RTS:
            printf("Корнем может быть любое действительное число.\n");
            break;
        case ZERO_RTS:
            printf("Нет корней.\n");
            break;
        case ONE_RT:
            printf("%lg - корень уравнения.\n", rts.x1);
            break;
        case TWO_RTS:
            printf("%lg и %lg - корни уравнения.\n", rts.x1, rts.x2);
            break;
        default:
            printf("Не ожидаемое количество корней.\n");
            break;
    }

    run_all_tests();
}

int solve_equation(struct coefficients coef, struct roots *rts)
{
    assert(isfinite(coef.a));
    assert(isfinite(coef.b));
    assert(isfinite(coef.c));
    assert(&rts->x1 != NULL);
    assert(&rts->x1 != NULL);


    return (float_comp(coef.a, 0)) ? qlinear_equation(coef, rts) : quadratic_equation(coef, rts);
}

int quadratic_equation(struct coefficients coef, struct roots *rts)
{
    double D = coef.b * coef.b - 4 * coef.a * coef.c; //дискриминант

    if(float_comp(D, 0))
    {
        rts->x1 = rts->x2 = - (coef.b / (2 * coef.a));

        return ONE_RT;
    }
    else if(D < 0)
    {
        return ZERO_RTS;
    }
    else
    {
        rts->x1 = (-coef.b - sqrt(D)) / (2 * coef.a);
        rts->x2 = (-coef.b + sqrt(D)) / (2 * coef.a);

        return TWO_RTS;
    }
}

int qlinear_equation(struct coefficients coef, struct roots *rts)
{
    if(float_comp(coef.b, 0) && float_comp(coef.c, 0))
    {
        return INF_RTS;
    }
    else if(float_comp(coef.b, 0) && fabs(coef.c) > 0)
    {
        return ZERO_RTS;
    }
    else
    {
        rts->x1 = rts->x2 = - (coef.c / coef.b);

        return ONE_RT;
    }
}

int float_comp(double a, double b)
{
    return (fabs(a - b) < M_ERR) ? 1 : 0;
}

void get_coefficients(struct coefficients *coef)
{
    printf("Введите коэффициент перед x^2: ");
    check_scan_f(&coef->a);

    printf("Введите коэффициент перед x: ");
    check_scan_f(&coef->b);

    printf("Введите свободный член: ");
    check_scan_f(&coef->c);
}

void check_scan_f(double *k)
{
    char ncheck = '\0';
    int scanf_out = 0;

    while(1)
    {
        scanf_out = scanf("%lg%c", k, &ncheck);
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
    while(getchar() != '\n');
}

void run_test(struct coefficients coef, struct roots rts_exp, int num_exp, size_t* counter, size_t* counter_true)
{
    struct roots rts = {0, 0};

	int num = solve_equation(coef, &rts);

	(*counter)++;

    if((num == num_exp && ((float_comp(rts.x1, rts_exp.x1) && float_comp(rts.x2, rts_exp.x2)) || (float_comp(rts.x1, rts_exp.x2) && float_comp(rts.x2, rts_exp.x1)))))
    {
        (*counter_true)++;
    }
    else
    {
        printf("Ошибка в тесте №%zu", *counter);
    }
}

void run_all_tests(void)
{
    size_t counter = 0;
	size_t counter_true = 0;

	run_test({0, 0, 0}, {0, 0}, INF_RTS, &counter, &counter_true);
    run_test({0, 0, 5}, {0, 0}, ZERO_RTS, &counter, &counter_true);
    run_test({0, 5, 0}, {0, 0}, ONE_RT, &counter, &counter_true);
    run_test({0, 2, 5}, {-2.5, -2.5}, ONE_RT, &counter, &counter_true);
    run_test({1, 0, 5}, {0, 0}, ZERO_RTS, &counter, &counter_true);
    run_test({1, 1, 0}, {-1, 0}, TWO_RTS, &counter, &counter_true);
    run_test({1, -4, 4}, {2, 2}, ONE_RT, &counter, &counter_true);
    run_test({1, -5, 6}, {2, 3}, TWO_RTS, &counter, &counter_true);
    run_test({1, 1, 1}, {0, 0}, ZERO_RTS, &counter, &counter_true);
    run_test({1, 0, 0}, {0, 0}, ONE_RT, &counter, &counter_true);
    run_test({1, 0, -1}, {-1, 1}, TWO_RTS, &counter, &counter_true);

	printf("%zu/%zu tests passed\n", counter_true, counter);
}
