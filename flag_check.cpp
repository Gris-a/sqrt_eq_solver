#include <stdio.h>
#include <string.h>
#include "main.h"
#include "flag_check.h"

/**
 * @file flag_check.cpp
 * @author Gris-a
 * @brief File with flag processing functionsю
*/

int flag_check(int argc, char *argv[], const char arg[]) //подумать о длине
{
    int i = 0;
    if(argc > 1)
    {
        while(--argc > 0)
        {
            i++;
            if(!strncmp(arg, argv[i], MAX_ARG_LEN))
            {
                return 1;
            }
        }
    }
    return 0;
}
