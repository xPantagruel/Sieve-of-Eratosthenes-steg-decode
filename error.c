// error.c
// Řešení IJC-DU1, příklad b)
// Autor: Matej Macek, FIT
//Datum: 20.03.2022

#include <stdarg.h>
#include <stdio.h>
#include "error.h"
#include <stdlib.h>


void warning_msg(const char *fmt, ...)
{

    fprintf(stderr, " CHYBA ");
    va_list var;
    va_start(var, fmt);
    vfprintf(stderr, fmt, var);
    va_end(var);

}

void error_exit(const char *fmt, ...)
{
    va_list var;
    va_start(var, fmt);
    fprintf(stderr, " CHYBA ");
    vfprintf(stderr, fmt, var);
    va_end(var);
    exit(1);
}