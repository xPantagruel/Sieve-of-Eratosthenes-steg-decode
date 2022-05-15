// primes.c
// Řešení IJC-DU1, příklad a)
// Autor: Matej Macek, FIT
//Datum: 20.03.2022
//vytvori pole a zavola funkci erasthenes a vypise poslednich 10 prvocisel v danem poli

#include <stdio.h>
#include "bitset.h"
#include "eratosthenes.h"
#include <time.h>

#define size_of_array (300000000)
int main(){
    //start stopek
    clock_t start;
    start = clock();

    //alokace array
    bitset_create(array,size_of_array);
    eratosthenes(array);

    //vypise poslednich 10 prvocisel v array
    int counter_last_10 = 0;
    for(bitset_index_t i = size_of_array; i <= size_of_array; --i)
    {
        //vyskoceni z cyklu po vypsani prvocisel
        if(counter_last_10 == -1)
        {
            break;
        }

        //podminka pro otevreni cyklu ve kterem se vypisou prvocisla
        if(counter_last_10 == 10)
        {

            for (bitset_index_t j = i; j <= size_of_array; ++j)
            {

                if (bitset_getbit(array, j) == 0)
                {
                    printf("%lu\n",j);
                    --counter_last_10;//identifikator zda jsme uz vypsali vsech 10 prvocisel
                }

                //podminka pro vyskoceni z cyklu po vypsani vsech 10 prvocisel
                if (counter_last_10 == 0)
                {
                    counter_last_10 = -1;// pokud se rovna "-1" tak ukonci hlavni cyklus
                    break;
                }
            }
        }
        //scitac, ktery splni podminku pro cyklus ve kterem se vypisou prvocisla
        if ((bitset_getbit(array, i)) == 0)
        {
            ++counter_last_10;
        }
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
}

