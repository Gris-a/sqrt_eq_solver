#include <stdio.h>
#include <string.h>
#include "./include/main.h"
#include "./include/solve.h"
#include "./include/user.h"
#include "./include/tests.h"

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
int main(const int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("This programm solves quadratic equation.\n");
        printf("ZAG, 2023.\n"
                "\n");

        return 0;
    }

    int test = 0;
    int help = 0;
    int user = 0;
    int undef_arg = 0;

    for(int i = 1; i < argc; i++)
    {
        if(!strncmp(my_args.help, argv[i], ARG_LEN))
            {
                help = 1;
                break;
            }

        if(!strncmp(my_args.test, argv[i], ARG_LEN))
            {
                test = ++i;
                continue;
            }

        if(!strncmp(my_args.user, argv[i], ARG_LEN))
            {
                user = 1;
                continue;
            }

        undef_arg = 1;
        break;
    }

    if(undef_arg || help)
    {
        if(undef_arg)
        {
            printf("Undefined options.\n");
        }

        printf("Usage: <program path> [options]\n"
               "Options:\n"
               "--help              Print this message and exit.\n"
               "\n"
               "--test DIRECTORY    Run tests for program.\n"
               "\n"
               "--user              Solve equation with user input-output.\n"
               "\n");

        return (undef_arg) ? 1 : 0;
    }

    if(test)
    {
        run_all_tests(fopen(argv[test], "r"));
    }

    if(user)
    {
        solve_equation_user();
    }

    return 0;
}
