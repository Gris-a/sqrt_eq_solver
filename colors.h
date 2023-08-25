/**
 * @file colors.h
 * @brief Macros for highlighting text.
*/

#define RED_COLOR "\033[1;31m"    ///< Red color escape-sequence.
#define GREEN_COLOR "\033[1;32m"  ///< Green color escape-sequence.
#define YELLOW_COLOR "\033[1;33m" ///< Yellow color escape-sequence.
#define RESET_COLOR "\033[1;0m"   ///< Reset color escape-sequence.

#define color_red(str) RED_COLOR str RESET_COLOR       ///< Red colored text.

#define color_green(str) GREEN_COLOR str RESET_COLOR   ///< Red colored text.

#define color_yellow(str) YELLOW_COLOR str RESET_COLOR ///< Red colored text.
