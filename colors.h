/**
 * @file colors.h
 * @author Gris-a
 * @brief Macros for highlighting text.
*/

/**
 * Macros that makes text red.
*/
#define RED(expr) ("\033[1;31m" expr "\033[1;0m")
/**
 * Macros that makes text green.
*/
#define GREEN(expr) ("\033[1;32m" expr "\033[1;0m")
/**
 * Macros that makes text yellow.
*/
#define YELLOW(expr) ("\033[1;33m" expr "\033[1;0m")
