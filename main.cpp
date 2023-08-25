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
int main(const int argc, char *argv[]) //проверка всех аргументов
{
    if(argc == 1)
    {
        printf("This programm solves quadratic equation.\n");
        printf("ZAG, 2023.\n"
                "\n");
        return 0;
    }
    int test = flag_check(argc, argv, my_args.test);
    int user = flag_check(argc, argv, my_args.user);
    int help = flag_check(argc, argv, my_args.help);
    int undef_argc = (argc - 1 - test - user - help) != 0;
    if(undef_argc || help)
    {
        if(undef_argc)
        {
            printf("Undefined options.\n");
        }
        printf("Usage: ./programm.out [options]\n"
               "Options:\n"
               "--help          Print this message and exit.\n"
               "\n"
               "--test          Run tests for program.\n"
               "\n"
               "--uio           Solve equation with user input-output.\n"
               "\n");
        return (undef_argc) ? 1 : 0;
    }
    if(test)
    {
        run_all_tests();
    }
    if(user)
    {
        solve_equation_user();
    }
    return 0;
}
