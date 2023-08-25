#include <stdio.h>
#include "main.h"
#include "solve.h"
#include "user.h"
#include "tests.h"
#include "flag_check.h"

/**
 * @mainpage Quadratic equation solver
 * @author Gris-a
 *
 * Это документация для QES. Вы можете скачать её <a href="https://github.com/Gris-a/sqrt_eq_solver">здесь.</a>
 * @par About
 * Эта программа решает квадратное уравнение.

 * @par Self-testing
 *
 *
*/

/**
 * @file main.cpp
 * @author Gris-a.
 * @brief Program solves quadratic equation.
*/

/**
 * @brief Main function that depends on command line arguments.
 * @param argc Number of command line arguments.
 * @param argv Array with pointers to command line arguments.
 * @return
*/
int main(const int argc, char *argv[])
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
               "--user          Solve equation with user input-output.\n"
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
