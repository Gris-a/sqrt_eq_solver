#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "./include/main.h"
#include "./include/solve.h"

/**
 * @file solve.cpp
 * @author Gris-a
 * @brief Functions for solving equation.
*/

int solve_equation(const struct coefficients coef, struct roots *const rts)
{
    assert(isfinite(coef.a));
    assert(isfinite(coef.b));
    assert(isfinite(coef.c));
    assert(!isnan(coef.a));
    assert(!isnan(coef.b));
    assert(!isnan(coef.c));
    assert(rts != NULL);
    int nRoots = (float_cmp(coef.a, 0.0, M_ERR)) ? linear_equation(coef, rts) : quadratic_equation(coef, rts);
    rts->x1 = (float_cmp(rts->x1, 0.0, M_ERR)) ? 0.0 : rts->x1;
    rts->x2 = (float_cmp(rts->x2, 0.0, M_ERR)) ? 0.0 : rts->x2;
    if(nRoots == 2 && float_cmp(rts->x1, rts->x2, M_ERR))
    {
        nRoots = 1;
        rts->x2 = rts->x1;
    }
    return nRoots;
}

int quadratic_equation(const struct coefficients coef, struct roots *const rts)
{
    if(float_cmp(coef.c, 0.0, M_ERR))
    {
        if(float_cmp(coef.b, 0.0, M_ERR))
        {
            rts->x1 = rts->x2 = 0.0;
            return ONE_ROOT;
        }
        rts->x1 = 0.0;
        rts->x2 = -(coef.b / coef.a);
        return TWO_ROOTS;
    }
    if(float_cmp(coef.b, 0.0, M_ERR))
    {
        if((coef.a < 0) == (coef.c < 0.0))
        {
            return ZERO_ROOTS;
        }
        rts->x1 = sqrt(-(coef.c / coef.a));
        rts->x2 = -rts->x1;
        return TWO_ROOTS;
    }
    double D = coef.b * coef.b - 4 * coef.a * coef.c;
    if(float_cmp(D, 0.0, M_ERR))
    {
        rts->x1 = rts->x2 = - (coef.b / (2 * coef.a));
        return ONE_ROOT;
    }
    else if(D < 0.0)
    {
        return ZERO_ROOTS;
    }
    else
    {
        double D_sqrt = sqrt(D);
        rts->x1 = (-coef.b - D_sqrt) / (2 * coef.a);
        rts->x2 = (-coef.b + D_sqrt) / (2 * coef.a);
        return TWO_ROOTS;
    }
}

int linear_equation(const struct coefficients coef, struct roots *const rts)
{
    if(float_cmp(coef.b, 0.0, M_ERR))
    {
        if(float_cmp(coef.c, 0.0, M_ERR))
        {
            return INF_ROOTS;
        }
        return ZERO_ROOTS;
    }
    else
    {
        rts->x1 = rts->x2 = - (coef.c / coef.b);
        return ONE_ROOT;
    }
}

int float_cmp(const double a, const double b, const double err)
{
    return fabs(a - b) < err;
}