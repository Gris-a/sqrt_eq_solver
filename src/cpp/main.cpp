#include <stdio.h>
#include "../include/args_check.h"
#include "../include/solve.h" //TODO: можно неявно?
#include "../include/user.h"
#include "../include/tests.h"

/**
 * @file main.cpp
 * @author Gris-a.
 * @brief Program solves quadratic equation.
*/

/**
 * @brief Main function that depends on command line arguments.
 * @param argc Number of command line arguments.
 * @param argv Array with pointers to command line arguments.
 * @return @b 0 if arguements are valid.
*/
int main(const int argc, const char *argv[])
{
    if(argc == 1)
    {
        printf("This program solves quadratic equation.\n");
        printf("ZAG, 2023.\n"
               "\n");

        return 0;
    }

    struct arguments_check check_arg = {0, NULL, 0};
    int undef_arg = args_check(argc, argv, &check_arg);

    if(undef_arg || check_arg.help)
    {
        if(undef_arg)
        {
            printf("Undefined options.\n");
        }

        printf("Usage: <program path> [options] [target]\n"
               "Options:\n"
               "--help              Print this message and exit.\n"
               "\n"
               "--test FILE         Run tests from FILE.\n"
               "\n"
               "--user              Solve equation with user input-output.\n"
               "\n");

        return (undef_arg) ? 1 : 0;
    }

    if(check_arg.test != NULL)
    {
        run_all_tests(check_arg.test);
    }

    if(check_arg.user)
    {
        solve_equation_user();
    }

    return 0;
}