#include <stdio.h>
#include <string.h>
#include "main.h"
#include "flag_check.h"

/**
 * @file flag_check.cpp
 * @author Gris-a
 * @brief File with flag processing functions.
*/

int flag_check(int argc, char *argv[], const char arg[])
{
    int i = 0;
    if(argc > 1)
    {
        while(--argc > 0)
        {
            i++;
            if(!strncmp(arg, argv[i], MAX_ARG_LEN)) //подумать о длине
            {
                return 1;
            }
        }
    }
    return 0;
}
