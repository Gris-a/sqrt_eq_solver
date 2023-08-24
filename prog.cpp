#include <stdio.h>
#include <string.h>
#include "prog.h"

/**
 * @file prog.cpp
 * @author Gris-a
 * @brief Main prog file.
*/

int flag_check(int argc, char *argv[], const char arg[])
{
    int i = 0;
    if(argc > 1)
    {
        while(--argc > 0)
        {
            i++;
            if(!strncmp(arg, argv[i], (strlen(arg) <= strlen(argv[i])) ? strlen(arg) : strlen(argv[i])))
            {
                return 1;
            }
        }
    }
    return 0;
}

void run_prog(const int argc, char *argv[])
{
    printf("This programm solves quadratic equation.\n");
    printf("ZAG, 2023.\n\n");
    if(argc == 1)
    {
        printf("--help for more info.\n\n");
        return;
    }
    if(flag_check(argc, argv, "--help"))
    {
        printf("--test to test the program.\n\n--uio to solve equation with user input-output.\n\n");
        return;
    }
    if(flag_check(argc, argv, "--test"))
    {
        run_all_tests();
    }
    if(flag_check(argc, argv, "--uio"))
    {
        solve_equation_user();
    }
}
