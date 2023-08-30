#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../include/args_check.h"

/**
 * @file args_check.cpp
 * @author Gris-a
 * @brief Processing command line arguments.
*/

bool check_args(const int argc, const char *argv[], struct Config_settings *const config_settings)
{
    assert(argv != NULL);

    for(int i = 1; i < argc; i++)
    {
        if(!strncmp(MY_ARGS.help, argv[i], MAX_ARG_LEN))
        {
            config_settings->is_help = true;

            continue;
        }

        if(!strncmp(MY_ARGS.test, argv[i], MAX_ARG_LEN))
        {
            config_settings->test_path = argv[++i];

            continue;
        }

        if(!strncmp(MY_ARGS.user, argv[i], MAX_ARG_LEN))
        {
            config_settings->is_interactive = true;

            continue;
        }

        return true;
    }

    return false;
}
