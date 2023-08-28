#include<string.h>
#include "./include/main.h"
#include "./include/args_check.h"

/**
 * @file args_check.cpp
 * @author Gris-a
 * @brief Functions for processing command line arguments.
*/

int args_check(const int argc, const char *argv[], struct arguments_check *const check_arg)
{
    for(int i = 1; i < argc; i++)
    {
        if(!strncmp(my_args.help, argv[i], ARG_LEN))
            {
                check_arg->help = i;
                break;
            }

        if(!strncmp(my_args.test, argv[i], ARG_LEN))
            {
                check_arg->test = ++i;
                continue;
            }

        if(!strncmp(my_args.user, argv[i], ARG_LEN))
            {
                check_arg->user = i;
                continue;
            }

        return 1;
    }

    return 0;
}
