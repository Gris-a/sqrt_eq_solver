/**
 * @file colors.h
*/

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define RESET_COLOR "\033[1;0m"

#define color_red(str) RED_COLOR str RESET_COLOR

#define color_green(str) GREEN_COLOR str RESET_COLOR

#define color_yellow(str) YELLOW_COLOR str RESET_COLOR
