// bitset.h
// Řešení IJC-DU1, příklad a)
// Autor: Matej Macek, FIT
// Datum: 20.03.2022
// bitset.h slouzi k deklaraci maker a inline funkci

#ifndef IJC_1_BITSET_H
#define IJC_1_BITSET_H
#include "bitset.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "error.h"
#include <assert.h>

typedef unsigned long bitset_t[];

typedef unsigned long bitset_index_t;//32 bit(4 bytes)

#define bitset_create(jmeno_pole,velikost) _Static_assert(!(velikost <= 0),"Velikost makra bitset_create je spatne definovana") ; bitset_index_t jmeno_pole[(velikost / (sizeof(bitset_index_t)*8)) + ((velikost %  (sizeof(bitset_index_t)*8)) ? 1 : 0) + 1] = {velikost};

#define bitset_alloc(jmeno_pole,velikost) assert(!(velikost <= 0));bitset_index_t *jmeno_pole= calloc(((velikost / (sizeof(bitset_index_t)*8)) + ((velikost % (sizeof(bitset_index_t)*8)) ? 1 : 0))+1 ,(sizeof(bitset_index_t)));jmeno_pole[0] = velikost;


#ifdef USE_INLINE

static inline bitset_index_t bitset_size(bitset_t jmeno_pole)
    {
        return jmeno_pole[0];
    }

    static inline void bitset_free(bitset_t jmeno_pole)
    {
        free(jmeno_pole);
    }

    static inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, bitset_index_t vyraz)
    {
     if((unsigned long)index > (unsigned long) jmeno_pole[0]){
         error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)(jmeno_pole[0]-1));
     }
     else{
        (vyraz>=1) ? ((jmeno_pole)[((index) / (sizeof(bitset_index_t)*8)) + (((index) %  (sizeof(bitset_index_t)*8)) ? 1 : 0)]  |= 1UL << (index)) : \
                                                            ((jmeno_pole)[((index) / (sizeof(bitset_index_t)*8)) + (((index) %  (sizeof(bitset_index_t)*8)) ? 1 : 0)] &= ~(1UL << (index)));}
    }

    static inline bitset_index_t bitset_getbit(bitset_t jmeno_pole,bitset_index_t index)
    {
         if ((unsigned long)index > (unsigned long) jmeno_pole[0]){
             error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)(jmeno_pole[0]-1));
             return -1;
         }

        return (((jmeno_pole)[((index) / (sizeof(bitset_index_t)*8)) + (((index) %  (sizeof(bitset_index_t)*8)) ? 1 : 0)] >> (index)) & 1U);


    }

#else


#define bitset_free(jmeno_pole) free(jmeno_pole)

#define bitset_size(jmeno_pole)jmeno_pole[0]

#define bitset_setbit(jmeno_pole,index,vyraz) vyraz>=1 ? ((jmeno_pole)[((index) / (sizeof(bitset_index_t)*8)) + (((index) %  (sizeof(bitset_index_t)*8)) ? 1 : 0)]  |= 1UL << (index)) : \
                                                            ((jmeno_pole)[((index) / (sizeof(bitset_index_t)*8)) + (((index) %  (sizeof(bitset_index_t)*8)) ? 1 : 0)] &= ~(1UL << (index)));

#define bitset_getbit(jmeno_pole,index) \
                            ((unsigned long)index > ((unsigned long) bitset_size(jmeno_pole))) ?\
                            (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)(jmeno_pole[0]-1)), 0):\
                            (((jmeno_pole)[((index) / (sizeof(bitset_index_t)*8)) + (((index) %  (sizeof(bitset_index_t)*8)) ? 1 : 0)] >> (index)) & 1U)


#endif //USE_INLINE

#endif //IJC_1_BITSET_H