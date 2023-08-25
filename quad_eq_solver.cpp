#include <stdio.h>
#include "main.h"
#include "solve.h"
#include "user.h"
#include "tests.h"
#include "flag_check.h"

/**
 * @mainpage Quadratic equation solver
 * @file quad_eq_solver.cpp
 * @author Gris-a.
 * @brief Program solves quadratic equation.
*/

/**
 * @brief Main function.
 * @param argc Number of command line arguments.
 * @param argv Array with pointers to command line arguments.
 * @return returns @b 0;
 * Function depends on command line arguments.
*/
int main(int argc, char *argv[])
{
    printf("This programm solves quadratic equation.\n");
    printf("ZAG, 2023.\n"
           "\n");
    if(argc == 1)
    {
        printf("--help for more info.\n"
               "\n");
        return 0;
    }
    if(flag_check(argc, argv, my_args.help))
    {
        printf("Usage: ./prog.out [options]\n"
               "Options:\n"
               "--test          Run tests for program.\n"
               "\n"
               "--uio           Solve equation with user input-output.\n"
               "\n");
        return 0;
    }
    if(flag_check(argc, argv, my_args.test))
    {
        run_all_tests();
    }
    if(flag_check(argc, argv, my_args.user))
    {
        solve_equation_user();
    }
    return 0;
}
