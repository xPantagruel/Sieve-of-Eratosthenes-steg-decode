// error.h
// Řešení IJC-DU1, příklad b)
// Autor: Matej Macek, FIT
//Datum: 20.03.2022

#ifndef IJC_1_ERROR_H
#define IJC_1_ERROR_H


//vypise warning message nevypne program
void warning_msg(const char *fmt, ...);

//vypise warning message vypne program
void error_exit(const char *fmt, ...);

#endif //IJC_1_ERROR_H
