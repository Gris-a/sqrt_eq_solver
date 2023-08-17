#include <stdio.h>
#include <math.h>

/*программма решает уравнение вида a*x**2+b*x+c=0, получая на вход коэффициенты a, b и c.
Подразумевается, что коэффициенты и корни уравнения действительные числа*/

void c_scanf(double *a, double *b, double *c); //ввод и проверка коэффициентов
void ln_eq(double b, double c, double *x1); //решение линейного уравнения(если квадратное сводится к таковому)
void sq_eq(double a, double b, double c, double *x1, double *x2); //решение квадратного уравнения

int main(void)
{
    //коэффициенты
    double a = 0;
    double b = 0;
    double c = 0;
    //корни
    double x1 = 0;
    double x2 = 0;

    printf("Введите коэффициенты квадратного уравнения: ");
    c_scanf(&a, &b, &c);

    if (fabs(a) < __DBL_EPSILON__)
    {
        ln_eq(b, c, &x1);
    }
    else
    {
        sq_eq(a, b, c, &x1, &x2);

    }
    return 0;
}

void c_scanf(double *k1, double *k2, double *k3)
{
    while(1)
    {
        scanf("%lf", k1);
        scanf("%lf", k2);
        scanf("%lf", k3);
        break;
    }
}

void ln_eq(double b, double c, double *x1)
{
    if(fabs(b) < __DBL_EPSILON__ && fabs(c) < __DBL_EPSILON__)
    {
        printf("Корнем может быть любое действительное число\n");
    }
    else if(abs(b) < __DBL_EPSILON__ && fabs(c) >= __DBL_EPSILON__)
    {
        printf("Нет корней\n");
    }
    else
    {
        *x1 = - (c / b);
        printf("%lf - корень уравнения\n", *x1);
    }
}

void sq_eq(double a, double b, double c, double *x1, double *x2)
{
    double D = b * b - 4 * a * c; //дискриминант

    if(fabs(D) < __DBL_EPSILON__)
    {
        *x1 = - (b / (2 * a));
        printf("%lf - корень уравнения\n", *x1);
    }
    else if(D < 0)
    {
        printf("Нет корней\n");
    }
    else
    {
        *x1 = (-b - sqrt(D)) / (2 * a);
        *x2 = (-b + sqrt(D)) / (2 * a);
        printf("%lf и %lf - корни уравнения\n", *x1, *x2);
    }
}
