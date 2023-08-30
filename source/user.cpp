#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "../include/user.h"

#include "../include/colors.h"
#include "../include/solve.h"

/**
 * @file user.cpp
 * @author Gris-a
 * @brief Functions with user input-output.
*/
void solve_equation_user(void)
{
    struct Coefficients coef = {0, 0, 0};
    struct Roots rts = {0, 0, ZERO_ROOTS};

    if(get_coefficients(&coef))
    {
        printf(color_red("\n"
                         "End of File.\n"));

        return;
    }

    solve_equation(&coef, &rts);

    printf_roots(&rts);
}

bool get_coefficients(struct Coefficients *const coef)
{
    assert(coef != NULL);

    printf("Введите коэффициент перед x^2: ");
    if(check_scanf_double(&coef->a))
    {
        return true;
    }

    printf("Введите коэффициент перед x: ");
    if(check_scanf_double(&coef->b))
    {
        return true;
    }

    printf("Введите свободный член: ");
    if(check_scanf_double(&coef->c))
    {
        return true;
    }

    return false;
}

bool check_scanf_double(double *const dbl)
{
    assert(dbl != NULL);

    char ncheck = '\0';
    int scanf_out = 0;

    while(true)
    {
        scanf_out = scanf("%lg%c", dbl, &ncheck);

        if((scanf_out != 2) || (ncheck != '\n'))
        {
            if(clean_buff() == EOF)
            {
                return true;
            }

            printf("Некорректный ввод, попробуйте снова: ");
        }
        else
        {
            return false;
        }
    }
}

int clean_buff(void)
{
    int ch = 0;

    while(ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }

    return ch;
}

void printf_roots(const struct Roots *const rts)
{
    assert(rts != NULL);
    assert(isfinite(rts->x1));
    assert(isfinite(rts->x2));

    switch(rts->n_roots)
    {
        case INF_ROOTS:
            printf("Корнем может быть любое действительное число.\n");
            break;
        case ZERO_ROOTS:
            printf("Нет корней.\n");
            break;
        case ONE_ROOT:
            printf("%.*lg - корень уравнения.\n", DIGITS, rts->x1);
            break;
        case TWO_ROOTS:
            printf("%.*lg и %.*lg - корни уравнения.\n", DIGITS, rts->x1, DIGITS, rts->x2);
            break;
        default:
            printf("Не верное количество корней.\n");
            break;
    }
}
