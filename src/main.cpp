#include <stdio.h>
#include "./include/main.h"
#include "./include/solve.h"
#include "./include/user.h"
#include "./include/tests.h"
#include "./include/args_check.h"

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

    struct arguments_check check_arg= {0, 0, 0};
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
               "--test DIRECTORY    Run tests for program.\n"
               "\n"
               "--user              Solve equation with user input-output.\n"
               "\n");

        return (undef_arg) ? 1 : 0;
    }

    if(check_arg.test != 0)
    {
        run_all_tests(argv[check_arg.test]);
    }

    if(check_arg.user)
    {
        solve_equation_user();
    }

    return 0;
}
