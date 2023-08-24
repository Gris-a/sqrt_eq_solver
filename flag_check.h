/**
 * @file flag_check.h
 * @author Gris-a
 * @brief Contains flag_check.cpp functions declarations
*/

/**
 * @brief Checks if @b arg in @b argv[].
 * @param argc Number of command line arguments.
 * @param argv Array with pointers to command line arguments.
 * @param arg Argument that is searching in @b argv.
 * @return @b 1 if @b arg in @b argv, otherwise @b 0.
*/
int flag_check(int argc, char *argv[], const char arg[]);
