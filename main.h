#ifndef MAIN_H
#define MAIN_H

/* Preprocessor directives to prevent multiple inclusion of the header file */
/* ifndef checks if the identifier MAIN_H has not been defined yet */
/* define MAIN_H ensures that it is defined now, to prevent further inclusion */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/* Definition of a struct that stores the conversion specifier and its corresponding function */
typedef struct format
{
    char *id;
    int (*f)();
} convert_match;

/* Declaration of the _printf function, which formats and prints output to stdout */
/* Takes a format string and variable number of arguments */
/* Returns the number of characters printed, or -1 if an error occurs */
int _printf(const char *format, ...);

/* End of the include guard */
#endif
