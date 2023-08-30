/**
 * @file args_check.h
 * @author Gris-a
 * @brief Processing command line arguments.
*/

#ifndef ARGS_CHECK_H
#define ARGS_CHECK_H

#include <stdbool.h>

/**
 * Max length of args in MY_ARGS.
*/
const size_t MAX_ARG_LEN = 32;

/**
 * @brief Command line arguments of the program.
*/
struct Arguments
{
    char help[MAX_ARG_LEN]; ///< For more info.
    char test[MAX_ARG_LEN]; ///< For testing.
    char user[MAX_ARG_LEN]; ///< For user input-output.
} const MY_ARGS = {"--help", "--test", "--user"}; ///< Arguments.

/**
 * @brief Struct for detecting if arguments from MY_ARGS in argv.
*/
struct Config_settings
{
    bool is_help;          ///< @b true if MY_ARGS.help in @b argv.

    const char *test_path; ///< Pointer to string that contains path to file with tests.

    bool is_interactive;   ///< @b true if MY_ARGS.user in @b argv.
};

/**
 * @brief Search arguments from MY_ARGS in argv.
 * @param argc Number of arguments of command line.
 * @param argv Array with pointers to command line arguments.
 * @param config_settings Pointer to struct that checks arguments.
 * @return @b true if there is undefined arguments.
*/

bool check_args(const int argc, const char *argv[], struct Config_settings *const config_settings);

#endif //ARGS_CHECK_H
