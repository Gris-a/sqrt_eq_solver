#include <stdio.h>
#include <math.h>

/*программма решает уравнение вида a*x**2+b*x+c=0, получая на вход коэффициенты a, b и c.
Подразумевается, что коэффициенты и корни уравнения действительные числа*/

int main(void)
{
    float a, b, c; //коэффициенты уравнения
    float x1, x2; //корни уравнения

    printf("Введите коэффициенты квадратного уравнения через пробел: ");
    scanf("%f %f %f", &a, &b, &c);

    if (fabs(a) < __FLT_EPSILON__)
    {
        if (fabs(b) < __FLT_EPSILON__)
        {
            if (fabs(c) < __FLT_EPSILON__)
            {
                printf("корнем уравнения может быть любое действительное число.\n");
                return -1;
            }
            printf("Корней нет.\n");
            return 0;
        }
        x1 = -(c / b);
        printf("%f - корень уравнения.\n", x1);
        return 1;
    }

    float D; //дискриминант
    D = powf(b, 2) - 4 * a * c;

    if (D < 0)
    {
        printf("Корней нет.\n");
        return 0;
    }
    if (fabs(D) < __FLT_EPSILON__)
    {
        x1 = -(b / (2 * a));
        printf("%f - корень уравнения.\n", x1);
        return 1;
    }

    x1 = (-b - sqrtf(D)) / (2 * a);
    x2 = (-b + sqrtf(D)) / (2 * a);
    printf("%f и %f - корни уравнения\n", x1, x2);
    return 2;
}
