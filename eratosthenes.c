// eratosthenes.c
// Řešení IJC-DU1, příklad a)
// Autor: Matej Macek, FIT
//Datum: 20.03.2022
//funkce eratosthenes, ktera v bitovem poli nastavi 1 na mista, kde se nejedna pozicne o prvocislo
//a na pozicich prvocisel nastavi 0

#include "bitset.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eratosthenes.h"


void eratosthenes(bitset_t array){

    bitset_index_t size = bitset_size(array);
    int first_iteration = 0;

    bitset_index_t point = sqrt(size);//deklarace odmocniny
    //podminka odmocnina z i nesmi by vetsi nez odmocnina bitset_size
    //cyklus nastavi bit s pozici, ktere neni prvocislo na 1
    //prvni cyklus zacne az od 2
    for (bitset_index_t i = 2; i <= point; ++i) {

        //podminka pro preskoceni nasobku
        if(bitset_getbit(array,i)==0)
        {
            for (bitset_index_t j = i; j <= size; j = j + i) {
                //podminka jestli jde o prvni iteraci
                if (first_iteration == 0) {
                    first_iteration = 1;//zmena aby mohl loop splnit ucel
                    continue;
                }
                bitset_setbit(array, j, 1);
            }
            first_iteration = 0;//vraceni podminky ze jde o prvni iteraci
        }
    }
}