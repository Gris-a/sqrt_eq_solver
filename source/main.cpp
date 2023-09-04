#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/args_check.h"
#include "../include/solve.h"
#include "../include/tests.h"
#include "../include/user.h"

/**
 * @file main.cpp
 * @author Gris-a.
 * @brief Program solves quadratic equation.
*/

int main(const int argc, const char *argv[])
{
    if(argc == 1)
    {
        printf("This program solves quadratic equation.\n");
        printf("ZAG, 2023.\n"
               "\n"
               "--help for more info.\n"
               "\n");

        return EXIT_SUCCESS;
    }

    struct Config_settings config_settings = {0, NULL, 0};

    bool undef_arg = check_args(argc, argv, &config_settings);

    if(undef_arg || config_settings.is_help)
    {
        if(undef_arg)
        {
            printf("Undefined options.\n");
        }

        printf("Usage: ./solver.out [options] [target]\n"
               "Options:\n"
               "--help              Print this message and exit.\n"
               "\n"
               "--test FILE         Run tests from FILE.\n"
               "\n"
               "--user              Solve equation with user input-output.\n"
               "\n");

        return (undef_arg) ? EXIT_FAILURE : EXIT_SUCCESS;
    }

    if(config_settings.test_path != NULL)
    {
        run_all_tests(config_settings.test_path);
    }

    if(config_settings.is_interactive)
    {
        solve_equation_user();
    }

    return EXIT_SUCCESS;
}
