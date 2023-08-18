#include <stdio.h>
#include <math.h>

/*программма решает уравнение вида a*x**2+b*x+c=0, получая на вход коэффициенты a, b и c.
Подразумевается, что коэффициенты и корни уравнения действительные числа*/

void check_scanf(double *k); //ввод и проверка коэффициентов
void linear_equation(double b, double c); //решение линейного уравнения(если квадратное сводится к таковому)
void quadratic_equation(double a, double b, double c); //решение квадратного уравнения
void clean_buff(void); //очищает буфер для корректного считывания scanf

int main(void)
{
    //коэффициенты
    double a = 0;
    double b = 0;
    double c = 0;
    printf("Введите коэффициент перед x^2: ");
    check_scanf(&a);

    printf("Введите коэффициент перед x: ");
    check_scanf(&b);

    printf("Введите свободный член: ");
    check_scanf(&c);

    if (fabs(a) < __DBL_EPSILON__)
    {
        linear_equation(b, c);
    }
    else
    {
        quadratic_equation(a, b, c);
    }
    return 0;
}

void check_scanf(double *k)
{
    char ncheck = '\0'; //проверка строки на \n после числа
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

void linear_equation(double b, double c)
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
        double x = - (c / b);

        printf("%lf - корень уравнения\n", x);
    }
}

void quadratic_equation(double a, double b, double c)
{
    double D = b * b - 4 * a * c; //дискриминант

    if(fabs(D) < __DBL_EPSILON__)
    {
        double x = - (b / (2 * a));

        printf("%lf - корень уравнения\n", x);
    }
    else if(D < 0)
    {
        printf("Нет корней\n");
    }
    else
    {
        double x1 = (-b - sqrt(D)) / (2 * a);
        double x2 = (-b + sqrt(D)) / (2 * a);

        printf("%lf и %lf - корни уравнения\n", x1, x2);
    }
}

void clean_buff(void)
{
    int ch = 0;

    while(ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }
}
