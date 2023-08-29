#include "../include/args_check.h"

#include <assert.h>
#include <math.h>
#include <string.h>

/**
 * @file args_check.cpp
 * @author Gris-a
 * @brief
*/

int args_check(const int argc, const char *argv[], struct arguments_check *const check_arg)
{
    assert(!isnan(argc));
    assert(argv != NULL);
    assert(check_arg != NULL);

    for(int i = 1; i < argc; i++)
    {
        if(!strncmp(my_args.help, argv[i], max_arg_len))
            {
                check_arg->help = 1;
                break;
            }

        if(!strncmp(my_args.test, argv[i], max_arg_len))
            {
                check_arg->test = argv[++i];
                continue;
            }

        if(!strncmp(my_args.user, argv[i], max_arg_len))
            {
                check_arg->user = 1;
                continue;
            }

        return 1;
    }

    return 0;
}
