/**
 * @file args_check.h
 * @author Gris-a
 * @brief Processing command line arguments.
*/

/**
 * Max length of args in my_args.
*/
const int max_arg_len = 32;

/**
 * @brief Command line arguments of the program.
*/
struct arguments
{
    char help[max_arg_len]; ///< For more info.
    char test[max_arg_len]; ///< For testing.
    char user[max_arg_len]; ///< For user input-output.
} const my_args = {"--help", "--test", "--user"}; ///< Arguments.

/**
 * @brief Struct for detecting if arguments from my_args in argv.
*/
struct arguments_check
{
    int help;   ///< @b true if my_args.help in @b argv.
    const char *test; ///< Pointer to string that contains path to file with tests.
    int user;   ///< @b true if my_args.user in @b argv.
};

/**
 * @brief Search arguments from my_args in argv.
 * @param argc Number of arguments of command line.
 * @param argv Array with pointers to command line arguments.
 * @param check_arg Pointer to struct that checks arguments.
 * @return @b true if there is undefined arguments.
*/
int args_check(const int argc, const char *argv[], struct arguments_check *const check_arg);
