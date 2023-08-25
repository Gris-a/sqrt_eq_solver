#include <stdio.h>

/**
 * @file colors.h
 * @author Gris-a
 * @brief Macros for highlighting text.
*/

/**
 * Macro that prints text red.
*/
#define PRINTF_R(...)  printf("\033[1;31m");\
                       printf(__VA_ARGS__);\
                       printf("\033[1;0m")
/**
 * Macro that prints text green.
*/
#define PRINTF_G(...)  printf("\033[1;32m");\
                       printf(__VA_ARGS__);\
                       printf("\033[1;0m")
/**
 * Macro that prints text yellow.
*/
#define PRINTF_Y(...)  printf("\033[1;33m");\
                       printf(__VA_ARGS__);\
                       printf("\033[1;0m")
