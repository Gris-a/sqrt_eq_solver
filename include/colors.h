/**
 * @file colors.h
 * @author Gris-a
 * @brief Macros for highlighting text.
*/

/**
 * Red color escape-sequence.
*/
#define RED_COLOR "\033[1;31m"
/**
 * Green color escape-sequence.
*/
#define GREEN_COLOR "\033[1;32m"
/**
 * Yellow color escape-sequence.
*/
#define YELLOW_COLOR "\033[1;33m"
/**
 * Reset color escape-sequence.
*/
#define RESET_COLOR "\033[1;0m"
/**
 * Red colored text.
*/
#define color_red(str) RED_COLOR str RESET_COLOR
/**
 * Green colored text.
*/
#define color_green(str) GREEN_COLOR str RESET_COLOR
/**
 * Yellow colored text.
*/
#define color_yellow(str) YELLOW_COLOR str RESET_COLOR
