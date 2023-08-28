#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "./include/main.h"
#include "./include/solve.h"
#include "./include/user.h"

/**
 * @file user.cpp
 * @author Gris-a
 * @brief Functions with user input-output.
*/

void solve_equation_user(void)
{
    struct coefficients coef = {0.0, 0.0, 0.0};
    struct roots rts = {0.0, 0.0};
    int nRoots = 0;

    if(get_coefficients(&coef))
    {
        printf(color_red("\n"
               "End of File.\n"));

        return;
    }

    nRoots = solve_equation(&coef, &rts);

    printf_roots(&rts, nRoots);
}

int get_coefficients(struct coefficients *const coef)
{
    assert(coef != NULL);

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
    assert(dbl != NULL);

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
    assert(rts != NULL);
    assert(isfinite(rts->x1));
    assert(isfinite(rts->x2));
    assert(!isnan(nRoots));

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
