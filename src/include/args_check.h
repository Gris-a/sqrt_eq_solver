/**
 * @file args_check.h
 * @author Gris-a
 * @brief Contains declarations of functions for processing command line arguments.
*/

/**
 * @brief Ищет аргументы из my_args в argv.
 * @param argc Number of arguments.
 * @param argv Array with pointers to command line arguments.
 * @param check_arg Указатель на структуру, в которую помещаются индексы вхождения аргументов my_args в argv.
 * @return @b true if there is undefined argument, otherwise @b false.
 * @note в переменную test в структуре помещается индекс пути к файлу с тестами.
*/
int args_check(const int argc, const char *argv[], struct arguments_check *const check_arg);
