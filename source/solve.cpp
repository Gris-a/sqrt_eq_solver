#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "../include/solve.h"

/**
 * @file solve.cpp
 * @author Gris-a
 * @brief Functions for solving equation.
*/

void solve_equation(const struct Coefficients *const coef, struct Roots *const rts)
{
    assert(isfinite(coef->a));
    assert(isfinite(coef->b));
    assert(isfinite(coef->c));
    assert(rts != NULL);
    assert(coef != NULL);

    float_cmp(coef->a, 0) ? linear_equation(coef, rts) : quadratic_equation(coef, rts);

    rts->x1 = (float_cmp(rts->x1, 0)) ? 0 : rts->x1;
    rts->x2 = (float_cmp(rts->x2, 0)) ? 0 : rts->x2;
}

void quadratic_equation(const struct Coefficients *const coef, struct Roots *const rts)
{
    assert(isfinite(coef->a));
    assert(isfinite(coef->b));
    assert(isfinite(coef->c));
    assert(rts != NULL);
    assert(coef != NULL);

    if(float_cmp(coef->c, 0))
    {
        if(float_cmp(coef->b, 0))
        {
            rts->x1 = rts->x2 = 0;
            rts->n_roots = ONE_ROOT;

            return;
        }

        rts->x1 = 0;
        rts->x2 = -(coef->b / coef->a);
        rts->n_roots = TWO_ROOTS;

        return;
    }
    if(float_cmp(coef->b, 0))
    {
        if(coef->a * coef->c > 0)
        {
            rts->n_roots = ZERO_ROOTS;

            return;
        }

        rts->x1 = sqrt(-(coef->c / coef->a));
        rts->x2 = -rts->x1;
        rts->n_roots = TWO_ROOTS;

        return;
    }

    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    if(float_cmp(D, 0))
    {
        rts->x1 = rts->x2 = - (coef->b / (2 * coef->a));
        rts->n_roots = ONE_ROOT;
    }
    else if(D < 0)
    {
        rts->n_roots = ZERO_ROOTS;
    }
    else
    {
        double D_sqrt = sqrt(D);

        rts->x1 = -(coef->b - D_sqrt) / (2 * coef->a);
        rts->x2 = -(coef->b + D_sqrt) / (2 * coef->a);
        rts->n_roots = TWO_ROOTS;
    }
}

void linear_equation(const struct Coefficients *const coef, Roots *const rts)
{
    assert(isfinite(coef->a));
    assert(isfinite(coef->b));
    assert(isfinite(coef->c));
    assert(rts != NULL);
    assert(coef != NULL);

    if(float_cmp(coef->b, 0))
    {
        if(float_cmp(coef->c, 0))
        {
            rts->n_roots = INF_ROOTS;

            return;
        }

        rts->n_roots = ZERO_ROOTS;
    }
    else
    {
        rts->x1 = rts->x2 = - (coef->c / coef->b);
        rts->n_roots = ONE_ROOT;
    }
}
//TODO: нормальное сравнение чисел
bool float_cmp(const double a, const double b, const double ERR)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(ERR));

    return fabs(a - b) < ERR;
}
