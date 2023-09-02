/**
 * @file colors.h
 * @author Gris-a
 * @brief Macros for highlighting text.
*/

#ifndef COLORS_H
#define COLORS_H

/**
 * Red color escape-sequence.
*/
#define RED_ESCAPE_SEQUENCE "\033[1;31m"

/**
 * Green color escape-sequence.
*/
#define GREEN_ESCAPE_SEQUENCE "\033[1;32m"

/**
 * Yellow color escape-sequence.
*/
#define YELLOW_ESCAPE_SEQUENCE "\033[1;33m"

/**
 * Purple color escape-sequence.
*/
#define PURPLE_ESCAPE_SEQUENCE "\033[1;35m"

/**
 * Reset color escape-sequence.
*/
#define RESET_ESCAPE_SEQUENCE "\033[1;0m"

/**
 * Red colored text.
*/
#define color_red(str) RED_ESCAPE_SEQUENCE str RESET_ESCAPE_SEQUENCE

/**
 * Green colored text.
*/
#define color_green(str) GREEN_ESCAPE_SEQUENCE str RESET_ESCAPE_SEQUENCE

/**
 * Yellow colored text.
*/
#define color_yellow(str) YELLOW_ESCAPE_SEQUENCE str RESET_ESCAPE_SEQUENCE

/**
 * Purple colored text.
*/
#define color_purple(str) PURPLE_ESCAPE_SEQUENCE str RESET_ESCAPE_SEQUENCE

#endif //COLORS_H
