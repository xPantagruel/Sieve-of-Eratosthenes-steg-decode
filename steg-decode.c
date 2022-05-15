// steg-decode.c
// Řešení IJC-DU1, příklad b)
// Autor: Matej Macek, FIT
// Datum: 20.03.2022
//nacte obrazek formatu .ppm a v nem nalezne ukrytou zpravu
//tajna zprava je spojeni bitu na pozicich prvocisel od 29

#include "ppm.h"
#include <stdio.h>
#include "error.h"
#include <stdlib.h>
#include "eratosthenes.h"
#include "bitset.h"

int main(int argc, char *argv[]) {
    //kontrola zda jsme nacetli dostatecne argumentu
    if (argc != 2) {
        error_exit("Argumenty spatne zadane\n");
    }

    struct ppm *pm_head = ppm_read(argv[1]);//hlava struktury s daty


    unsigned size_for_allocation = pm_head->xsize * pm_head->ysize * 3;//velikost pro alokaci
    bitset_alloc(array, size_for_allocation);//alokace noveho retezce pro eratosthenes

    //pokud se na
    if (array == NULL) {
        error_exit("Chyba pri alokovani pameti");
    }

    eratosthenes(array);

    char whole_array_print = 0;//inicializace noveho retezce pro ukladani bitu a nasledne vypsani
    char bit_for_array ;
    int maximum = 7;  //podminka ukonceni
    int position = 0;
    //cyklus pro vypsani znaku
    for (unsigned i = 29; i < size_for_allocation; i++)
    {
        if (bitset_getbit(array, i) == 1) {
            continue;
        }

        bit_for_array = pm_head->data[i];
        bit_for_array = bit_for_array & 1;
        bit_for_array = bit_for_array << position;
        whole_array_print |= bit_for_array;

        //vypsani znaku
        //podminka pro reset promenne na 0 a kontrola zda nejsme na konci
        if(position == maximum )
        {
            if (whole_array_print != '\0') {//podminka pro ukonceni a break

                printf("%c", whole_array_print);
                whole_array_print = 0;
                position = 0;


            }else
            {
                ppm_free(pm_head);
                bitset_free(array);
                return 0;
            }

        }else {
            position++;//pocitac pro nacitani bitu do pole
        }
    }
    ppm_free(pm_head);
    bitset_free(array);
    error_exit("Spatne precteni zpravy\n");
}





